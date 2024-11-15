#ifndef _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#endif

#include <float.h>
#include <limits.h>
#include <string.h>
#include <memory.h> 
#include <stddef.h>

#include "dtcc/dtc_scext.hpp"


#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif


/****************************************************************************/
// s_EncodingRequestExtended

/*==========================================================================*/
uint16_t DTC::s_EncodingRequestExtended::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
void DTC::s_EncodingRequestExtended::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_EncodingRequestExtended), *static_cast<uint16_t*>(p_SourceData)));
}
/*==========================================================================*/
int32_t DTC::s_EncodingRequestExtended::GetProtocolVersion() const
{
	if (Size < offsetof(s_EncodingRequestExtended, ProtocolVersion) + sizeof(ProtocolVersion))
		return 0;

	return ProtocolVersion;
}
/*==========================================================================*/
DTC::EncodingEnum DTC::s_EncodingRequestExtended::GetEncoding() const
{
	if (Size < offsetof(s_EncodingRequestExtended, Encoding) + sizeof(Encoding))
		return DTC::BINARY_ENCODING;

	return Encoding;
}
/*==========================================================================*/
const char* DTC::s_EncodingRequestExtended::GetProtocolType() const
{
	if (Size < offsetof(s_EncodingRequestExtended, ProtocolType) + sizeof(ProtocolType))
		return "";

	//ProtocolType[sizeof(ProtocolType) - 1] = '\0';  // Ensure that the null terminator exists

	return ProtocolType;
}

/*==========================================================================*/
void DTC::s_EncodingRequestExtended::SetProtocolType(const char* NewValue)
{
	//Do not use the secure version of this function. This version of the function will set the remaining bytes in the destination after the null terminator to nulls. The secure version does not do this.
	strncpy(ProtocolType, NewValue, sizeof(ProtocolType) - 1);
}
/*==========================================================================*/
n_DTCNonStandard::UseCompressionEnum DTC::s_EncodingRequestExtended::GetUseCompression() const
{
	if (Size < offsetof(s_EncodingRequestExtended, UseCompression) + sizeof(UseCompression))
		return n_DTCNonStandard::USE_COMPRESSION_DISABLED;

	return UseCompression;
}


/****************************************************************************/
// s_HeartbeatExtended

/*==========================================================================*/
uint16_t DTC::s_HeartbeatExtended::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_HeartbeatExtended::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HeartbeatExtended), *static_cast<uint16_t*>( p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_HeartbeatExtended::GetNumDroppedMessages() const
{
	if (Size < offsetof(s_HeartbeatExtended, NumDroppedMessages) + sizeof(NumDroppedMessages))
		return 0;

	return NumDroppedMessages;
}

/*==========================================================================*/
DTC::t_DateTime DTC::s_HeartbeatExtended::GetCurrentDateTime() const
{
	if (Size < offsetof(s_HeartbeatExtended, CurrentDateTime) + sizeof(CurrentDateTime))
		return 0;

	return CurrentDateTime;
}

/*==========================================================================*/
uint16_t DTC::s_HeartbeatExtended::GetSecondsSinceLastReceivedHeartbeat() const
{
	if (Size < offsetof(s_HeartbeatExtended, SecondsSinceLastReceivedHeartbeat) + sizeof(SecondsSinceLastReceivedHeartbeat))
		return 0;

	return SecondsSinceLastReceivedHeartbeat;
}

/*==========================================================================*/
uint16_t DTC::s_HeartbeatExtended::GetNumberOfOutstandingSentBuffers() const
{
	if (Size < offsetof(s_HeartbeatExtended, NumberOfOutstandingSentBuffers) + sizeof(NumberOfOutstandingSentBuffers))
		return 0;

	return NumberOfOutstandingSentBuffers;
}

/*==========================================================================*/
uint16_t DTC::s_HeartbeatExtended::GetPendingTransmissionDelayInMilliseconds() const
{
	if (Size < offsetof(s_HeartbeatExtended, PendingTransmissionDelayInMilliseconds) + sizeof(PendingTransmissionDelayInMilliseconds))
		return 0;

	return PendingTransmissionDelayInMilliseconds;
}

/*==========================================================================*/
uint32_t DTC::s_HeartbeatExtended::GetCurrentSendBufferSizeInBytes() const
{
	if (Size < offsetof(s_HeartbeatExtended, CurrentSendBufferSizeInBytes) + sizeof(CurrentSendBufferSizeInBytes))
		return 0;

	return CurrentSendBufferSizeInBytes;
}

/*==========================================================================*/
DTC::t_DateTimeWithMicrosecondsInt DTC::s_HeartbeatExtended::GetSendingDateTimeMicroseconds() const
{
	if (Size < offsetof(s_HeartbeatExtended, SendingDateTimeMicroseconds) + sizeof(SendingDateTimeMicroseconds))
		return 0;

	return SendingDateTimeMicroseconds;

}

/*==========================================================================*/
float DTC::s_HeartbeatExtended::GetDataCompressionRatio() const
{
	if (Size < offsetof(s_HeartbeatExtended, DataCompressionRatio) + sizeof(DataCompressionRatio))
		return 0;

	return DataCompressionRatio;
}

/*==========================================================================*/
uint64_t DTC::s_HeartbeatExtended::GetTotalUncompressedBytes() const
{
	if (Size < offsetof(s_HeartbeatExtended, TotalUncompressedBytes) + sizeof(TotalUncompressedBytes))
		return 0;

	return TotalUncompressedBytes;
}

/*==========================================================================*/
double DTC::s_HeartbeatExtended::GetTotalCompressionTime() const
{
	if (Size < offsetof(s_HeartbeatExtended, TotalCompressionTime) + sizeof(TotalCompressionTime))
		return 0;

	return TotalCompressionTime;
}

/*==========================================================================*/
uint32_t DTC::s_HeartbeatExtended::GetNumberOfCompressions() const
{
	if (Size < offsetof(s_HeartbeatExtended, NumberOfCompressions) + sizeof(NumberOfCompressions))
		return 0;

	return NumberOfCompressions;
}

/*==========================================================================*/
uint32_t DTC::s_HeartbeatExtended::GetSourceIPAddress() const
{
	if (Size < offsetof(s_HeartbeatExtended, SourceIPAddress) + sizeof(SourceIPAddress))
		return 0;

	return SourceIPAddress;
}

/*==========================================================================*/
uint32_t DTC::s_HeartbeatExtended::GetMaximumSendBufferSizeInBytes() const
{
	if (Size < offsetof(s_HeartbeatExtended, MaximumSendBufferSizeInBytes) + sizeof(MaximumSendBufferSizeInBytes))
		return 0;

	return MaximumSendBufferSizeInBytes;
}

/*==========================================================================*/
DTC::t_DateTime DTC::s_HeartbeatExtended::GetMaximumSendBufferSizeInBytesDateTime() const
{
	if (Size < offsetof(s_HeartbeatExtended, MaximumSendBufferSizeInBytesDateTime) + sizeof(MaximumSendBufferSizeInBytesDateTime))
		return 0;

	return MaximumSendBufferSizeInBytesDateTime;
}

/****************************************************************************/
// s_HistoricalTradesRequest

/*==========================================================================*/
uint16_t DTC::s_HistoricalTradesRequest::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalTradesRequest), *static_cast<uint16_t*>( p_SourceData)));
}

/*==========================================================================*/
int32_t DTC::s_HistoricalTradesRequest::GetRequestID() const
{
	if (Size < offsetof(s_HistoricalTradesRequest, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
const char* DTC::s_HistoricalTradesRequest::GetSymbol()
{
	if (Size < offsetof(s_HistoricalTradesRequest, Symbol) + sizeof(Symbol))
		return "";

	Symbol[sizeof(Symbol) - 1] = '\0';  // Ensure that the null terminator exists

	return Symbol;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesRequest::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
const char* DTC::s_HistoricalTradesRequest::GetTradeAccount()
{
	if (Size < offsetof(s_HistoricalTradesRequest, TradeAccount) + sizeof(TradeAccount))
		return "";

	TradeAccount[sizeof(TradeAccount) - 1] = '\0';  // Ensure that the null terminator exists

	return TradeAccount;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesRequest::SetTradeAccount(const char* NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
DTC::t_DateTime DTC::s_HistoricalTradesRequest::GetStartDateTime() const
{
	if (Size < offsetof(s_HistoricalTradesRequest, StartDateTime) + sizeof(StartDateTime))
		return 0;

	return StartDateTime;
}

/*==========================================================================*/
uint32_t DTC::s_HistoricalTradesRequest::GetSubAccountIdentifier() const
{
	if (Size < offsetof(s_HistoricalTradesRequest, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/*==========================================================================*/
uint8_t DTC::s_HistoricalTradesRequest::GetCreateFlatToFlatTrades() const
{
	if (Size < offsetof(s_HistoricalTradesRequest, CreateFlatToFlatTrades) + sizeof(CreateFlatToFlatTrades))
		return 0;

	return CreateFlatToFlatTrades;
}

/****************************************************************************/
// s_HistoricalTradesReject

/*==========================================================================*/
uint16_t DTC::s_HistoricalTradesReject::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesReject::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalTradesReject), *static_cast<uint16_t*>( p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_HistoricalTradesReject::GetRequestID() const
{
	if (Size < offsetof(s_HistoricalTradesReject, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
const char* DTC::s_HistoricalTradesReject::GetRejectText()
{
	if (Size < offsetof(s_HistoricalTradesReject, RejectText) + sizeof(RejectText))
		return "";

	RejectText[sizeof(RejectText) - 1] = '\0';  // Ensure that the null terminator exists

	return RejectText;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesReject::SetRejectText(const char* NewValue)
{
	strncpy(RejectText, NewValue, sizeof(RejectText) - 1);
}

/****************************************************************************/
// s_HistoricalTradesResponse

/*==========================================================================*/
uint16_t DTC::s_HistoricalTradesResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesResponse::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_HistoricalTradesResponse), *static_cast<uint16_t*>( p_SourceData)));
}

/*==========================================================================*/
int32_t DTC::s_HistoricalTradesResponse::GetRequestID() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC::s_HistoricalTradesResponse::GetIsFinalMessage() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, IsFinalMessage) + sizeof(IsFinalMessage))
		return 0;

	return IsFinalMessage;
}

/*==========================================================================*/
const char* DTC::s_HistoricalTradesResponse::GetSymbol()
{
	if (Size < offsetof(s_HistoricalTradesResponse, Symbol) + sizeof(Symbol))
		return "";

	Symbol[sizeof(Symbol) - 1] = '\0';  // Ensure that the null terminator exists

	return Symbol;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesResponse::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
const char* DTC::s_HistoricalTradesResponse::GetTradeAccount()
{
	if (Size < offsetof(s_HistoricalTradesResponse, TradeAccount) + sizeof(TradeAccount))
		return "";

	TradeAccount[sizeof(TradeAccount) - 1] = '\0';  // Ensure that the null terminator exists

	return TradeAccount;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesResponse::SetTradeAccount(const char* NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
DTC::t_DateTimeWithMilliseconds DTC::s_HistoricalTradesResponse::GetEntryDateTime() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, EntryDateTime) + sizeof(EntryDateTime))
		return 0.0;

	return EntryDateTime;
}

/*==========================================================================*/
DTC::t_DateTimeWithMilliseconds DTC::s_HistoricalTradesResponse::GetExitDateTime() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, ExitDateTime) + sizeof(ExitDateTime))
		return 0.0;

	return ExitDateTime;
}

/*==========================================================================*/
double DTC::s_HistoricalTradesResponse::GetEntryPrice() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, EntryPrice) + sizeof(EntryPrice))
		return 0.0;

	return EntryPrice;
}

/*==========================================================================*/
double DTC::s_HistoricalTradesResponse::GetExitPrice() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, ExitPrice) + sizeof(ExitPrice))
		return 0.0;

	return ExitPrice;
}

/*==========================================================================*/
DTC::BuySellEnum DTC::s_HistoricalTradesResponse::GetTradeType() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, TradeType) + sizeof(TradeType))
		return DTC::BUY_SELL_UNSET;

	return TradeType;
}

/*==========================================================================*/
uint32_t DTC::s_HistoricalTradesResponse::GetEntryQuantity() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, EntryQuantity) + sizeof(EntryQuantity))
		return 0;

	return EntryQuantity;
}

/*==========================================================================*/
uint32_t DTC::s_HistoricalTradesResponse::GetExitQuantity() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, ExitQuantity) + sizeof(ExitQuantity))
		return 0;

	return ExitQuantity;
}

/*==========================================================================*/
uint32_t DTC::s_HistoricalTradesResponse::GetMaxOpenQuantity() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, MaxOpenQuantity) + sizeof(MaxOpenQuantity))
		return 0;

	return MaxOpenQuantity;
}

/*==========================================================================*/
double DTC::s_HistoricalTradesResponse::GetClosedProfitLoss() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, ClosedProfitLoss) + sizeof(ClosedProfitLoss))
		return 0.0;

	return ClosedProfitLoss;
}

/*==========================================================================*/
double DTC::s_HistoricalTradesResponse::GetMaximumOpenPositionLoss() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, MaximumOpenPositionLoss) + sizeof(MaximumOpenPositionLoss))
		return 0.0;

	return MaximumOpenPositionLoss;
}

/*==========================================================================*/
double DTC::s_HistoricalTradesResponse::GetMaximumOpenPositionProfit() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, MaximumOpenPositionProfit) + sizeof(MaximumOpenPositionProfit))
		return 0.0;

	return MaximumOpenPositionProfit;
}

/*==========================================================================*/
double DTC::s_HistoricalTradesResponse::GetCommission() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, Commission) + sizeof(Commission))
		return 0.0;

	return Commission;
}

