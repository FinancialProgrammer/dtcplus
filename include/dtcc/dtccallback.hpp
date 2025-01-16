#pragma once
#include <dtcc/dtc.hpp>
#include <dtcc/dtcvls.hpp>
#include <dtcc/log.hpp>

#include <netc.h>

#include <signal.h> // sig_atomic_t
#include <stdlib.h>

#include <mutex>

typedef void (*callback_t)(void*);

namespace dtcc {
  struct BaseCallback {
    // exit
    sig_atomic_t volatile* m_exit;

    // client encoding
    sig_atomic_t volatile* m_clientencodingF;
    DTC::EncodingEnum volatile* m_clientencoding;
    std::mutex m_clientencoding_mtx;
    DTC::EncodingEnum m_encoding = DTC::EncodingEnum::BINARY_ENCODING;

    // client logon
    sig_atomic_t volatile* m_clientlogonF;
    std::mutex m_clientlogon_mtx;
    DTC::LogonStatusEnum volatile* m_clientlogon;

    // socket
    std::mutex m_sock_mtx;
    nc_socket_t *m_sock;

    BaseCallback( 
      sig_atomic_t volatile* exit, 
      DTC::EncodingEnum volatile* clientencoding, sig_atomic_t volatile* clientencodingF,
      DTC::LogonStatusEnum volatile* m_clientlogon, sig_atomic_t volatile* m_clientlogonF
    ) : 
      m_exit(exit), 
      m_clientencoding(clientencoding), m_clientencodingF(clientencodingF),
      m_clientlogon(m_clientlogon), m_clientlogonF(m_clientlogonF)
    {}
    BaseCallback(const BaseCallback&) = delete;
    BaseCallback(const BaseCallback&&) = delete;
    ~BaseCallback() = default;

