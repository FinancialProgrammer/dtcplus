#pragma once
#ifndef DTCP_NO_NC_EXTS
  #define NC_TLS // include openssl extenstion
#endif

#include <netc.h>
#include <dtcc/dtc.hpp>
#include <dtcc/dtcvls.hpp>

#include <cstdio>
#include <cstdlib>
#include <thread>

#ifndef LOG
  #define LOG(msg, ...) std::printf(msg "\n", __VA_ARGS__)
#endif

#ifndef WARN
  #define WARN(msg, ...) std::printf(msg "\n", __VA_ARGS__)
#endif

#ifndef ERR
  #define ERR(msg, ...) std::fprintf(stderr, msg "\n", __VA_ARGS__)
#endif

// namespace dp = dtcp;
namespace dtcp {
  struct BasicCallback {
    // backend
    uint16_t GetSize(const char *buffer) { // different for other encodings
      return ((DTC::s_MessageHeader*)buffer)->Size;
    }
    uint16_t GetType(const char *buffer) { // different for other encodings
      return ((DTC::s_MessageHeader*)buffer)->Type;
    }

    // callbacks
      // auxiliary
        void user_log(nc_socket_t *sock, void *voidmsg) {
          DTC::s_UserMessage *msg = (DTC::s_UserMessage*)voidmsg;
          LOG("UserLog, popup-%hhu: '%s'", msg->GetIsPopupMessage(), msg->GetUserMessage());
        }
        void general_log(nc_socket_t *sock, void *voidmsg) {
          DTC::s_GeneralLogMessage *msg = (DTC::s_GeneralLogMessage*)voidmsg;
          LOG("GeneralLog: '%s'", msg->GetMessageText());
        }
        void alert(nc_socket_t *sock, void *voidmsg) {
          DTC::s_AlertMessage *msg = (DTC::s_AlertMessage*)voidmsg;
          WARN("Alert, acc-'%s': '%s'", msg->GetTradeAccount(), msg->GetMessageText());
        }
        void heartbeat(nc_socket_t *sock, void *voidmsg) {
          DTC::s_Heartbeat *msg = (DTC::s_Heartbeat*)voidmsg;
          DTC::s_Heartbeat hb = {.NumDroppedMessages=0};
          size_t bytes_written = 0;
          nwrite(sock, &hb, sizeof(hb), &bytes_written, NC_OPT_NULL);
        }
        void encode_response(nc_socket_t *sock, void *voidmsg) {
          DTC::s_EncodingResponse *msg = (DTC::s_EncodingResponse*)voidmsg;
          LOG("Protocol '%s', of version '%d', with encoding %d", msg->ProtocolType, msg->ProtocolVersion, msg->Encoding);
        }
      // Logging
      // auth
        void logon_response(nc_socket_t *sock, void *voidmsg) { 
          DTC::s_LogonResponse *msg = (DTC::s_LogonResponse*)voidmsg;
          switch (msg->Result) {
            case DTC::LOGON_SUCCESS:
              LOG("Connected to server '%s', Result '%s'", msg->ServerName, msg->ResultText);
              break;
            case DTC::LOGON_RECONNECT_NEW_ADDRESS:
              ERR("Logon Reconnect New Address Not Implemented %d", 0);
              break;
            case DTC::LOGON_ERROR:
              WARN("Logon Error: '%s'", msg->ResultText);
              break;
            case DTC::LOGON_ERROR_NO_RECONNECT:
              WARN("Logon Error (No Reconnect): '%s'", msg->ResultText);
              break;
            default:
              WARN("Invalid Logon Result %d", msg->Result);
              return;
          }
        }
        void logoff(nc_socket_t *sock, void *voidmsg) {
          DTC::s_Logoff *msg = (DTC::s_Logoff*)voidmsg;
          DTC::s_Logoff sendmsg = {
            .Reason="Server Requested Logoff",
            .DoNotReconnect=true
          };
          size_t written;
          nwrite(sock, &sendmsg, sizeof(sendmsg), &written, NC_OPT_NULL);
        }
      // market data
        void MktDataReject() {}
        void MktDataSnapshot() {}
        void MktDataUpdateTrade() {}
        void MktDataUpdateTradeWithUnbundledIndicator2() {}
        void MktDataUpdateTradeNoTimestamp() {}
        void MktDataUpdateTradeCompact() {}
      // market depth
        void MktDepthReject() {}
        void MktDepthSnapshotLevel() {}
        void MktDepthSnapshotLevelFloat() {} // shouldn't this be compact?
        void MktDepthUpdateLevel() {}
        void MktDepthUpdateLevelFloatWithMS() {}
        void MktDepthUpdateLevelNoTimestamp() {}
    // END