/*==========================================================================*/
const char* DTC::s_HistoricalTradesResponse::GetOpenFillExecutionID()
{
	if (Size < offsetof(s_HistoricalTradesResponse, OpenFillExecutionID) + sizeof(OpenFillExecutionID))
		return "";

	OpenFillExecutionID[sizeof(OpenFillExecutionID) - 1] = '\0';  // Ensure that the null terminator exists

	return OpenFillExecutionID;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesResponse::SetOpenFillExecutionID(const char* NewValue)
{
	strncpy(OpenFillExecutionID, NewValue, sizeof(OpenFillExecutionID) - 1);
}

/*==========================================================================*/
const char* DTC::s_HistoricalTradesResponse::GetCloseFillExecutionID()
{
	if (Size < offsetof(s_HistoricalTradesResponse, CloseFillExecutionID) + sizeof(CloseFillExecutionID))
		return "";

	CloseFillExecutionID[sizeof(CloseFillExecutionID) - 1] = '\0';  // Ensure that the null terminator exists

	return CloseFillExecutionID;
}

/*==========================================================================*/
void DTC::s_HistoricalTradesResponse::SetCloseFillExecutionID(const char* NewValue)
{
	strncpy(CloseFillExecutionID, NewValue, sizeof(CloseFillExecutionID) - 1);
}

/*==========================================================================*/
uint32_t DTC::s_HistoricalTradesResponse::GetSubAccountIdentifier() const
{
	if (Size < offsetof(s_HistoricalTradesResponse, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/****************************************************************************/
// s_ReplayChartData

/*==========================================================================*/
uint16_t DTC::s_ReplayChartData::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_ReplayChartData::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ReplayChartData), *static_cast<uint16_t*>( p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_ReplayChartData::GetRequestID() const
{
	if (Size < offsetof(s_ReplayChartData, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
const char* DTC::s_ReplayChartData::GetSymbol()
{
	if (Size < offsetof(s_ReplayChartData, Symbol) + sizeof(Symbol))
		return "";

	Symbol[sizeof(Symbol) - 1] = '\0';  // Ensure that the null terminator exists

	return Symbol;
}

/*==========================================================================*/
void DTC::s_ReplayChartData::SetSymbol(const char* NewValue)
{
	strncpy(Symbol, NewValue, sizeof(Symbol) - 1);
}

/*==========================================================================*/
const char* DTC::s_ReplayChartData::GetTradeAccount()
{
	if (Size < offsetof(s_ReplayChartData, TradeAccount) + sizeof(TradeAccount))
		return "";

	TradeAccount[sizeof(TradeAccount) - 1] = '\0';  // Ensure that the null terminator exists

	return TradeAccount;
}

/*==========================================================================*/
void DTC::s_ReplayChartData::SetTradeAccount(const char* NewValue)
{
	strncpy(TradeAccount, NewValue, sizeof(TradeAccount) - 1);
}

/*==========================================================================*/
const char* DTC::s_ReplayChartData::GetTimeZone()
{
	if (Size < offsetof(s_ReplayChartData, TimeZone) + sizeof(TimeZone))
		return "";

	TimeZone[sizeof(TimeZone) - 1] = '\0';  // Ensure that the null terminator exists

	return TimeZone;
}

/*==========================================================================*/
void DTC::s_ReplayChartData::SetTimeZone(const char* NewValue)
{
	strncpy(TimeZone, NewValue, sizeof(TimeZone) - 1);
}

/*==========================================================================*/
DTC::t_DateTimeWithMillisecondsInt DTC::s_ReplayChartData::GetStartDateTimeForInitialData() const
{
	if (Size < offsetof(s_ReplayChartData, StartDateTimeForInitialData) + sizeof(StartDateTimeForInitialData))
		return 0;

	return StartDateTimeForInitialData;
}

/*==========================================================================*/
DTC::t_DateTimeWithMillisecondsInt DTC::s_ReplayChartData::GetStartDateTime() const
{
	if (Size < offsetof(s_ReplayChartData, StartDateTime) + sizeof(StartDateTime))
		return 0;

	return StartDateTime;
}

/*==========================================================================*/
DTC::t_DateTimeWithMillisecondsInt DTC::s_ReplayChartData::GetStopDateTime() const
{
	if (Size < offsetof(s_ReplayChartData, StopDateTime) + sizeof(StopDateTime))
		return 0;

	return StopDateTime;
}

/*==========================================================================*/
uint16_t DTC::s_ReplayChartData::GetSessionBeginTimeInSeconds() const
{
	if (Size < offsetof(s_ReplayChartData, SessionBeginTimeInSeconds) + sizeof(SessionBeginTimeInSeconds))
		return 0;

	return SessionBeginTimeInSeconds;
}

/*==========================================================================*/
uint16_t DTC::s_ReplayChartData::GetSessionEndTimeInSeconds() const
{
	if (Size < offsetof(s_ReplayChartData, SessionEndTimeInSeconds) + sizeof(SessionEndTimeInSeconds))
		return 0;

	return SessionEndTimeInSeconds;
}

/*==========================================================================*/
float DTC::s_ReplayChartData::GetReplaySpeed() const
{
	if (Size < offsetof(s_ReplayChartData, ReplaySpeed) + sizeof(ReplaySpeed))
		return 0.0;

	return ReplaySpeed;
}

/*==========================================================================*/
int32_t DTC::s_ReplayChartData::GetBarTimeInSeconds() const
{
	if (Size < offsetof(s_ReplayChartData, BarTimeInSeconds) + sizeof(BarTimeInSeconds))
		return 0;

	return BarTimeInSeconds;
}

/*==========================================================================*/
uint8_t DTC::s_ReplayChartData::GetPauseReplayAfterInitialDataSent() const
{
	if (Size < offsetof(s_ReplayChartData, PauseReplayAfterInitialDataSent) + sizeof(PauseReplayAfterInitialDataSent))
		return 0;

	return PauseReplayAfterInitialDataSent;
}

/*==========================================================================*/
uint8_t DTC::s_ReplayChartData::GetUseSavedPriorState() const
{
	if (Size < offsetof(s_ReplayChartData, UseSavedPriorState) + sizeof(UseSavedPriorState))
		return 0;

	return UseSavedPriorState;
}

/*==========================================================================*/
float DTC::s_ReplayChartData::GetSymbolVolatility() const
{
	if (Size < offsetof(s_ReplayChartData, SymbolVolatility) + sizeof(SymbolVolatility))
		return 0.0;

	return SymbolVolatility;
}

/*==========================================================================*/
float DTC::s_ReplayChartData::GetInterestRate() const
{
	if (Size < offsetof(s_ReplayChartData, InterestRate) + sizeof(InterestRate))
		return 0.0;

	return InterestRate;
}

/*==========================================================================*/
int32_t DTC::s_ReplayChartData::GetNumberOfOrdersToTriggerFinishToStopDateTime() const
{
	if (Size < offsetof(s_ReplayChartData, NumberOfOrdersToTriggerFinishToStopDateTime) + sizeof(NumberOfOrdersToTriggerFinishToStopDateTime))
		return 0;

	return NumberOfOrdersToTriggerFinishToStopDateTime;
}

/*==========================================================================*/
int32_t DTC::s_ReplayChartData::GetMaximumNumberOfOrdersPerReplaySession() const
{
	if (Size < offsetof(s_ReplayChartData, MaximumNumberOfOrdersPerReplaySession) + sizeof(MaximumNumberOfOrdersPerReplaySession))
		return 0;

	return MaximumNumberOfOrdersPerReplaySession;
}

/*==========================================================================*/
int32_t DTC::s_ReplayChartData::GetNumberOfDaysForInitialDataFromBeforeLastSavedDateTime() const
{
	if (Size < offsetof(s_ReplayChartData, NumberOfDaysForInitialDataFromBeforeLastSavedDateTime) + sizeof(NumberOfDaysForInitialDataFromBeforeLastSavedDateTime))
		return 0;

	return NumberOfDaysForInitialDataFromBeforeLastSavedDateTime;
}

/*==========================================================================*/
uint32_t DTC::s_ReplayChartData::GetSubAccountIdentifier() const
{
	if (Size < offsetof(s_ReplayChartData, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/*==========================================================================*/
int32_t DTC::s_ReplayChartData::GetOptionsPriceSendIntervalInSeconds() const
{
	if (Size < offsetof(s_ReplayChartData, OptionsPriceSendIntervalInSeconds) + sizeof(OptionsPriceSendIntervalInSeconds))
		return 0;

	return OptionsPriceSendIntervalInSeconds;
}

/****************************************************************************/
// s_ReplayChartDataPerformAction

/*==========================================================================*/
uint16_t DTC::s_ReplayChartDataPerformAction::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_ReplayChartDataPerformAction::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ReplayChartDataPerformAction), *static_cast<uint16_t*>( p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_ReplayChartDataPerformAction::GetRequestID() const
{
	if (Size < offsetof(s_ReplayChartDataPerformAction, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
n_DTCNonStandard::ReplayChartDataActionEnum DTC::s_ReplayChartDataPerformAction::GetAction() const
{
	if (Size < offsetof(s_ReplayChartDataPerformAction, Action) + sizeof(Action))
		return n_DTCNonStandard::REPLAY_CHART_DATA_ACTION_NONE;

	return Action;
}

/*==========================================================================*/
float DTC::s_ReplayChartDataPerformAction::GetReplaySpeed() const
{
	if (Size < offsetof(s_ReplayChartDataPerformAction, ReplaySpeed) + sizeof(ReplaySpeed))
		return 0.0;

	return ReplaySpeed;
}

/****************************************************************************/
// s_ReplayChartDataStatus

/*==========================================================================*/
uint16_t DTC::s_ReplayChartDataStatus::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_ReplayChartDataStatus::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ReplayChartDataStatus), *static_cast<uint16_t*>( p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_ReplayChartDataStatus::GetRequestID() const
{
	if (Size < offsetof(s_ReplayChartDataStatus, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
const char* DTC::s_ReplayChartDataStatus::GetErrorMessage()
{
	if (Size < offsetof(s_ReplayChartDataStatus, ErrorMessage) + sizeof(ErrorMessage))
		return "";

	ErrorMessage[sizeof(ErrorMessage) - 1] = '\0';  // Ensure that the null terminator exists

	return ErrorMessage;
}

/*==========================================================================*/
void DTC::s_ReplayChartDataStatus::SetErrorMessage(const char* NewValue)
{
	strncpy(ErrorMessage, NewValue, sizeof(ErrorMessage) - 1);
}

/*==========================================================================*/
n_DTCNonStandard::ReplayChartDataStatusEnum DTC::s_ReplayChartDataStatus::GetStatus() const
{
	if (Size < offsetof(s_ReplayChartDataStatus, Status) + sizeof(Status))
		return n_DTCNonStandard::REPLAY_CHART_DATA_STATUS_UNSET;

	return Status;
}

/*==========================================================================*/
uint32_t DTC::s_ReplayChartDataStatus::GetSubAccountIdentifier() const
{
	if (Size < offsetof(s_ReplayChartDataStatus, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/****************************************************************************/
// s_ClientDeviceUpdate

/*==========================================================================*/
uint16_t DTC::s_ClientDeviceUpdate::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_ClientDeviceUpdate::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_ClientDeviceUpdate), *static_cast<uint16_t*>(p_SourceData)));
}

/*==========================================================================*/
int64_t DTC::s_ClientDeviceUpdate::GetClientDeviceIdentifier() const
{
	if (Size < offsetof(s_ClientDeviceUpdate, ClientDeviceIdentifier) + sizeof(ClientDeviceIdentifier))
		return 0;

	return ClientDeviceIdentifier;
}

/****************************************************************************/
// s_InterprocessSynchronizationSnapshotRequest

/*==========================================================================*/
uint16_t DTC::s_InterprocessSynchronizationSnapshotRequest::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_InterprocessSynchronizationSnapshotRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_InterprocessSynchronizationSnapshotRequest), *static_cast<uint16_t*>(p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_InterprocessSynchronizationSnapshotRequest::GetRequestID() const
{
	if (Size < offsetof(s_InterprocessSynchronizationSnapshotRequest, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
// s_InterprocessSynchronizationTradeActivityRequest

/*==========================================================================*/
uint16_t DTC::s_InterprocessSynchronizationTradeActivityRequest::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_InterprocessSynchronizationTradeActivityRequest::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_InterprocessSynchronizationTradeActivityRequest), *static_cast<uint16_t*>(p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_InterprocessSynchronizationTradeActivityRequest::GetRequestID() const
{
	if (Size < offsetof(s_InterprocessSynchronizationTradeActivityRequest, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
int64_t DTC::s_InterprocessSynchronizationTradeActivityRequest::GetStartDateTimeUTC() const
{
	if (Size < offsetof(s_InterprocessSynchronizationTradeActivityRequest, StartDateTimeUTC) + sizeof(StartDateTimeUTC))
		return 0;

	return StartDateTimeUTC;
}

/****************************************************************************/
// s_SCConfigurationSynchronization

/*==========================================================================*/
uint16_t DTC_VLS::s_SCConfigurationSynchronization::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_SCConfigurationSynchronization::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_SCConfigurationSynchronization::GetMessageID() const
{
	if (BaseSize < offsetof(s_SCConfigurationSynchronization, MessageID) + sizeof(MessageID))
		return 0;

	return MessageID;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_SCConfigurationSynchronization::GetCurrentInboundSequenceNumber() const
{
	if (BaseSize < offsetof(s_SCConfigurationSynchronization, CurrentInboundSequenceNumber) + sizeof(CurrentInboundSequenceNumber))
		return 0;

	return CurrentInboundSequenceNumber;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_SCConfigurationSynchronization::GetCurrentOutboundSequenceNumber() const
{
	if (BaseSize < offsetof(s_SCConfigurationSynchronization, CurrentOutboundSequenceNumber) + sizeof(CurrentOutboundSequenceNumber))
		return 0;

	return CurrentOutboundSequenceNumber;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_SCConfigurationSynchronization::GetCurrentInternalOrderID() const
{
	if (BaseSize < offsetof(s_SCConfigurationSynchronization, CurrentInternalOrderID) + sizeof(CurrentInternalOrderID))
		return 0;

	return CurrentInternalOrderID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_SCConfigurationSynchronization::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_SCConfigurationSynchronization, IsSnapshot) + sizeof(IsSnapshot))
		return 0;

	return IsSnapshot;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_SCConfigurationSynchronization::GetSessionUUID() const
{
	if (BaseSize < offsetof(s_SCConfigurationSynchronization, SessionUUID) + sizeof(SessionUUID))
	{
		return 0;
	}

	return SessionUUID;	
}

/*==========================================================================*/
int64_t DTC_VLS::s_SCConfigurationSynchronization::GetSessionUUIDGeneratedDateTimeUTC() const
{
	if (BaseSize < offsetof(s_SCConfigurationSynchronization, SessionUUIDGeneratedDateTimeUTC) + sizeof(SessionUUIDGeneratedDateTimeUTC))
	{
		return 0;
	}

	return SessionUUIDGeneratedDateTimeUTC;
}

/****************************************************************************/
// s_DownloadHistoricalOrderFillAndAccountBalanceData

/*==========================================================================*/
uint16_t DTC_VLS::s_DownloadHistoricalOrderFillAndAccountBalanceData::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_DownloadHistoricalOrderFillAndAccountBalanceData::GetBaseSize() const
{
	return BaseSize;
}

/****************************************************************************/
// s_HistoricalTradesRequest

/*==========================================================================*/
uint16_t DTC_VLS::s_HistoricalTradesRequest::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_HistoricalTradesRequest::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
int32_t DTC_VLS::s_HistoricalTradesRequest::GetRequestID() const
{
	if (BaseSize < offsetof(s_HistoricalTradesRequest, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
DTC::t_DateTime DTC_VLS::s_HistoricalTradesRequest::GetStartDateTime() const
{
	if (BaseSize < offsetof(s_HistoricalTradesRequest, StartDateTime) + sizeof(StartDateTime))
		return 0;

	return StartDateTime;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_HistoricalTradesRequest::GetSubAccountIdentifier() const
{
	if (BaseSize < offsetof(s_HistoricalTradesRequest, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_HistoricalTradesRequest::GetCreateFlatToFlatTrades() const
{
	if (BaseSize < offsetof(s_HistoricalTradesRequest, CreateFlatToFlatTrades) + sizeof(CreateFlatToFlatTrades))
		return 0;

	return CreateFlatToFlatTrades;
}

/****************************************************************************/
// s_HistoricalTradesReject

/*==========================================================================*/
uint16_t DTC_VLS::s_HistoricalTradesReject::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_HistoricalTradesReject::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_HistoricalTradesReject::GetRequestID() const
{
	if (BaseSize < offsetof(s_HistoricalTradesReject, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
// s_HistoricalTradesResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_HistoricalTradesResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_HistoricalTradesResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
int32_t DTC_VLS::s_HistoricalTradesResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_HistoricalTradesResponse::GetIsFinalMessage() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, IsFinalMessage) + sizeof(IsFinalMessage))
		return 0;

	return IsFinalMessage;
}

/*==========================================================================*/
DTC::t_DateTimeWithMilliseconds DTC_VLS::s_HistoricalTradesResponse::GetEntryDateTime() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, EntryDateTime) + sizeof(EntryDateTime))
		return 0.0;

	return EntryDateTime;
}

/*==========================================================================*/
DTC::t_DateTimeWithMilliseconds DTC_VLS::s_HistoricalTradesResponse::GetExitDateTime() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, ExitDateTime) + sizeof(ExitDateTime))
		return DTC::BUY_SELL_UNSET;

	return ExitDateTime;
}

/*==========================================================================*/
double DTC_VLS::s_HistoricalTradesResponse::GetEntryPrice() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, EntryPrice) + sizeof(EntryPrice))
		return 0.0;

	return EntryPrice;
}

/*==========================================================================*/
double DTC_VLS::s_HistoricalTradesResponse::GetExitPrice() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, ExitPrice) + sizeof(ExitPrice))
		return 0.0;

	return ExitPrice;
}

/*==========================================================================*/
DTC::BuySellEnum DTC_VLS::s_HistoricalTradesResponse::GetTradeType() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, TradeType) + sizeof(TradeType))
		return DTC::BUY_SELL_UNSET;

	return TradeType;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_HistoricalTradesResponse::GetEntryQuantity() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, EntryQuantity) + sizeof(EntryQuantity))
		return 0;

	return EntryQuantity;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_HistoricalTradesResponse::GetExitQuantity() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, ExitQuantity) + sizeof(ExitQuantity))
		return 0;

	return ExitQuantity;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_HistoricalTradesResponse::GetMaxOpenQuantity() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, MaxOpenQuantity) + sizeof(MaxOpenQuantity))
		return 0;

	return MaxOpenQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_HistoricalTradesResponse::GetClosedProfitLoss() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, ClosedProfitLoss) + sizeof(ClosedProfitLoss))
		return 0.0;

	return ClosedProfitLoss;
}

/*==========================================================================*/
double DTC_VLS::s_HistoricalTradesResponse::GetMaximumOpenPositionLoss() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, MaximumOpenPositionLoss) + sizeof(MaximumOpenPositionLoss))
		return 0.0;

	return MaximumOpenPositionLoss;
}

/*==========================================================================*/
double DTC_VLS::s_HistoricalTradesResponse::GetMaximumOpenPositionProfit() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, MaximumOpenPositionProfit) + sizeof(MaximumOpenPositionProfit))
		return 0.0;

	return MaximumOpenPositionProfit;
}

/*==========================================================================*/
double DTC_VLS::s_HistoricalTradesResponse::GetCommission() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, Commission) + sizeof(Commission))
		return 0.0;

	return Commission;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_HistoricalTradesResponse::GetSubAccountIdentifier() const
{
	if (BaseSize < offsetof(s_HistoricalTradesResponse, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/****************************************************************************/
// s_ReplayChartData

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartData::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartData::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ReplayChartData::GetRequestID() const
{
	if (BaseSize < offsetof(s_ReplayChartData, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
DTC::t_DateTimeWithMillisecondsInt DTC_VLS::s_ReplayChartData::GetStartDateTimeForInitialData() const
{
	if (BaseSize < offsetof(s_ReplayChartData, StartDateTimeForInitialData) + sizeof(StartDateTimeForInitialData))
		return 0;

	return StartDateTimeForInitialData;
}

/*==========================================================================*/
DTC::t_DateTimeWithMillisecondsInt DTC_VLS::s_ReplayChartData::GetStartDateTime() const
{
	if (BaseSize < offsetof(s_ReplayChartData, StartDateTime) + sizeof(StartDateTime))
		return 0;

	return StartDateTime;
}

/*==========================================================================*/
DTC::t_DateTimeWithMillisecondsInt DTC_VLS::s_ReplayChartData::GetStopDateTime() const
{
	if (BaseSize < offsetof(s_ReplayChartData, StopDateTime) + sizeof(StopDateTime))
		return 0;

	return StopDateTime;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartData::GetSessionBeginTimeInSeconds() const
{
	if (BaseSize < offsetof(s_ReplayChartData, SessionBeginTimeInSeconds) + sizeof(SessionBeginTimeInSeconds))
		return 0;

	return SessionBeginTimeInSeconds;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartData::GetSessionEndTimeInSeconds() const
{
	if (BaseSize < offsetof(s_ReplayChartData, SessionEndTimeInSeconds) + sizeof(SessionEndTimeInSeconds))
		return 0;

	return SessionEndTimeInSeconds;
}

/*==========================================================================*/
float DTC_VLS::s_ReplayChartData::GetReplaySpeed() const
{
	if (BaseSize < offsetof(s_ReplayChartData, ReplaySpeed) + sizeof(ReplaySpeed))
		return 0.0;

	return ReplaySpeed;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ReplayChartData::GetBarTimeInSeconds() const
{
	if (BaseSize < offsetof(s_ReplayChartData, BarTimeInSeconds) + sizeof(BarTimeInSeconds))
		return 0;

	return BarTimeInSeconds;
}
/*==========================================================================*/
uint8_t DTC_VLS::s_ReplayChartData::GetPauseReplayAfterInitialDataSent() const
{
	if (BaseSize < offsetof(s_ReplayChartData, PauseReplayAfterInitialDataSent) + sizeof(PauseReplayAfterInitialDataSent))
		return 0;

	return PauseReplayAfterInitialDataSent;
}
/*==========================================================================*/
uint8_t DTC_VLS::s_ReplayChartData::GetUseSavedPriorState() const
{
	if (BaseSize < offsetof(s_ReplayChartData, UseSavedPriorState) + sizeof(UseSavedPriorState))
		return 0;

	return UseSavedPriorState;
}

/*==========================================================================*/
float DTC_VLS::s_ReplayChartData::GetSymbolVolatility() const
{
	if (BaseSize < offsetof(s_ReplayChartData, SymbolVolatility) + sizeof(SymbolVolatility))
		return 0.0;

	return SymbolVolatility;
}

/*==========================================================================*/
float DTC_VLS::s_ReplayChartData::GetInterestRate() const
{
	if (BaseSize < offsetof(s_ReplayChartData, InterestRate) + sizeof(InterestRate))
		return 0.0;

	return InterestRate;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ReplayChartData::GetNumberOfOrdersToTriggerFinishToStopDateTime() const
{
	if (BaseSize < offsetof(s_ReplayChartData, NumberOfOrdersToTriggerFinishToStopDateTime) + sizeof(NumberOfOrdersToTriggerFinishToStopDateTime))
		return 0;

	return NumberOfOrdersToTriggerFinishToStopDateTime;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ReplayChartData::GetMaximumNumberOfOrdersPerReplaySession() const
{
	if (BaseSize < offsetof(s_ReplayChartData, MaximumNumberOfOrdersPerReplaySession) + sizeof(MaximumNumberOfOrdersPerReplaySession))
		return 0;

	return MaximumNumberOfOrdersPerReplaySession;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ReplayChartData::GetNumberOfDaysForInitialDataFromBeforeLastSavedDateTime() const
{
	if (BaseSize < offsetof(s_ReplayChartData, NumberOfDaysForInitialDataFromBeforeLastSavedDateTime) + sizeof(NumberOfDaysForInitialDataFromBeforeLastSavedDateTime))
		return 0;

	return NumberOfDaysForInitialDataFromBeforeLastSavedDateTime;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ReplayChartData::GetSubAccountIdentifier() const
{
	if (BaseSize < offsetof(s_ReplayChartData, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ReplayChartData::GetOptionsPriceSendIntervalInSeconds() const
{
	if (BaseSize < offsetof(s_ReplayChartData, OptionsPriceSendIntervalInSeconds) + sizeof(OptionsPriceSendIntervalInSeconds))
		return 0;

	return OptionsPriceSendIntervalInSeconds;
}

/****************************************************************************/
// s_ReplayChartDataPerformAction

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartDataPerformAction::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartDataPerformAction::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ReplayChartDataPerformAction::GetRequestID() const
{
	if (BaseSize < offsetof(s_ReplayChartDataPerformAction, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
n_DTCNonStandard::ReplayChartDataActionEnum DTC_VLS::s_ReplayChartDataPerformAction::GetAction() const
{
	if (BaseSize < offsetof(s_ReplayChartDataPerformAction, Action) + sizeof(Action))
		return n_DTCNonStandard::REPLAY_CHART_DATA_ACTION_NONE;

	return Action;
}

/*==========================================================================*/
float DTC_VLS::s_ReplayChartDataPerformAction::GetReplaySpeed() const
{
	if (BaseSize < offsetof(s_ReplayChartDataPerformAction, ReplaySpeed) + sizeof(ReplaySpeed))
		return 0.0;

	return ReplaySpeed;
}

/****************************************************************************/
// s_ReplayChartDataStatus

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartDataStatus::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ReplayChartDataStatus::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ReplayChartDataStatus::GetRequestID() const
{
	if (BaseSize < offsetof(s_ReplayChartDataStatus, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
n_DTCNonStandard::ReplayChartDataStatusEnum DTC_VLS::s_ReplayChartDataStatus::GetStatus() const
{
	if (BaseSize < offsetof(s_ReplayChartDataStatus, Status) + sizeof(Status))
		return n_DTCNonStandard::REPLAY_CHART_DATA_STATUS_UNSET;

	return Status;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ReplayChartDataStatus::GetSubAccountIdentifier() const
{
	if (BaseSize < offsetof(s_ReplayChartDataStatus, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/****************************************************************************/
// s_RequestNumCurrentClientConnections

/*==========================================================================*/
uint16_t DTC_VLS::s_RequestNumCurrentClientConnections::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_RequestNumCurrentClientConnections::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_RequestNumCurrentClientConnections::GetRequestID() const
{
	if (BaseSize < offsetof(s_RequestNumCurrentClientConnections, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
// s_NumCurrentClientConnectionsResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier1() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier1) + sizeof(ClientDeviceIdentifier1))
		return 0;

	return ClientDeviceIdentifier1;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier2() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier2) + sizeof(ClientDeviceIdentifier2))
		return 0;

	return ClientDeviceIdentifier2;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier3() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier3) + sizeof(ClientDeviceIdentifier3))
		return 0;

	return ClientDeviceIdentifier3;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier4() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier4) + sizeof(ClientDeviceIdentifier4))
		return 0;

	return ClientDeviceIdentifier4;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier5() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier5) + sizeof(ClientDeviceIdentifier5))
		return 0;

	return ClientDeviceIdentifier5;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier6() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier6) + sizeof(ClientDeviceIdentifier6))
		return 0;

	return ClientDeviceIdentifier6;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier7() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier7) + sizeof(ClientDeviceIdentifier7))
		return 0;

	return ClientDeviceIdentifier7;
}

/*==========================================================================*/
int64_t DTC_VLS::s_NumCurrentClientConnectionsResponse::GetClientDeviceIdentifier8() const
{
	if (BaseSize < offsetof(s_NumCurrentClientConnectionsResponse, ClientDeviceIdentifier8) + sizeof(ClientDeviceIdentifier8))
		return 0;

	return ClientDeviceIdentifier8;
}

/****************************************************************************/
// s_SCTradeOrder

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeOrder::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeOrder::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsOrderDeleted() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsOrderDeleted) + sizeof(m_IsOrderDeleted))
		return 0;

	return m_IsOrderDeleted;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_InternalOrderID) + sizeof(m_InternalOrderID))
		return 0;

	return m_InternalOrderID;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeOrder::GetOrderStatusCode() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderStatusCode) + sizeof(m_OrderStatusCode))
		return 0;

	return m_OrderStatusCode;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeOrder::GetOrderStatusBeforePendingModify() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderStatusBeforePendingModify) + sizeof(m_OrderStatusBeforePendingModify))
		return 0;

	return m_OrderStatusBeforePendingModify;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeOrder::GetOrderStatusBeforePendingCancel() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderStatusBeforePendingCancel) + sizeof(m_OrderStatusBeforePendingCancel))
		return 0;

	return m_OrderStatusBeforePendingCancel;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetOrderType() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderType) + sizeof(m_OrderType))
		return 0;

	return m_OrderType;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeOrder::GetBuySell() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_BuySell) + sizeof(m_BuySell))
		return 0;

	return m_BuySell;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetPrice1() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_Price1) + sizeof(m_Price1))
		return 0;

	return m_Price1;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetPrice2() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_Price2) + sizeof(m_Price2))
		return 0;

	return m_Price2;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetOrderQuantity() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderQuantity) + sizeof(m_OrderQuantity))
		return 0;

	return m_OrderQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetFilledQuantity() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_FilledQuantity) + sizeof(m_FilledQuantity))
		return 0;

	return m_FilledQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetAverageFillPrice() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_AverageFillPrice) + sizeof(m_AverageFillPrice))
		return 0;

	return m_AverageFillPrice;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetRealtimeFillStatus() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_RealtimeFillStatus) + sizeof(m_RealtimeFillStatus))
		return 0;

	return m_RealtimeFillStatus;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsRestingOrderDuringFill() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsRestingOrderDuringFill) + sizeof(m_IsRestingOrderDuringFill))
		return 0;

	return m_IsRestingOrderDuringFill;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetOrderRejectType() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderRejectType) + sizeof(m_OrderRejectType))
		return 0;

	return m_OrderRejectType;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeOrder::GetSubAccountIdentifier() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SubAccountIdentifier) + sizeof(m_SubAccountIdentifier))
		return 0;

	return m_SubAccountIdentifier;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetInternalOrderIDModifierForService() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_InternalOrderIDModifierForService) + sizeof(m_InternalOrderIDModifierForService))
		return 0;

	return m_InternalOrderIDModifierForService;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeOrder::GetSequenceNumberBasedClientOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SequenceNumberBasedClientOrderID) + sizeof(m_SequenceNumberBasedClientOrderID))
		return 0;

	return m_SequenceNumberBasedClientOrderID;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetEntryDateTime() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_EntryDateTime) + sizeof(m_EntryDateTime))
		return 0;

	return m_EntryDateTime;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetLastActionDateTime() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastActionDateTime) + sizeof(m_LastActionDateTime))
		return 0;

	return m_LastActionDateTime;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetServiceUpdateDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_ServiceUpdateDateTimeUTC) + sizeof(m_ServiceUpdateDateTimeUTC))
		return 0;

	return m_ServiceUpdateDateTimeUTC;
}

/*==========================================================================*/
unsigned int DTC_VLS::s_TradeOrder::GetOrderEntryTimeForService() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderEntryTimeForService) + sizeof(m_OrderEntryTimeForService))
		return 0;

	return m_OrderEntryTimeForService;
}

/*==========================================================================*/
unsigned int DTC_VLS::s_TradeOrder::GetLastModifyTimeForService() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastModifyTimeForService) + sizeof(m_LastModifyTimeForService))
		return 0;

	return m_LastModifyTimeForService;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetGoodTillDateTime() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_GoodTillDateTime) + sizeof(m_GoodTillDateTime))
		return 0;

	return m_GoodTillDateTime;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetTimeInForce() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TimeInForce) + sizeof(m_TimeInForce))
		return 0;

	return m_TimeInForce;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeOrder::GetOpenClose() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OpenClose) + sizeof(m_OpenClose))
		return 0;

	return m_OpenClose;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetTrailStopOffset1() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TrailStopOffset1) + sizeof(m_TrailStopOffset1))
		return 0;

	return m_TrailStopOffset1;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetTrailStopStep() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TrailStopStep) + sizeof(m_TrailStopStep))
		return 0;

	return m_TrailStopStep;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetTrailTriggerPrice() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TrailTriggerPrice) + sizeof(m_TrailTriggerPrice))
		return 0;

	return m_TrailTriggerPrice;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetTrailingStopTriggerOffset() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TrailingStopTriggerOffset) + sizeof(m_TrailingStopTriggerOffset))
		return 0;

	return m_TrailingStopTriggerOffset;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetTrailTriggerHit() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TrailTriggerHit) + sizeof(m_TrailTriggerHit))
		return 0;

	return m_TrailTriggerHit;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetTrailToBreakEvenStopOffset() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TrailToBreakEvenStopOffset) + sizeof(m_TrailToBreakEvenStopOffset))
		return 0;

	return m_TrailToBreakEvenStopOffset;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetMaximumChaseAmountAsPrice() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_MaximumChaseAmountAsPrice) + sizeof(m_MaximumChaseAmountAsPrice))
		return 0;

	return m_MaximumChaseAmountAsPrice;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetInitialChaseOrderPrice1() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_InitialChaseOrderPrice1) + sizeof(m_InitialChaseOrderPrice1))
		return 0;

	return m_InitialChaseOrderPrice1;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetInitialLastTradePriceForChaseOrders() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_InitialLastTradePriceForChaseOrders) + sizeof(m_InitialLastTradePriceForChaseOrders))
		return 0;

	return m_InitialLastTradePriceForChaseOrders;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetTrailingStopTriggerOCOGroupNumber() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TrailingStopTriggerOCOGroupNumber) + sizeof(m_TrailingStopTriggerOCOGroupNumber))
		return 0;

	return m_TrailingStopTriggerOCOGroupNumber;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetLastModifyPrice1() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastModifyPrice1) + sizeof(m_LastModifyPrice1))
		return 0;

	return m_LastModifyPrice1;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetLastModifyQuantity() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastModifyQuantity) + sizeof(m_LastModifyQuantity))
		return 0;

	return m_LastModifyQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetCumulativeOrderQuantityFromParentFills() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_CumulativeOrderQuantityFromParentFills) + sizeof(m_CumulativeOrderQuantityFromParentFills))
		return 0;

	return m_CumulativeOrderQuantityFromParentFills;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetPriorFilledQuantity() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_PriorFilledQuantity) + sizeof(m_PriorFilledQuantity))
		return 0;

	return m_PriorFilledQuantity;
}

/*==========================================================================*/
float DTC_VLS::s_TradeOrder::GetTickSize() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TickSize) + sizeof(m_TickSize))
		return 0;

	return m_TickSize;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetValueFormat() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_ValueFormat) + sizeof(m_ValueFormat))
		return 0;

	return m_ValueFormat;
}

