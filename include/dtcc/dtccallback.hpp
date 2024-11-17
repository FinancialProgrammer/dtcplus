#pragma once
#include <dtcc/dtc.hpp>
#include <dtcc/dtcvls.hpp>
#include <dtcc/log.hpp>

#include <netc.h>

#include <signal.h> // sig_atomic_t
#include <stdlib.h>

typedef void (*callback_t)(void*);

namespace dtcc {
  struct BaseCallback {
    sig_atomic_t volatile*m_exit;
    sig_atomic_t volatile*m_clientencodingF;
    DTC::EncodingEnum volatile*m_clientencoding;
    DTC::EncodingEnum m_encoding;

    nc_socket_t *m_sock;

    BaseCallback(nc_socket_t *sock, sig_atomic_t volatile*exit, DTC::EncodingEnum volatile*clientencoding, sig_atomic_t volatile*clientencodingF) 
    : m_sock(sock), m_exit(exit), m_clientencoding(clientencoding), m_clientencodingF(clientencodingF) {}
    BaseCallback(const BaseCallback&) = delete;
    BaseCallback(const BaseCallback&&) = delete;
    ~BaseCallback() = default;

    // callbacks
      // --- auxiliary --- //
        void Encoding(DTC::s_EncodingResponse *resp) {
          this->m_encoding = resp->Encoding;
          *this->m_clientencoding = this->m_encoding;
          *this->m_clientencodingF = true; // alert client value is now readable
        }
        void Heartbeat(DTC::s_Heartbeat *hb) {
          DTC::s_Heartbeat hbreq;
          size_t _;
          nc_error_t err = nwrite(this->m_sock, &hbreq, sizeof(hbreq), &_, NC_OPT_NULL);
          if (err != NC_ERR_GOOD) {
            WARN("Failed to write heatbeat back to server, %s", nstrerr(err));
          }
        }
        void GeneralLog(const char *msg) { LOG("General Log %s", msg); }
        void UserLog(const char *msg, uint8_t IsPopupMsg) { LOG("User Log %s", msg); }
        void Alert(const char *msg, const char *tradeacc) { LOG("Alert %s", msg); }
      // --- auth --- //
        void Logon(
          DTC::LogonStatusEnum result, int32_t _1,
          const char *resultText, const char *reconAddr,
          const char *serverName, const char *symbolExchangeDelim,
          uint8_t *flags1, uint8_t *flags2
        ) {
          if (result == DTC::LogonStatusEnum::LOGON_SUCCESS) {
            LOG("Logon Sucess to %s", serverName);
          } else if (result == DTC::LogonStatusEnum::LOGON_RECONNECT_NEW_ADDRESS) {
            ERR("Logon Failed (NotImplemented) to %s, attempting reconnection to address %s ", serverName, reconAddr);
          } else if (result == DTC::LogonStatusEnum::LOGON_ERROR) {
            ERR("Logon Failed to %s with result %s", serverName, resultText);
          } else if (result == DTC::LogonStatusEnum::LOGON_ERROR_NO_RECONNECT) {
            ERR("Logon Failed (No Reconnect) to %s with result %s", serverName, resultText);
          }
        }
        void Logoff(const char *reason, uint8_t DoNotReconnect) {
          WARN("Server Sent Logoff, Client Attempting Graceful Close");
          *m_exit = true;
        }
      // --- market auxiliary --- //
      // --- market data --- //
      // --- market depth --- //
      // --- trading auxiliary --- //
      // --- order --- //
      // --- position --- //
    // backend
      uint16_t GetType(const void *buffer) { 
        if (this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING || this->m_encoding == DTC::EncodingEnum::BINARY_WITH_VARIABLE_LENGTH_STRINGS) {
          return ((DTC::s_MessageHeader*)buffer)->Type;
        } else {
          ERR("Encoding not supported");
        }
        return 65535; // max uint16 value
      }
      uint16_t GetSize(const void *buffer) { 
        if (this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING || this->m_encoding == DTC::EncodingEnum::BINARY_WITH_VARIABLE_LENGTH_STRINGS) {
          return ((DTC::s_MessageHeader*)buffer)->Size;
        } else {
          ERR("Encoding not supported");
        }
        return 65535; // max uint16 value
      }
    // filter
    template <class ChildSocketT>
    static void filter(
      ChildSocketT *_this, 
      char *buffer, size_t bufferSize
    ) {
      if (
        _this->m_encoding != DTC::EncodingEnum::BINARY_ENCODING &&
        _this->m_encoding != DTC::EncodingEnum::BINARY_WITH_VARIABLE_LENGTH_STRINGS
      ) {
        WARN("Invalid Encoding for callbacks selected!");
        return;
      }

      size_t bytes_parsed = 0;
      while (bytes_parsed < bufferSize) {
        if (bufferSize - bytes_parsed < sizeof(DTC::s_MessageHeader)) {
          WARN("bytes left is too little: received %zu, parsed %zu", bufferSize, bytes_parsed);
          break;
        }

        uint16_t msg_size = _this->GetSize(buffer);
        uint16_t type = _this->GetType(buffer);

        if (msg_size > bufferSize - bytes_parsed) {
          WARN("msg size could be invalid: %hu", msg_size);
          break;
        }

        switch (type) {
          // Fixed and Variable LS
          case DTC::USER_MESSAGE:
            if (_this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING) {
              _this->UserLog(
                ((DTC::s_UserMessage*)buffer)->GetUserMessage(),
                ((DTC::s_UserMessage*)buffer)->IsPopupMessage
              );
            } else {
              _this->UserLog(
                ((DTC_VLS::s_UserMessage*)buffer)->GetUserMessage(),
                ((DTC_VLS::s_UserMessage*)buffer)->IsPopupMessage
              );
            }
            break;
          case DTC::GENERAL_LOG_MESSAGE:
            if (_this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING) {
              _this->GeneralLog(
                ((DTC::s_GeneralLogMessage*)buffer)->GetMessageText()
              );
            } else {
              _this->GeneralLog(
                ((DTC_VLS::s_GeneralLogMessage*)buffer)->GetMessageText()
              );
            }
            break;
          case DTC::ALERT_MESSAGE:
            if (_this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING) {
              _this->Alert(
                ((DTC::s_AlertMessage*)buffer)->GetMessageText(),
                ((DTC::s_AlertMessage*)buffer)->GetTradeAccount()
              );
            } else {
              _this->Alert(
                ((DTC_VLS::s_AlertMessage*)buffer)->GetMessageText(),
                ((DTC_VLS::s_AlertMessage*)buffer)->GetTradeAccount()
              );
            }
            break;
          case DTC::LOGON_RESPONSE:
            if (_this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING) {
              _this->Logon(
                ((DTC::s_LogonResponse*)buffer)->Result, ((DTC::s_LogonResponse*)buffer)->Integer_1,
                ((DTC::s_LogonResponse*)buffer)->GetResultText(), ((DTC::s_LogonResponse*)buffer)->GetReconnectAddress(),
                ((DTC::s_LogonResponse*)buffer)->GetServerName(), ((DTC::s_LogonResponse*)buffer)->GetSymbolExchangeDelimiter(),
                &((DTC::s_LogonResponse*)buffer)->MarketDepthUpdatesBestBidAndAsk, &((DTC::s_LogonResponse*)buffer)->SecurityDefinitionsSupported
              );
            } else {
              _this->Logon(
                ((DTC::s_LogonResponse*)buffer)->Result, ((DTC::s_LogonResponse*)buffer)->Integer_1,
                ((DTC::s_LogonResponse*)buffer)->GetResultText(), ((DTC::s_LogonResponse*)buffer)->GetReconnectAddress(),
                ((DTC::s_LogonResponse*)buffer)->GetServerName(), ((DTC::s_LogonResponse*)buffer)->GetSymbolExchangeDelimiter(),
                &((DTC::s_LogonResponse*)buffer)->MarketDepthUpdatesBestBidAndAsk, &((DTC::s_LogonResponse*)buffer)->SecurityDefinitionsSupported
              );
            }
            break;
          case DTC::LOGOFF:
            if (_this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING) {
              _this->Logoff(
                ((DTC::s_Logoff*)buffer)->GetReason(),
                ((DTC::s_Logoff*)buffer)->DoNotReconnect
              );
            } else {
              _this->Logoff(
                ((DTC_VLS::s_Logoff*)buffer)->GetReason(),
                ((DTC_VLS::s_Logoff*)buffer)->DoNotReconnect
              );
            }
            break;
          // Universal
          case DTC::ENCODING_RESPONSE:
            _this->Encoding(
              ((DTC::s_EncodingResponse*)buffer)
            );
            break;
          case DTC::HEARTBEAT:
            _this->Heartbeat(
              ((DTC::s_Heartbeat*)buffer)
            );
            break;
          default:
            // LOG WARNING (Garbage Type)
            WARN("Invalid Type: %hu", type);
        };

        bytes_parsed += msg_size;
        buffer += msg_size;
      }
    }

    template <class ChildSocketT>
    static void receive_loop(
      ChildSocketT *_this,
      char *buffer, size_t buffer_size 
    ) {
      nc_error_t err;
      size_t bytes_received;
      while (!(*_this->m_exit)) {
        err = nread(_this->m_sock, buffer, buffer_size, &bytes_received, NC_OPT_NULL);
        if (err == NC_ERR_WOULD_BLOCK) { continue; } // recv timeout
        else if (err != NC_ERR_GOOD) { break; } // parse error
        _this->template filter<ChildSocketT>(_this, buffer, bytes_received);
      }
      ::free(buffer);
    }


  };


};