    // Base Functions
    template <class ChildSocketT>
    static void filter(
      ChildSocketT *_this, nc_socket_t *sock, 
      char *buffer, size_t bufferSize
    ) {
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
          case DTC::USER_MESSAGE:
            _this->user_log(sock, buffer);
            break;
          case DTC::GENERAL_LOG_MESSAGE:
            _this->general_log(sock, buffer);
            break;
          case DTC::ALERT_MESSAGE:
            _this->alert(sock, buffer);
            break;
          case DTC::HEARTBEAT:
            _this->heartbeat(sock, buffer);
            break;
          case DTC::ENCODING_RESPONSE:
            _this->encode_response(sock, buffer);
            break;
          case DTC::LOGON_RESPONSE:
            _this->logon_response(sock, buffer);
            break;
          case DTC::LOGOFF:
            _this->logoff(sock, buffer);
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
      ChildSocketT *_this, nc_socket_t *sock, 
      char *buffer, size_t buffer_size, 
      int *should_exit
    ) {
      nc_error_t err;
      size_t bytes_received;
      while (!(*should_exit)) {
        err = nread(sock, buffer, buffer_size, &bytes_received, NC_OPT_NULL);
        if (err == NC_ERR_WOULD_BLOCK) { continue; } // recv timeout
        else if (err != NC_ERR_GOOD) { break; } // parse error
        _this->template filter<ChildSocketT>(_this, sock, buffer, bytes_received);
      }
      ::free(buffer);
    }
  };
  struct BasicVLSCallback : public BasicCallback {
    // Callbacks
    // auxiliary
      void user_log(nc_socket_t *sock, void *voidmsg) {
        DTC_VLS::s_UserMessage *msg = (DTC_VLS::s_UserMessage*)voidmsg;
        LOG("UserLog, popup-%hhu: '%s'", msg->GetIsPopupMessage(), msg->GetUserMessage());
      }
      void general_log(nc_socket_t *sock, void *voidmsg) {
        DTC_VLS::s_GeneralLogMessage *msg = (DTC_VLS::s_GeneralLogMessage*)voidmsg;
        LOG("GeneralLog: '%s'", msg->GetMessageText());
      }
      void alert(nc_socket_t *sock, void *voidmsg) {
        DTC_VLS::s_AlertMessage *msg = (DTC_VLS::s_AlertMessage*)voidmsg;
        WARN("Alert, acc-'%s': '%s'", msg->GetTradeAccount(), msg->GetMessageText());
      }
    // Logging
    // auth
      void logon_response(nc_socket_t *sock, void *voidmsg) {
        DTC_VLS::s_LogonResponse *msg = (DTC_VLS::s_LogonResponse*)voidmsg;
        switch (msg->Result) {
          case DTC::LOGON_SUCCESS:
            LOG("Connected to server '%s', Result '%s'", msg->GetServerName(), msg->GetResultText());
            break;
          case DTC::LOGON_RECONNECT_NEW_ADDRESS:
            ERR("Logon Reconnect New Address Not Implemented %d", 0);
            break;
          case DTC::LOGON_ERROR:
            WARN("Logon Error: '%s'", msg->GetResultText());
            break;
          case DTC::LOGON_ERROR_NO_RECONNECT:
            WARN("Logon Error (No Reconnect): '%s'", msg->GetResultText());
            break;
          default:
            WARN("Invalid Logon Result %d", msg->GetResult());
            return;
        }
      }
      void logoff(nc_socket_t *sock, void *voidmsg) {
        DTC_VLS::s_Logoff *msg = (DTC_VLS::s_Logoff*)voidmsg;
        DTC_VLS::s_Logoff sendmsg = {
          .DoNotReconnect=true
        };
        size_t written;
        nwrite(sock, &sendmsg, sizeof(sendmsg), &written, NC_OPT_NULL);
      }
    // market data
      void MktDataReject() {}
    // market depth
      void MktDepthReject() {}
    // END
  };

  template <class CallbackT>
  class BinaryClient;

  template <class CallbackT>
  class BinaryVLSClient;

  template <class CallbackT>
  class BinaryClient { // TODO: Urgent!
    nc_socket_t *m_sock;
    CallbackT callbacks;
    int receive_thread_exit = false;
    std::thread receive_thread;
  public:
    // specials
    BinaryClient(nc_socket_t *sock) : m_sock(sock) {}
    BinaryClient(const BinaryClient&) = delete;
    BinaryClient(BinaryClient&&); // move the instance to a different class
    // BinaryClient(BinaryVLSClient&&); // construct from binary vls client
    ~BinaryClient() { this->close(); } // close receive thread