/*==========================================================================*/
float DTC_VLS::s_TradeOrder::GetPriceMultiplier() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_PriceMultiplier) + sizeof(m_PriceMultiplier))
		return 0;

	return m_PriceMultiplier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetParentInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_ParentInternalOrderID) + sizeof(m_ParentInternalOrderID))
		return 0;

	return m_ParentInternalOrderID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetTargetChildInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TargetChildInternalOrderID) + sizeof(m_TargetChildInternalOrderID))
		return 0;

	return m_TargetChildInternalOrderID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetStopChildInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_StopChildInternalOrderID) + sizeof(m_StopChildInternalOrderID))
		return 0;

	return m_StopChildInternalOrderID;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetAttachedOrderPriceOffset1() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_AttachedOrderPriceOffset1) + sizeof(m_AttachedOrderPriceOffset1))
		return 0;

	return m_AttachedOrderPriceOffset1;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetLinkInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LinkInternalOrderID) + sizeof(m_LinkInternalOrderID))
		return 0;

	return m_LinkInternalOrderID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetOCOGroupInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OCOGroupInternalOrderID) + sizeof(m_OCOGroupInternalOrderID))
		return 0;

	return m_OCOGroupInternalOrderID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetOCOSiblingInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OCOSiblingInternalOrderID) + sizeof(m_OCOSiblingInternalOrderID))
		return 0;

	return m_OCOSiblingInternalOrderID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetDisableChildAndSiblingRelatedActions() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_DisableChildAndSiblingRelatedActions) + sizeof(m_DisableChildAndSiblingRelatedActions))
		return 0;

	return m_DisableChildAndSiblingRelatedActions;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetOCOManagedByService() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OCOManagedByService) + sizeof(m_OCOManagedByService))
		return 0;

	return m_OCOManagedByService;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetBracketOrderServerManaged() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_BracketOrderServerManaged) + sizeof(m_BracketOrderServerManaged))
		return 0;

	return m_BracketOrderServerManaged;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetStopLimitOrderStopPriceTriggered() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_StopLimitOrderStopPriceTriggered) + sizeof(m_StopLimitOrderStopPriceTriggered))
		return 0;

	return m_StopLimitOrderStopPriceTriggered;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetOCOFullSiblingCancelOnPartialFill() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OCOFullSiblingCancelOnPartialFill) + sizeof(m_OCOFullSiblingCancelOnPartialFill))
		return 0;

	return m_OCOFullSiblingCancelOnPartialFill;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetReverseOnCompleteFill() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_ReverseOnCompleteFill) + sizeof(m_ReverseOnCompleteFill))
		return 0;

	return m_ReverseOnCompleteFill;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetSupportScaleIn() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SupportScaleIn) + sizeof(m_SupportScaleIn))
		return 0;

	return m_SupportScaleIn;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetSupportScaleOut() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SupportScaleOut) + sizeof(m_SupportScaleOut))
		return 0;

	return m_SupportScaleOut;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetSourceChartNumber() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SourceChartNumber) + sizeof(m_SourceChartNumber))
		return 0;

	return m_SourceChartNumber;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsAutomatedOrder() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsAutomatedOrder) + sizeof(m_IsAutomatedOrder))
		return 0;

	return m_IsAutomatedOrder;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetSimulatedOrder() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SimulatedOrder) + sizeof(m_SimulatedOrder))
		return 0;

	return m_SimulatedOrder;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsChartReplaying() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsChartReplaying) + sizeof(m_IsChartReplaying))
		return 0;

	return m_IsChartReplaying;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetAttachedOrderOCOGroupNumber() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_AttachedOrderOCOGroupNumber) + sizeof(m_AttachedOrderOCOGroupNumber))
		return 0;

	return m_AttachedOrderOCOGroupNumber;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetFillCount() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_FillCount) + sizeof(m_FillCount))
		return 0;

	return m_FillCount;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetLastFillQuantity() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastFillQuantity) + sizeof(m_LastFillQuantity))
		return 0;

	return m_LastFillQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetLastFillPrice() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastFillPrice) + sizeof(m_LastFillPrice))
		return 0;

	return m_LastFillPrice;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetLastFillDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastFillDateTimeUTC) + sizeof(m_LastFillDateTimeUTC))
		return 0;

	return m_LastFillDateTimeUTC;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeOrder::GetRejectedStopOCOSiblingInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_RejectedStopOCOSiblingInternalOrderID) + sizeof(m_RejectedStopOCOSiblingInternalOrderID))
		return 0;

	return m_RejectedStopOCOSiblingInternalOrderID;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetRejectedStopReplacementMarketOrderQuantity() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_RejectedStopReplacementMarketOrderQuantity) + sizeof(m_RejectedStopReplacementMarketOrderQuantity))
		return 0;

	return m_RejectedStopReplacementMarketOrderQuantity;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetEvaluatingForFill() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_EvaluatingForFill) + sizeof(m_EvaluatingForFill))
		return 0;

	return m_EvaluatingForFill;
}

/*==========================================================================*/
unsigned int DTC_VLS::s_TradeOrder::GetLastProcessedTimeSalesRecordSequenceForPrices() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastProcessedTimeSalesRecordSequenceForPrices) + sizeof(m_LastProcessedTimeSalesRecordSequenceForPrices))
		return 0;

	return m_LastProcessedTimeSalesRecordSequenceForPrices;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsMarketDataManagementOfOrderEnabled() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsMarketDataManagementOfOrderEnabled) + sizeof(m_IsMarketDataManagementOfOrderEnabled))
		return 0;

	return m_IsMarketDataManagementOfOrderEnabled;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetTimedOutOrderRequestedStatusDateTime() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_TimedOutOrderRequestedStatusDateTime) + sizeof(m_TimedOutOrderRequestedStatusDateTime))
		return 0;

	return m_TimedOutOrderRequestedStatusDateTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetRequestedStatusForTimedOutOrder() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_RequestedStatusForTimedOutOrder) + sizeof(m_RequestedStatusForTimedOutOrder))
		return 0;

	return m_RequestedStatusForTimedOutOrder;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetSendFlattenMarketOrderWhenRelatedOrdersConfirmedCanceled() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SendFlattenMarketOrderWhenRelatedOrdersConfirmedCanceled) + sizeof(m_SendFlattenMarketOrderWhenRelatedOrdersConfirmedCanceled))
		return 0;

	return m_SendFlattenMarketOrderWhenRelatedOrdersConfirmedCanceled;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetQuantityToIncreaseFromParentFill() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_QuantityToIncreaseFromParentFill) + sizeof(m_QuantityToIncreaseFromParentFill))
		return 0;

	return m_QuantityToIncreaseFromParentFill;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetMoveToBreakevenStopReferencePrice() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_MoveToBreakevenStopReferencePrice) + sizeof(m_MoveToBreakevenStopReferencePrice))
		return 0;

	return m_MoveToBreakevenStopReferencePrice;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetQuantityTriggeredStop_QuantityForTrigger() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_QuantityTriggeredStop_QuantityForTrigger) + sizeof(m_QuantityTriggeredStop_QuantityForTrigger))
		return 0;

	return m_QuantityTriggeredStop_QuantityForTrigger;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetAccumulatedTradeVolumeForTriggeredStop() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_AccumulatedTradeVolumeForTriggeredStop) + sizeof(m_AccumulatedTradeVolumeForTriggeredStop))
		return 0;

	return m_AccumulatedTradeVolumeForTriggeredStop;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetBidAskQuantityStopInitialTriggerMet() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_BidAskQuantityStopInitialTriggerMet) + sizeof(m_BidAskQuantityStopInitialTriggerMet))
		return 0;

	return m_BidAskQuantityStopInitialTriggerMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetNeedToOverrideLock() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_NeedToOverrideLock) + sizeof(m_NeedToOverrideLock))
		return 0;

	return m_NeedToOverrideLock;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetCurrentMarketPrice() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_CurrentMarketPrice) + sizeof(m_CurrentMarketPrice))
		return 0;

	return m_CurrentMarketPrice;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetCurrentMarketDateTime() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_CurrentMarketDateTime) + sizeof(m_CurrentMarketDateTime))
		return 0;

	return m_CurrentMarketDateTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetSupportOrderFillBilling() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_SupportOrderFillBilling) + sizeof(m_SupportOrderFillBilling))
		return 0;

	return m_SupportOrderFillBilling;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsBillable() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsBillable) + sizeof(m_IsBillable))
		return 0;

	return m_IsBillable;
}

/*==========================================================================*/
int DTC_VLS::s_TradeOrder::GetQuantityForBilling() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_QuantityForBilling) + sizeof(m_QuantityForBilling))
		return 0;

	return m_QuantityForBilling;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeOrder::GetNumberOfFailedOrderModifications() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_NumberOfFailedOrderModifications) + sizeof(m_NumberOfFailedOrderModifications))
		return 0;

	return m_NumberOfFailedOrderModifications;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeOrder::GetDTCServerIndex() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_DTCServerIndex) + sizeof(m_DTCServerIndex))
		return 0;

	return m_DTCServerIndex;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeOrder::GetCTICode() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_CTICode) + sizeof(m_CTICode))
		return 0;

	return m_CTICode;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetObtainOrderActionDateTimeFromLastTradeTimeInChart() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_ObtainOrderActionDateTimeFromLastTradeTimeInChart) + sizeof(m_ObtainOrderActionDateTimeFromLastTradeTimeInChart))
		return 0;

	return m_ObtainOrderActionDateTimeFromLastTradeTimeInChart;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetMaximumShowQuantity() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_MaximumShowQuantity) + sizeof(m_MaximumShowQuantity))
		return 0;

	return m_MaximumShowQuantity;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetOrderSubmitted() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_OrderSubmitted) + sizeof(m_OrderSubmitted))
		return 0;

	return m_OrderSubmitted;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsSnapshot) + sizeof(m_IsSnapshot))
		return 0;

	return m_IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsFirstMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsFirstMessageInBatch) + sizeof(m_IsFirstMessageInBatch))
		return 0;

	return m_IsFirstMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeOrder::GetIsLastMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_IsLastMessageInBatch) + sizeof(m_IsLastMessageInBatch))
		return 0;

	return m_IsLastMessageInBatch;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeOrder::GetExternalLastActionDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_ExternalLastActionDateTimeUTC) + sizeof(m_ExternalLastActionDateTimeUTC))
		return 0;

	return m_ExternalLastActionDateTimeUTC;
}

/*==========================================================================*/
double DTC_VLS::s_TradeOrder::GetLastModifyPrice2() const
{
	if (BaseSize < offsetof(s_TradeOrder, m_LastModifyPrice2) + sizeof(m_LastModifyPrice2))
		return 0;

	return m_LastModifyPrice2;
}

/****************************************************************************/
//s_IndividualTradePosition

/*==========================================================================*/
uint16_t DTC_VLS::s_IndividualTradePosition::GetMessageSize() const
{	
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_IndividualTradePosition::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_IndividualTradePosition::GetIsSimulated() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_IsSimulated) + sizeof(m_IsSimulated))
		return 0;

	return m_IsSimulated;
}

/*==========================================================================*/
double DTC_VLS::s_IndividualTradePosition::GetQuantity() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_Quantity) + sizeof(m_Quantity))
		return 0;

	return m_Quantity;
}

/*==========================================================================*/
double DTC_VLS::s_IndividualTradePosition::GetPositionPrice() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_PositionPrice) + sizeof(m_PositionPrice))
		return 0;

	return m_PositionPrice;
}

/*==========================================================================*/
double DTC_VLS::s_IndividualTradePosition::GetOpenProfitLoss() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_OpenProfitLoss) + sizeof(m_OpenProfitLoss))
		return 0;

	return m_OpenProfitLoss;
}

/*==========================================================================*/
int64_t DTC_VLS::s_IndividualTradePosition::GetTradeDateTime() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_TradeDateTime) + sizeof(m_TradeDateTime))
		return 0;

	return m_TradeDateTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_IndividualTradePosition::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_IsSnapshot) + sizeof(m_IsSnapshot))
		return 0;

	return m_IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_IndividualTradePosition::GetIsFirstMessageInBatch() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_IsFirstMessageInBatch) + sizeof(m_IsFirstMessageInBatch))
		return 0;

	return m_IsFirstMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_IndividualTradePosition::GetIsLastMessageInBatch() const
{
	if (BaseSize < offsetof(s_IndividualTradePosition, m_IsLastMessageInBatch) + sizeof(m_IsLastMessageInBatch))
		return 0;

	return m_IsLastMessageInBatch;
}

/*==========================================================================*/
/****************************************************************************/
//s_TradePositionConsolidated

/*==========================================================================*/
uint16_t DTC_VLS::s_TradePositionConsolidated::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradePositionConsolidated::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradePositionConsolidated::GetIsDeleted() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_IsDeleted) + sizeof(m_IsDeleted))
		return 0;

	return m_IsDeleted;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradePositionConsolidated::GetIsSimulated() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_IsSimulated) + sizeof(m_IsSimulated))
		return 0;

	return m_IsSimulated;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetQuantity() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_Quantity) + sizeof(m_Quantity))
		return 0;

	return m_Quantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetAveragePrice() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_AveragePrice) + sizeof(m_AveragePrice))
		return 0;

	return m_AveragePrice;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetOpenProfitLoss() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_OpenProfitLoss) + sizeof(m_OpenProfitLoss))
		return 0;

	return m_OpenProfitLoss;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetDailyProfitLoss() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_DailyProfitLoss) + sizeof(m_DailyProfitLoss))
		return 0;

	return m_DailyProfitLoss;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradePositionConsolidated::GetLastDailyProfitLossResetDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_LastDailyProfitLossResetDateTimeUTC) + sizeof(m_LastDailyProfitLossResetDateTimeUTC))
		return 0;

	return m_LastDailyProfitLossResetDateTimeUTC;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetServicePositionQuantity() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_ServicePositionQuantity) + sizeof(m_ServicePositionQuantity))
		return 0;

	return m_ServicePositionQuantity;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradePositionConsolidated::GetPositionHasBeenUpdatedByService() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_PositionHasBeenUpdatedByService) + sizeof(m_PositionHasBeenUpdatedByService))
		return 0;

	return m_PositionHasBeenUpdatedByService;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetPriceHighDuringPosition() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_PriceHighDuringPosition) + sizeof(m_PriceHighDuringPosition))
		return 0;

	return m_PriceHighDuringPosition;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetPriceLowDuringPosition() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_PriceLowDuringPosition) + sizeof(m_PriceLowDuringPosition))
		return 0;

	return m_PriceLowDuringPosition;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetPriceLastDuringPosition() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_PriceLastDuringPosition) + sizeof(m_PriceLastDuringPosition))
		return 0;

	return m_PriceLastDuringPosition;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradePositionConsolidated::GetLastProcessedTimeAndSalesSequence() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_LastProcessedTimeAndSalesSequence) + sizeof(m_LastProcessedTimeAndSalesSequence))
		return 0;

	return m_LastProcessedTimeAndSalesSequence;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetTotalMarginRequirement() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_TotalMarginRequirement) + sizeof(m_TotalMarginRequirement))
		return 0;

	return m_TotalMarginRequirement;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradePositionConsolidated::GetInitialEntryDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_InitialEntryDateTimeUTC) + sizeof(m_InitialEntryDateTimeUTC))
		return 0;

	return m_InitialEntryDateTimeUTC;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradePositionConsolidated::GetIsFromDTCServerReplay() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_IsFromDTCServerReplay) + sizeof(m_IsFromDTCServerReplay))
		return 0;

	return m_IsFromDTCServerReplay;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradePositionConsolidated::GetMostRecentPositionIncreaseDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_MostRecentPositionIncreaseDateTimeUTC) + sizeof(m_MostRecentPositionIncreaseDateTimeUTC))
		return 0;

	return m_MostRecentPositionIncreaseDateTimeUTC;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradePositionConsolidated::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_IsSnapshot) + sizeof(m_IsSnapshot))
		return 0;

	return m_IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradePositionConsolidated::GetIsFirstMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_IsFirstMessageInBatch) + sizeof(m_IsFirstMessageInBatch))
		return 0;

	return m_IsFirstMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradePositionConsolidated::GetIsLastMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_IsLastMessageInBatch) + sizeof(m_IsLastMessageInBatch))
		return 0;

	return m_IsLastMessageInBatch;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetMarginRequirementFull() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_MarginRequirementFull) + sizeof(m_MarginRequirementFull))
		return 0;

	return m_MarginRequirementFull;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetMarginRequirementFullPositionsOnly() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_MarginRequirementFullPositionsOnly) + sizeof(m_MarginRequirementFullPositionsOnly))
		return 0;

	return m_MarginRequirementFullPositionsOnly;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetMaxPotentialPositionQuantity() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_MaxPotentialPositionQuantity) + sizeof(m_MaxPotentialPositionQuantity))
		return 0;

	return m_MaxPotentialPositionQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetQuantityAtEndOfDayCaptureTime() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_QuantityAtEndOfDayCaptureTime) + sizeof(m_QuantityAtEndOfDayCaptureTime))
		return 0;

	return m_QuantityAtEndOfDayCaptureTime;
}

/*==========================================================================*/
double DTC_VLS::s_TradePositionConsolidated::GetMarginRequirementPositionsOnly() const
{
	if (BaseSize < offsetof(s_TradePositionConsolidated, m_MarginRequirementPositionsOnly) + sizeof(m_MarginRequirementPositionsOnly))
		return 0;

	return m_MarginRequirementPositionsOnly;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeActivityData

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeActivityData::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeActivityData::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetActivityType() const
{
	if (BaseSize < offsetof(s_TradeActivityData, ActivityType) + sizeof(ActivityType))
		return 0;

	return ActivityType;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeActivityData::GetDataDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradeActivityData, DataDateTimeUTC) + sizeof(DataDateTimeUTC))
		return 0;

	return DataDateTimeUTC;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeActivityData::GetInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeActivityData, InternalOrderID) + sizeof(InternalOrderID))
		return 0;

	return InternalOrderID;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetQuantity() const
{
	if (BaseSize < offsetof(s_TradeActivityData, Quantity) + sizeof(Quantity))
		return 0;

	return Quantity;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetBuySell() const
{
	if (BaseSize < offsetof(s_TradeActivityData, BuySell) + sizeof(BuySell))
		return 0;

	return BuySell;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetPrice1() const
{
	if (BaseSize < offsetof(s_TradeActivityData, Price1) + sizeof(Price1))
		return 0;

	return Price1;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetPrice2() const
{
	if (BaseSize < offsetof(s_TradeActivityData, Price2) + sizeof(Price2))
		return 0;

	return Price2;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetNewOrderStatus() const
{
	if (BaseSize < offsetof(s_TradeActivityData, NewOrderStatus) + sizeof(NewOrderStatus))
		return 0;

	return NewOrderStatus;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetFillPrice() const
{
	if (BaseSize < offsetof(s_TradeActivityData, FillPrice) + sizeof(FillPrice))
		return 0;

	return FillPrice;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetOrderFilledQuantity() const
{
	if (BaseSize < offsetof(s_TradeActivityData, OrderFilledQuantity) + sizeof(OrderFilledQuantity))
		return 0;

	return OrderFilledQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetHighPriceDuringPosition() const
{
	if (BaseSize < offsetof(s_TradeActivityData, HighPriceDuringPosition) + sizeof(HighPriceDuringPosition))
		return 0;

	return HighPriceDuringPosition;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetLowPriceDuringPosition() const
{
	if (BaseSize < offsetof(s_TradeActivityData, LowPriceDuringPosition) + sizeof(LowPriceDuringPosition))
		return 0;

	return LowPriceDuringPosition;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetLastPriceDuringPosition() const
{
	if (BaseSize < offsetof(s_TradeActivityData, LastPriceDuringPosition) + sizeof(LastPriceDuringPosition))
		return 0;

	return LastPriceDuringPosition;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeActivityData::GetParentInternalOrderID() const
{
	if (BaseSize < offsetof(s_TradeActivityData, ParentInternalOrderID) + sizeof(ParentInternalOrderID))
		return 0;

	return ParentInternalOrderID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetOpenClose() const
{
	if (BaseSize < offsetof(s_TradeActivityData, OpenClose) + sizeof(OpenClose))
		return 0;

	return OpenClose;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetIsSimulated() const
{
	if (BaseSize < offsetof(s_TradeActivityData, IsSimulated) + sizeof(IsSimulated))
		return 0;

	return IsSimulated;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetIsAutomatedOrder() const
{
	if (BaseSize < offsetof(s_TradeActivityData, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
		return 0;

	return IsAutomatedOrder;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetIsChartReplaying() const
{
	if (BaseSize < offsetof(s_TradeActivityData, IsChartReplaying) + sizeof(IsChartReplaying))
		return 0;

	return IsChartReplaying;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetPositionQuantity() const
{
	if (BaseSize < offsetof(s_TradeActivityData, PositionQuantity) + sizeof(PositionQuantity))
		return 0;

	return PositionQuantity;
}

/*==========================================================================*/
int DTC_VLS::s_TradeActivityData::GetSourceChartNumber() const
{
	if (BaseSize < offsetof(s_TradeActivityData, SourceChartNumber) + sizeof(SourceChartNumber))
		return 0;

	return SourceChartNumber;
}

/*==========================================================================*/
int DTC_VLS::s_TradeActivityData::GetTimeInForce() const
{
	if (BaseSize < offsetof(s_TradeActivityData, TimeInForce) + sizeof(TimeInForce))
		return 0;

	return TimeInForce;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetTradeAccountBalance() const
{
	if (BaseSize < offsetof(s_TradeActivityData, TradeAccountBalance) + sizeof(TradeAccountBalance))
		return 0;

	return TradeAccountBalance;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetSupportsPositionQuantityField() const
{
	if (BaseSize < offsetof(s_TradeActivityData, SupportsPositionQuantityField) + sizeof(SupportsPositionQuantityField))
		return 0;

	return SupportsPositionQuantityField;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetIsBillable() const
{
	if (BaseSize < offsetof(s_TradeActivityData, IsBillable) + sizeof(IsBillable))
		return 0;

	return IsBillable;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeActivityData::GetQuantityForBilling() const
{
	if (BaseSize < offsetof(s_TradeActivityData, QuantityForBilling) + sizeof(QuantityForBilling))
		return 0;

	return QuantityForBilling;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeActivityData::GetSubAccountIdentifier() const
{
	if (BaseSize < offsetof(s_TradeActivityData, SubAccountIdentifier) + sizeof(SubAccountIdentifier))
		return 0;

	return SubAccountIdentifier;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeActivityData::GetAuditTrail_TransactDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_TransactDateTimeUTC) + sizeof(AuditTrail_TransactDateTimeUTC))
		return 0;

	return AuditTrail_TransactDateTimeUTC;
}

/*==========================================================================*/
int DTC_VLS::s_TradeActivityData::GetAuditTrail_MessageDirection() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_MessageDirection) + sizeof(AuditTrail_MessageDirection))
		return 0;

	return AuditTrail_MessageDirection;
}

/*==========================================================================*/
int16_t DTC_VLS::s_TradeActivityData::GetAuditTrail_CustomerTypeIndicator() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_CustomerTypeIndicator) + sizeof(AuditTrail_CustomerTypeIndicator))
		return 0;

	return AuditTrail_CustomerTypeIndicator;
}

/*==========================================================================*/
int16_t DTC_VLS::s_TradeActivityData::GetAuditTrail_CustomerOrFirm() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_CustomerOrFirm) + sizeof(AuditTrail_CustomerOrFirm))
		return 0;

	return AuditTrail_CustomerOrFirm;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetAuditTrail_IFMFlag() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_IFMFlag) + sizeof(AuditTrail_IFMFlag))
		return 0;

	return AuditTrail_IFMFlag;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetAuditTrail_DisplayQuantity() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_DisplayQuantity) + sizeof(AuditTrail_DisplayQuantity))
		return 0;

	return AuditTrail_DisplayQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetAuditTrail_FillQuantity() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_FillQuantity) + sizeof(AuditTrail_FillQuantity))
		return 0;

	return AuditTrail_FillQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetAuditTrail_RemainingQuantity() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_RemainingQuantity) + sizeof(AuditTrail_RemainingQuantity))
		return 0;

	return AuditTrail_RemainingQuantity;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetAuditTrail_AggressorFlag() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_AggressorFlag) + sizeof(AuditTrail_AggressorFlag))
		return 0;

	return AuditTrail_AggressorFlag;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeActivityData::GetAuditTrail_SourceOfCancellation() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_SourceOfCancellation) + sizeof(AuditTrail_SourceOfCancellation))
		return 0;

	return AuditTrail_SourceOfCancellation;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_TradeActivityData, IsSnapshot) + sizeof(IsSnapshot))
		return 0;

	return IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetIsFirstMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeActivityData, IsFirstMessageInBatch) + sizeof(IsFirstMessageInBatch))
		return 0;

	return IsFirstMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeActivityData::GetIsLastMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeActivityData, IsLastMessageInBatch) + sizeof(IsLastMessageInBatch))
		return 0;

	return IsLastMessageInBatch;
}

/*==========================================================================*/
double DTC_VLS::s_TradeActivityData::GetAuditTrail_MinimumQuantity() const
{
	if (BaseSize < offsetof(s_TradeActivityData, AuditTrail_MinimumQuantity) + sizeof(AuditTrail_MinimumQuantity))
		return 0.0;

	return AuditTrail_MinimumQuantity;
}

/*==========================================================================*/

