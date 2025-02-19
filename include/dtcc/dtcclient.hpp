#pragma once
#include <dtcc/dtc.hpp>
#include <dtcc/dtcvls.hpp>
#include <dtcc/log.hpp>

#include <netc.h>

#include <thread>
#include <cstring>
#include <csignal>
#include <cstdlib>

/*
* For json encoding i will probably just serialize the binary vls struct
* this is probably slower but its json (why would you use json with the expection of speed?)
* example by microsoft copilot
*
#include <iostream>
#include <boost/pfr.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct Example {
  int a = 10;
  char x = 'A';

  void foo() {}
};

template <typename T>
json to_json(const T& obj) {
  json j;

  boost::pfr::for_each_field(obj, [&j](const auto& field, std::size_t idx) {
    j[boost::pfr::get_field_name<0>(idx)] = field;
  });

  return j;
}

int main() {
  Example example;
  json j = to_json(example);
  std::cout << j.dump(4) << std::endl;  // Pretty print with 4 spaces indentation
  return 0;
}

*/

#define DTCC_ADDVLS(param, struct_, ident) \
  if ((param)) \
    if (!this->addvls( \
      (DTC_VLS::s_MessageHeader*)req, &req->ident,  \
      (param), strlen((param)), offsetof(struct_, ident) \
    )) ERR("Couldn't add vls parameter, maybe check lengths");

#define DTCC_ADDBIN(param, ident) \
  if ((param)) { memcpy(req.ident, &(param), strlen((param))); }

namespace dtcc {
template <class CallbackT, size_t T_thread_count>
class Client {
  // connection
  nc_socket_t *m_sock;

  // sync
  volatile sig_atomic_t m_exit = false;

  // client's worker threads
  std::thread m_threads[T_thread_count];

  // client-worker thread communication
  volatile sig_atomic_t m_encodingF = false; // set in recieve thread, checked in main thread
  volatile DTC::EncodingEnum m_encoding; // set in recieve thread, read in main thread

  volatile sig_atomic_t m_logonresponseF = false; // set in recieve thread, checked in main thread
  volatile DTC::LogonStatusEnum m_logonresponse; // set in recieve thread, read in main thread

  // Manually Closed Flag
  bool m_manually_closed = false;

public:
  CallbackT callbacks;

  char sendbuf[65536];
  size_t sendbufsize = 65536;
public: // special functions
  Client() :
    callbacks(&this->m_exit, &this->m_encoding, &this->m_encodingF, &this->m_logonresponse, &this->m_logonresponseF) 
  {}
  Client(const Client&) = delete;
  Client(Client&&);
  ~Client() { if (!this->m_manually_closed) this->close(); }

  void operator=(const Client&) = delete;
  void operator=(Client&&);

  bool operator!() { return this->m_exit; } // check if client is usable
public: // backend
  void set_socket(nc_socket_t *sock) {
    this->m_sock = sock;
    this->callbacks.set_socket(sock);
  }
  void open(size_t recv_buffer_size) { // open connection to either historical or realtime server
    // start receive thread
    for (size_t i = 0; i < T_thread_count; ++i) {
      this->m_threads[i] = std::thread(
        &(CallbackT::template receive_loop<CallbackT>),
        &this->callbacks,
        malloc(recv_buffer_size), recv_buffer_size
      );
    }
  }
  void close() { // rejoin receive threads
    this->m_manually_closed = true;
    this->m_exit = true;
    for (size_t i = 0; i < T_thread_count; ++i) {
      if (this->m_threads[i].joinable()) {
        this->m_threads[i].join();
      } else {
        ERR("thread %zu is not joinable", i);
      }
    }
  }
  nc_socket_t *socket() { return this->m_sock; }