    // socket
      void open(char *recv_buffer, size_t recv_buffer_size) { // open connection to either historical or realtime server
        // start receive thread
        this->receive_thread = std::thread(
          &(CallbackT::template receive_loop<CallbackT>),
          &this->callbacks,
          this->m_sock,
          recv_buffer,
          recv_buffer_size,
          &receive_thread_exit
        );
      }
      void close() { 
        this->receive_thread_exit = true;
        if (this->receive_thread.joinable()) {
          this->receive_thread.join(); // allow receive thread cleanup
        }
      } // close connection
      nc_socket_t *socket() { return this->m_sock; } // get raw socket (for interaction with netc)
    // dtc
      // * EReq stands for Easy Request.
      // * This is a request that focuses on easy use with core functionality.
      // * Detailed requests should be made for nwrite.
      // auxiliary
        nc_error_t EReqEncoding() {
          DTC::s_EncodingRequest req = {
            .Encoding=DTC::EncodingEnum::BINARY_ENCODING
          };
          size_t _;
          return nwrite(this->m_sock, &req, sizeof(req), &_, NC_OPT_NULL);
        }
      // auth
        nc_error_t EReqLogon(
          int HbIntervalSecs,
          const char usr[DTC::USERNAME_PASSWORD_LENGTH], const char pswd[DTC::USERNAME_PASSWORD_LENGTH],
          const char tradeacc[DTC::TRADE_ACCOUNT_LENGTH], const char client[32], 
          const char hardwareIdent[DTC::GENERAL_IDENTIFIER_LENGTH], const char text[DTC::GENERAL_IDENTIFIER_LENGTH]
        ) {
          DTC::s_LogonRequest req{
            .HeartbeatIntervalInSeconds=HbIntervalSecs
          };
          if (usr)
            memcpy(req.Username, usr, strlen(usr));
          if (pswd)
            memcpy(req.Password, pswd, strlen(pswd));
          if (tradeacc)
            memcpy(req.TradeAccount, tradeacc, strlen(tradeacc));
          if (client)
            memcpy(req.ClientName, client, strlen(client));
          if (hardwareIdent)
            memcpy(req.HardwareIdentifier, hardwareIdent, strlen(hardwareIdent));
          if (text)
            memcpy(req.GeneralTextData, text, strlen(text));
          size_t _;
          return nwrite(this->m_sock, &req, sizeof(req), &_, NC_OPT_NULL);
        }
    // END
  };
  /*
  * I believe sierra chart actually usese this internally
  */
  template <class CallbackT>
  class BinaryVLSClient { // TODO: Urgent!
    nc_socket_t *m_sock;
    CallbackT callbacks;
    int receive_thread_exit = false;
    std::thread receive_thread;

    char sendbuf[65536];
    size_t sendbufsize = 65536;
  public:
    // specials
    BinaryVLSClient(nc_socket_t *sock) : m_sock(sock) {}
    BinaryVLSClient(const BinaryVLSClient&) = delete;
    BinaryVLSClient(BinaryVLSClient&&); // move the instance to a different class
    // BinaryVLSClient(BinaryClient&&); // construct from binary client
    ~BinaryVLSClient() { this->close(); } // close receive thread