/****************************************************************************/
//s_RequestTradeAccountData

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataRequest::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataRequest::GetBaseSize() const
{
	return BaseSize;
}
/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataRequest::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataRequest, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_RequestID) + sizeof(m_RequestID))
		return 0;

	return m_RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetTradeAccountNotExist() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_TradeAccountNotExist) + sizeof(m_TradeAccountNotExist))
		return 0;

	return m_TradeAccountNotExist;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsSimulated() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsSimulated) + sizeof(m_IsSimulated))
		return 0;

	return m_IsSimulated;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetCurrentCashBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_CurrentCashBalance) + sizeof(m_CurrentCashBalance))
		return 0;

	return m_CurrentCashBalance;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetAvailableFundsForNewPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_AvailableFundsForNewPositions) + sizeof(m_AvailableFundsForNewPositions))
		return 0;

	return m_AvailableFundsForNewPositions;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetMarginRequirement() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MarginRequirement) + sizeof(m_MarginRequirement))
		return 0;

	return m_MarginRequirement;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetAccountValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_AccountValue) + sizeof(m_AccountValue))
		return 0;

	return m_AccountValue;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetOpenPositionsProfitLoss() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_OpenPositionsProfitLoss) + sizeof(m_OpenPositionsProfitLoss))
		return 0;

	return m_OpenPositionsProfitLoss;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetDailyProfitLoss() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_DailyProfitLoss) + sizeof(m_DailyProfitLoss))
		return 0;

	return m_DailyProfitLoss;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeAccountDataResponse::GetTransactionIdentifierForCashBalanceAdjustment() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_TransactionIdentifierForCashBalanceAdjustment) + sizeof(m_TransactionIdentifierForCashBalanceAdjustment))
		return 0;

	return m_TransactionIdentifierForCashBalanceAdjustment;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetLastTransactionDateTime() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_LastTransactionDateTime) + sizeof(m_LastTransactionDateTime))
		return 0;

	return m_LastTransactionDateTime;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetTrailingAccountValueAtWhichToNotAllowNewPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_TrailingAccountValueAtWhichToNotAllowNewPositions) + sizeof(m_TrailingAccountValueAtWhichToNotAllowNewPositions))
		return 0;

	return m_TrailingAccountValueAtWhichToNotAllowNewPositions;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetCalculatedDailyNetLossLimitInAccountCurrency() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_CalculatedDailyNetLossLimitInAccountCurrency) + sizeof(m_CalculatedDailyNetLossLimitInAccountCurrency))
		return 0;

	return m_CalculatedDailyNetLossLimitInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetDailyNetLossLimitHasBeenReached() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_DailyNetLossLimitHasBeenReached) + sizeof(m_DailyNetLossLimitHasBeenReached))
		return 0;

	return m_DailyNetLossLimitHasBeenReached;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetLastResetDailyNetLossManagementVariablesDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_LastResetDailyNetLossManagementVariablesDateTimeUTC) + sizeof(m_LastResetDailyNetLossManagementVariablesDateTimeUTC))
		return 0;

	return m_LastResetDailyNetLossManagementVariablesDateTimeUTC;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsUnderRequiredMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsUnderRequiredMargin) + sizeof(m_IsUnderRequiredMargin))
		return 0;

	return m_IsUnderRequiredMargin;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataResponse::GetDailyNetLossLimitInAccountCurrency() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_DailyNetLossLimitInAccountCurrency) + sizeof(m_DailyNetLossLimitInAccountCurrency))
		return 0;

	return m_DailyNetLossLimitInAccountCurrency;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataResponse::GetPercentOfAccountValueForDailyNetLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_PercentOfAccountValueForDailyNetLossLimit) + sizeof(m_PercentOfAccountValueForDailyNetLossLimit))
		return 0;

	return m_PercentOfAccountValueForDailyNetLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseTrailingAccountValueToNotAllowIncreaseInPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseTrailingAccountValueToNotAllowIncreaseInPositions) + sizeof(m_UseTrailingAccountValueToNotAllowIncreaseInPositions))
		return 0;

	return m_UseTrailingAccountValueToNotAllowIncreaseInPositions;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetDoNotAllowIncreaseInPositionsAtDailyLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_DoNotAllowIncreaseInPositionsAtDailyLossLimit) + sizeof(m_DoNotAllowIncreaseInPositionsAtDailyLossLimit))
		return 0;

	return m_DoNotAllowIncreaseInPositionsAtDailyLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetFlattenPositionsAtDailyLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FlattenPositionsAtDailyLossLimit) + sizeof(m_FlattenPositionsAtDailyLossLimit))
		return 0;

	return m_FlattenPositionsAtDailyLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetClosePositionsAtEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_ClosePositionsAtEndOfDay) + sizeof(m_ClosePositionsAtEndOfDay))
		return 0;

	return m_ClosePositionsAtEndOfDay;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetFlattenPositionsWhenUnderMarginIntraday() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FlattenPositionsWhenUnderMarginIntraday) + sizeof(m_FlattenPositionsWhenUnderMarginIntraday))
		return 0;

	return m_FlattenPositionsWhenUnderMarginIntraday;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetFlattenPositionsWhenUnderMarginAtEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FlattenPositionsWhenUnderMarginAtEndOfDay) + sizeof(m_FlattenPositionsWhenUnderMarginAtEndOfDay))
		return 0;

	return m_FlattenPositionsWhenUnderMarginAtEndOfDay;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataResponse::GetCTICode() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_CTICode) + sizeof(m_CTICode))
		return 0;

	return m_CTICode;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetTradeAccountIsReadOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_TradeAccountIsReadOnly) + sizeof(m_TradeAccountIsReadOnly))
		return 0;

	return m_TradeAccountIsReadOnly;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataResponse::GetMaximumGlobalPositionQuantity() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MaximumGlobalPositionQuantity) + sizeof(m_MaximumGlobalPositionQuantity))
		return 0;

	return m_MaximumGlobalPositionQuantity;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetTradeFeePerContract() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_TradeFeePerContract) + sizeof(m_TradeFeePerContract))
		return 0;

	return m_TradeFeePerContract;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetTradeFeePerShare() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_TradeFeePerShare) + sizeof(m_TradeFeePerShare))
		return 0;

	return m_TradeFeePerShare;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetRequireSufficientMarginForNewPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_RequireSufficientMarginForNewPositions) + sizeof(m_RequireSufficientMarginForNewPositions))
		return 0;

	return m_RequireSufficientMarginForNewPositions;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataResponse::GetUsePercentOfMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UsePercentOfMargin) + sizeof(m_UsePercentOfMargin))
		return 0;

	return m_UsePercentOfMargin;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataResponse::GetUsePercentOfMarginForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UsePercentOfMarginForDayTrading) + sizeof(m_UsePercentOfMarginForDayTrading))
		return 0;

	return m_UsePercentOfMarginForDayTrading;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataResponse::GetMaximumAllowedAccountBalanceForPositionsAsPercentage() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MaximumAllowedAccountBalanceForPositionsAsPercentage) + sizeof(m_MaximumAllowedAccountBalanceForPositionsAsPercentage))
		return 0;

	return m_MaximumAllowedAccountBalanceForPositionsAsPercentage;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetTradingIsDisabled() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_TradingIsDisabled) + sizeof(m_TradingIsDisabled))
		return 0;

	return m_TradingIsDisabled;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsMasterFirmControlAccount() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsMasterFirmControlAccount) + sizeof(m_IsMasterFirmControlAccount))
		return 0;

	return m_IsMasterFirmControlAccount;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetMinimumRequiredAccountValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MinimumRequiredAccountValue) + sizeof(m_MinimumRequiredAccountValue))
		return 0;

	return m_MinimumRequiredAccountValue;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetBeginTimeForDayMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_BeginTimeForDayMargin) + sizeof(m_BeginTimeForDayMargin))
		return 0;

	return m_BeginTimeForDayMargin;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetEndTimeForDayMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_EndTimeForDayMargin) + sizeof(m_EndTimeForDayMargin))
		return 0;

	return m_EndTimeForDayMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsSnapshot) + sizeof(m_IsSnapshot))
		return 0;

	return m_IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsFirstMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsFirstMessageInBatch) + sizeof(m_IsFirstMessageInBatch))
		return 0;

	return m_IsFirstMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsLastMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsLastMessageInBatch) + sizeof(m_IsLastMessageInBatch))
		return 0;

	return m_IsLastMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsDeleted() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsDeleted) + sizeof(m_IsDeleted))
		return 0;

	return m_IsDeleted;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_FlattenPositionsWhenUnderMarginIntraday() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday) + sizeof(m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday))
		return 0;

	return m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay) + sizeof(m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay))
		return 0;

	return m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_TradeFees() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_TradeFees) + sizeof(m_UseMasterFirm_TradeFees))
		return 0;

	return m_UseMasterFirm_TradeFees;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_RequireSufficientMarginForNewPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_RequireSufficientMarginForNewPositions) + sizeof(m_UseMasterFirm_RequireSufficientMarginForNewPositions))
		return 0;

	return m_UseMasterFirm_RequireSufficientMarginForNewPositions;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_UsePercentOfMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_UsePercentOfMargin) + sizeof(m_UseMasterFirm_UsePercentOfMargin))
		return 0;

	return m_UseMasterFirm_UsePercentOfMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage) + sizeof(m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage))
		return 0;

	return m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_MinimumRequiredAccountValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_MinimumRequiredAccountValue) + sizeof(m_UseMasterFirm_MinimumRequiredAccountValue))
		return 0;

	return m_UseMasterFirm_MinimumRequiredAccountValue;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_MarginTimeSettings() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_MarginTimeSettings) + sizeof(m_UseMasterFirm_MarginTimeSettings))
		return 0;

	return m_UseMasterFirm_MarginTimeSettings;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_TradingIsDisabled() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_TradingIsDisabled) + sizeof(m_UseMasterFirm_TradingIsDisabled))
		return 0;

	return m_UseMasterFirm_TradingIsDisabled;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsTradeStatisticsPublicallyShared() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsTradeStatisticsPublicallyShared) + sizeof(m_IsTradeStatisticsPublicallyShared))
		return 0;

	return m_IsTradeStatisticsPublicallyShared;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsReadOnlyFollowingRequestsAllowed() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsReadOnlyFollowingRequestsAllowed) + sizeof(m_IsReadOnlyFollowingRequestsAllowed))
		return 0;

	return m_IsReadOnlyFollowingRequestsAllowed;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetIsTradeAccountSharingAllowed() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_IsTradeAccountSharingAllowed) + sizeof(m_IsTradeAccountSharingAllowed))
		return 0;

	return m_IsTradeAccountSharingAllowed;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetReadOnlyShareToAllSCUsernames() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_ReadOnlyShareToAllSCUsernames) + sizeof(m_ReadOnlyShareToAllSCUsernames))
		return 0;

	return m_ReadOnlyShareToAllSCUsernames;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_SymbolCommissionsArray() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_SymbolCommissionsArray) + sizeof(m_UseMasterFirm_SymbolCommissionsArray))
		return 0;

	return m_UseMasterFirm_SymbolCommissionsArray;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit) + sizeof(m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit))
		return 0;

	return m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_UsePercentOfMarginForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_UsePercentOfMarginForDayTrading) + sizeof(m_UseMasterFirm_UsePercentOfMarginForDayTrading))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForDayTrading;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetOpenPositionsProfitLossBasedOnSettlement() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_OpenPositionsProfitLossBasedOnSettlement) + sizeof(m_OpenPositionsProfitLossBasedOnSettlement))
		return 0;

	return m_OpenPositionsProfitLossBasedOnSettlement;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetMarginRequirementFull() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MarginRequirementFull) + sizeof(m_MarginRequirementFull))
		return 0;

	return m_MarginRequirementFull;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetMarginRequirementFullPositionsOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MarginRequirementFullPositionsOnly) + sizeof(m_MarginRequirementFullPositionsOnly))
		return 0;

	return m_MarginRequirementFullPositionsOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_TradeFeesFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_TradeFeesFullOverride) + sizeof(m_UseMasterFirm_TradeFeesFullOverride))
		return 0;

	return m_UseMasterFirm_TradeFeesFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders) + sizeof(m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders))
		return 0;

	return m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_UsePercentOfMarginFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_UsePercentOfMarginFullOverride) + sizeof(m_UseMasterFirm_UsePercentOfMarginFullOverride))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_UsePercentOfMarginForDayTradingFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride) + sizeof(m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetPeakMarginRequirement() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_PeakMarginRequirement) + sizeof(m_PeakMarginRequirement))
		return 0;

	return m_PeakMarginRequirement;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetLiquidationOnlyMode() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_LiquidationOnlyMode) + sizeof(m_LiquidationOnlyMode))
		return 0;

	return m_LiquidationOnlyMode;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetFlattenPositionsWhenUnderMarginIntradayTriggered() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FlattenPositionsWhenUnderMarginIntradayTriggered) + sizeof(m_FlattenPositionsWhenUnderMarginIntradayTriggered))
		return 0;

	return m_FlattenPositionsWhenUnderMarginIntradayTriggered;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetFlattenPositionsWhenUnderMinimumAccountValueTriggered() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FlattenPositionsWhenUnderMinimumAccountValueTriggered) + sizeof(m_FlattenPositionsWhenUnderMinimumAccountValueTriggered))
		return 0;

	return m_FlattenPositionsWhenUnderMinimumAccountValueTriggered;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetAccountValueAtEndOfDayCaptureTime() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_AccountValueAtEndOfDayCaptureTime) + sizeof(m_AccountValueAtEndOfDayCaptureTime))
		return 0;

	return m_AccountValueAtEndOfDayCaptureTime;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetEndOfDayCaptureTime() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_EndOfDayCaptureTime) + sizeof(m_EndOfDayCaptureTime))
		return 0;

	return m_EndOfDayCaptureTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetCustomerOrFirm() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_CustomerOrFirm) + sizeof(m_CustomerOrFirm))
		return 0;

	return m_CustomerOrFirm;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetMasterFirm_FlattenCancelAccountWhenDailyLossLimitMet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet) + sizeof(m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet))
		return 0;

	return m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetMasterFirm_FlattenCancelWhenUnderMinimumAccountValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetMasterFirm_FlattenCancelWhenUnderMarginIntraday() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MasterFirm_FlattenCancelWhenUnderMarginIntraday) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMarginIntraday))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMarginIntraday;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetMasterFirm_FlattenCancelWhenUnderMarginEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataResponse::GetMasterFirm_MaximumOrderQuantity() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MasterFirm_MaximumOrderQuantity) + sizeof(m_MasterFirm_MaximumOrderQuantity))
		return 0;

	return m_MasterFirm_MaximumOrderQuantity;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetLastTriggerDateTimeUTCForDailyLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_LastTriggerDateTimeUTCForDailyLossLimit) + sizeof(m_LastTriggerDateTimeUTCForDailyLossLimit))
		return 0;

	return m_LastTriggerDateTimeUTCForDailyLossLimit;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetProfitLossForOpenPositionDateTimeUTC() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_ProfitLossForOpenPositionDateTimeUTC) + sizeof(m_ProfitLossForOpenPositionDateTimeUTC))
		return 0;

	return m_ProfitLossForOpenPositionDateTimeUTC;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseFixedCashOnHandBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseFixedCashOnHandBalance) + sizeof(m_UseFixedCashOnHandBalance))
		return 0;

	return m_UseFixedCashOnHandBalance;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataResponse::GetFixedCashOnHandBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FixedCashOnHandBalance) + sizeof(m_FixedCashOnHandBalance))
		return 0;

	return m_FixedCashOnHandBalance;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetEndOfDayNetLiquidatingValueFromImportFile() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_EndOfDayNetLiquidatingValueFromImportFile) + sizeof(m_EndOfDayNetLiquidatingValueFromImportFile))
		return 0;

	return m_EndOfDayNetLiquidatingValueFromImportFile;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetRejectCrossingOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_RejectCrossingOrders) + sizeof(m_RejectCrossingOrders))
		return 0;

	return m_RejectCrossingOrders;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataResponse::GetMessageLimitPerTenSeconds() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MessageLimitPerTenSeconds) + sizeof(m_MessageLimitPerTenSeconds))
		return 0;

	return m_MessageLimitPerTenSeconds;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataResponse::GetLastTradeDateSource() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_LastTradeDateSource) + sizeof(m_LastTradeDateSource))
		return 0;

	return m_LastTradeDateSource;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetDisableTradingForParentAccountOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_DisableTradingForParentAccountOnly) + sizeof(m_DisableTradingForParentAccountOnly))
		return 0;

	return m_DisableTradingForParentAccountOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetSupportIntendedPositionOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_SupportIntendedPositionOrders) + sizeof(m_SupportIntendedPositionOrders))
		return 0;

	return m_SupportIntendedPositionOrders;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetMarginRecalculationTime1() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MarginRecalculationTime1) + sizeof(m_MarginRecalculationTime1))
		return 0;

	return m_MarginRecalculationTime1;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetMarginRecalculationTime2() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MarginRecalculationTime2) + sizeof(m_MarginRecalculationTime2))
		return 0;

	return m_MarginRecalculationTime2;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetClosePositionsAtEndOfDayTime() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_ClosePositionsAtEndOfDayTime) + sizeof(m_ClosePositionsAtEndOfDayTime))
		return 0;

	return m_ClosePositionsAtEndOfDayTime;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataResponse::GetUsePercentOfMarginForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UsePercentOfMarginForOvernightTrading) + sizeof(m_UsePercentOfMarginForOvernightTrading))
		return 0;

	return m_UsePercentOfMarginForOvernightTrading;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetBeginTimeForOvernightMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_BeginTimeForOvernightMargin) + sizeof(m_BeginTimeForOvernightMargin))
		return 0;

	return m_BeginTimeForOvernightMargin;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetEndTimeForOvernightMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_EndTimeForOvernightMargin) + sizeof(m_EndTimeForOvernightMargin))
		return 0;

	return m_EndTimeForOvernightMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_UsePercentOfMarginForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_UsePercentOfMarginForOvernightTrading) + sizeof(m_UseMasterFirm_UsePercentOfMarginForOvernightTrading))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForOvernightTrading;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride) + sizeof(m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetUseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum) + sizeof(m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum))
		return 0;

	return m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponse::GetMasterFirmSupportUserSetProfitLossManagement() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MasterFirm_SupportUserSetProfitLossManagement) + sizeof(m_MasterFirm_SupportUserSetProfitLossManagement))
	{
		return 0;
	}

	return m_MasterFirm_SupportUserSetProfitLossManagement;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetMarginRequirementPositionsOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_MarginRequirementPositionsOnly) + sizeof(m_MarginRequirementPositionsOnly))
	{
		return 0.0;
	}

	return m_MarginRequirementPositionsOnly;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataResponse::GetFundsOnHoldToDeductFromAccountBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FundsOnHoldToDeductFromAccountBalance) + sizeof(m_FundsOnHoldToDeductFromAccountBalance))
	{
		return 0.0;
	}

	return m_FundsOnHoldToDeductFromAccountBalance;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataResponse::GetFundsOnHoldExpirationDate() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponse, m_FundsOnHoldExpirationDate) + sizeof(m_FundsOnHoldExpirationDate))
	{
		return 0;
	}

	return m_FundsOnHoldExpirationDate;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataUpdate

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUpdate::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUpdate::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUpdate::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsNewAccount() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsNewAccount) + sizeof(IsNewAccount))
		return 0;

	return IsNewAccount;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetCurrencyCodeIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, CurrencyCodeIsSet) + sizeof(CurrencyCodeIsSet))
		return 0;

	return CurrencyCodeIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetDailyNetLossLimitInAccountCurrencyIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, DailyNetLossLimitInAccountCurrencyIsSet) + sizeof(DailyNetLossLimitInAccountCurrencyIsSet))
		return 0;

	return DailyNetLossLimitInAccountCurrencyIsSet;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataUpdate::GetDailyNetLossLimitInAccountCurrency() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, DailyNetLossLimitInAccountCurrency) + sizeof(DailyNetLossLimitInAccountCurrency))
		return 0;

	return DailyNetLossLimitInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetPercentOfCashBalanceForDailyNetLossLimitIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, PercentOfCashBalanceForDailyNetLossLimitIsSet) + sizeof(PercentOfCashBalanceForDailyNetLossLimitIsSet))
		return 0;

	return PercentOfCashBalanceForDailyNetLossLimitIsSet;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataUpdate::GetPercentOfCashBalanceForDailyNetLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, PercentOfCashBalanceForDailyNetLossLimit) + sizeof(PercentOfCashBalanceForDailyNetLossLimit))
		return 0;

	return PercentOfCashBalanceForDailyNetLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseTrailingAccountValueToNotAllowIncreaseInPositionsIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, UseTrailingAccountValueToNotAllowIncreaseInPositionsIsSet) + sizeof(UseTrailingAccountValueToNotAllowIncreaseInPositionsIsSet))
		return 0;

	return UseTrailingAccountValueToNotAllowIncreaseInPositionsIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseTrailingAccountValueToNotAllowIncreaseInPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, UseTrailingAccountValueToNotAllowIncreaseInPositions) + sizeof(UseTrailingAccountValueToNotAllowIncreaseInPositions))
		return 0;

	return UseTrailingAccountValueToNotAllowIncreaseInPositions;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetDoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet) + sizeof(DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet))
		return 0;

	return DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetDoNotAllowIncreaseInPositionsAtDailyLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, DoNotAllowIncreaseInPositionsAtDailyLossLimit) + sizeof(DoNotAllowIncreaseInPositionsAtDailyLossLimit))
		return 0;

	return DoNotAllowIncreaseInPositionsAtDailyLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFlattenPositionsAtDailyLossLimitIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, FlattenPositionsAtDailyLossLimitIsSet) + sizeof(FlattenPositionsAtDailyLossLimitIsSet))
		return 0;

	return FlattenPositionsAtDailyLossLimitIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFlattenPositionsAtDailyLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, FlattenPositionsAtDailyLossLimit) + sizeof(FlattenPositionsAtDailyLossLimit))
		return 0;

	return FlattenPositionsAtDailyLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetClosePositionsAtEndOfDayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, ClosePositionsAtEndOfDayIsSet) + sizeof(ClosePositionsAtEndOfDayIsSet))
		return 0;

	return ClosePositionsAtEndOfDayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetClosePositionsAtEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, ClosePositionsAtEndOfDay) + sizeof(ClosePositionsAtEndOfDay))
		return 0;

	return ClosePositionsAtEndOfDay;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFlattenPositionsWhenUnderMarginIntradayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, FlattenPositionsWhenUnderMarginIntradayIsSet) + sizeof(FlattenPositionsWhenUnderMarginIntradayIsSet))
		return 0;

	return FlattenPositionsWhenUnderMarginIntradayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFlattenPositionsWhenUnderMarginIntraday() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, FlattenPositionsWhenUnderMarginIntraday) + sizeof(FlattenPositionsWhenUnderMarginIntraday))
		return 0;

	return FlattenPositionsWhenUnderMarginIntraday;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFlattenPositionsWhenUnderMarginAtEndOfDayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, FlattenPositionsWhenUnderMarginAtEndOfDayIsSet) + sizeof(FlattenPositionsWhenUnderMarginAtEndOfDayIsSet))
		return 0;

	return FlattenPositionsWhenUnderMarginAtEndOfDayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFlattenPositionsWhenUnderMarginAtEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, FlattenPositionsWhenUnderMarginAtEndOfDay) + sizeof(FlattenPositionsWhenUnderMarginAtEndOfDay))
		return 0;

	return FlattenPositionsWhenUnderMarginAtEndOfDay;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSenderSubIDIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, SenderSubIDIsSet) + sizeof(SenderSubIDIsSet))
		return 0;

	return SenderSubIDIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSenderLocationIdIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, SenderLocationIdIsSet) + sizeof(SenderLocationIdIsSet))
		return 0;

	return SenderLocationIdIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSelfMatchPreventionIDIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, SelfMatchPreventionIDIsSet) + sizeof(SelfMatchPreventionIDIsSet))
		return 0;

	return SelfMatchPreventionIDIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetCTICodeIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, CTICodeIsSet) + sizeof(CTICodeIsSet))
		return 0;

	return CTICodeIsSet;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataUpdate::GetCTICode() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, CTICode) + sizeof(CTICode))
		return 0;

	return CTICode;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetTradeAccountIsReadOnlyIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradeAccountIsReadOnlyIsSet) + sizeof(TradeAccountIsReadOnlyIsSet))
		return 0;

	return TradeAccountIsReadOnlyIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetTradeAccountIsReadOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradeAccountIsReadOnly) + sizeof(TradeAccountIsReadOnly))
		return 0;

	return TradeAccountIsReadOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMaximumGlobalPositionQuantityIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, MaximumGlobalPositionQuantityIsSet) + sizeof(MaximumGlobalPositionQuantityIsSet))
		return 0;

	return MaximumGlobalPositionQuantityIsSet;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataUpdate::GetMaximumGlobalPositionQuantity() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, MaximumGlobalPositionQuantity) + sizeof(MaximumGlobalPositionQuantity))
		return 0;

	return MaximumGlobalPositionQuantity;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetTradeFeePerContractIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradeFeePerContractIsSet) + sizeof(TradeFeePerContractIsSet))
		return 0;

	return TradeFeePerContractIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataUpdate::GetTradeFeePerContract() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradeFeePerContract) + sizeof(TradeFeePerContract))
		return 0;

	return TradeFeePerContract;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetTradeFeePerShareIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradeFeePerShareIsSet) + sizeof(TradeFeePerShareIsSet))
		return 0;

	return TradeFeePerShareIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataUpdate::GetTradeFeePerShare() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradeFeePerShare) + sizeof(TradeFeePerShare))
		return 0;

	return TradeFeePerShare;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetRequireSufficientMarginForNewPositionsIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, RequireSufficientMarginForNewPositionsIsSet) + sizeof(RequireSufficientMarginForNewPositionsIsSet))
		return 0;

	return RequireSufficientMarginForNewPositionsIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetRequireSufficientMarginForNewPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, RequireSufficientMarginForNewPositions) + sizeof(RequireSufficientMarginForNewPositions))
		return 0;

	return RequireSufficientMarginForNewPositions;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUsePercentOfMarginIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, UsePercentOfMarginIsSet) + sizeof(UsePercentOfMarginIsSet))
		return 0;

	return UsePercentOfMarginIsSet;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataUpdate::GetUsePercentOfMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, UsePercentOfMargin) + sizeof(UsePercentOfMargin))
		return 0;

	return UsePercentOfMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUsePercentOfMarginForDayTradingIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, UsePercentOfMarginForDayTradingIsSet) + sizeof(UsePercentOfMarginForDayTradingIsSet))
		return 0;

	return UsePercentOfMarginForDayTradingIsSet;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataUpdate::GetUsePercentOfMarginForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, UsePercentOfMarginForDayTrading) + sizeof(UsePercentOfMarginForDayTrading))
		return 0;

	return UsePercentOfMarginForDayTrading;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMaximumAllowedAccountBalanceForPositionsAsPercentageIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet) + sizeof(MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet))
		return 0;

	return MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataUpdate::GetMaximumAllowedAccountBalanceForPositionsAsPercentage() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, MaximumAllowedAccountBalanceForPositionsAsPercentage) + sizeof(MaximumAllowedAccountBalanceForPositionsAsPercentage))
		return 0;

	return MaximumAllowedAccountBalanceForPositionsAsPercentage;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFirmIDIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, FirmIDIsSet) + sizeof(FirmIDIsSet))
		return 0;

	return FirmIDIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetTradingIsDisabledIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradingIsDisabledIsSet) + sizeof(TradingIsDisabledIsSet))
		return 0;

	return TradingIsDisabledIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetTradingIsDisabled() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, TradingIsDisabled) + sizeof(TradingIsDisabled))
		return 0;

	return TradingIsDisabled;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetDescriptiveNameIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, DescriptiveNameIsSet) + sizeof(DescriptiveNameIsSet))
		return 0;

	return DescriptiveNameIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsMasterFirmControlAccountIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsMasterFirmControlAccountIsSet) + sizeof(IsMasterFirmControlAccountIsSet))
		return 0;

	return IsMasterFirmControlAccountIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsMasterFirmControlAccount() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsMasterFirmControlAccount) + sizeof(IsMasterFirmControlAccount))
		return 0;

	return IsMasterFirmControlAccount;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMinimumRequiredAccountValueIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, MinimumRequiredAccountValueIsSet) + sizeof(MinimumRequiredAccountValueIsSet))
		return 0;

	return MinimumRequiredAccountValueIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataUpdate::GetMinimumRequiredAccountValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, MinimumRequiredAccountValue) + sizeof(MinimumRequiredAccountValue))
		return 0;

	return MinimumRequiredAccountValue;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetBeginTimeForDayMarginIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, BeginTimeForDayMarginIsSet) + sizeof(BeginTimeForDayMarginIsSet))
		return 0;

	return BeginTimeForDayMarginIsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetBeginTimeForDayMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, BeginTimeForDayMargin) + sizeof(BeginTimeForDayMargin))
		return 0;

	return BeginTimeForDayMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetEndTimeForDayMarginIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, EndTimeForDayMarginIsSet) + sizeof(EndTimeForDayMarginIsSet))
		return 0;

	return EndTimeForDayMarginIsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetEndTimeForDayMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, EndTimeForDayMargin) + sizeof(EndTimeForDayMargin))
		return 0;

	return EndTimeForDayMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetDayMarginTimeZoneIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, DayMarginTimeZoneIsSet) + sizeof(DayMarginTimeZoneIsSet))
		return 0;

	return DayMarginTimeZoneIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_FlattenPositionsWhenUnderMarginIntradayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntradayIsSet) + sizeof(m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntradayIsSet))
		return 0;

	return m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntradayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_FlattenPositionsWhenUnderMarginIntraday() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday) + sizeof(m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday))
		return 0;

	return m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDayIsSet) + sizeof(m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDayIsSet))
		return 0;

	return m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay) + sizeof(m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay))
		return 0;

	return m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_SymbolLimitsArrayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_SymbolLimitsArrayIsSet) + sizeof(m_UseMasterFirm_SymbolLimitsArrayIsSet))
		return 0;

	return m_UseMasterFirm_SymbolLimitsArrayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_SymbolLimitsArray() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_SymbolLimitsArray) + sizeof(m_UseMasterFirm_SymbolLimitsArray))
		return 0;

	return m_UseMasterFirm_SymbolLimitsArray;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradeFeesIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradeFeesIsSet) + sizeof(m_UseMasterFirm_TradeFeesIsSet))
		return 0;

	return m_UseMasterFirm_TradeFeesIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradeFees() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradeFees) + sizeof(m_UseMasterFirm_TradeFees))
		return 0;

	return m_UseMasterFirm_TradeFees;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradeFeePerShareIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradeFeePerShareIsSet) + sizeof(m_UseMasterFirm_TradeFeePerShareIsSet))
		return 0;

	return m_UseMasterFirm_TradeFeePerShareIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradeFeePerShare() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradeFeePerShare) + sizeof(m_UseMasterFirm_TradeFeePerShare))
		return 0;

	return m_UseMasterFirm_TradeFeePerShare;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_RequireSufficientMarginForNewPositionsIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_RequireSufficientMarginForNewPositionsIsSet) + sizeof(m_UseMasterFirm_RequireSufficientMarginForNewPositionsIsSet))
		return 0;

	return m_UseMasterFirm_RequireSufficientMarginForNewPositionsIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_RequireSufficientMarginForNewPositions() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_RequireSufficientMarginForNewPositions) + sizeof(m_UseMasterFirm_RequireSufficientMarginForNewPositions))
		return 0;

	return m_UseMasterFirm_RequireSufficientMarginForNewPositions;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginIsSet) + sizeof(m_UseMasterFirm_UsePercentOfMarginIsSet))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMargin) + sizeof(m_UseMasterFirm_UsePercentOfMargin))
		return 0;

	return m_UseMasterFirm_UsePercentOfMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet) + sizeof(m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet))
		return 0;

	return m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage) + sizeof(m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage))
		return 0;

	return m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_MinimumRequiredAccountValueIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_MinimumRequiredAccountValueIsSet) + sizeof(m_UseMasterFirm_MinimumRequiredAccountValueIsSet))
		return 0;

	return m_UseMasterFirm_MinimumRequiredAccountValueIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_MinimumRequiredAccountValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_MinimumRequiredAccountValue) + sizeof(m_UseMasterFirm_MinimumRequiredAccountValue))
		return 0;

	return m_UseMasterFirm_MinimumRequiredAccountValue;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_MarginTimeSettingsIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_MarginTimeSettingsIsSet) + sizeof(m_UseMasterFirm_MarginTimeSettingsIsSet))
		return 0;

	return m_UseMasterFirm_MarginTimeSettingsIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_MarginTimeSettings() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_MarginTimeSettings) + sizeof(m_UseMasterFirm_MarginTimeSettings))
		return 0;

	return m_UseMasterFirm_MarginTimeSettings;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradingIsDisabledIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradingIsDisabledIsSet) + sizeof(m_UseMasterFirm_TradingIsDisabledIsSet))
		return 0;

	return m_UseMasterFirm_TradingIsDisabledIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradingIsDisabled() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradingIsDisabled) + sizeof(m_UseMasterFirm_TradingIsDisabled))
		return 0;

	return m_UseMasterFirm_TradingIsDisabled;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsTradeStatisticsPublicallySharedIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsTradeStatisticsPublicallySharedIsSet) + sizeof(IsTradeStatisticsPublicallySharedIsSet))
		return 0;

	return IsTradeStatisticsPublicallySharedIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsTradeStatisticsPublicallyShared() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsTradeStatisticsPublicallyShared) + sizeof(IsTradeStatisticsPublicallyShared))
		return 0;

	return IsTradeStatisticsPublicallyShared;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsReadOnlyFollowingRequestsAllowedIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsReadOnlyFollowingRequestsAllowedIsSet) + sizeof(IsReadOnlyFollowingRequestsAllowedIsSet))
		return 0;

	return IsReadOnlyFollowingRequestsAllowedIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsReadOnlyFollowingRequestsAllowed() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsReadOnlyFollowingRequestsAllowed) + sizeof(IsReadOnlyFollowingRequestsAllowed))
		return 0;

	return IsReadOnlyFollowingRequestsAllowed;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsTradeAccountSharingAllowedIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsTradeAccountSharingAllowedIsSet) + sizeof(IsTradeAccountSharingAllowedIsSet))
		return 0;

	return IsTradeAccountSharingAllowedIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIsTradeAccountSharingAllowed() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, IsTradeAccountSharingAllowed) + sizeof(IsTradeAccountSharingAllowed))
		return 0;

	return IsTradeAccountSharingAllowed;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetReadOnlyShareToAllSCUsernamesIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, ReadOnlyShareToAllSCUsernamesIsSet) + sizeof(ReadOnlyShareToAllSCUsernamesIsSet))
		return 0;

	return ReadOnlyShareToAllSCUsernamesIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetReadOnlyShareToAllSCUsernames() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, ReadOnlyShareToAllSCUsernames) + sizeof(ReadOnlyShareToAllSCUsernames))
		return 0;

	return ReadOnlyShareToAllSCUsernames;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_SymbolCommissionsArrayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_SymbolCommissionsArrayIsSet) + sizeof(m_UseMasterFirm_SymbolCommissionsArrayIsSet))
		return 0;

	return m_UseMasterFirm_SymbolCommissionsArrayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_SymbolCommissionsArray() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_SymbolCommissionsArray) + sizeof(m_UseMasterFirm_SymbolCommissionsArray))
		return 0;

	return m_UseMasterFirm_SymbolCommissionsArray;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet) + sizeof(m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet))
		return 0;

	return m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit) + sizeof(m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit))
		return 0;

	return m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForDayTradingIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForDayTradingIsSet) + sizeof(m_UseMasterFirm_UsePercentOfMarginForDayTradingIsSet))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForDayTradingIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForDayTrading) + sizeof(m_UseMasterFirm_UsePercentOfMarginForDayTrading))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForDayTrading;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_SymbolCommissionsArrayFullOverrideIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_SymbolCommissionsArrayFullOverrideIsSet) + sizeof(m_UseMasterFirm_SymbolCommissionsArrayFullOverrideIsSet))
		return 0;

	return m_UseMasterFirm_SymbolCommissionsArrayFullOverrideIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_SymbolCommissionsArrayFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_SymbolCommissionsArrayFullOverride) + sizeof(m_UseMasterFirm_SymbolCommissionsArrayFullOverride))
		return 0;

	return m_UseMasterFirm_SymbolCommissionsArrayFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrdersIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrdersIsSet) + sizeof(m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrdersIsSet))
		return 0;

	return m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrdersIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders) + sizeof(m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders))
		return 0;

	return m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginFullOverrideIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginFullOverrideIsSet) + sizeof(m_UseMasterFirm_UsePercentOfMarginFullOverrideIsSet))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginFullOverrideIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginFullOverride) + sizeof(m_UseMasterFirm_UsePercentOfMarginFullOverride))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradeFeesFullOverrideIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradeFeesFullOverrideIsSet) + sizeof(m_UseMasterFirm_TradeFeesFullOverrideIsSet))
		return 0;

	return m_UseMasterFirm_TradeFeesFullOverrideIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_TradeFeesFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_TradeFeesFullOverride) + sizeof(m_UseMasterFirm_TradeFeesFullOverride))
		return 0;

	return m_UseMasterFirm_TradeFeesFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForDayTradingFullOverrideIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverrideIsSet) + sizeof(m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverrideIsSet))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverrideIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForDayTradingFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride) + sizeof(m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetLiquidationOnlyModeIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_LiquidationOnlyModeIsSet) + sizeof(m_LiquidationOnlyModeIsSet))
		return 0;

	return m_LiquidationOnlyModeIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetLiquidationOnlyMode() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_LiquidationOnlyMode) + sizeof(m_LiquidationOnlyMode))
		return 0;

	return m_LiquidationOnlyMode;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetCustomerOrFirmIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_CustomerOrFirmIsSet) + sizeof(m_CustomerOrFirmIsSet))
		return 0;

	return m_CustomerOrFirmIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetCustomerOrFirm() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_CustomerOrFirm) + sizeof(m_CustomerOrFirm))
		return 0;

	return m_CustomerOrFirm;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelAccountWhenDailyLossLimitMetIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMetIsSet) + sizeof(m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMetIsSet))
		return 0;

	return m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMetIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelAccountWhenDailyLossLimitMet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet) + sizeof(m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet))
		return 0;

	return m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelWhenUnderMinimumAccountValueIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValueIsSet) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValueIsSet))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValueIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelWhenUnderMinimumAccountValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelWhenUnderMarginIntradayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelWhenUnderMarginIntradayIsSet) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMarginIntradayIsSet))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMarginIntradayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelWhenUnderMarginIntraday() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelWhenUnderMarginIntraday) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMarginIntraday))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMarginIntraday;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelWhenUnderMarginEndOfDayIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDayIsSet) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDayIsSet))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDayIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_FlattenCancelWhenUnderMarginEndOfDay() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay) + sizeof(m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay))
		return 0;

	return m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_MaximumOrderQuantityIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_MaximumOrderQuantityIsSet) + sizeof(m_MasterFirm_MaximumOrderQuantityIsSet))
		return 0;

	return m_MasterFirm_MaximumOrderQuantityIsSet;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_MaximumOrderQuantity() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_MaximumOrderQuantity) + sizeof(m_MasterFirm_MaximumOrderQuantity))
		return 0;

	return m_MasterFirm_MaximumOrderQuantity;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetExchangeTraderIdIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_ExchangeTraderIdIsSet) + sizeof(m_ExchangeTraderIdIsSet))
		return 0;

	return m_ExchangeTraderIdIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseFixedCashOnHandBalanceIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseFixedCashOnHandBalanceIsSet) + sizeof(m_UseFixedCashOnHandBalanceIsSet))
		return 0;

	return m_UseFixedCashOnHandBalanceIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseFixedCashOnHandBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseFixedCashOnHandBalance) + sizeof(m_UseFixedCashOnHandBalance))
		return 0;

	return m_UseFixedCashOnHandBalance;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFixedCashOnHandBalanceIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_FixedCashOnHandBalanceIsSet) + sizeof(m_FixedCashOnHandBalanceIsSet))
		return 0;

	return m_FixedCashOnHandBalanceIsSet;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataUpdate::GetFixedCashOnHandBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_FixedCashOnHandBalance) + sizeof(m_FixedCashOnHandBalance))
		return 0;

	return m_FixedCashOnHandBalance;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetAdministratorUsernamesOwnAccountAccessIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_AdministratorUsernamesOwnAccountAccessIsSet) + sizeof(m_AdministratorUsernamesOwnAccountAccessIsSet))
		return 0;

	return m_AdministratorUsernamesOwnAccountAccessIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetTradeAccountPrefixForExchangeIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_TradeAccountPrefixForExchangeIsSet) + sizeof(m_TradeAccountPrefixForExchangeIsSet))
		return 0;

	return m_TradeAccountPrefixForExchangeIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetIntroducingBrokerIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_IntroducingBrokerIsSet) + sizeof(m_IntroducingBrokerIsSet))
		return 0;

	return m_IntroducingBrokerIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetRejectCrossingOrdersIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_RejectCrossingOrdersIsSet) + sizeof(m_RejectCrossingOrdersIsSet))
		return 0;

	return m_RejectCrossingOrdersIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetRejectCrossingOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_RejectCrossingOrders) + sizeof(m_RejectCrossingOrders))
		return 0;

	return m_RejectCrossingOrders;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSenderSubIDsForUserNamesIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_SenderSubIDsForUserNamesIsSet) + sizeof(m_SenderSubIDsForUserNamesIsSet))
		return 0;

	return m_SenderSubIDsForUserNamesIsSet;
}