    // callbacks
      // --- auxiliary --- //
        void Encoding(DTC::s_EncodingResponse *resp) {
          std::lock_guard<std::mutex> lock(this->m_clientencoding_mtx);
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
          std::lock_guard<std::mutex> lock(this->m_clientlogon_mtx);
          *this->m_clientlogon = result;
          *this->m_clientlogonF = true; // alert client value is now readable

          // Internal Sierra Chart API can use 8 for sucess
          if (result == DTC::LogonStatusEnum::LOGON_SUCCESS || result == 8) {
            LOG("Logon Sucess to %s", serverName);
          } else if (result == DTC::LogonStatusEnum::LOGON_RECONNECT_NEW_ADDRESS) {
            ERR("Logon Failed (NotImplemented) to %s, attempting reconnection to address %s ", serverName, reconAddr);
          } else if (result == DTC::LogonStatusEnum::LOGON_ERROR) {
            ERR("Logon Failed to %s with result %s", serverName, resultText);
          } else if (result == DTC::LogonStatusEnum::LOGON_ERROR_NO_RECONNECT) {
            ERR("Logon Failed (No Reconnect) to %s with result %s", serverName, resultText);
          } else {
            ERR("Invalid Logon Result %d with text %s", result, resultText);
          }
        }
        void Logoff(const char *reason, uint8_t DoNotReconnect) {
          WARN("Server Sent Logoff with reason '%s', Client Attempting Graceful Close", reason);
          *m_exit = true;
        }
      // --- market auxiliary --- //
        void MktFeedStatus(DTC::s_MarketDataFeedStatus *msg) {}
        void MktFeedSymbolStatus(DTC::s_MarketDataFeedSymbolStatus *msg) {}
      // --- market data --- //
        void MktDataReject(uint32_t symbolID, const char *rejectText) {
          LOG("Market Data Request Rejected %u, '%s'", symbolID, rejectText);
        }
        void MktDataSnapshot(DTC::s_MarketDataSnapshot *msg) {
          LOG("Market Data Snapshot Sent");
        }
        // Trade
        void MktDataUpdateTrade(DTC::s_MarketDataUpdateTrade *msg) {}
        void MktDataUpdateTradeWithUnbundledIndicator2(DTC::s_MarketDataUpdateTradeWithUnbundledIndicator2 *msg) {}
        void MktDataUpdateTradeNoTimestamp(DTC::s_MarketDataUpdateTradeNoTimestamp *msg) {}
        void MktDataUpdateTradeCompact(DTC::s_MarketDataUpdateTradeCompact *msg) {}
        void MktDataUpdateLastTradeSnapshot(DTC::s_MarketDataUpdateLastTradeSnapshot *msg) {}
        // bid ask
        void MktDataUpdateBidAsk(DTC::s_MarketDataUpdateBidAsk *msg) {}
        void MktDataUpdateBidAskNoTimeStamp(DTC::s_MarketDataUpdateBidAskNoTimeStamp *msg) {}
        void MktDataUpdateBidAskFloatMS(DTC::s_MarketDataUpdateBidAskFloatWithMicroseconds *msg) {}
        // session
        void MktDataUpdateSessionOpen(DTC::s_MarketDataUpdateSessionOpen *msg) {}
        void MktDataUpdateSessionHigh(DTC::s_MarketDataUpdateSessionHigh *msg) {}
        void MktDataUpdateSessionLow(DTC::s_MarketDataUpdateSessionLow *msg) {}
        void MktDataUpdateSessionSettlement(DTC::s_MarketDataUpdateSessionSettlement *msg) {}
        void MktDataUpdateSessionVolume(DTC::s_MarketDataUpdateSessionVolume *msg) {}
        void MktDataUpdateSessionOpenInterest(DTC::s_MarketDataUpdateOpenInterest *msg) {}
        void MktDataUpdateSessionNumTrades(DTC::s_MarketDataUpdateSessionNumTrades *msg) {}
        void MktDataUpdateSessionDate(DTC::s_MarketDataUpdateTradingSessionDate *msg) {}
      // --- market depth --- //
        void MktDepthReject(uint32_t symbolID, const char *rejectText) {}
        void MktDepthSnapshotLevel(DTC::s_MarketDepthSnapshotLevel *msg) {}
        void MktDepthSnapshotLevelFloat(DTC::s_MarketDepthSnapshotLevelFloat *msg) {}
        void MktDepthUpdateLevel(DTC::s_MarketDepthUpdateLevel *msg) {}
        void MktDepthUpdateLevelFloatMS(DTC::s_MarketDepthUpdateLevelFloatWithMilliseconds *msg) {}
        void MktDepthUpdateLevelNoTimestamp(DTC::s_MarketDepthUpdateLevelNoTimestamp *msg) {}
      // --- trading auxiliary --- //
        void TradingSymbolStatus(DTC::s_TradingSymbolStatus *msg) {}
      // --- order --- //
      // --- position --- //
    // backend
      bool ReadHeader(nc_socket_t *sock, void *buffer) {
        nc_error_t err = NC_ERR_NULL;
        size_t __notused_br = 0;
        while (!(*this->m_exit)) {
          if (this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING || this->m_encoding == DTC::EncodingEnum::BINARY_WITH_VARIABLE_LENGTH_STRINGS) {
            err = nread(sock, buffer, sizeof(DTC::s_MessageHeader), &__notused_br, NC_OPT_DO_ALL);
            if (err == NC_ERR_WOULD_BLOCK) { LOG("timeout on reading header"); continue; } // Timeout 
            else if (err != NC_ERR_GOOD) {
              ERR("Early exit by nread error '%s'", nstrerr(err));
              return true;
            }
            return false;
          } else {
            ERR("Encoding not supported");
            return true;
          }
        }
        return true;
      }
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
      void set_socket(nc_socket_t *sock) { this->m_sock = sock; }
    // filter
    template <class ChildSocketT>
    static void filter(
      ChildSocketT *_this, void *buffer
    ) {
      if (
        _this->m_encoding != DTC::EncodingEnum::BINARY_ENCODING &&
        _this->m_encoding != DTC::EncodingEnum::BINARY_WITH_VARIABLE_LENGTH_STRINGS
      ) {
        WARN("Invalid Encoding for callbacks selected!");
        return;
      }

      uint16_t msg_size = _this->GetSize(buffer);
      uint16_t type = _this->GetType(buffer);

      if (msg_size == 0) {
        WARN("msg size is zero and type is %hu", type);
        return;
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
        case DTC::MARKET_DATA_REJECT: 
          if (_this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING) {
            _this->MktDataReject(
              ((DTC::s_MarketDataReject*)buffer)->SymbolID,
              ((DTC::s_MarketDataReject*)buffer)->GetRejectText()
            );
          } else {
            _this->MktDataReject(
              ((DTC_VLS::s_MarketDataReject*)buffer)->SymbolID,
              ((DTC_VLS::s_MarketDataReject*)buffer)->GetRejectText()
            );
          }
          break;
        case DTC::MARKET_DEPTH_REJECT: 
          if (_this->m_encoding == DTC::EncodingEnum::BINARY_ENCODING) {
            _this->MktDepthReject(
              ((DTC::s_MarketDepthReject*)buffer)->SymbolID,
              ((DTC::s_MarketDepthReject*)buffer)->GetRejectText()
            );
          } else {
            _this->MktDepthReject(
              ((DTC_VLS::s_MarketDepthReject*)buffer)->SymbolID,
              ((DTC_VLS::s_MarketDepthReject*)buffer)->GetRejectText()
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
        // Market Auxiliary
        case DTC::MARKET_DATA_FEED_STATUS: 
          _this->MktFeedStatus( ((DTC::s_MarketDataFeedStatus*)buffer) );
          break;
        case DTC::MARKET_DATA_FEED_SYMBOL_STATUS: 
          _this->MktFeedSymbolStatus( ((DTC::s_MarketDataFeedSymbolStatus*)buffer) );
          break;
        // Trading Auxiliary
        case DTC::TRADING_SYMBOL_STATUS:
          _this->TradingSymbolStatus( ((DTC::s_TradingSymbolStatus*)buffer) );
          break;
        // Market Data
        case DTC::MARKET_DATA_SNAPSHOT: _this->MktDataSnapshot( ((DTC::s_MarketDataSnapshot*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_TRADE: _this->MktDataUpdateTrade( ((DTC::s_MarketDataUpdateTrade*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_TRADE_WITH_UNBUNDLED_INDICATOR_2: _this->MktDataUpdateTradeWithUnbundledIndicator2( ((DTC::s_MarketDataUpdateTradeWithUnbundledIndicator2*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_TRADE_NO_TIMESTAMP: _this->MktDataUpdateTradeNoTimestamp( ((DTC::s_MarketDataUpdateTradeNoTimestamp*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_TRADE_COMPACT: _this->MktDataUpdateTradeCompact( ((DTC::s_MarketDataUpdateTradeCompact*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_LAST_TRADE_SNAPSHOT: _this->MktDataUpdateLastTradeSnapshot( ((DTC::s_MarketDataUpdateLastTradeSnapshot*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_BID_ASK: _this->MktDataUpdateBidAsk( ((DTC::s_MarketDataUpdateBidAsk*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_BID_ASK_NO_TIMESTAMP: _this->MktDataUpdateBidAskNoTimeStamp( ((DTC::s_MarketDataUpdateBidAskNoTimeStamp*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_BID_ASK_FLOAT_WITH_MICROSECONDS: _this->MktDataUpdateBidAskFloatMS( ((DTC::s_MarketDataUpdateBidAskFloatWithMicroseconds*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_SESSION_OPEN: _this->MktDataUpdateSessionOpen( ((DTC::s_MarketDataUpdateSessionOpen*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_SESSION_HIGH: _this->MktDataUpdateSessionHigh( ((DTC::s_MarketDataUpdateSessionHigh*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_SESSION_LOW: _this->MktDataUpdateSessionLow( ((DTC::s_MarketDataUpdateSessionLow*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_SESSION_SETTLEMENT: _this->MktDataUpdateSessionSettlement( ((DTC::s_MarketDataUpdateSessionSettlement*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_SESSION_VOLUME: _this->MktDataUpdateSessionVolume( ((DTC::s_MarketDataUpdateSessionVolume*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_OPEN_INTEREST: _this->MktDataUpdateSessionOpenInterest( ((DTC::s_MarketDataUpdateOpenInterest*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_SESSION_NUM_TRADES: _this->MktDataUpdateSessionNumTrades( ((DTC::s_MarketDataUpdateSessionNumTrades*)buffer) ); break;
        case DTC::MARKET_DATA_UPDATE_TRADING_SESSION_DATE: _this->MktDataUpdateSessionDate( ((DTC::s_MarketDataUpdateTradingSessionDate*)buffer) ); break;
        // Market Depth
        case DTC::MARKET_DEPTH_SNAPSHOT_LEVEL: _this->MktDepthSnapshotLevel( ((DTC::s_MarketDepthSnapshotLevel*)buffer) ); break;
        case DTC::MARKET_DEPTH_SNAPSHOT_LEVEL_FLOAT: _this->MktDepthSnapshotLevelFloat( ((DTC::s_MarketDepthSnapshotLevelFloat*)buffer) ); break;
        case DTC::MARKET_DEPTH_UPDATE_LEVEL: _this->MktDepthUpdateLevel( ((DTC::s_MarketDepthUpdateLevel*)buffer) ); break;
        case DTC::MARKET_DEPTH_UPDATE_LEVEL_FLOAT_WITH_MILLISECONDS: _this->MktDepthUpdateLevelFloatMS( ((DTC::s_MarketDepthUpdateLevelFloatWithMilliseconds*)buffer) ); break;
        case DTC::MARKET_DEPTH_UPDATE_LEVEL_NO_TIMESTAMP: _this->MktDepthUpdateLevelNoTimestamp( ((DTC::s_MarketDepthUpdateLevelNoTimestamp*)buffer) ); break;
        // default
        default:
          // LOG WARNING (Garbage Type)
          WARN("Invalid Type: %hu", type);

      };
    }

    template <class ChildSocketT>
    static void receive_loop(
      ChildSocketT *_this,
      void *buffer, size_t buffer_size,
      volatile sig_atomic_t *exit_flag
    ) {
      if (buffer == NULL) {
        ERR("Thread failed at start due to memory allocation failure");
        return;
      }

      nc_error_t err;
      size_t __notused_br;

      while (!(*_this->m_exit)) {
        { // socket lock scope
          std::lock_guard<std::mutex> lock(_this->m_sock_mtx);

          // Read Header
          if (_this->ReadHeader(_this->m_sock, buffer)) {
            break;
          }

          // Read Body
          uint16_t msg_size = _this->GetSize(buffer);

          if (msg_size == 0) {
            LOG("message size is zero");
            break;
          }

          if (msg_size > buffer_size) {
            LOG("Allocating bigger buffer");
            ::free(buffer);
            buffer_size = msg_size * 2;
            buffer = ::malloc(buffer_size);
            if (buffer == NULL) {
              ERR("The requested buffer size is larger than the system can support");
              break;
            }
          }

          err = nread(_this->m_sock, ((char*)buffer) + sizeof(DTC::s_MessageHeader), msg_size - sizeof(DTC::s_MessageHeader), &__notused_br, NC_OPT_DO_ALL);
          if (err == NC_ERR_WOULD_BLOCK) { // timeout
            LOG("read timeout on body read");
            continue;
          } else if (err != NC_ERR_GOOD) { 
            LOG("Early exit by nread error '%s'", nstrerr(err));
            break; 
          }
        } // Clear up socket so that other workers can read from socket while thread is filtering
        // Filter
        _this->template filter<ChildSocketT>(_this, buffer);
      }
      ::free(buffer);
      *exit_flag = true;
    }
  };
};