    // socket
      void open(char *recv_buffer, size_t recv_buffer_size) { // open connection to either historical or realtime server
        // start receive thread
        this->receive_thread = std::thread(
          &(CallbackT::template receive_loop<CallbackT>),
          &this->callbacks,
          this->m_sock,
          recv_buffer,
          recv_buffer_size,
          &receive_thread_exit
        );
      }
      void close() { 
        this->receive_thread_exit = true;
        if (this->receive_thread.joinable()) {
          this->receive_thread.join(); // allow receive thread cleanup
        }
      } // close connection
      nc_socket_t *socket() { return this->m_sock; }
    // backend
      char *GetVlsData( 
        const uint16_t MessageSizeField, 
        const uint16_t BaseStructureSizeField, 
        DTC_VLS::vls_t& VariableLengthStringField, 
        const uint16_t VariableLengthStringFieldOffset
      ) {
        static char null_str[] = "";
        if (BaseStructureSizeField < VariableLengthStringFieldOffset + sizeof(DTC_VLS::vls_t))
          return null_str;
        else if (VariableLengthStringField.Offset == 0 || VariableLengthStringField.Length <= 1)
          return null_str;
        else if ((VariableLengthStringField.Offset + VariableLengthStringField.Length) > MessageSizeField)
          return null_str;
        else {
          const int MaximumLength = 50 * 1024;
          int Length = VariableLengthStringField.Length;
          if (Length > MaximumLength)
          {
            Length = MaximumLength;
          }

          char * TerminatorCharacter = this->sendbuf + VariableLengthStringField.Offset + Length - 1;

          *TerminatorCharacter = 0; // Make sure there is a null terminator here.

          return this->sendbuf + VariableLengthStringField.Offset;
        }
      }
      bool addvls(
        DTC_VLS::s_MessageHeader *header,
        DTC_VLS::vls_t *vls,
        const char *data, size_t datalen, size_t offset
      ) {
        AddVariableLengthStringField(header->Size, *vls, datalen);
        char *_data = this->GetVlsData(
          header->Size, header->BaseSize,
          *vls, offset
        );
        if (data == "") {
          return false;
        }
        memcpy(_data, data, datalen);
        return true;
      }
    // dtc
      // * EReq stands for Easy Request.
      // * This is a request that focuses on easy use with core functionality.
      // * Detailed requests should be made for nwrite.
      // auxiliary
        nc_error_t EReqEncoding() {
          DTC::s_EncodingRequest req = {
            .Encoding=DTC::EncodingEnum::BINARY_WITH_VARIABLE_LENGTH_STRINGS
          };
          size_t _;
          return nwrite(this->m_sock, &req, sizeof(req), &_, NC_OPT_NULL);
        }
      // auth
        nc_error_t EReqLogon(
          int HbIntervalSecs, int int1, int int2,
          const char *usr, const char *pswd,
          const char *tradeacc, const char *client, 
          const char *hardwareIdent, const char *text
        ) {
          DTC_VLS::s_LogonRequest base_req = {};
          DTC_VLS::s_LogonRequest *req = (DTC_VLS::s_LogonRequest*)this->sendbuf;
          memcpy(req, &base_req, sizeof(base_req));
          req->HeartbeatIntervalInSeconds = HbIntervalSecs;
          req->Integer_1 = int1;
          req->Integer_2 = int2;

          if (usr)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->Username, 
              usr, strlen(usr), offsetof(DTC_VLS::s_LogonRequest, Username)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);
          if (pswd)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->Password, 
              pswd, strlen(pswd), offsetof(DTC_VLS::s_LogonRequest, Password)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);
          if (text)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->GeneralTextData, 
              text, strlen(text), offsetof(DTC_VLS::s_LogonRequest, GeneralTextData)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);
          if (tradeacc)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->TradeAccount, 
              tradeacc, strlen(tradeacc), offsetof(DTC_VLS::s_LogonRequest, TradeAccount)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);
          if (hardwareIdent)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->HardwareIdentifier, 
              hardwareIdent, strlen(hardwareIdent), offsetof(DTC_VLS::s_LogonRequest, HardwareIdentifier)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);
          if (client)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->ClientName, 
              client, strlen(client), offsetof(DTC_VLS::s_LogonRequest, ClientName)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);

          size_t _;
          return nwrite(this->m_sock, req, req->Size, &_, NC_OPT_NULL);
        }
        nc_error_t EReqLogoff(
          const char *reason,
          uint8_t dont_reconnect = false
        ) {
          DTC_VLS::s_Logoff base_req = {};
          DTC_VLS::s_Logoff *req = (DTC_VLS::s_Logoff*)this->sendbuf;
          memcpy(req, &base_req, sizeof(base_req));
          req->DoNotReconnect = dont_reconnect;
          if (reason)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->Reason, 
              reason, strlen(reason), offsetof(DTC_VLS::s_Logoff, Reason)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);
          size_t _;
          return nwrite(this->m_sock, req, req->Size, &_, NC_OPT_NULL);
        }
      // market data
        nc_error_t EReqMktData(
          DTC::RequestActionEnum reqAct,
		      const char *symbol, const char *exchange,
          uint32_t sID = 1, uint32_t intervalForSnapshotMS = 0
        ) {
          DTC_VLS::s_MarketDataRequest base_req = {};
          DTC_VLS::s_MarketDataRequest *req = (DTC_VLS::s_MarketDataRequest*)this->sendbuf;
          memcpy(req, &base_req, sizeof(base_req));
          req->IntervalForSnapshotUpdatesInMilliseconds = intervalForSnapshotMS;
          req->SymbolID = sID;

          if (symbol)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->Symbol, 
              symbol, strlen(symbol), offsetof(DTC_VLS::s_MarketDataRequest, Symbol)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);
          if (exchange)
            if (!this->addvls(
              (DTC_VLS::s_MessageHeader*)req, &req->Exchange, 
              exchange, strlen(exchange), offsetof(DTC_VLS::s_MarketDataRequest, Exchange)
            )) ERR("Couldn't add vls parameter, maybe check lengths %d", 0);

          size_t _;
          return nwrite(this->m_sock, req, req->Size, &_, NC_OPT_NULL);
        }
      // market depth
    // END
  };

  // Work on this last (client is more important right now)
  /*
  * The main Server,
  * incorporates for all encodings,
  *
  * supports TLS/SSL encryption if desired,
  * espically for authentication
  */
  class Server {

  };
};