/*==========================================================================*/
uint8_t  DTC_VLS::s_TradeAccountDataUpdate::GetMessageLimitPerTenSecondsIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MessageLimitPerTenSecondsIsSet) + sizeof(m_MessageLimitPerTenSecondsIsSet))
		return 0;

	return m_MessageLimitPerTenSecondsIsSet;
}

/*==========================================================================*/
uint32_t  DTC_VLS::s_TradeAccountDataUpdate::GetMessageLimitPerTenSeconds() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MessageLimitPerTenSeconds) + sizeof(m_MessageLimitPerTenSeconds))
		return 0;

	return m_MessageLimitPerTenSeconds;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetLastTradeDateSourceIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_LastTradeDateSourceIsSet) + sizeof(m_LastTradeDateSourceIsSet))
		return 0;

	return m_LastTradeDateSourceIsSet;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUpdate::GetLastTradeDateSource() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_LastTradeDateSource) + sizeof(m_LastTradeDateSource))
		return 0;

	return m_LastTradeDateSource;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetDisableTradingForParentAccountOnlyIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_DisableTradingForParentAccountOnlyIsSet) + sizeof(m_DisableTradingForParentAccountOnlyIsSet))
		return 0;

	return m_DisableTradingForParentAccountOnlyIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetDisableTradingForParentAccountOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_DisableTradingForParentAccountOnly) + sizeof(m_DisableTradingForParentAccountOnly))
		return 0;

	return m_DisableTradingForParentAccountOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSupportIntendedPositionOrdersIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_SupportIntendedPositionOrdersIsSet) + sizeof(m_SupportIntendedPositionOrdersIsSet))
		return 0;

	return m_SupportIntendedPositionOrdersIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSupportIntendedPositionOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_SupportIntendedPositionOrders) + sizeof(m_SupportIntendedPositionOrders))
		return 0;

	return m_SupportIntendedPositionOrders;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMarginRecalculationTime1IsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MarginRecalculationTime1IsSet) + sizeof(m_MarginRecalculationTime1IsSet))
		return 0;

	return m_MarginRecalculationTime1IsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetMarginRecalculationTime1() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MarginRecalculationTime1) + sizeof(m_MarginRecalculationTime1))
		return 0;

	return m_MarginRecalculationTime1;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMarginRecalculationTime2IsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MarginRecalculationTime2IsSet) + sizeof(m_MarginRecalculationTime2IsSet))
		return 0;

	return m_MarginRecalculationTime2IsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetMarginRecalculationTime2() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MarginRecalculationTime2) + sizeof(m_MarginRecalculationTime2))
		return 0;

	return m_MarginRecalculationTime2;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetClosePositionsAtEndOfDayTimeIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_ClosePositionsAtEndOfDayTimeIsSet) + sizeof(m_ClosePositionsAtEndOfDayTimeIsSet))
		return 0;

	return m_ClosePositionsAtEndOfDayTimeIsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetClosePositionsAtEndOfDayTime() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_ClosePositionsAtEndOfDayTime) + sizeof(m_ClosePositionsAtEndOfDayTime))
		return 0;

	return m_ClosePositionsAtEndOfDayTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterSettingsTimeZoneIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterSettingsTimeZoneIsSet) + sizeof(m_MasterSettingsTimeZoneIsSet))
		return 0;

	return m_MasterSettingsTimeZoneIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUsePercentOfMarginForOvernightTradingIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UsePercentOfMarginForOvernightTradingIsSet) + sizeof(m_UsePercentOfMarginForOvernightTradingIsSet))
		return 0;

	return m_UsePercentOfMarginForOvernightTradingIsSet;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataUpdate::GetUsePercentOfMarginForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UsePercentOfMarginForOvernightTrading) + sizeof(m_UsePercentOfMarginForOvernightTrading))
		return 0;

	return m_UsePercentOfMarginForOvernightTrading;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetBeginTimeForOvernightMarginIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_BeginTimeForOvernightMarginIsSet) + sizeof(m_BeginTimeForOvernightMarginIsSet))
		return 0;

	return m_BeginTimeForOvernightMarginIsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetBeginTimeForOvernightMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_BeginTimeForOvernightMargin) + sizeof(m_BeginTimeForOvernightMargin))
		return 0;

	return m_BeginTimeForOvernightMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetEndTimeForOvernightMarginIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_EndTimeForOvernightMarginIsSet) + sizeof(m_EndTimeForOvernightMarginIsSet))
		return 0;

	return m_EndTimeForOvernightMarginIsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetEndTimeForOvernightMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_EndTimeForOvernightMargin) + sizeof(m_EndTimeForOvernightMargin))
		return 0;

	return m_EndTimeForOvernightMargin;
}

/*==========================================================================*/		
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForOvernightTradingIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForOvernightTradingIsSet) + sizeof(m_UseMasterFirm_UsePercentOfMarginForOvernightTradingIsSet))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForOvernightTradingIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForOvernightTrading) + sizeof(m_UseMasterFirm_UsePercentOfMarginForOvernightTrading))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForOvernightTrading;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverrideIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverrideIsSet) + sizeof(m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverrideIsSet))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverrideIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride) + sizeof(m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride))
		return 0;

	return m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximumIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximumIsSet) + sizeof(m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximumIsSet))
		return 0;

	return m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximumIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetUseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum) + sizeof(m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum))
		return 0;

	return m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSupportUserSetProfitLossManagementIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_SupportUserSetProfitLossManagementIsSet) + sizeof(m_SupportUserSetProfitLossManagementIsSet))
		return 0;

	return m_SupportUserSetProfitLossManagementIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetSupportUserSetProfitLossManagement() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_SupportUserSetProfitLossManagement) + sizeof(m_SupportUserSetProfitLossManagement))
		return 0;

	return m_SupportUserSetProfitLossManagement;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetGenerateTradeAccountDataReport() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_GenerateTradeAccountDataReport) + sizeof(m_GenerateTradeAccountDataReport))
		return 0;

	return m_GenerateTradeAccountDataReport;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_SuffixesOfSubaccountsToAddForNewAccountIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccountIsSet) + sizeof(m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccountIsSet))
		return 0;

	return m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccountIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetMasterFirm_UsernameGroupDefinitionsIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_MasterFirm_UsernameGroupDefinitionsIsSet) + sizeof(m_MasterFirm_UsernameGroupDefinitionsIsSet))
		return 0;

	return m_MasterFirm_UsernameGroupDefinitionsIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetRiskManagerUsernameGroupIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_RiskManagerUsernameGroupIsSet) + sizeof(m_RiskManagerUsernameGroupIsSet))
		return 0;

	return m_RiskManagerUsernameGroupIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetResetDailyNetLossLimitHasBeenReached() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_ResetDailyNetLossLimitHasBeenReached) + sizeof(m_ResetDailyNetLossLimitHasBeenReached))
	{
		return 0;
	}

	return m_ResetDailyNetLossLimitHasBeenReached;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFundsOnHoldToDeductFromAccountBalanceIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_FundsOnHoldToDeductFromAccountBalanceIsSet) + sizeof(m_FundsOnHoldToDeductFromAccountBalanceIsSet))
	{
		return 0;
	}

	return m_FundsOnHoldToDeductFromAccountBalanceIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataUpdate::GetFundsOnHoldToDeductFromAccountBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_FundsOnHoldToDeductFromAccountBalance) + sizeof(m_FundsOnHoldToDeductFromAccountBalance))
	{
		return 0;
	}

	return m_FundsOnHoldToDeductFromAccountBalance;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdate::GetFundsOnHoldExpirationDateIsSet() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_FundsOnHoldExpirationDateIsSet) + sizeof(m_FundsOnHoldExpirationDateIsSet))
	{
		return 0;
	}

	return m_FundsOnHoldExpirationDateIsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_TradeAccountDataUpdate::GetFundsOnHoldExpirationDate() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdate, m_FundsOnHoldExpirationDate) + sizeof(m_FundsOnHoldExpirationDate))
	{
		return 0;
	}

	return m_FundsOnHoldExpirationDate;
}

/****************************************************************************/
//s_TradeAccountDataDelete

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataDelete::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataDelete::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataDelete::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataDelete, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataSymbolLimits

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetTradePositionLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, TradePositionLimit) + sizeof(TradePositionLimit))
		return 0;

	return TradePositionLimit;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetOrderQuantityLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, OrderQuantityLimit) + sizeof(OrderQuantityLimit))
		return 0;

	return OrderQuantityLimit;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetUsePercentOfMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, UsePercentOfMargin) + sizeof(UsePercentOfMargin))
		return 0;

	return UsePercentOfMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetOverrideMarginOtherAccounts() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, OverrideMarginOtherAccounts) + sizeof(OverrideMarginOtherAccounts))
		return 0;

	return OverrideMarginOtherAccounts;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetUsePercentOfMarginForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, UsePercentOfMarginForDayTrading) + sizeof(UsePercentOfMarginForDayTrading))
		return 0;

	return UsePercentOfMarginForDayTrading;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetNumberOfDaysBeforeLastTradingDateToDisallowOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, NumberOfDaysBeforeLastTradingDateToDisallowOrders) + sizeof(NumberOfDaysBeforeLastTradingDateToDisallowOrders))
		return 0;

	return NumberOfDaysBeforeLastTradingDateToDisallowOrders;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetFixedMarginCashValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, FixedMarginCashValue) + sizeof(FixedMarginCashValue))
		return 0;

	return FixedMarginCashValue;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetFixedMarginCashValueForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, FixedMarginCashValueForDayTrading) + sizeof(FixedMarginCashValueForDayTrading))
		return 0;

	return FixedMarginCashValueForDayTrading;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetUsePercentOfMarginForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, UsePercentOfMarginForOvernightTrading) + sizeof(UsePercentOfMarginForOvernightTrading))
		return 0;

	return UsePercentOfMarginForOvernightTrading;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataSymbolLimitsResponse::GetFixedMarginCashValueForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsResponse, FixedMarginCashValueForOvernightTrading) + sizeof(FixedMarginCashValueForOvernightTrading))
		return 0;

	return FixedMarginCashValueForOvernightTrading;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataSymbolLimitsUpdate

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetIsDeleted() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, IsDeleted) + sizeof(IsDeleted))
		return 0;

	return IsDeleted;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetTradePositionLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, TradePositionLimit) + sizeof(TradePositionLimit))
		return 0;

	return TradePositionLimit;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetOrderQuantityLimit() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, OrderQuantityLimit) + sizeof(OrderQuantityLimit))
		return 0;

	return OrderQuantityLimit;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetUsePercentOfMargin() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, UsePercentOfMargin) + sizeof(UsePercentOfMargin))
		return 0;

	return UsePercentOfMargin;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetOverrideMarginOtherAccounts() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, OverrideMarginOtherAccounts) + sizeof(OverrideMarginOtherAccounts))
		return 0;

	return OverrideMarginOtherAccounts;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetUsePercentOfMarginForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, UsePercentOfMarginForDayTrading) + sizeof(UsePercentOfMarginForDayTrading))
		return 0;

	return UsePercentOfMarginForDayTrading;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetNumberOfDaysBeforeLastTradingDateToDisallowOrders() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, NumberOfDaysBeforeLastTradingDateToDisallowOrders) + sizeof(NumberOfDaysBeforeLastTradingDateToDisallowOrders))
		return 0;

	return NumberOfDaysBeforeLastTradingDateToDisallowOrders;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetFixedMarginCashValue() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, FixedMarginCashValue) + sizeof(FixedMarginCashValue))
		return 0;

	return FixedMarginCashValue;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetFixedMarginCashValueForDayTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, FixedMarginCashValueForDayTrading) + sizeof(FixedMarginCashValueForDayTrading))
		return 0;

	return FixedMarginCashValueForDayTrading;
}