  nc_error_t sendreq(const void *b, size_t bs) {
    size_t _;
    return nwrite(this->m_sock, b, bs, &_, NC_OPT_DO_ALL);
    // if (err != NC_ERR_GOOD) {
    //   ERR("socket writing error, server may have closed its connection '%s'", nstrerr(err));
    //   this->m_exit = true;
    //   return 0;
    // }
  }

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
public: // E*
  // --- auxiliary --- //
    nc_error_t EReqEncoding(DTC::EncodingEnum encoding) {
      DTC::s_EncodingRequest req;
      req.Encoding = encoding;
      return this->sendreq(&req, sizeof(req));
    }
    DTC::EncodingEnum EGetEncoding() {
      while (!this->m_encodingF) std::this_thread::yield(); // wait until encoding is set
      this->m_encodingF = false;
      return this->m_encoding;
    }
  // --- auth --- //
    nc_error_t EReqLogon(
      const char *usr, const char *pswd,
      const char *generalText, 
      int32_t _1, int32_t _2, int32_t hb, int32_t _3,
      const char *tradeAcc, const char *hardwareIdent, const char *clientName,
      int32_t mktDataTransmissionInterval
    ) {
      if (this->m_encoding == DTC::BINARY_ENCODING) {
        DTC::s_LogonRequest req{
          .Integer_1=_1,
          .Integer_2=_2,
          .HeartbeatIntervalInSeconds=hb,
          .Unused1=_3,
          .MarketDataTransmissionInterval=mktDataTransmissionInterval
        };

        DTCC_ADDBIN(usr, Username)
        DTCC_ADDBIN(pswd, Password)
        DTCC_ADDBIN(tradeAcc, TradeAccount)
        DTCC_ADDBIN(clientName, ClientName)
        DTCC_ADDBIN(hardwareIdent, HardwareIdentifier)
        DTCC_ADDBIN(generalText, GeneralTextData)

        size_t _;
        return nwrite(this->m_sock, &req, sizeof(req), &_, NC_OPT_NULL);
      } else if (this->m_encoding == DTC::BINARY_WITH_VARIABLE_LENGTH_STRINGS) {
        DTC_VLS::s_LogonRequest basereq{
          .Integer_1=_1,
          .Integer_2=_2,
          .HeartbeatIntervalInSeconds=hb,
          .Unused1=_3,
          .MarketDataTransmissionInterval=mktDataTransmissionInterval
        };
        DTC_VLS::s_LogonRequest *req = (DTC_VLS::s_LogonRequest*)this->sendbuf;
        memcpy(req, &basereq, sizeof(basereq));

        DTCC_ADDVLS(usr, DTC_VLS::s_LogonRequest, Username)
        DTCC_ADDVLS(pswd, DTC_VLS::s_LogonRequest, Password)
        DTCC_ADDVLS(generalText, DTC_VLS::s_LogonRequest, GeneralTextData)
        DTCC_ADDVLS(tradeAcc, DTC_VLS::s_LogonRequest, TradeAccount)
        DTCC_ADDVLS(hardwareIdent, DTC_VLS::s_LogonRequest, HardwareIdentifier)
        DTCC_ADDVLS(clientName, DTC_VLS::s_LogonRequest, ClientName)

        size_t _;
        return nwrite(this->m_sock, req, req->Size, &_, NC_OPT_NULL);
      } else {
        return NC_ERR_NULL;
      }
    }
    DTC::LogonStatusEnum EGetLogon() {
      while (!this->m_logonresponseF) std::this_thread::yield(); // wait until logon is set
      this->m_logonresponseF = false;
      return this->m_logonresponse;
    }
    nc_error_t EReqLogoff(
      const char *reason,
      uint8_t dont_reconnect = 0
    ) {
      if (this->m_encoding == DTC::BINARY_ENCODING) {
        DTC::s_Logoff req{ .DoNotReconnect = dont_reconnect };

        DTCC_ADDBIN(reason, Reason)

        size_t _;
        return nwrite(this->m_sock, &req, sizeof(req), &_, NC_OPT_NULL);
      } else if (this->m_encoding == DTC::BINARY_WITH_VARIABLE_LENGTH_STRINGS) {
        DTC_VLS::s_Logoff basereq = {
          .DoNotReconnect = dont_reconnect
        };
        DTC_VLS::s_Logoff *req = (DTC_VLS::s_Logoff*)this->sendbuf;
        memcpy(req, &basereq, sizeof(basereq));
        
        DTCC_ADDVLS(reason, DTC_VLS::s_Logoff, Reason)

        size_t _;
        return nwrite(this->m_sock, req, req->Size, &_, NC_OPT_NULL);
      } else {
        return NC_ERR_NULL;
      }
    }
  // --- market auxiliary --- //
  // --- market data --- //
    nc_error_t EReqMktData(
      DTC::RequestActionEnum reqAct, uint32_t ID,
      const char *symbol, const char *exchange,
      uint32_t IntervalSnapMS
    ) {
      if (this->m_encoding == DTC::BINARY_ENCODING) {
        DTC::s_MarketDataRequest req{ 
          .RequestAction=reqAct,
          .SymbolID=ID,
          .IntervalForSnapshotUpdatesInMilliseconds=IntervalSnapMS
        };

        DTCC_ADDBIN(symbol, Symbol)
        DTCC_ADDBIN(exchange, Exchange)

        size_t _;
        return nwrite(this->m_sock, &req, sizeof(req), &_, NC_OPT_NULL);
      } else if (this->m_encoding == DTC::BINARY_WITH_VARIABLE_LENGTH_STRINGS) {
        DTC_VLS::s_MarketDataRequest basereq{
          .RequestAction=reqAct,
          .SymbolID=ID,
          .IntervalForSnapshotUpdatesInMilliseconds=IntervalSnapMS
        };
        DTC_VLS::s_MarketDataRequest *req = (DTC_VLS::s_MarketDataRequest*)this->sendbuf;
        memcpy(req, &basereq, sizeof(basereq));
        
        DTCC_ADDVLS(symbol, DTC_VLS::s_MarketDataRequest, Symbol)
        DTCC_ADDVLS(exchange, DTC_VLS::s_MarketDataRequest, Exchange)

        size_t _;
        return nwrite(this->m_sock, req, req->Size, &_, NC_OPT_NULL);
      } else {
        return NC_ERR_NULL;
      }
    }
  // --- market depth --- //
  // --- trading auxiliary --- //
  // --- order --- //
  // --- position --- //
};
};

/*
if (this->m_encoding == DTC::BINARY_ENCODING) {

  size_t _;
  return nwrite(this->m_sock, &req, sizeof(req), &_, NC_OPT_NULL);
} else if (this->m_encoding == DTC::BINARY_WITH_VARIABLE_LENGTH_STRINGS) {

  size_t _;
  return nwrite(this->m_sock, req, req->Size, &_, NC_OPT_NULL);
} else {
  return NC_ERR_NULL;
}
*/