/*==========================================================================*/
int32_t DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetUsePercentOfMarginForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, UsePercentOfMarginForOvernightTrading) + sizeof(UsePercentOfMarginForOvernightTrading))
		return 0;

	return UsePercentOfMarginForOvernightTrading;
}

/*==========================================================================*/
float DTC_VLS::s_TradeAccountDataSymbolLimitsUpdate::GetFixedMarginCashValueForOvernightTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolLimitsUpdate, FixedMarginCashValueForOvernightTrading) + sizeof(FixedMarginCashValueForOvernightTrading))
		return 0;

	return FixedMarginCashValueForOvernightTrading;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataSymbolCommissionResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolCommissionResponse::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolCommissionResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataSymbolCommissionResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolCommissionResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSymbolCommissionResponse::GetTradeFeePerContract() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolCommissionResponse, TradeFeePerContract) + sizeof(TradeFeePerContract))
		return 0;

	return TradeFeePerContract;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataSymbolCommissionUpdate

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolCommissionUpdate::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSymbolCommissionUpdate::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataSymbolCommissionUpdate::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolCommissionUpdate, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSymbolCommissionUpdate::GetIsDeleted() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolCommissionUpdate, IsDeleted) + sizeof(IsDeleted))
		return 0;

	return IsDeleted;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSymbolCommissionUpdate::GetTradeFeePerContract() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSymbolCommissionUpdate, TradeFeePerContract) + sizeof(TradeFeePerContract))
		return 0;

	return TradeFeePerContract;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataSubAccountResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSubAccountResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSubAccountResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataSubAccountResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSubAccountResponse::GetBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountResponse, m_Balance) + sizeof(m_Balance))
		return 0;

	return m_Balance;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSubAccountResponse::GetUseMainAccountForMarginAndBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountResponse, m_UseMainAccountForMarginAndBalance) + sizeof(m_UseMainAccountForMarginAndBalance))
		return 0;

	return m_UseMainAccountForMarginAndBalance;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_TradeAccountDataSubAccountResponse::GetTransactionIdentifierForCashBalanceAdjustment() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountResponse, m_TransactionIdentifierForCashBalanceAdjustment) + sizeof(m_TransactionIdentifierForCashBalanceAdjustment))
		return 0;

	return m_TransactionIdentifierForCashBalanceAdjustment;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSubAccountResponse::GetDisableTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountResponse, m_DisableTrading) + sizeof(m_DisableTrading))
		return 0;

	return m_DisableTrading;
}

/****************************************************************************/
//s_TradeAccountDataSubAccountUpdate

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSubAccountUpdate::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataSubAccountUpdate::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataSubAccountUpdate::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountUpdate, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSubAccountUpdate::GetIsDeleted() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountUpdate, IsDeleted) + sizeof(IsDeleted))
		return 0;

	return IsDeleted;
}

/*==========================================================================*/
double DTC_VLS::s_TradeAccountDataSubAccountUpdate::GetBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountUpdate, m_Balance) + sizeof(m_Balance))
		return 0;

	return m_Balance;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSubAccountUpdate::GetUseMainAccountForMarginAndBalance() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountUpdate, m_UseMainAccountForMarginAndBalance) + sizeof(m_UseMainAccountForMarginAndBalance))
		return 0;

	return m_UseMainAccountForMarginAndBalance;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataSubAccountUpdate::GetDisableTrading() const
{
	if (BaseSize < offsetof(s_TradeAccountDataSubAccountUpdate, m_DisableTrading) + sizeof(m_DisableTrading))
		return 0;

	return m_DisableTrading;
}

/****************************************************************************/
//s_TradeAccountDataAuthorizedUsernameResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameResponse::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataAuthorizedUsernameResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameResponse::GetUpdateOperationComplete() const
{
	if (BaseSize < offsetof(s_TradeAccountDataAuthorizedUsernameResponse, UpdateOperationComplete) + sizeof(UpdateOperationComplete))
		return 0;

	return UpdateOperationComplete;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameResponse::GetUpdateOperationMessageType() const
{
	if (BaseSize < offsetof(s_TradeAccountDataAuthorizedUsernameResponse, UpdateOperationMessageType) + sizeof(UpdateOperationMessageType))
		return 0;

	return UpdateOperationMessageType;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataAuthorizedUsernameAdd

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameAdd::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameAdd::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameAdd::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataAuthorizedUsernameAdd, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataAuthorizedUsernameRemove

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameRemove::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameRemove::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataAuthorizedUsernameRemove::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataAuthorizedUsernameRemove, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataUsernameToShareWithResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUsernameToShareWithResponse::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUsernameToShareWithResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUsernameToShareWithResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUsernameToShareWithResponse::GetIsReadOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithResponse, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUsernameToShareWithResponse::GetUpdateOperationComplete() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithResponse, UpdateOperationComplete) + sizeof(UpdateOperationComplete))
		return 0;

	return UpdateOperationComplete;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUsernameToShareWithResponse::GetUpdateOperationMessageType() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithResponse, UpdateOperationMessageType) + sizeof(UpdateOperationMessageType))
		return 0;

	return UpdateOperationMessageType;
}

/*==========================================================================*/

/****************************************************************************/
// s_TradeAccountDataUsernameToShareWithAdd

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUsernameToShareWithAdd::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUsernameToShareWithAdd::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUsernameToShareWithAdd::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithAdd, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUsernameToShareWithAdd::GetIsReadOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithAdd, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataUsernameToShareWithRemove

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUsernameToShareWithRemove::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUsernameToShareWithRemove::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUsernameToShareWithRemove::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithRemove, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUsernameToShareWithRemove::GetIsReadOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUsernameToShareWithRemove, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/*==========================================================================*/


/****************************************************************************/
//s_TradeAccountDataResponseTrailer

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataResponseTrailer::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataResponseTrailer::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataResponseTrailer::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponseTrailer, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponseTrailer::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponseTrailer, m_IsSnapshot) + sizeof(m_IsSnapshot))
		return 0;

	return m_IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponseTrailer::GetIsFirstMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponseTrailer, m_IsFirstMessageInBatch) + sizeof(m_IsFirstMessageInBatch))
		return 0;

	return m_IsFirstMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataResponseTrailer::GetIsLastMessageInBatch() const
{
	if (BaseSize < offsetof(s_TradeAccountDataResponseTrailer, m_IsLastMessageInBatch) + sizeof(m_IsLastMessageInBatch))
		return 0;

	return m_IsLastMessageInBatch;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountDataUpdateOperationComplete

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUpdateOperationComplete::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataUpdateOperationComplete::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataUpdateOperationComplete::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdateOperationComplete, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdateOperationComplete::GetIsError() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdateOperationComplete, IsError) + sizeof(IsError))
		return 0;

	return IsError;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdateOperationComplete::GetIsDeleteOperation() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdateOperationComplete, IsDeleteOperation) + sizeof(IsDeleteOperation))
		return 0;

	return IsDeleteOperation;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdateOperationComplete::GetIsSymbolLimitsUpdateOperation() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdateOperationComplete, IsSymbolLimitsUpdateOperation) + sizeof(IsSymbolLimitsUpdateOperation))
		return 0;

	return IsSymbolLimitsUpdateOperation;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataUpdateOperationComplete::GetIsSymbolCommissionUpdateOperation() const
{
	if (BaseSize < offsetof(s_TradeAccountDataUpdateOperationComplete, IsSymbolCommissionUpdateOperation) + sizeof(IsSymbolCommissionUpdateOperation))
		return 0;

	return IsSymbolCommissionUpdateOperation;
}

/*==========================================================================*/

/****************************************************************************/
//s_TradeAccountTradingIsDisabledRequest

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountTradingIsDisabledRequest::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountTradingIsDisabledRequest::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountTradingIsDisabledRequest::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountTradingIsDisabledRequest, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
n_DTCNonStandard::TradingIsDisabledEnum DTC_VLS::s_TradeAccountTradingIsDisabledRequest::GetSetTradingIsDisabled() const
{
	if (Size < offsetof(s_TradeAccountTradingIsDisabledRequest, SetTradingIsDisabled) + sizeof(SetTradingIsDisabled))
	{
		return n_DTCNonStandard::TradingIsDisabledEnum::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;
	}

	return SetTradingIsDisabled;
}

/*==========================================================================*/
n_DTCNonStandard::TradingIsDisabledEnum DTC_VLS::s_TradeAccountTradingIsDisabledRequest::GetSetDisableTradingForParentAccountOnly() const
{
	if (Size < offsetof(s_TradeAccountTradingIsDisabledRequest, SetDisableTradingForParentAccountOnly) + sizeof(SetDisableTradingForParentAccountOnly))
	{
		return n_DTCNonStandard::TradingIsDisabledEnum::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;
	}

	return SetDisableTradingForParentAccountOnly;
}


/****************************************************************************/
//s_TradeAccountTradingIsDisabledResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountTradingIsDisabledResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountTradingIsDisabledResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountTradingIsDisabledResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountTradingIsDisabledResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
n_DTCNonStandard::TradingIsDisabledEnum DTC_VLS::s_TradeAccountTradingIsDisabledResponse::GetTradingIsDisabled() const
{
	if (BaseSize < offsetof(s_TradeAccountTradingIsDisabledResponse, TradingIsDisabled) + sizeof(TradingIsDisabled))
		return n_DTCNonStandard::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;

	return TradingIsDisabled;
}

/*==========================================================================*/
n_DTCNonStandard::TradingIsDisabledEnum DTC_VLS::s_TradeAccountTradingIsDisabledResponse::GetDisableTradingForParentAccountOnly() const
{
	if (BaseSize < offsetof(s_TradeAccountTradingIsDisabledResponse, DisableTradingForParentAccountOnly) + sizeof(DisableTradingForParentAccountOnly))
		return n_DTCNonStandard::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;

	return DisableTradingForParentAccountOnly;
}

/****************************************************************************/
//s_TradeAccountDataDuplicate

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataDuplicate::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_TradeAccountDataDuplicate::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_TradeAccountDataDuplicate::GetRequestID() const
{
	if (BaseSize < offsetof(s_TradeAccountDataDuplicate, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_TradeAccountDataDuplicate::GetTradingIsDisabled() const
{
	if (BaseSize < offsetof(s_TradeAccountDataDuplicate, TradingIsDisabled) + sizeof(TradingIsDisabled))
		return 0;

	return TradingIsDisabled;
}

/****************************************************************************/
//s_UserProfitLossManagementDataResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetRequestID() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_RequestID) + sizeof(m_RequestID))
		return 0;

	return m_RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetIsSnapshot() const 
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_IsSnapshot) + sizeof(m_IsSnapshot))
		return 0;

	return m_IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetFlattenAllPositionsWhenProfitRulesMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_FlattenAllPositionsWhenProfitRulesMet) + sizeof(m_FlattenAllPositionsWhenProfitRulesMet))
		return 0;

	return m_FlattenAllPositionsWhenProfitRulesMet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetProfitTriggerValueInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_ProfitTriggerValueInAccountCurrency) + sizeof(m_ProfitTriggerValueInAccountCurrency))
		return 0;

	return m_ProfitTriggerValueInAccountCurrency;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency) + sizeof(m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency))
		return 0;

	return m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetTrailDailyNetProfit_IsEnabled() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_TrailDailyNetProfit_IsEnabled) + sizeof(m_TrailDailyNetProfit_IsEnabled))
		return 0;

	return m_TrailDailyNetProfit_IsEnabled;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetTrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency) + sizeof(m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency))
		return 0;

	return m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetTrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency) + sizeof(m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency))
		return 0;

	return m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetFlattenAllPositionsWhenLossRuleMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_FlattenAllPositionsWhenLossRuleMet) + sizeof(m_FlattenAllPositionsWhenLossRuleMet))
		return 0;

	return m_FlattenAllPositionsWhenLossRuleMet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetLossTriggerValueInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_LossTriggerValueInAccountCurrency) + sizeof(m_LossTriggerValueInAccountCurrency))
		return 0;

	return m_LossTriggerValueInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetFlattenPositionsAtSetTime() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_FlattenPositionsAtSetTime) + sizeof(m_FlattenPositionsAtSetTime))
		return 0;

	return m_FlattenPositionsAtSetTime;
}

/*==========================================================================*/
int64_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetFlattenPositionsTime() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_FlattenPositionsTime) + sizeof(m_FlattenPositionsTime))
		return 0;

	return m_FlattenPositionsTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetActionToPerformWhenProfitTriggerRulesMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_ActionToPerformWhenProfitTriggerRulesMet) + sizeof(m_ActionToPerformWhenProfitTriggerRulesMet))
		return 0;

	return m_ActionToPerformWhenProfitTriggerRulesMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetIsProfitTriggerValueInAccountCurrencyMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_IsProfitTriggerValueInAccountCurrencyMet) + sizeof(m_IsProfitTriggerValueInAccountCurrencyMet))
		return 0;

	return m_IsProfitTriggerValueInAccountCurrencyMet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetProfitLossValueAfterProfitTriggerToFlattenPositionsInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_ProfitLossValueAfterProfitTriggerToFlattenPositionsInAccountCurrency) + sizeof(m_ProfitLossValueAfterProfitTriggerToFlattenPositionsInAccountCurrency))
		return 0;

	return m_ProfitLossValueAfterProfitTriggerToFlattenPositionsInAccountCurrency;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetMaxProfitReachedForDailyProfitManagement() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_MaxProfitReachedForDailyProfitManagement) + sizeof(m_MaxProfitReachedForDailyProfitManagement))
		return 0;

	return m_MaxProfitReachedForDailyProfitManagement;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataResponse::GetCalculatedLossTriggerValueInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_CalculatedLossTriggerValueInAccountCurrency) + sizeof(m_CalculatedLossTriggerValueInAccountCurrency))
		return 0;

	return m_CalculatedLossTriggerValueInAccountCurrency;
}

/*==========================================================================*/
int64_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetDateTimeUTCPositionsFlattenedForProfitManagement() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_DateTimeUTCPositionsFlattenedForProfitManagement) + sizeof(m_DateTimeUTCPositionsFlattenedForProfitManagement))
		return 0;

	return m_DateTimeUTCPositionsFlattenedForProfitManagement;
}

/*==========================================================================*/
int64_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetDateTimeUTCPositionsFlattenedForDailyLossMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_DateTimeUTCPositionsFlattenedForDailyLossMet) + sizeof(m_DateTimeUTCPositionsFlattenedForDailyLossMet))
		return 0;

	return m_DateTimeUTCPositionsFlattenedForDailyLossMet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetDateTimeUTCPositionsFlattenedForAtSetTime() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_DateTimeUTCPositionsFlattenedForAtSetTime) + sizeof(m_DateTimeUTCPositionsFlattenedForAtSetTime))
		return 0;

	return m_DateTimeUTCPositionsFlattenedForAtSetTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetFlattenOperationPerformedForLossManagementInCurrentTradeDate() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_FlattenOperationPerformedForLossManagementInCurrentTradeDate) + sizeof(m_FlattenOperationPerformedForLossManagementInCurrentTradeDate))
		return 0;

	return m_FlattenOperationPerformedForLossManagementInCurrentTradeDate;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetFlattenOperationPerformedForProfitManagementInCurrentTradeDate() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_FlattenOperationPerformedForProfitManagementInCurrentTradeDate) + sizeof(m_FlattenOperationPerformedForProfitManagementInCurrentTradeDate))
	{
		return 0;
	}

	return m_FlattenOperationPerformedForProfitManagementInCurrentTradeDate;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetFlattenOperationPerformedForAtSetTimeInCurrentTradeDate() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_FlattenOperationPerformedForAtSetTimeInCurrentTradeDate) + sizeof(m_FlattenOperationPerformedForAtSetTimeInCurrentTradeDate))
	{
		return 0;
	}

	return m_FlattenOperationPerformedForAtSetTimeInCurrentTradeDate;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetActionToPerformWhenLossTriggerRuleMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_ActionToPerformWhenLossTriggerRuleMet) + sizeof(m_ActionToPerformWhenLossTriggerRuleMet))
	{
		return 0;
	}

	return m_ActionToPerformWhenLossTriggerRuleMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataResponse::GetActionToPerformWhenAtSetTimeTriggerRuleMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataResponse, m_ActionToPerformWhenAtSetTimeTriggerRuleMet) + sizeof(m_ActionToPerformWhenAtSetTimeTriggerRuleMet))
	{
		return 0;
	}

	return m_ActionToPerformWhenAtSetTimeTriggerRuleMet;
}

/****************************************************************************/
//s_UserProfitLossManagementDataUpdate

/*==========================================================================*/
uint16_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetRequestID() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_RequestID) + sizeof(m_RequestID))
		return 0;

	return m_RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenAllPositionsWhenProfitRulesMetIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenAllPositionsWhenProfitRulesMetIsSet) + sizeof(m_FlattenAllPositionsWhenProfitRulesMetIsSet))
		return 0;

	return m_FlattenAllPositionsWhenProfitRulesMetIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenAllPositionsWhenProfitRulesMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenAllPositionsWhenProfitRulesMet) + sizeof(m_FlattenAllPositionsWhenProfitRulesMet))
		return 0;

	return m_FlattenAllPositionsWhenProfitRulesMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetProfitTriggerValueInAccountCurrencyIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ProfitTriggerValueInAccountCurrencyIsSet) + sizeof(m_ProfitTriggerValueInAccountCurrencyIsSet))
		return 0;

	return m_ProfitTriggerValueInAccountCurrencyIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataUpdate::GetProfitTriggerValueInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ProfitTriggerValueInAccountCurrency) + sizeof(m_ProfitTriggerValueInAccountCurrency))
		return 0;

	return m_ProfitTriggerValueInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet) + sizeof(m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet))
		return 0;

	return m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataUpdate::GetProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency) + sizeof(m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency))
		return 0;

	return m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetTrailDailyNetProfit_IsEnabledIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_TrailDailyNetProfit_IsEnabledIsSet) + sizeof(m_TrailDailyNetProfit_IsEnabledIsSet))
		return 0;

	return m_TrailDailyNetProfit_IsEnabledIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetTrailDailyNetProfit_IsEnabled() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_TrailDailyNetProfit_IsEnabled) + sizeof(m_TrailDailyNetProfit_IsEnabled))
		return 0;

	return m_TrailDailyNetProfit_IsEnabled;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetTrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrencyIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrencyIsSet) + sizeof(m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrencyIsSet))
		return 0;

	return m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrencyIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataUpdate::GetTrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency) + sizeof(m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency))
		return 0;

	return m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetTrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet) + sizeof(m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet))
		return 0;

	return m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataUpdate::GetTrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency) + sizeof(m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency))
		return 0;

	return m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenAllPositionsWhenLossRuleMetIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenAllPositionsWhenLossRuleMetIsSet) + sizeof(m_FlattenAllPositionsWhenLossRuleMetIsSet))
		return 0;

	return m_FlattenAllPositionsWhenLossRuleMetIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenAllPositionsWhenLossRuleMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenAllPositionsWhenLossRuleMet) + sizeof(m_FlattenAllPositionsWhenLossRuleMet))
		return 0;

	return m_FlattenAllPositionsWhenLossRuleMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetLossTriggerValueInAccountCurrencyIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_LossTriggerValueInAccountCurrencyIsSet) + sizeof(m_LossTriggerValueInAccountCurrencyIsSet))
		return 0;

	return m_LossTriggerValueInAccountCurrencyIsSet;
}

/*==========================================================================*/
double DTC_VLS::s_UserProfitLossManagementDataUpdate::GetLossTriggerValueInAccountCurrency() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_LossTriggerValueInAccountCurrency) + sizeof(m_LossTriggerValueInAccountCurrency))
		return 0;

	return m_LossTriggerValueInAccountCurrency;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenPositionsAtSetTimeIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenPositionsAtSetTimeIsSet) + sizeof(m_FlattenPositionsAtSetTimeIsSet))
		return 0;

	return m_FlattenPositionsAtSetTimeIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenPositionsAtSetTime() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenPositionsAtSetTime) + sizeof(m_FlattenPositionsAtSetTime))
		return 0;

	return m_FlattenPositionsAtSetTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenPositionsTimeIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenPositionsTimeIsSet) + sizeof(m_FlattenPositionsTimeIsSet))
		return 0;

	return m_FlattenPositionsTimeIsSet;
}

/*==========================================================================*/
int64_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetFlattenPositionsTime() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_FlattenPositionsTime) + sizeof(m_FlattenPositionsTime))
		return 0;

	return m_FlattenPositionsTime;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetActionToPerformWhenProfitTriggerRulesMetIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ActionToPerformWhenProfitTriggerRulesMetIsSet) + sizeof(m_ActionToPerformWhenProfitTriggerRulesMetIsSet))
		return 0;

	return m_ActionToPerformWhenProfitTriggerRulesMetIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetActionToPerformWhenProfitTriggerRulesMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ActionToPerformWhenProfitTriggerRulesMet) + sizeof(m_ActionToPerformWhenProfitTriggerRulesMet))
		return 0;

	return m_ActionToPerformWhenProfitTriggerRulesMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetActionToPerformWhenLossTriggerRuleMetIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ActionToPerformWhenLossTriggerRuleMetIsSet) + sizeof(m_ActionToPerformWhenLossTriggerRuleMetIsSet))
		return 0;

	return m_ActionToPerformWhenLossTriggerRuleMetIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetActionToPerformWhenLossTriggerRuleMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ActionToPerformWhenLossTriggerRuleMet) + sizeof(m_ActionToPerformWhenLossTriggerRuleMet))
		return 0;

	return m_ActionToPerformWhenLossTriggerRuleMet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetActionToPerformWhenAtSetTimeTriggerRuleMetIsSet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ActionToPerformWhenAtSetTimeTriggerRuleMetIsSet) + sizeof(m_ActionToPerformWhenAtSetTimeTriggerRuleMetIsSet))
		return 0;

	return m_ActionToPerformWhenAtSetTimeTriggerRuleMetIsSet;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdate::GetActionToPerformWhenAtSetTimeTriggerRuleMet() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdate, m_ActionToPerformWhenAtSetTimeTriggerRuleMet) + sizeof(m_ActionToPerformWhenAtSetTimeTriggerRuleMet))
		return 0;

	return m_ActionToPerformWhenAtSetTimeTriggerRuleMet;
}

/****************************************************************************/
//s_UserProfitLossManagementDataUpdateOperationComplete

/*==========================================================================*/
uint16_t DTC_VLS::s_UserProfitLossManagementDataUpdateOperationComplete::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_UserProfitLossManagementDataUpdateOperationComplete::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_UserProfitLossManagementDataUpdateOperationComplete::GetRequestID() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdateOperationComplete, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_UserProfitLossManagementDataUpdateOperationComplete::GetIsError() const
{
	if (BaseSize < offsetof(s_UserProfitLossManagementDataUpdateOperationComplete, IsError) + sizeof(IsError))
		return 0;

	return IsError;
}

/****************************************************************************/
//s_ProcessedFillIdentifier

/*==========================================================================*/
uint16_t DTC_VLS::s_ProcessedFillIdentifier::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ProcessedFillIdentifier::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ProcessedFillIdentifier::GetIsSnapshot() const
{
	if (BaseSize < offsetof(s_ProcessedFillIdentifier, IsSnapshot) + sizeof(IsSnapshot))
		return 0;

	return IsSnapshot;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ProcessedFillIdentifier::GetIsFirstMessageInBatch() const
{
	if (BaseSize < offsetof(s_ProcessedFillIdentifier, IsFirstMessageInBatch) + sizeof(IsFirstMessageInBatch))
		return 0;

	return IsFirstMessageInBatch;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ProcessedFillIdentifier::GetIsLastMessageInBatch() const
{
	if (BaseSize < offsetof(s_ProcessedFillIdentifier, IsLastMessageInBatch) + sizeof(IsLastMessageInBatch))
		return 0;

	return IsLastMessageInBatch;
}

/*==========================================================================*/

/****************************************************************************/
//s_FlattenPositionsForTradeAccount

/*==========================================================================*/
uint16_t DTC_VLS::s_FlattenPositionsForTradeAccount::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_FlattenPositionsForTradeAccount::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_FlattenPositionsForTradeAccount::GetIsAutomatedOrder() const
{
	if (BaseSize < offsetof(s_FlattenPositionsForTradeAccount, IsAutomatedOrder) + sizeof(IsAutomatedOrder))
		return 0;

	return IsAutomatedOrder;
}

/*==========================================================================*/

/****************************************************************************/
//s_UserInformation

/*==========================================================================*/
uint16_t DTC_VLS::s_UserInformation::GetMessageSize() const
{
	return Size;
}
/*==========================================================================*/
uint16_t DTC_VLS::s_UserInformation::GetBaseSize() const
{
	return BaseSize;
}
/*==========================================================================*/

/****************************************************************************/
//s_WriteIntradayDataFileSessionValue

/*==========================================================================*/
uint16_t DTC::s_WriteIntradayDataFileSessionValue::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_WriteIntradayDataFileSessionValue::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_WriteIntradayDataFileSessionValue), *static_cast<uint16_t*>(p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_WriteIntradayDataFileSessionValue::GetSymbolID() const
{
	if (Size < offsetof(s_WriteIntradayDataFileSessionValue, SymbolID) + sizeof(SymbolID))
		return 0;

	return SymbolID;
}

/*==========================================================================*/
n_DTCNonStandard::WriteIntradayDataFileSessionValueTypeEnum DTC::s_WriteIntradayDataFileSessionValue::GetValueType() const
{
	if (Size < offsetof(s_WriteIntradayDataFileSessionValue, ValueType) + sizeof(ValueType))
		return n_DTCNonStandard::INTRADAY_DATA_FILE_SESSION_VALUE_UNSET;

	return ValueType;
}

/*==========================================================================*/
DTC::t_DateTimeWithMicrosecondsInt DTC::s_WriteIntradayDataFileSessionValue::GetDateTime() const
{
	if (Size < offsetof(s_WriteIntradayDataFileSessionValue, DateTime) + sizeof(DateTime))
		return 0;

	return DateTime;
}

/*==========================================================================*/
DTC::t_DateTime DTC::s_WriteIntradayDataFileSessionValue::GetDate() const
{
	if (Size < offsetof(s_WriteIntradayDataFileSessionValue, Date) + sizeof(Date))
		return 0;

	return Date;
}

/*==========================================================================*/
double DTC::s_WriteIntradayDataFileSessionValue::GetPrice() const
{
	if (Size < offsetof(s_WriteIntradayDataFileSessionValue, Price) + sizeof(Price))
		return 0;

	return Price;
}

/*==========================================================================*/
double DTC::s_WriteIntradayDataFileSessionValue::GetVolume() const
{
	if (Size < offsetof(s_WriteIntradayDataFileSessionValue, Volume) + sizeof(Volume))
		return 0;

	return Volume;
}

/****************************************************************************/
//s_MarketDataUpdateOrderImbalanceData

/*==========================================================================*/
uint16_t DTC::s_MarketDataUpdateOrderImbalanceData::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
void DTC::s_MarketDataUpdateOrderImbalanceData::CopyFrom(void* p_SourceData)
{
	memcpy(this, p_SourceData, min(sizeof(s_MarketDataUpdateOrderImbalanceData), *static_cast<uint16_t*>(p_SourceData)));
}

/*==========================================================================*/
uint32_t DTC::s_MarketDataUpdateOrderImbalanceData::GetSymbolID() const
{
	if (Size < offsetof(s_MarketDataUpdateOrderImbalanceData, SymbolID) + sizeof(SymbolID))
		return 0;

	return SymbolID;
}

/*==========================================================================*/
DTC::t_DateTimeWithMicrosecondsInt DTC::s_MarketDataUpdateOrderImbalanceData::GetDateTime() const
{
	if (Size < offsetof(s_MarketDataUpdateOrderImbalanceData, DateTime) + sizeof(DateTime))
		return 0;

	return DateTime;
}

/*==========================================================================*/
double DTC::s_MarketDataUpdateOrderImbalanceData::GetMatchingQuantity() const
{
	if (Size < offsetof(s_MarketDataUpdateOrderImbalanceData, MatchingQuantity) + sizeof(MatchingQuantity))
		return 0;

	return MatchingQuantity;
}

/*==========================================================================*/
double DTC::s_MarketDataUpdateOrderImbalanceData::GetNonMatchingQuantity() const
{
	if (Size < offsetof(s_MarketDataUpdateOrderImbalanceData, NonMatchingQuantity) + sizeof(NonMatchingQuantity))
		return 0;

	return NonMatchingQuantity;
}

/*==========================================================================*/
double DTC::s_MarketDataUpdateOrderImbalanceData::GetCurrentReferencePrice() const
{
	if (Size < offsetof(s_MarketDataUpdateOrderImbalanceData, CurrentReferencePrice) + sizeof(CurrentReferencePrice))
		return 0;

	return CurrentReferencePrice;
}

/*==========================================================================*/
uint8_t DTC::s_MarketDataUpdateOrderImbalanceData::GetImbalanceDirection() const
{
	if (Size < offsetof(s_MarketDataUpdateOrderImbalanceData, ImbalanceDirection) + sizeof(ImbalanceDirection))
		return 0;

	return ImbalanceDirection;
}

/*==========================================================================*/
uint8_t DTC::s_MarketDataUpdateOrderImbalanceData::GetCrossType() const
{
	if (Size < offsetof(s_MarketDataUpdateOrderImbalanceData, CrossType) + sizeof(CrossType))
		return 0;

	return CrossType;
}

/****************************************************************************/
//s_MarginDataRequest

/*==========================================================================*/
uint16_t DTC_VLS::s_MarginDataRequest::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_MarginDataRequest::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_MarginDataRequest::GetRequestID() const
{
	if (BaseSize < offsetof(s_MarginDataRequest, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
//s_MarginDataResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_MarginDataResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_MarginDataResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_MarginDataResponse::GetRequestID() const
{
	if (Size < offsetof(s_MarginDataResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
double DTC_VLS::s_MarginDataResponse::GetExchangeMargin() const
{
	if (Size < offsetof(s_MarginDataResponse, ExchangeMargin) + sizeof(ExchangeMargin))
		return 0;

	return ExchangeMargin;
}

/*==========================================================================*/
double DTC_VLS::s_MarginDataResponse::GetAccountMargin() const
{
	if (Size < offsetof(s_MarginDataResponse, AccountMargin) + sizeof(AccountMargin))
		return 0;

	return AccountMargin;
}

/*==========================================================================*/
inline void AddVariableLengthBinaryField
( uint16_t& r_BaseStructureSizeField
, DTC_VLS::vls_t& r_VariableLengthBinaryField
, uint16_t SizeToAdd
)
{
	if (SizeToAdd == 0)
	{
		r_VariableLengthBinaryField.Offset = 0;
		r_VariableLengthBinaryField.Length = 0;
	}
	else
	{
		r_VariableLengthBinaryField.Offset = r_BaseStructureSizeField;
		r_VariableLengthBinaryField.Length = SizeToAdd;
		r_BaseStructureSizeField += r_VariableLengthBinaryField.Length;
	}
}

/*==========================================================================*/
inline const char* GetVariableLengthBinaryField
( const uint16_t& MessageSizeField
, uint16_t BaseStructureSizeField
, const DTC_VLS::vls_t& VariableLengthBinaryField
, const uint16_t VariableLengthBinaryFieldOffset
)
{
	if (BaseStructureSizeField < VariableLengthBinaryFieldOffset + sizeof(DTC_VLS::vls_t))
		return nullptr;
	else if (VariableLengthBinaryField.Offset == 0 || VariableLengthBinaryField.Length < 1)
		return nullptr;
	else if ((VariableLengthBinaryField.Offset + VariableLengthBinaryField.Length) > MessageSizeField)
		return nullptr;
	else
	{
		const char* BaseMessage = reinterpret_cast<const char*>(&MessageSizeField);
		return BaseMessage + VariableLengthBinaryField.Offset;
	}
}

/****************************************************************************/
// s_BinaryTransfer

/*==========================================================================*/
uint32_t DTC_VLS::s_BinaryTransfer::GetFileID() const
{
	if (Size < offsetof(s_BinaryTransfer, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
int64_t DTC_VLS::s_BinaryTransfer::GetTimeStamp() const
{
	if (Size < offsetof(s_BinaryTransfer, TimeStamp) + sizeof(TimeStamp))
		return 0;

	return TimeStamp;
}

/*==========================================================================*/
const char* DTC_VLS::s_BinaryTransfer::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_BinaryTransfer, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_BinaryTransfer::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_BinaryTransfer::GetBinaryData() const
{
	if (BinaryDataSize != 0)
		return reinterpret_cast<const char*>(this) + Size;

	return nullptr;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_BinaryTransfer::GetBinaryDataLength() const
{
	return BinaryDataSize;
}

/****************************************************************************/
// s_ChartbookSharingConnect

/*==========================================================================*/
int64_t DTC_VLS::s_ChartbookSharingConnect::GetUserTimeStamp() const
{
	if (Size < offsetof(s_ChartbookSharingConnect, UserTimeStamp) + sizeof(UserTimeStamp))
		return 0;

	return UserTimeStamp;
}

/****************************************************************************/
// s_ChartbookSharingConnected

/*==========================================================================*/
int64_t DTC_VLS::s_ChartbookSharingConnected::GetServerTimeStamp() const
{
	if (Size < offsetof(s_ChartbookSharingConnected, ServerTimeStamp) + sizeof(ServerTimeStamp))
		return 0;

	return ServerTimeStamp;
}

/****************************************************************************/
// s_ChartbookSharingSearch

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingSearch::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingSearch, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingSearch::GetSearchPattern() const
{
	return GetVariableLengthStringField(Size, BaseSize, SearchPattern, offsetof(s_ChartbookSharingSearch, SearchPattern));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingSearch::AddSearchPattern(uint16_t PatternLength)
{
	AddVariableLengthStringField(Size, SearchPattern, PatternLength);
}

/****************************************************************************/
// s_ChartbookSharingSearchResult

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingSearchResult::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingSearchResult, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
int64_t DTC_VLS::s_ChartbookSharingSearchResult::GetFileTimeStamp() const
{
	if (Size < offsetof(s_ChartbookSharingSearchResult, FileTimeStamp) + sizeof(FileTimeStamp))
		return 0;

	return FileTimeStamp;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingSearchResult::GetSubscribedNum() const
{
	if (Size < offsetof(s_ChartbookSharingSearchResult, SubscribedNum) + sizeof(SubscribedNum))
		return 0;

	return SubscribedNum;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingSearchResult::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingSearchResult, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingSearchResult::GetAuthorName() const
{
	return GetVariableLengthStringField(Size, BaseSize, AuthorName, offsetof(s_ChartbookSharingSearchResult, AuthorName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingSearchResult::AddAuthorName(uint16_t Length)
{
	AddVariableLengthStringField(Size, AuthorName, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingSearchResult::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingSearchResult, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingSearchResult::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingSearchResult::GetDescription() const
{
	return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_ChartbookSharingSearchResult, Description));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingSearchResult::AddDescription(uint16_t Length)
{
	AddVariableLengthStringField(Size, Description, Length);
}

/****************************************************************************/
// s_ChartbookSharingGetInfo

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingGetInfo::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingGetInfo, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingGetInfo::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingGetInfo, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/****************************************************************************/
// s_ChartbookSharingGetUpdate

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingGetUpdate::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingGetUpdate, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingShare

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingShare::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingShare, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingShare::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingShare, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingShare::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingShare::GetDescription() const
{
	return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_ChartbookSharingShare, Description));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingShare::AddDescription(uint16_t Length)
{
	AddVariableLengthStringField(Size, Description, Length);
}

/****************************************************************************/
// s_ChartbookSharingShared

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingShared::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingShared, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingShared::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingShared, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingShared::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingShared, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingShared::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingShared::GetDescription() const
{
	return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_ChartbookSharingShared, Description));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingShared::AddDescription(uint16_t Length)
{
	AddVariableLengthStringField(Size, Description, Length);
}

/****************************************************************************/
// s_ChartbookSharingShareUpdate

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingShareUpdate::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingShareUpdate, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingShareUpdate::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingShareUpdate, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingShareUpdate::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingShareUpdate, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingShareUpdate::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingShareUpdate::GetDescription() const
{
	return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_ChartbookSharingShareUpdate, Description));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingShareUpdate::AddDescription(uint16_t Length)
{
	AddVariableLengthStringField(Size, Description, Length);
}

/****************************************************************************/
// s_ChartbookSharingAllowClient

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingAllowClient::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingAllowClient, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingAllowClient::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingAllowClient, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingAllowClient::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingAllowClient, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingAllowClient::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/****************************************************************************/
// s_ChartbookSharingAllowedClient

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingAllowedClient::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingAllowedClient, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingAllowedClient::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingAllowedClient, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingAllowedClient::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingAllowedClient, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingAllowedClient::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/****************************************************************************/
// s_ChartbookSharingUnShare

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingUnShare::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingUnShare, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingUnShared

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingUnShared::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingUnShared, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingUnShared::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingUnShared, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingUnShared::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingUnShared::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingUnShared, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingUnShared::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/****************************************************************************/
// s_ChartbookSharingSubscribe

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingSubscribe::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingSubscribe, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingSubscribed

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingSubscribed::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingSubscribed, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingSubscribed::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingSubscribed, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingSubscribed::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingSubscribed::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingSubscribed, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingSubscribed::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/****************************************************************************/
// s_ChartbookSharingUnSubscribe

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingUnSubscribe::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingUnSubscribe, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingUnSubscribed

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingUnSubscribed::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingUnSubscribed, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingUnSubscribed::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingUnSubscribed, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingUnSubscribed::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingUnSubscribed::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingUnSubscribed, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingUnSubscribed::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/****************************************************************************/
// s_ChartbookSharingStart

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingStart::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingStart, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingStarted

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingStarted::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingStarted, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingStarted::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingStarted, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingStarted::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingStarted, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingStarted::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingStarted::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingStarted, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingStarted::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/****************************************************************************/
// s_ChartbookSharingStop

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingStop::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingStop, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingStopped

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingStopped::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingStopped, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingStopped::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingStopped, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingStopped::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingStopped, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingStopped::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingStopped::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingStopped, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingStopped::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/****************************************************************************/
// s_ChartbookSharingPause

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingPause::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingPause, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingPaused

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingPaused::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingPaused, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingPaused::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingPaused, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingPaused::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingPaused::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingPaused, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingPaused::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/****************************************************************************/
// s_ChartbookSharingResume

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingResume::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingResume, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/****************************************************************************/
// s_ChartbookSharingResumed

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingResumed::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingResumed, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingResumed::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingResumed, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingResumed::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingResumed::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingResumed, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingResumed::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/****************************************************************************/
// s_ChartbookSharingDelegate

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingDelegate::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingDelegate, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingDelegate::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingDelegate, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingDelegate::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/****************************************************************************/
// s_ChartbookSharingDelegated

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingDelegated::GetFileID() const
{
	if (Size < offsetof(s_ChartbookSharingDelegated, FileID) + sizeof(FileID))
		return 0;

	return FileID;
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingDelegated::GetUsername() const
{
	return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_ChartbookSharingDelegated, Username));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingDelegated::AddUsername(uint16_t Length)
{
	AddVariableLengthStringField(Size, Username, Length);
}

/*==========================================================================*/
const char* DTC_VLS::s_ChartbookSharingDelegated::GetFileName() const
{
	return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChartbookSharingDelegated, FileName));
}

/*==========================================================================*/
void DTC_VLS::s_ChartbookSharingDelegated::AddFileName(uint16_t Length)
{
	AddVariableLengthStringField(Size, FileName, Length);
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChartbookSharingServerRestarted::GetFlags() const
{
	if (Size < offsetof(s_ChartbookSharingServerRestarted, Flags) + sizeof(Flags))
		return 0;

	return Flags;
}

/****************************************************************************/
// s_ConvertPositionToSubAccountBalanceAdjustments

/*==========================================================================*/
uint16_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustments::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustments::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustments::GetRequestID() const
{
	if (Size < offsetof(s_ConvertPositionToSubAccountBalanceAdjustments, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustments::GetIsSimulated() const
{
	if (Size < offsetof(s_ConvertPositionToSubAccountBalanceAdjustments, IsSimulated) + sizeof(IsSimulated))
		return 0;

	return IsSimulated;
}

/****************************************************************************/
// s_ConvertPositionToSubAccountBalanceAdjustmentsReject

/*==========================================================================*/
uint16_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsReject::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsReject::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsReject::GetRequestID() const
{
	if (Size < offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsReject, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsReject::GetIsSimulated() const
{
	if (Size < offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsReject, IsSimulated) + sizeof(IsSimulated))
		return 0;

	return IsSimulated;
}

/****************************************************************************/
// s_ConvertPositionToSubAccountBalanceAdjustmentsComplete

/*==========================================================================*/
uint16_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsComplete::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsComplete::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsComplete::GetRequestID() const
{
	if (Size < offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsComplete, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
int64_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsComplete::GetTransactionID() const
{
	if (Size < offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsComplete, TransactionID) + sizeof(TransactionID))
		return 0;

	return TransactionID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ConvertPositionToSubAccountBalanceAdjustmentsComplete::GetIsSimulated() const
{
	if (Size < offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsComplete, IsSimulated) + sizeof(IsSimulated))
		return 0;

	return IsSimulated;
}


/****************************************************************************/
//s_ChatServiceSetProfileSettings

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSetProfileSettings::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSetProfileSettings::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSetProfileSettings::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceSetProfileSettings, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceSetProfileSettings::GetSearchable() const
{
	if (Size < offsetof(s_ChatServiceSetProfileSettings, Searchable) + sizeof(Searchable))
		return 0;

	return Searchable;
}

/****************************************************************************/
//s_ChatServiceSetProfileSettingsResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSetProfileSettingsResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSetProfileSettingsResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSetProfileSettingsResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceSetProfileSettingsResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
//s_ChatServiceGetProfileSettings

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetProfileSettings::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetProfileSettings::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetProfileSettings::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetProfileSettings, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
//s_ChatServiceGetProfileSettingsResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetProfileSettingsResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetProfileSettingsResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetProfileSettingsResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetProfileSettingsResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetProfileSettingsResponse::GetSearchable() const
{
	if (Size < offsetof(s_ChatServiceGetProfileSettingsResponse, Searchable) + sizeof(Searchable))
		return 0;

	return Searchable;
}

/****************************************************************************/
//s_ChatServiceSendTextMessage

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSendTextMessage::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSendTextMessage::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSendTextMessage::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSendTextMessage::GetToChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, ToChatIdentifier) + sizeof(ToChatIdentifier))
		return 0;

	return ToChatIdentifier;
}

/*==========================================================================*/
int64_t DTC_VLS::s_ChatServiceSendTextMessage::GetCreationTime() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, CreationTime) + sizeof(CreationTime))
		return 0;

	return CreationTime;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSendTextMessage::GetReplyToMessageIdentifier() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, ReplyToMessageIdentifier) + sizeof(ReplyToMessageIdentifier))
		return 0;

	return ReplyToMessageIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSendTextMessage::GetUpdateForMessageIdentifier() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, UpdateForMessageIdentifier) + sizeof(UpdateForMessageIdentifier))
		return 0;

	return UpdateForMessageIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceSendTextMessage::GetDocumentAttachentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, DocumentAttachentIdentifier) + sizeof(DocumentAttachentIdentifier))
		return 0;

	return DocumentAttachentIdentifier;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSendTextMessage::GetMessageState() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, MessageState) + sizeof(MessageState))
		return 0;

	return MessageState;
}

/*==========================================================================*/
uint8_t	DTC_VLS::s_ChatServiceSendTextMessage::GetDeleteMessage() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, DeleteMessage) + sizeof(DeleteMessage))
		return 0;

	return DeleteMessage;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceSendTextMessage::GetFinalMessageInBatch() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessage, FinalMessageInBatch) + sizeof(FinalMessageInBatch))
		return 1;

	return FinalMessageInBatch;
}

/****************************************************************************/
//s_ChatServiceSendTextMessageResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSendTextMessageResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSendTextMessageResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSendTextMessageResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessageResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSendTextMessageResponse::GetToChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessageResponse, ToChatIdentifier) + sizeof(ToChatIdentifier))
		return 0;

	return ToChatIdentifier;
}

/*==========================================================================*/
int64_t DTC_VLS::s_ChatServiceSendTextMessageResponse::GetTimestamp() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessageResponse, Timestamp) + sizeof(Timestamp))
		return 0;

	return Timestamp;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSendTextMessageResponse::GetMessageState() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessageResponse, MessageState) + sizeof(MessageState))
		return 0;

	return MessageState;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSendTextMessageResponse::GetMessageIdentifier() const
{
	if (Size < offsetof(s_ChatServiceSendTextMessageResponse, MessageIdentifier) + sizeof(MessageIdentifier))
		return 0;

	return MessageIdentifier;
}

/****************************************************************************/
//s_ChatServiceGetTextMessages

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetTextMessages::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetTextMessages::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetTextMessages::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetTextMessages, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetTextMessages::GetChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetTextMessages, ChatIdentifier) + sizeof(ChatIdentifier))
		return 0;

	return ChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetTextMessages::GetLastDownloadedMessageIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetTextMessages, LastDownloadedMessageIdentifier) + sizeof(LastDownloadedMessageIdentifier))
		return 0;

	return LastDownloadedMessageIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetTextMessages::GetLimitDownloadingToDays() const
{
	if (Size < offsetof(s_ChatServiceGetTextMessages, LimitDownloadingToDays) + sizeof(LimitDownloadingToDays))
		return 0;

	return LimitDownloadingToDays;
}

/****************************************************************************/
//s_ChatServiceServerToClientTextMessage

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetMessageIdentifier() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, MessageIdentifier) + sizeof(MessageIdentifier))
		return 0;

	return MessageIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, ChatIdentifier) + sizeof(ChatIdentifier))
		return 0;

	return ChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetFromUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, FromUserIdentifier) + sizeof(FromUserIdentifier))
		return 0;

	return FromUserIdentifier;
}

/*==========================================================================*/
int64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetCreationTime() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, CreationTime) + sizeof(CreationTime))
		return 0;

	return CreationTime;
}

/*==========================================================================*/
int64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetTimestamp() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, Timestamp) + sizeof(Timestamp))
		return 0;

	return Timestamp;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetMessageState() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, MessageState) + sizeof(MessageState))
		return 0;

	return MessageState;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetReplyToMessageIdentifier() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, ReplyToMessageIdentifier) + sizeof(ReplyToMessageIdentifier))
		return 0;

	return ReplyToMessageIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetUpdateForMessageIdentifier() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, UpdateForMessageIdentifier) + sizeof(UpdateForMessageIdentifier))
		return 0;

	return UpdateForMessageIdentifier;
}

/*==========================================================================*/
uint8_t	DTC_VLS::s_ChatServiceServerToClientTextMessage::GetDeleteMessage() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, DeleteMessage) + sizeof(DeleteMessage))
		return 0;

	return DeleteMessage;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetDocumentAttachentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, DocumentAttachentIdentifier) + sizeof(DocumentAttachentIdentifier))
		return 0;

	return DocumentAttachentIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceServerToClientTextMessage::GetIsFinal() const
{
	if (Size < offsetof(s_ChatServiceServerToClientTextMessage, IsFinal) + sizeof(IsFinal))
		return 0;

	return IsFinal;
}

/****************************************************************************/
//s_ChatServiceCreateChatGroup

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceCreateChatGroup::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceCreateChatGroup::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceCreateChatGroup::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceCreateChatGroup::GetPeerUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, PeerUserIdentifier) + sizeof(PeerUserIdentifier))
		return 0;

	return PeerUserIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetIsPublicGroup() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, IsPublicGroup) + sizeof(IsPublicGroup))
		return 0;

	return IsPublicGroup;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetIsReadOnly() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetRelayToTelegram() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, RelayToTelegram) + sizeof(RelayToTelegram))
		return 0;

	return RelayToTelegram;

}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetRelayOwnMessagesToTelegram() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, RelayOwnMessagesToTelegram) + sizeof(RelayOwnMessagesToTelegram))
		return 0;

	return RelayOwnMessagesToTelegram;

}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetKeepUserListPrivate() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, KeepUserListPrivate) + sizeof(KeepUserListPrivate))
		return 0;

	return KeepUserListPrivate;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetAllowViewScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, AllowViewScreenSharing) + sizeof(AllowViewScreenSharing))
		return 0;

	return AllowViewScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetAllowSendScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, AllowSendScreenSharing) + sizeof(AllowSendScreenSharing))
		return 0;

	return AllowSendScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroup::GetAllowRemoteControl() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroup, AllowRemoteControl) + sizeof(AllowRemoteControl))
		return 0;

	return AllowRemoteControl;
}

/****************************************************************************/
//s_ChatServiceCreateChatGroupResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceCreateChatGroupResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceCreateChatGroupResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceCreateChatGroupResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroupResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceCreateChatGroupResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroupResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceCreateChatGroupResponse::GetPeerUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroupResponse, PeerUserIdentifier) + sizeof(PeerUserIdentifier))
		return 0;

	return PeerUserIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroupResponse::GetIsPublicGroup() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroupResponse, IsPublicGroup) + sizeof(IsPublicGroup))
		return 0;

	return IsPublicGroup;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceCreateChatGroupResponse::GetIsReadOnly() const
{
	if (Size < offsetof(s_ChatServiceCreateChatGroupResponse, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/****************************************************************************/
//s_ChatServiceAddChatGroupMember

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceAddChatGroupMember::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceAddChatGroupMember::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceAddChatGroupMember::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMember, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceAddChatGroupMember::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMember, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceAddChatGroupMember::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMember, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceAddChatGroupMember::GetAccessRights() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMember, AccessRights) + sizeof(AccessRights))
		return 0;

	return AccessRights;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceAddChatGroupMember::GetIsFinal() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMember, IsFinal) + sizeof(IsFinal))
		return 0;

	return IsFinal;
}

/****************************************************************************/
//s_ChatServiceAddChatGroupMemberResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceAddChatGroupMemberResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceAddChatGroupMemberResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceAddChatGroupMemberResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMemberResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceAddChatGroupMemberResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMemberResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceAddChatGroupMemberResponse::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMemberResponse, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceAddChatGroupMemberResponse::GetAccessRights() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMemberResponse, AccessRights) + sizeof(AccessRights))
		return 0;

	return AccessRights;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceAddChatGroupMemberResponse::GetResult() const
{
	if (Size < offsetof(s_ChatServiceAddChatGroupMemberResponse, Result) + sizeof(Result))
		return 0;

	return Result;
}

/****************************************************************************/
//s_ChatServiceUpdateChatGroupMember

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroupMember::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroupMember::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupMember::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMember, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupMember::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMember, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupMember::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMember, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceUpdateChatGroupMember::GetAccessRights() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMember, AccessRights) + sizeof(AccessRights))
		return 0;

	return AccessRights;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroupMember::GetIsFinal() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMember, IsFinal) + sizeof(IsFinal))
		return 0;

	return IsFinal;
}

/****************************************************************************/
//s_ChatServiceUpdateChatGroupMemberResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMemberResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMemberResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMemberResponse, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetAccessRights() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMemberResponse, AccessRights) + sizeof(AccessRights))
		return 0;

	return AccessRights;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetResult() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMemberResponse, Result) + sizeof(Result))
		return 0;

	return Result;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroupMemberResponse::GetIsFinal() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupMemberResponse, IsFinal) + sizeof(IsFinal))
		return 0;

	return IsFinal;
}

/****************************************************************************/
//s_ChatServiceDeleteChatGroupMember

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroupMember::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroupMember::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupMember::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMember, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupMember::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMember, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupMember::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMember, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}


/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceDeleteChatGroupMember::GetIsFinal() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMember, IsFinal) + sizeof(IsFinal))
		return 0;

	return IsFinal;
}

/****************************************************************************/
//s_ChatServiceDeleteChatGroupMemberResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroupMemberResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroupMemberResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupMemberResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMemberResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupMemberResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMemberResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupMemberResponse::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMemberResponse, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceDeleteChatGroupMemberResponse::GetResult() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMemberResponse, Result) + sizeof(Result))
		return 0;

	return Result;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceDeleteChatGroupMemberResponse::GetIsFinal() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupMemberResponse, IsFinal) + sizeof(IsFinal))
		return 0;

	return IsFinal;
}

/****************************************************************************/
//s_ChatServiceDeleteChatGroup

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroup::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroup::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroup::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroup, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroup::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroup, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/****************************************************************************/
//s_ChatServiceDeleteChatGroupResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroupResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDeleteChatGroupResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDeleteChatGroupResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceDeleteChatGroupResponse::GetResult() const
{
	if (Size < offsetof(s_ChatServiceDeleteChatGroupResponse, Result) + sizeof(Result))
		return 0;

	return Result;
}

/****************************************************************************/
//s_ChatServiceRenameChatGroup

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}


/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetIsPublicGroup() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, IsPublicGroup) + sizeof(IsPublicGroup))
		return 0;

	return IsPublicGroup;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetIsReadOnly() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetRelayToTelegram() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, RelayToTelegram) + sizeof(RelayToTelegram))
		return 0;

	return RelayToTelegram;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetRelayOwnMessagesToTelegram() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, RelayOwnMessagesToTelegram) + sizeof(RelayOwnMessagesToTelegram))
		return 0;

	return RelayOwnMessagesToTelegram;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetKeepUserListPrivate() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, KeepUserListPrivate) + sizeof(KeepUserListPrivate))
		return 0;

	return KeepUserListPrivate;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetAllowViewScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, AllowViewScreenSharing) + sizeof(AllowViewScreenSharing))
		return 0;

	return AllowViewScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetAllowSendScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, AllowSendScreenSharing) + sizeof(AllowSendScreenSharing))
		return 0;

	return AllowSendScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroup::GetAllowRemoteControl() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroup, AllowRemoteControl) + sizeof(AllowRemoteControl))
		return 0;

	return AllowRemoteControl;
}

/****************************************************************************/
//s_ChatServiceRenameChatGroupResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetResult() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, Result) + sizeof(Result))
		return 0;

	return Result;
}

/*==========================================================================*/
int8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetIsPublicGroup() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, IsPublicGroup) + sizeof(IsPublicGroup))
		return 0;

	return IsPublicGroup;
}

/*==========================================================================*/
int8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetIsReadOnly() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/*==========================================================================*/
int8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetRelayToTelegram() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, RelayToTelegram) + sizeof(RelayToTelegram))
		return 0;

	return RelayToTelegram;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetRelayOwnMessagesToTelegram() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, RelayOwnMessagesToTelegram) + sizeof(RelayOwnMessagesToTelegram))
		return 0;

	return RelayOwnMessagesToTelegram;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetKeepUserListPrivate() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, KeepUserListPrivate) + sizeof(KeepUserListPrivate))
		return 0;

	return KeepUserListPrivate;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetAllowViewScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, AllowViewScreenSharing) + sizeof(AllowViewScreenSharing))
		return 0;

	return AllowViewScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetAllowSendScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, AllowSendScreenSharing) + sizeof(AllowSendScreenSharing))
		return 0;

	return AllowSendScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceUpdateChatGroupResponse::GetAllowRemoteControl() const
{
	if (Size < offsetof(s_ChatServiceUpdateChatGroupResponse, AllowRemoteControl) + sizeof(AllowRemoteControl))
		return 0;

	return AllowRemoteControl;
}

/****************************************************************************/
//s_ChatServiceGetChatGroupMembers

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatGroupMembers::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatGroupMembers::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatGroupMembers::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembers, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatGroupMembers::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembers, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatGroupMembers::GetUpdateId() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembers, UpdateId) + sizeof(UpdateId))
		return 0;

	return UpdateId;
}

/****************************************************************************/
//s_ChatServiceGetChatGroupMembersResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetCurrentGroupMemberIndex() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, CurrentGroupMemberIndex) + sizeof(CurrentGroupMemberIndex))
		return 0;

	return CurrentGroupMemberIndex;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetLastGroupMemberIndex() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, LastGroupMemberIndex) + sizeof(LastGroupMemberIndex))
		return 0;

	return LastGroupMemberIndex;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetAccessRights() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, AccessRights) + sizeof(AccessRights))
		return 0;

	return AccessRights;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetIsDeleted() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, IsDeleted) + sizeof(IsDeleted))
		return 0;

	return IsDeleted;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetChatGroupMembersResponse::GetUpdateIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatGroupMembersResponse, UpdateIdentifier) + sizeof(UpdateIdentifier))
		return 0;

	return UpdateIdentifier;
}

/****************************************************************************/
//s_ChatServiceGetChatsList

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatsList::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatsList::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatsList::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetChatsList, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetChatsList::GetUpdateIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatsList, UpdateIdentifier) + sizeof(UpdateIdentifier))
		return 0;

	return UpdateIdentifier;
}


/****************************************************************************/
//s_ChatServiceGetChatsListResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetCurrentChatIndex() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, CurrentChatIndex) + sizeof(CurrentChatIndex))
		return 0;

	return CurrentChatIndex;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetLastIndex() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, LastIndex) + sizeof(LastIndex))
		return 0;

	return LastIndex;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetIsDeletedChat() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, IsDeletedChat) + sizeof(IsDeletedChat))
		return 0;

	return IsDeletedChat;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetIsGroupChat() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, IsGroupChat) + sizeof(IsGroupChat))
		return 0;

	return IsGroupChat;
}

/*==========================================================================*/

uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetIsLeftChat() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, IsLeftChat) + sizeof(IsLeftChat))
		return 0;

	return IsLeftChat;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetUpdateIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, UpdateIdentifier) + sizeof(UpdateIdentifier))
		return 0;

	return UpdateIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetRecordIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, RecordIdentifier) + sizeof(RecordIdentifier))
		return 0;

	return RecordIdentifier;
}


/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetIsPublicGroup() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, IsPublicGroup) + sizeof(IsPublicGroup))
		return 0;

	return IsPublicGroup;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetIsReadOnly() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, IsReadOnly) + sizeof(IsReadOnly))
		return 0;

	return IsReadOnly;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetRelayToTelegram() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, RelayToTelegram) + sizeof(RelayToTelegram))
		return 0;

	return RelayToTelegram;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetRelayOwnMessagesToTelegram() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, RelayOwnMessagesToTelegram) + sizeof(RelayOwnMessagesToTelegram))
		return 0;

	return RelayOwnMessagesToTelegram;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetKeepUserListPrivate() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, KeepUserListPrivate) + sizeof(KeepUserListPrivate))
		return 0;

	return KeepUserListPrivate;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetAllowViewScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, AllowViewScreenSharing) + sizeof(AllowViewScreenSharing))
		return 0;

	return AllowViewScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetAllowSendScreenSharing() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, AllowSendScreenSharing) + sizeof(AllowSendScreenSharing))
		return 0;

	return AllowSendScreenSharing;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceGetChatsListResponse::GetAllowRemoteControl() const
{
	if (Size < offsetof(s_ChatServiceGetChatsListResponse, AllowRemoteControl) + sizeof(AllowRemoteControl))
		return 0;

	return AllowRemoteControl;
}

/****************************************************************************/
//s_ChatServiceGetUserInformation

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetUserInformation::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetUserInformation::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetUserInformation::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetUserInformation, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetUserInformation::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetUserInformation, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}


/****************************************************************************/
//s_ChatServiceGetUserInformationResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetUserInformationResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetUserInformationResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetUserInformationResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetUserInformationResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetUserInformationResponse::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetUserInformationResponse, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}


/****************************************************************************/
//s_ChatServiceFindUserByName

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceFindUserByName::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceFindUserByName::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceFindUserByName::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceFindUserByName, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceFindUserByName::GetDoSmartSearch() const
{
	if (Size < offsetof(s_ChatServiceFindUserByName, DoSmartSearch) + sizeof(DoSmartSearch))
		return 0;

	return DoSmartSearch;
}

/****************************************************************************/
//s_ChatServiceFindUserByNameResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceFindUserByNameResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceFindUserByNameResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceFindUserByNameResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceFindUserByNameResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceFindUserByNameResponse::GetAmountOfItems() const
{
	if (Size < offsetof(s_ChatServiceFindUserByNameResponse, AmountOfItems) + sizeof(AmountOfItems))
		return 0;

	return AmountOfItems;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatServiceFindUserByNameResponse::GetDoSmartSearch() const
{
	if (Size < offsetof(s_ChatServiceFindUserByNameResponse, DoSmartSearch) + sizeof(DoSmartSearch))
		return 0;

	return DoSmartSearch;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceFindUserByNameResponse::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceFindUserByNameResponse, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceFindUserByNameResponse::GetCurrentItem() const
{
	if (Size < offsetof(s_ChatServiceFindUserByNameResponse, CurrentItem) + sizeof(CurrentItem))
		return 0;

	return CurrentItem;
}

/****************************************************************************/
//s_ChatServiceStartUploadFile

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceStartUploadFile::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceStartUploadFile::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceStartUploadFile::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceStartUploadFile, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceStartUploadFile::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceStartUploadFile, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceStartUploadFile::GetFileSize() const
{
	if (Size < offsetof(s_ChatServiceStartUploadFile, FileSize) + sizeof(FileSize))
		return 0;

	return FileSize;
}

/****************************************************************************/
//s_ChatServiceStartUploadFileResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceStartUploadFileResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceStartUploadFileResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceStartUploadFileResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceStartUploadFileResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceStartUploadFileResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceStartUploadFileResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceStartUploadFileResponse::GetFileSize() const
{
	if (Size < offsetof(s_ChatServiceStartUploadFileResponse, FileSize) + sizeof(FileSize))
		return 0;

	return FileSize;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceStartUploadFileResponse::GetDocumentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceStartUploadFileResponse, DocumentIdentifier) + sizeof(DocumentIdentifier))
		return 0;

	return DocumentIdentifier;
}

/****************************************************************************/
//s_ChatServiceUploadFile

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUploadFile::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUploadFile::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUploadFile::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceUploadFile, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUploadFile::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUploadFile, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceUploadFile::GetDocumentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUploadFile, DocumentIdentifier) + sizeof(DocumentIdentifier))
		return 0;

	return DocumentIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUploadFile::GetBlockOffset() const
{
	if (Size < offsetof(s_ChatServiceUploadFile, BlockOffset) + sizeof(BlockOffset))
		return 0;

	return BlockOffset;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceUploadFile::GetBlockSize() const
{
	if (Size < offsetof(s_ChatServiceUploadFile, BlockSize) + sizeof(BlockSize))
		return 0;

	return BlockSize;
}


/****************************************************************************/
//s_ChatServiceUploadFileResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUploadFileResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceUploadFileResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUploadFileResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceUploadFileResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUploadFileResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUploadFileResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceUploadFileResponse::GetDocumentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceUploadFileResponse, DocumentIdentifier) + sizeof(DocumentIdentifier))
		return 0;

	return DocumentIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceUploadFileResponse::GetBlockOffset() const
{
	if (Size < offsetof(s_ChatServiceUploadFileResponse, BlockOffset) + sizeof(BlockOffset))
		return 0;

	return BlockOffset;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceUploadFileResponse::GetBlockSize() const
{
	if (Size < offsetof(s_ChatServiceUploadFileResponse, BlockSize) + sizeof(BlockSize))
		return 0;

	return BlockSize;
}

/*==========================================================================*/
uint8_t  DTC_VLS::s_ChatServiceUploadFileResponse::GetUploadingResult() const
{
	if (Size < offsetof(s_ChatServiceUploadFileResponse, UploadingResult) + sizeof(UploadingResult))
		return 0;

	return UploadingResult;
}

/****************************************************************************/
//s_ChatServiceDownloadFile

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDownloadFile::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDownloadFile::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDownloadFile::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceDownloadFile, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDownloadFile::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDownloadFile, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceDownloadFile::GetDocumentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDownloadFile, DocumentIdentifier) + sizeof(DocumentIdentifier))
		return 0;

	return DocumentIdentifier;
}

/****************************************************************************/
//s_ChatServiceDownloadFileResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceDownloadFileResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDownloadFileResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetDocumentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceDownloadFileResponse, DocumentIdentifier) + sizeof(DocumentIdentifier))
		return 0;

	return DocumentIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetFileSize() const
{
	if (Size < offsetof(s_ChatServiceDownloadFileResponse, FileSize) + sizeof(FileSize))
		return 0;

	return FileSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetBlockOffset() const
{
	if (Size < offsetof(s_ChatServiceDownloadFileResponse, BlockOffset) + sizeof(BlockOffset))
		return 0;

	return BlockOffset;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceDownloadFileResponse::GetBlockSize() const
{
	if (Size < offsetof(s_ChatServiceDownloadFileResponse, BlockSize) + sizeof(BlockSize))
		return 0;

	return BlockSize;
}

/****************************************************************************/
//s_ChatServiceGetFileInformation

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetFileInformation::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetFileInformation::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetFileInformation::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetFileInformation, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetFileInformation::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetFileInformation, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetFileInformation::GetDocumentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetFileInformation, DocumentIdentifier) + sizeof(DocumentIdentifier))
		return 0;

	return DocumentIdentifier;
}

/****************************************************************************/
//s_ChatServiceGetFileInformationResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetFileInformationResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetFileInformationResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetFileInformationResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetFileInformationResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetFileInformationResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetFileInformationResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatServiceGetFileInformationResponse::GetDocumentIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetFileInformationResponse, DocumentIdentifier) + sizeof(DocumentIdentifier))
		return 0;

	return DocumentIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetFileInformationResponse::GetFileSize() const
{
	if (Size < offsetof(s_ChatServiceGetFileInformationResponse, FileSize) + sizeof(FileSize))
		return 0;

	return FileSize;
}

/****************************************************************************/
//s_ChatServiceSearchPublicGroups

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSearchPublicGroups::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSearchPublicGroups::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSearchPublicGroups::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceSearchPublicGroups, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
//s_ChatServiceSearchPublicGroupsResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSearchPublicGroupsResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceSearchPublicGroupsResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSearchPublicGroupsResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceSearchPublicGroupsResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceSearchPublicGroupsResponse::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceSearchPublicGroupsResponse, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceSearchPublicGroupsResponse::GetCurrentIndex() const
{
	if (Size < offsetof(s_ChatServiceSearchPublicGroupsResponse, CurrentIndex) + sizeof(CurrentIndex))
		return 0;

	return CurrentIndex;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatServiceSearchPublicGroupsResponse::GetResultArraySize() const
{
	if (Size < offsetof(s_ChatServiceSearchPublicGroupsResponse, ResultArraySize) + sizeof(ResultArraySize))
		return 0;

	return ResultArraySize;
}

/****************************************************************************/
//s_ChatServiceJoinPublicGroup

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceJoinPublicGroup::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceJoinPublicGroup::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceJoinPublicGroup::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceJoinPublicGroup, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceJoinPublicGroup::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatServiceJoinPublicGroup, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}



/****************************************************************************/
//s_ScreenShareRemoteControlNegotiation

/*==========================================================================*/
uint16_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetMessageSize() const
{
	return Size;
}


/*==========================================================================*/
uint16_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetRequestID() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetState() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, State) + sizeof(State))
		return 0;

	return State;
}

/*==========================================================================*/
void DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetKey(uint8_t(*p_Key)[32]) const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, Key) + sizeof(Key))
		return;

	memcpy(*p_Key, &Key, sizeof(Key));
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetUnixTimeStampMS() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, UnixTimeStampMS) + sizeof(UnixTimeStampMS))
		return 0;

	return UnixTimeStampMS;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetRole() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, Role) + sizeof(Role))
		return 0;

	return Role;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetScreenSharingUserIdentifier() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, ScreenSharingUserIdentifier) + sizeof(ScreenSharingUserIdentifier))
		return 0;

	return ScreenSharingUserIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetCreatorOfSession() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, CreatorOfSession) + sizeof(CreatorOfSession))
		return 0;

	return CreatorOfSession;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetBitPerSample() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, BitPerSample) + sizeof(BitPerSample))
		return 0;

	return BitPerSample;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetScreenFormat() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, ScreenFormat) + sizeof(ScreenFormat))
		return 0;

	return ScreenFormat;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetCompressionAlgorithm() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, CompressionAlgorithm) + sizeof(CompressionAlgorithm))
		return 0;

	return CompressionAlgorithm;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetUniqueRdpSessionIdentifier() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, UniqueRdpSessionIdentifier) + sizeof(UniqueRdpSessionIdentifier))
	{
		return 0;
	}

	return UniqueRdpSessionIdentifier;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetDropVideoFramesIfGreaterEqualMillisecondsOfDataInSendBuffer() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, DropVideoFramesIfGreaterEqualMillisecondsOfDataInSendBuffer) + sizeof(DropVideoFramesIfGreaterEqualMillisecondsOfDataInSendBuffer))
	{
		return 0;
	}

	return DropVideoFramesIfGreaterEqualMillisecondsOfDataInSendBuffer;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetIsDirectPeerToPeer() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, IsDirectPeerToPeer) + sizeof(IsDirectPeerToPeer))
	{
		return 0;
	}

	return IsDirectPeerToPeer;
}

/*==========================================================================*/
int16_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetPeerToPeerServerPortNumber() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, PeerToPeerServerPortNumber) + sizeof(PeerToPeerServerPortNumber))
	{
		return 0;
	}

	return PeerToPeerServerPortNumber;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ScreenShareRemoteControlNegotiation::GetPeerToPeerServerIPAddress() const
{
	if (Size < offsetof(s_ScreenShareRemoteControlNegotiation, PeerToPeerServerIPAddress) + sizeof(PeerToPeerServerIPAddress))
	{
		return 0;
	}

	return PeerToPeerServerIPAddress;
}

/*==========================================================================*/
void DTC_VLS::s_ScreenShareRemoteControlNegotiation::SetKey(const uint8_t NewKey[32])
{
	memcpy(Key, NewKey, sizeof(Key));
}


/****************************************************************************/
//s_ChatServiceGetConnectionInformation

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetConnectionInformation::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetConnectionInformation::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetConnectionInformation::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetConnectionInformation, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/****************************************************************************/
//s_ChatServiceGetConnectionInformationResponse

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetConnectionInformationResponse::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatServiceGetConnectionInformationResponse::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetConnectionInformationResponse::GetRequestID() const
{
	if (Size < offsetof(s_ChatServiceGetConnectionInformationResponse, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatServiceGetConnectionInformationResponse::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatServiceGetConnectionInformationResponse, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/****************************************************************************/
//s_ChatRemoteControlStopNotification

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatRemoteControlInputData::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatRemoteControlInputData::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlInputData::GetRequestID() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlInputData::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatRemoteControlInputData::GetInputTypeFlag() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, InputTypeFlag) + sizeof(InputTypeFlag))
		return 0;

	return InputTypeFlag;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatRemoteControlInputData::GetMouseX() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, MouseX) + sizeof(MouseX))
		return 0;

	return MouseX;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatRemoteControlInputData::GetMouseY() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, MouseY) + sizeof(MouseY))
		return 0;

	return MouseY;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatRemoteControlInputData::GetMouseData() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, MouseData) + sizeof(MouseData))
		return 0;

	return MouseData;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatRemoteControlInputData::GetMouseFlags() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, MouseFlags) + sizeof(MouseFlags))
		return 0;

	return MouseFlags;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlInputData::GetMouseMessage() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, MouseMessage) + sizeof(MouseMessage))
		return 0;

	return MouseMessage;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatRemoteControlInputData::GetKeyboardVirtualKey() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, KeyboardVirtualKey) + sizeof(KeyboardVirtualKey))
		return 0;

	return KeyboardVirtualKey;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatRemoteControlInputData::GetKeyboardScanCode() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, KeyboardScanCode) + sizeof(KeyboardScanCode))
		return 0;

	return KeyboardScanCode;
}

/*==========================================================================*/
uint32_t DTC_VLS::s_ChatRemoteControlInputData::GetKeyboardFlags() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, KeyboardFlags) + sizeof(KeyboardFlags))
		return 0;

	return KeyboardFlags;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlInputData::GetKeyboardMessage() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, KeyboardMessage) + sizeof(KeyboardMessage))
		return 0;

	return KeyboardMessage;
}

/*==========================================================================*/
int32_t DTC_VLS::s_ChatRemoteControlInputData::GetRepeatCount() const
{
	if (Size < offsetof(s_ChatRemoteControlInputData, RepeatCount) + sizeof(RepeatCount))
		return 0;

	return RepeatCount;
}

/****************************************************************************/
//s_ChatRemoteControlSessionState

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatRemoteControlSessionState::GetMessageSize() const
{
	return Size;
}

/*==========================================================================*/
uint16_t DTC_VLS::s_ChatRemoteControlSessionState::GetBaseSize() const
{
	return BaseSize;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlSessionState::GetRequestID() const
{
	if (Size < offsetof(s_ChatRemoteControlSessionState, RequestID) + sizeof(RequestID))
		return 0;

	return RequestID;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlSessionState::GetUniqueChatIdentifier() const
{
	if (Size < offsetof(s_ChatRemoteControlSessionState, UniqueChatIdentifier) + sizeof(UniqueChatIdentifier))
		return 0;

	return UniqueChatIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlSessionState::GetUniqueRdpSessionIdentifier() const
{
	if (Size < offsetof(s_ChatRemoteControlSessionState, UniqueRdpSessionIdentifier) + sizeof(UniqueRdpSessionIdentifier))
		return 0;

	return UniqueRdpSessionIdentifier;
}

/*==========================================================================*/
uint64_t DTC_VLS::s_ChatRemoteControlSessionState::GetUserIdentifier() const
{
	if (Size < offsetof(s_ChatRemoteControlSessionState, UserIdentifier) + sizeof(UserIdentifier))
		return 0;

	return UserIdentifier;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatRemoteControlSessionState::GetRole() const
{
	if (Size < offsetof(s_ChatRemoteControlSessionState, Role) + sizeof(Role))
		return 0;

	return Role;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatRemoteControlSessionState::GetState() const
{
	if (Size < offsetof(s_ChatRemoteControlSessionState, State) + sizeof(State))
		return 0;

	return State;
}

/*==========================================================================*/
uint8_t DTC_VLS::s_ChatRemoteControlSessionState::GetFinal() const
{
	if (Size < offsetof(s_ChatRemoteControlSessionState, Final) + sizeof(Final))
		return 0;

	return Final;
}

/*==========================================================================*/
