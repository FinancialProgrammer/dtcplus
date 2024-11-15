#pragma once

#include "dtcc/dtcvls.hpp"

// Contains both binary and binary with variable length string messages
namespace n_DTCNonStandard
{
	const int FILE_CONTENT_SIZE = 63 * 1024;
	const int VIDEO_CONTENT_SIZE = 63 * 1024;

	/*==========================================================================*/
	//Nonstandard messages.
	const uint16_t HISTORICAL_TRADES_REQUEST = 10100;
	const uint16_t HISTORICAL_TRADES_REJECT = 10101;
	const uint16_t HISTORICAL_TRADES_RESPONSE = 10102;
	const uint16_t REPLAY_CHART_DATA = 10104;
	const uint16_t REPLAY_CHART_DATA_PERFORM_ACTION = 10105;
	const uint16_t REPLAY_CHART_DATA_STATUS = 10106;
	const uint16_t REQUEST_NUM_CURRENT_CLIENT_CONNECTIONS = 10107;
	const uint16_t NUM_CURRENT_CLIENT_CONNECTIONS_RESPONSE = 10108;

	const uint16_t SC_CONFIGURATION_SYNCHRONIZATION = 10109;
	const uint16_t SC_TRADE_ORDER = 10110;
	const uint16_t INDIVIDUAL_TRADE_POSITION = 10112;
	const uint16_t TRADE_POSITION_CONSOLIDATED = 10113;
	const uint16_t TRADE_ACTIVITY_DATA = 10114;

	const uint16_t TRADE_ACCOUNT_DATA_REQUEST = 10115;// Requests all trade account data including sharing data.

	const uint16_t TRADE_ACCOUNT_DATA_RESPONSE = 10116;
	const uint16_t TRADE_ACCOUNT_DATA_UPDATE = 10117;
	const uint16_t TRADE_ACCOUNT_DATA_DELETE = 10118;

	const uint16_t TRADE_ACCOUNT_DATA_SYMBOL_COMMISSION_RESPONSE = 10119;
	const uint16_t TRADE_ACCOUNT_DATA_SYMBOL_COMMISSION_UPDATE = 10120;

	const uint16_t TRADE_ACCOUNT_DATA_SYMBOL_LIMITS_RESPONSE = 10121;
	const uint16_t TRADE_ACCOUNT_DATA_SYMBOL_LIMITS_UPDATE = 10122;

	const uint16_t TRADE_ACCOUNT_DATA_AUTHORIZED_USERNAME_RESPONSE = 10124;
	const uint16_t TRADE_ACCOUNT_DATA_AUTHORIZED_USERNAME_ADD = 10125;
	const uint16_t TRADE_ACCOUNT_DATA_AUTHORIZED_USERNAME_REMOVE = 10126;

	const uint16_t TRADE_ACCOUNT_DATA_USERNAME_TO_SHARE_WITH_RESPONSE = 10127;
	const uint16_t TRADE_ACCOUNT_DATA_USERNAME_TO_SHARE_WITH_ADD = 10128;
	const uint16_t TRADE_ACCOUNT_DATA_USERNAME_TO_SHARE_WITH_REMOVE = 10129;

	const uint16_t TRADE_ACCOUNT_DATA_RESPONSE_TRAILER = 10130;
	const uint16_t TRADE_ACCOUNT_DATA_UPDATE_OPERATION_COMPLETE = 10131;

	const uint16_t PROCESSED_FILL_IDENTIFIER = 10132;
	const uint16_t INTERPROCESS_SYNCHRONIZATION_SNAPSHOT_REQUEST = 10133;

	const uint16_t INTERPROCESS_SYNCHRONIZATION_REMOTE_STATE = 10134;
	const uint16_t FLATTEN_POSITIONS_FOR_TRADE_ACCOUNT = 10135;

	const uint16_t USER_INFORMATION = 10136;

	const uint16_t INTERPROCESS_SYNCHRONIZATION_TRADE_ACTIVITY_REQUEST = 10137;
	const uint16_t DOWNLOAD_HISTORICAL_ORDER_FILL_AND_ACCOUNT_BALANCE_DATA = 10138;
	const uint16_t CLIENT_DEVICE_UPDATE = 10139;
	const uint16_t WRITE_INTRADAY_DATA_FILE_SESSION_VALUE = 10140;

	const uint16_t MARGIN_DATA_REQUEST = 10141;
	const uint16_t MARGIN_DATA_RESPONSE = 10142;

	const uint16_t CONVERT_POSITION_TO_SUB_ACCOUNT_BALANCE_ADJUSTMENTS = 10203;
	const uint16_t CONVERT_POSITION_TO_SUB_ACCOUNT_BALANCE_ADJUSTMENTS_REJECT = 10204;
	const uint16_t CONVERT_POSITION_TO_SUB_ACCOUNT_BALANCE_ADJUSTMENTS_COMPLETE = 10205;

	// Chartbook Sharing messages
	const uint16_t CHARTBOOK_SHARING_SEARCH = 10144;
	const uint16_t CHARTBOOK_SHARING_SHARED_CHARTBOOK = 10145;
	const uint16_t CHARTBOOK_SHARING_GET_INFO = 10146;
	const uint16_t CHARTBOOK_SHARING_GET_UPDATE = 10147;
	const uint16_t CHARTBOOK_SHARING_SHARE = 10148;
	const uint16_t CHARTBOOK_SHARING_SHARED = 10149;
	const uint16_t CHARTBOOK_SHARING_SHARE_UPDATE = 10150;
	const uint16_t CHARTBOOK_SHARING_ALLOW_CLIENT = 10151;
	const uint16_t CHARTBOOK_SHARING_ALLOWED_CLIENT = 10152;
	const uint16_t CHARTBOOK_SHARING_DISALLOW_CLIENT = 10153;
	const uint16_t CHARTBOOK_SHARING_UNSHARE = 10154;
	const uint16_t CHARTBOOK_SHARING_UNSHARED = 10155;
	const uint16_t CHARTBOOK_SHARING_SUBSCRIBE = 10156;
	const uint16_t CHARTBOOK_SHARING_SUBSCRIBED = 10157;
	const uint16_t CHARTBOOK_SHARING_UNSUBSCRIBE = 10158;
	const uint16_t CHARTBOOK_SHARING_UNSUBSCRIBED = 10159;
	const uint16_t CHARTBOOK_SHARING_START = 10160;
	const uint16_t CHARTBOOK_SHARING_STARTED = 10161;
	const uint16_t CHARTBOOK_SHARING_STOP = 10162;
	const uint16_t CHARTBOOK_SHARING_STOPPED = 10163;
	const uint16_t CHARTBOOK_SHARING_SUSPEND = 10164;
	const uint16_t CHARTBOOK_SHARING_SUSPENDED = 10165;
	const uint16_t CHARTBOOK_SHARING_RESUME = 10166;
	const uint16_t CHARTBOOK_SHARING_RESUMED = 10167;
	const uint16_t CHARTBOOK_SHARING_DELEGATE = 10168;
	const uint16_t CHARTBOOK_SHARING_DELEGATED = 10169;
	const uint16_t CHARTBOOK_SHARING_CONNECT = 10170;
	const uint16_t CHARTBOOK_SHARING_CONNECTED = 10171;
	const uint16_t CHARTBOOK_SHARING_SERVER_RESTARTED = 10172;
	const uint16_t CHARTBOOK_SHARING_DISCONNECT = 10173;
	const uint16_t CHARTBOOK_SHARING_DISCONNECTED = 10174;
	const uint16_t CHARTBOOK_BINARY_DATA_TRANSFER = 10175;

	const uint16_t MARKET_DATA_UPDATE_ORDER_IMBALANCE_DATA = 10200;

	const uint16_t TRADE_ACCOUNT_DATA_SUB_ACCOUNT_RESPONSE = 10201;
	const uint16_t TRADE_ACCOUNT_DATA_SUB_ACCOUNT_UPDATE = 10202;

	const uint16_t TRADE_ACCOUNT_TRADING_IS_DISABLED_REQUEST = 10206;
	const uint16_t TRADE_ACCOUNT_TRADING_IS_DISABLED_RESPONSE = 10207;
	const uint16_t TRADE_ACCOUNT_DATA_DUPLICATE = 10208;

	const uint16_t USER_PROFIT_LOSS_MANAGEMENT_DATA_RESPONSE = 10209;
	const uint16_t USER_PROFIT_LOSS_MANAGEMENT_DATA_UPDATE = 10210;
	const uint16_t USER_PROFIT_LOSS_MANAGEMENT_DATA_UPDATE_OPERATION_COMPLETE = 10211;

	const uint16_t CHAT_SERVICE_SET_PROFILE_SETTINGS = 10500;
	const uint16_t CHAT_SERVICE_SET_PROFILE_SETTINGS_RESPONSE = 10501;
	const uint16_t CHAT_SERVICE_GET_PROFILE_SETTINGS = 10502;
	const uint16_t CHAT_SERVICE_GET_PROFILE_SETTINGS_RESPONSE = 10503;
	const uint16_t CHAT_SERVICE_SEND_TEXT_MESSAGE = 10504;
	const uint16_t CHAT_SERVICE_SEND_TEXT_MESSAGE_RESPONSE = 10505;
	const uint16_t CHAT_SERVICE_GET_TEXT_MESSAGE = 10506;
	const uint16_t CHAT_SERVICE_SERVER_TO_CLIENT_TEXT_MESSAGE = 10507;
	const uint16_t CHAT_SERVICE_CREATE_CHAT_GROUP = 10508;
	const uint16_t CHAT_SERVICE_CREATE_CHAT_GROUP_RESPONSE = 10509;
	const uint16_t CHAT_SERVICE_ADD_CHAT_GROUP_MEMBER = 10510;
	const uint16_t CHAT_SERVICE_ADD_CHAT_GROUP_MEMBER_RESPONSE = 10511;
	const uint16_t CHAT_SERVICE_DELETE_CHAT_GROUP_MEMBER = 10512;
	const uint16_t CHAT_SERVICE_DELETE_CHAT_GROUP_MEMBER_RESPONSE = 10513;
	const uint16_t CHAT_SERVICE_DELETE_CHAT_GROUP = 10514;
	const uint16_t CHAT_SERVICE_DELETE_CHAT_GROUP_RESPONSE = 10515;
	const uint16_t CHAT_SERVICE_UPDATE_CHAT_GROUP = 10516;
	const uint16_t CHAT_SERVICE_UPDATE_CHAT_GROUP_RESPONSE = 10517;
	const uint16_t CHAT_SERVICE_GET_CHAT_GROUP_MEMBERS = 10518;
	const uint16_t CHAT_SERVICE_GET_CHAT_GROUP_MEMBERS_RESPONSE = 10519;
	const uint16_t CHAT_SERVICE_GET_CHATS_LIST = 10520;
	const uint16_t CHAT_SERVICE_GET_CHATS_LIST_RESPONSE = 10521;
	const uint16_t CHAT_SERVICE_GET_USER_INFORMATION = 10522;
	const uint16_t CHAT_SERVICE_GET_USER_INFORMATION_RESPONSE = 10523;
	const uint16_t CHAT_SERVICE_UPDATE_CHAT_GROUP_MEMBER = 10524;
	const uint16_t CHAT_SERVICE_UPDATE_CHAT_GROUP_MEMBER_RESPONSE = 10525;
	const uint16_t CHAT_SERVICE_FIND_USER_BY_NAME = 10526;
	const uint16_t CHAT_SERVICE_FIND_USER_BY_NAME_RESPONSE = 10527;
	const uint16_t CHAT_SERVICE_GET_CONNECTION_INFORMATION = 10528;
	const uint16_t CHAT_SERVICE_GET_CONNECTION_INFORMATION_RESPONSE = 10529;
	const uint16_t CHAT_SERVICE_START_UPLOAD_FILE = 10530;
	const uint16_t CHAT_SERVICE_START_UPLOAD_FILE_RESPONSE = 10531;
	//const uint16_t CHAT_SERVICE_UPLOAD_FILE = 10532;
	const uint16_t CHAT_SERVICE_UPLOAD_FILE_RESPONSE = 10533;
	const uint16_t CHAT_SERVICE_DOWNLOAD_FILE = 10534;
	//const uint16_t CHAT_SERVICE_DOWNLOAD_FILE_RESPONSE = 10535;
	const uint16_t CHAT_SERVICE_GET_FILE_INFORMATION = 10536;
	const uint16_t CHAT_SERVICE_GET_FILE_INFORMATION_RESPONSE = 10537;
	//const uint16_t CHAT_SERVICE_GET_CHAT_GROUP_MEMBERS_INTERNAL = 10538;
	const uint16_t CHAT_SERVICE_SEARCH_PUBLIC_GROUPS = 10539;
	const uint16_t CHAT_SERVICE_SEARCH_PUBLIC_GROUPS_RESPONSE = 10540;
	const uint16_t CHAT_SERVICE_JOIN_PUBLIC_GROUP = 10541;
	const uint16_t CHAT_SERVICE_SCREEN_SHARE_REMOTE_CONTROL_NEGOTIATION = 10542;
	const uint16_t CHAT_SERVICE_DOWNLOAD_FILE_RESPONSE_FAST = 10543;
	const uint16_t CHAT_SERVICE_UPLOAD_FILE_FAST = 10544;

	const uint16_t CHAT_SCREENSHARING_SERVICE_DIRECT_VIDEO_FRAME = 10609;

	const uint16_t CHAT_REMOTE_CONTROL_INPUT_DATA = 10705;	//s_ChatRemoteControlInputData
	const uint16_t CHAT_REMOTE_CONTROL_SESSION_STATE = 10706;	//s_ChatRemoteControlSessionState
	const uint16_t CHAT_REMOTE_CLIPBOARD_DATA = 10707;	//s_ChatRemoteClipboardData

	enum ReplayChartDataActionEnum : int32_t
	{
		REPLAY_CHART_DATA_ACTION_NONE = 0
		, REPLAY_CHART_DATA_ACTION_STOP = 1
		, REPLAY_CHART_DATA_ACTION_PAUSE = 2
		, REPLAY_CHART_DATA_ACTION_RESUME = 3
		, REPLAY_CHART_DATA_ACTION_FINISH = 4
		, REPLAY_CHART_DATA_ACTION_CHANGE_SPEED = 5
	};

	enum ReplayChartDataStatusEnum : int32_t
	{
		REPLAY_CHART_DATA_STATUS_UNSET = 0
		, REPLAY_CHART_DATA_STATUS_STARTED = 1
		, REPLAY_CHART_DATA_STATUS_ERROR = 2
		, REPLAY_CHART_DATA_STATUS_COMPLETE = 3
	};

	enum UseCompressionEnum : int32_t
	{
		USE_COMPRESSION_DISABLED = 0
		, USE_COMPRESSION_BLOCK_COMPRESSION = 1
		, USE_COMPRESSION_STREAMING_COMPRESSION = 2
	};

	enum WriteIntradayDataFileSessionValueTypeEnum : int32_t
	{
		INTRADAY_DATA_FILE_SESSION_VALUE_UNSET = 0
		, INTRADAY_DATA_FILE_SESSION_VALUE_DAILY_OPEN = 1
		, INTRADAY_DATA_FILE_SESSION_VALUE_DAILY_HIGH
		, INTRADAY_DATA_FILE_SESSION_VALUE_DAILY_LOW
		, INTRADAY_DATA_FILE_SESSION_VALUE_DAILY_VOLUME
		, INTRADAY_DATA_FILE_SESSION_VALUE_DAILY_SETTLEMENT_PRICE
		, INTRADAY_DATA_FILE_SESSION_VALUE_OPEN_INTEREST
		, INTRADAY_DATA_FILE_SESSION_VALUE_ODD_LOT_TRADE
		, INTRADAY_DATA_FILE_SESSION_VALUE_NON_LAST_UPDATE_EQUITY_TRADE
	};	
	
	enum TradingIsDisabledEnum : int32_t
	{
		TRADING_IS_DISABLED_RETURN_CURRENT_VALUE = 0
		, TRADING_IS_DISABLED_DISABLE = 1
		, TRADING_IS_DISABLED_ENABLE = 2
	};
}


/*==========================================================================*/
namespace DTC
{
#pragma pack(push, 1)

	/*==========================================================================*/
	struct s_EncodingRequestExtended
	{
		static constexpr uint16_t MESSAGE_TYPE = DTC::ENCODING_REQUEST;

		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		int32_t ProtocolVersion = DTC::CURRENT_VERSION;
		DTC::EncodingEnum Encoding = DTC::BINARY_ENCODING;
		char ProtocolType[4] = "DTC";
		n_DTCNonStandard::UseCompressionEnum UseCompression = n_DTCNonStandard::USE_COMPRESSION_DISABLED;

		uint16_t GetMessageSize() const;
		void CopyFrom(void* p_SourceData);
		int32_t GetProtocolVersion() const;
		DTC::EncodingEnum GetEncoding() const;
		const char* GetProtocolType() const;
		void SetProtocolType(const char* NewValue);
		n_DTCNonStandard::UseCompressionEnum GetUseCompression() const;
	};

	/*==========================================================================*/
	struct s_HeartbeatExtended
	{
		static constexpr uint16_t MESSAGE_TYPE = DTC::HEARTBEAT;

		uint16_t Size = 0;
		uint16_t Type = 0;

		uint32_t NumDroppedMessages = 0;
		DTC::t_DateTime CurrentDateTime = 0;

		uint16_t SecondsSinceLastReceivedHeartbeat = 0;
		uint16_t NumberOfOutstandingSentBuffers = 0;
		uint16_t PendingTransmissionDelayInMilliseconds = 0;
		uint32_t CurrentSendBufferSizeInBytes = 0;

		DTC::t_DateTimeWithMicrosecondsInt SendingDateTimeMicroseconds = 0;
		float DataCompressionRatio = 0;
		uint64_t TotalUncompressedBytes = 0;
		double TotalCompressionTime = 0;//In seconds
		uint32_t NumberOfCompressions = 0;
		uint32_t SourceIPAddress = 0;

		uint32_t MaximumSendBufferSizeInBytes = 0;
		DTC::t_DateTime MaximumSendBufferSizeInBytesDateTime = 0;

		s_HeartbeatExtended()
		{
			Size = sizeof(*this);
			Type = MESSAGE_TYPE;
		}

		uint16_t GetMessageSize() const;
		void CopyFrom(void* p_SourceData);

		uint32_t GetNumDroppedMessages() const;
		DTC::t_DateTime GetCurrentDateTime() const;

		uint16_t GetSecondsSinceLastReceivedHeartbeat() const;
		uint16_t GetNumberOfOutstandingSentBuffers() const;
		uint16_t GetPendingTransmissionDelayInMilliseconds() const;
		uint32_t GetCurrentSendBufferSizeInBytes() const;

		DTC::t_DateTimeWithMicrosecondsInt GetSendingDateTimeMicroseconds() const;

		float GetDataCompressionRatio() const;
		uint64_t GetTotalUncompressedBytes() const;
		double GetTotalCompressionTime() const;
		uint32_t GetNumberOfCompressions() const;
		uint32_t GetSourceIPAddress() const;

		uint32_t GetMaximumSendBufferSizeInBytes() const;
		DTC::t_DateTime GetMaximumSendBufferSizeInBytesDateTime() const;
	};

	/*==========================================================================*/
	struct s_HistoricalTradesRequest
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::HISTORICAL_TRADES_REQUEST;

		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char Symbol[SYMBOL_LENGTH];
		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		DTC::t_DateTime StartDateTime;
		uint32_t SubAccountIdentifier;
		uint8_t CreateFlatToFlatTrades;

		s_HistoricalTradesRequest()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		void CopyFrom(void * p_SourceData);
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalTradesRequest));
			Size = sizeof(s_HistoricalTradesRequest);
			Type = MESSAGE_TYPE;
		}

		int32_t GetRequestID() const;

		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);

		DTC::t_DateTime GetStartDateTime() const;
		uint32_t GetSubAccountIdentifier() const;
		uint8_t GetCreateFlatToFlatTrades() const;
	};

	/*==========================================================================*/
	struct s_HistoricalTradesReject
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::HISTORICAL_TRADES_REJECT;

		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		char RejectText[TEXT_DESCRIPTION_LENGTH];

		s_HistoricalTradesReject()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		void CopyFrom(void * p_SourceData);
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalTradesReject));
			Size = sizeof(s_HistoricalTradesReject);
			Type = MESSAGE_TYPE;
		}

		uint32_t GetRequestID() const;
		const char* GetRejectText();
		void SetRejectText(const char* NewValue);
	};

	/*==========================================================================*/
	struct s_HistoricalTradesResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::HISTORICAL_TRADES_RESPONSE;

		uint16_t Size;
		uint16_t Type;

		int32_t RequestID;
		uint8_t IsFinalMessage;
		char Symbol[SYMBOL_LENGTH];
		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		DTC::t_DateTimeWithMilliseconds EntryDateTime;
		DTC::t_DateTimeWithMilliseconds ExitDateTime;
		double EntryPrice;
		double ExitPrice;
		DTC::BuySellEnum TradeType;
		uint32_t EntryQuantity;
		uint32_t ExitQuantity;
		uint32_t MaxOpenQuantity;
		double ClosedProfitLoss;
		double MaximumOpenPositionLoss;
		double MaximumOpenPositionProfit;
		double Commission;
		char OpenFillExecutionID[ORDER_FILL_EXECUTION_LENGTH];
		char CloseFillExecutionID[ORDER_FILL_EXECUTION_LENGTH];
		uint32_t SubAccountIdentifier;

		s_HistoricalTradesResponse()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		void CopyFrom(void * p_SourceData);
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalTradesResponse));
			Size = sizeof(s_HistoricalTradesResponse);
			Type = MESSAGE_TYPE;

			TradeType = DTC::BUY_SELL_UNSET;
		}

		int32_t GetRequestID() const;
		uint8_t GetIsFinalMessage() const;
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
		DTC::t_DateTimeWithMilliseconds GetEntryDateTime() const;
		DTC::t_DateTimeWithMilliseconds GetExitDateTime() const;
		double GetEntryPrice() const;
		double GetExitPrice() const;
		DTC::BuySellEnum GetTradeType() const;
		uint32_t GetEntryQuantity() const;
		uint32_t GetExitQuantity() const;
		uint32_t GetMaxOpenQuantity() const;
		double GetClosedProfitLoss() const;
		double GetMaximumOpenPositionLoss() const;
		double GetMaximumOpenPositionProfit() const;
		double GetCommission() const;
		const char* GetOpenFillExecutionID();
		void SetOpenFillExecutionID(const char* NewValue);
		const char* GetCloseFillExecutionID();
		void SetCloseFillExecutionID(const char* NewValue);
		uint32_t GetSubAccountIdentifier() const;
	};

	/*==========================================================================*/
	struct s_ReplayChartData
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::REPLAY_CHART_DATA;

		uint16_t Size;
		uint16_t Type;

		uint32_t RequestID;
		char Symbol[SYMBOL_LENGTH];
		char TradeAccount[TRADE_ACCOUNT_LENGTH];
		char TimeZone[TEXT_MESSAGE_LENGTH];
		DTC::t_DateTimeWithMillisecondsInt StartDateTimeForInitialData;
		DTC::t_DateTimeWithMillisecondsInt StartDateTime;
		DTC::t_DateTimeWithMillisecondsInt StopDateTime;
		uint16_t SessionBeginTimeInSeconds;
		uint16_t SessionEndTimeInSeconds;
		float ReplaySpeed;
		int32_t BarTimeInSeconds;
		uint8_t PauseReplayAfterInitialDataSent;
		uint8_t UseSavedPriorState;
		float SymbolVolatility;
		float InterestRate;
		int32_t NumberOfOrdersToTriggerFinishToStopDateTime;
		int32_t MaximumNumberOfOrdersPerReplaySession;
		int32_t NumberOfDaysForInitialDataFromBeforeLastSavedDateTime;
		uint32_t SubAccountIdentifier = 0;
		int32_t OptionsPriceSendIntervalInSeconds = 0;

		s_ReplayChartData()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		void CopyFrom(void * p_SourceData);
		void Clear()
		{
			memset(this, 0, sizeof(s_ReplayChartData));
			Size = sizeof(s_ReplayChartData);
			Type = MESSAGE_TYPE;

			ReplaySpeed = 1.0;
		}

		uint32_t GetRequestID() const;
		const char* GetSymbol();
		void SetSymbol(const char* NewValue);
		const char* GetTradeAccount();
		void SetTradeAccount(const char* NewValue);
		const char* GetTimeZone();
		void SetTimeZone(const char* NewValue);
		DTC::t_DateTimeWithMillisecondsInt GetStartDateTimeForInitialData() const;
		DTC::t_DateTimeWithMillisecondsInt GetStartDateTime() const;
		DTC::t_DateTimeWithMillisecondsInt GetStopDateTime() const;
		uint16_t GetSessionBeginTimeInSeconds() const;
		uint16_t GetSessionEndTimeInSeconds() const;
		float GetReplaySpeed() const;
		int32_t GetBarTimeInSeconds() const;
		uint8_t GetPauseReplayAfterInitialDataSent() const;
		uint8_t GetUseSavedPriorState() const;
		float GetSymbolVolatility() const;
		float GetInterestRate() const;
		int32_t GetNumberOfOrdersToTriggerFinishToStopDateTime() const;
		int32_t GetMaximumNumberOfOrdersPerReplaySession() const;
		int32_t GetNumberOfDaysForInitialDataFromBeforeLastSavedDateTime() const;
		uint32_t GetSubAccountIdentifier() const;
		int32_t GetOptionsPriceSendIntervalInSeconds() const;
	};

	/*==========================================================================*/
	struct s_ReplayChartDataPerformAction
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::REPLAY_CHART_DATA_PERFORM_ACTION;

		uint16_t Size;
		uint16_t Type;

		uint32_t RequestID = 0;
		n_DTCNonStandard::ReplayChartDataActionEnum Action = n_DTCNonStandard::REPLAY_CHART_DATA_ACTION_NONE;
		float ReplaySpeed = 0;

		s_ReplayChartDataPerformAction()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		void CopyFrom(void * p_SourceData);
		void Clear()
		{
			memset(this, 0, sizeof(s_ReplayChartDataPerformAction));
			Size = sizeof(s_ReplayChartDataPerformAction);
			Type = MESSAGE_TYPE;
		}

		uint32_t GetRequestID() const;
		n_DTCNonStandard::ReplayChartDataActionEnum GetAction() const;
		float GetReplaySpeed() const;
	};

	/*==========================================================================*/
	struct s_ReplayChartDataStatus
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::REPLAY_CHART_DATA_STATUS;

		uint16_t Size;
		uint16_t Type;

		uint32_t RequestID = 0;
		char ErrorMessage[TEXT_MESSAGE_LENGTH];
		n_DTCNonStandard::ReplayChartDataStatusEnum Status = n_DTCNonStandard::REPLAY_CHART_DATA_STATUS_UNSET;
		uint32_t  SubAccountIdentifier = 0;

		s_ReplayChartDataStatus()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		void CopyFrom(void * p_SourceData);
		void Clear()
		{
			memset(this, 0, sizeof(s_ReplayChartDataStatus));
			Size = sizeof(s_ReplayChartDataStatus);
			Type = MESSAGE_TYPE;
		}

		uint32_t GetRequestID() const;
		const char* GetErrorMessage();
		void SetErrorMessage(const char* NewValue);
		n_DTCNonStandard::ReplayChartDataStatusEnum GetStatus() const;
		uint32_t GetSubAccountIdentifier() const;
	};

	/*==========================================================================*/
	struct s_ClientDeviceUpdate
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CLIENT_DEVICE_UPDATE;

		uint16_t Size = sizeof(s_ClientDeviceUpdate);
		uint16_t Type = MESSAGE_TYPE;

		int64_t ClientDeviceIdentifier = 0;

		uint16_t GetMessageSize() const;
		void CopyFrom(void* p_SourceData);

		int64_t GetClientDeviceIdentifier() const;
	
	};

	struct s_InterprocessSynchronizationSnapshotRequest
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::INTERPROCESS_SYNCHRONIZATION_SNAPSHOT_REQUEST;

		uint16_t Size = sizeof(s_InterprocessSynchronizationSnapshotRequest);
		uint16_t Type = MESSAGE_TYPE;

		uint32_t RequestID = 0;

		uint16_t GetMessageSize() const;
		void CopyFrom(void* p_SourceData);

		uint32_t GetRequestID() const;
	};

	struct s_InterprocessSynchronizationTradeActivityRequest
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::INTERPROCESS_SYNCHRONIZATION_TRADE_ACTIVITY_REQUEST;

		uint16_t Size = sizeof(s_InterprocessSynchronizationTradeActivityRequest);
		uint16_t Type = MESSAGE_TYPE;

		uint32_t RequestID = 0;
		int64_t StartDateTimeUTC = 0;

		uint16_t GetMessageSize() const;
		void CopyFrom(void* p_SourceData);

		uint32_t GetRequestID() const;
		int64_t GetStartDateTimeUTC() const;
	};

	/*==========================================================================*/
	struct s_WriteIntradayDataFileSessionValue
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::WRITE_INTRADAY_DATA_FILE_SESSION_VALUE;

		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;

		uint32_t SymbolID = 0;
		n_DTCNonStandard::WriteIntradayDataFileSessionValueTypeEnum ValueType = n_DTCNonStandard::INTRADAY_DATA_FILE_SESSION_VALUE_UNSET;
		DTC::t_DateTimeWithMicrosecondsInt DateTime = 0;
		DTC::t_DateTime Date = 0;
		double Price = 0;
		double Volume = 0;

		uint16_t GetMessageSize() const;
		void CopyFrom(void* p_SourceData);

		uint32_t GetSymbolID() const;
		n_DTCNonStandard::WriteIntradayDataFileSessionValueTypeEnum GetValueType() const;
		DTC::t_DateTimeWithMicrosecondsInt GetDateTime() const;
		DTC::t_DateTime GetDate() const;
		double GetPrice() const;
		double GetVolume() const;
	};

	/*==========================================================================*/
	struct s_MarketDataUpdateOrderImbalanceData
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::MARKET_DATA_UPDATE_ORDER_IMBALANCE_DATA;

		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;

		uint32_t SymbolID = 0;
		DTC::t_DateTimeWithMicrosecondsInt DateTime = 0;
		double MatchingQuantity = 0;
		double NonMatchingQuantity = 0;
		double CurrentReferencePrice = 0;
		uint8_t ImbalanceDirection = 0;
		uint8_t CrossType = 0;

		uint16_t GetMessageSize() const;
		void CopyFrom(void* p_SourceData);

		uint32_t GetSymbolID() const;
		DTC::t_DateTimeWithMicrosecondsInt GetDateTime() const;
		double GetMatchingQuantity() const;
		double GetNonMatchingQuantity() const;
		double GetCurrentReferencePrice() const;
		uint8_t GetImbalanceDirection() const;
		uint8_t GetCrossType() const;

	};

	

#pragma pack(pop)
}

/*==========================================================================*/
namespace DTC_VLS
{
#pragma pack(push, 1)

	/*==========================================================================*/
	struct s_SCConfigurationSynchronization
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::SC_CONFIGURATION_SYNCHRONIZATION;

		uint16_t Size = sizeof(s_SCConfigurationSynchronization);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = Size;

		uint32_t MessageID = 0;
		uint32_t CurrentInboundSequenceNumber = 0;
		uint32_t CurrentOutboundSequenceNumber = 0;
		uint64_t CurrentInternalOrderID = 0;
		uint8_t IsSnapshot = 0;
		DTC_VLS::vls_t LastReceivedExecutionIdentifier;
		uint64_t SessionUUID = 0;
		int64_t SessionUUIDGeneratedDateTimeUTC = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetMessageID() const;
		uint32_t GetCurrentInboundSequenceNumber() const;
		uint32_t GetCurrentOutboundSequenceNumber() const;
		uint64_t GetCurrentInternalOrderID() const;
		uint8_t GetIsSnapshot() const;
		uint64_t GetSessionUUID() const;
		int64_t GetSessionUUIDGeneratedDateTimeUTC() const;

		const char* GetLastReceivedExecutionIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, LastReceivedExecutionIdentifier, offsetof(s_SCConfigurationSynchronization, LastReceivedExecutionIdentifier));
		}

		void AddLastReceivedExecutionIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, LastReceivedExecutionIdentifier, StringLength);
		}
	};

	struct s_DownloadHistoricalOrderFillAndAccountBalanceData
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::DOWNLOAD_HISTORICAL_ORDER_FILL_AND_ACCOUNT_BALANCE_DATA;

		uint16_t Size = sizeof(s_DownloadHistoricalOrderFillAndAccountBalanceData);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = Size;

		DTC_VLS::vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_DownloadHistoricalOrderFillAndAccountBalanceData, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_HistoricalTradesRequest
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::HISTORICAL_TRADES_REQUEST;

		uint16_t Size = sizeof(s_HistoricalTradesRequest);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = Size;

		int32_t RequestID = 0;
		DTC_VLS::vls_t Symbol;
		DTC_VLS::vls_t TradeAccount;
		DTC::t_DateTime StartDateTime = 0;
		uint32_t SubAccountIdentifier = 0;
		uint8_t CreateFlatToFlatTrades = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		int32_t GetRequestID() const;

		DTC::t_DateTime GetStartDateTime() const;
		uint32_t GetSubAccountIdentifier() const;
		uint8_t GetCreateFlatToFlatTrades() const;

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_HistoricalTradesRequest, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalTradesRequest, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

	};

	/*==========================================================================*/
	struct s_HistoricalTradesReject
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::HISTORICAL_TRADES_REJECT;

		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		DTC_VLS::vls_t RejectText;

		s_HistoricalTradesReject()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalTradesReject));
			Size = sizeof(s_HistoricalTradesReject);
			Type = MESSAGE_TYPE;
			BaseSize = Size;
		}

		uint32_t GetRequestID() const;

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_HistoricalTradesReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_HistoricalTradesResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::HISTORICAL_TRADES_RESPONSE;

		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		int32_t RequestID;
		uint8_t IsFinalMessage;
		DTC_VLS::vls_t Symbol;
		DTC_VLS::vls_t TradeAccount;
		DTC::t_DateTimeWithMilliseconds EntryDateTime;
		DTC::t_DateTimeWithMilliseconds ExitDateTime;
		double EntryPrice;
		double ExitPrice;
		DTC::BuySellEnum TradeType;
		uint32_t EntryQuantity;
		uint32_t ExitQuantity;
		uint32_t MaxOpenQuantity;
		double ClosedProfitLoss;
		double MaximumOpenPositionLoss;
		double MaximumOpenPositionProfit;
		double Commission;
		DTC_VLS::vls_t OpenFillExecutionID;
		DTC_VLS::vls_t CloseFillExecutionID;
		uint32_t SubAccountIdentifier;

		s_HistoricalTradesResponse()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		void Clear()
		{
			memset(this, 0, sizeof(s_HistoricalTradesResponse));
			Size = sizeof(s_HistoricalTradesResponse);
			Type = MESSAGE_TYPE;
			BaseSize = Size;

			TradeType = DTC::BUY_SELL_UNSET;
		}

		int32_t GetRequestID() const;
		uint8_t GetIsFinalMessage() const;

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_HistoricalTradesResponse, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalTradesResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		DTC::t_DateTimeWithMilliseconds GetEntryDateTime() const;
		DTC::t_DateTimeWithMilliseconds GetExitDateTime() const;
		double GetEntryPrice() const;
		double GetExitPrice() const;
		DTC::BuySellEnum GetTradeType() const;
		uint32_t GetEntryQuantity() const;
		uint32_t GetExitQuantity() const;
		uint32_t GetMaxOpenQuantity() const;
		double GetClosedProfitLoss() const;
		double GetMaximumOpenPositionLoss() const;
		double GetMaximumOpenPositionProfit() const;
		double GetCommission() const;

		const char* GetOpenFillExecutionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OpenFillExecutionID, offsetof(s_HistoricalTradesResponse, OpenFillExecutionID));
		}

		void AddOpenFillExecutionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, OpenFillExecutionID, StringLength);
		}

		const char* GetCloseFillExecutionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, CloseFillExecutionID, offsetof(s_HistoricalTradesResponse, CloseFillExecutionID));
		}

		void AddCloseFillExecutionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, CloseFillExecutionID, StringLength);
		}

		uint32_t GetSubAccountIdentifier() const;
	};

	/*==========================================================================*/
	struct s_ReplayChartData
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::REPLAY_CHART_DATA;

		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		uint32_t RequestID;
		DTC_VLS::vls_t Symbol;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t TimeZone;
		DTC::t_DateTimeWithMillisecondsInt StartDateTimeForInitialData;
		DTC::t_DateTimeWithMillisecondsInt StartDateTime;
		DTC::t_DateTimeWithMillisecondsInt StopDateTime;
		uint16_t SessionBeginTimeInSeconds;
		uint16_t SessionEndTimeInSeconds;
		float ReplaySpeed;
		int32_t BarTimeInSeconds;
		uint8_t PauseReplayAfterInitialDataSent;
		uint8_t UseSavedPriorState;
		float SymbolVolatility;
		float InterestRate;
		int32_t NumberOfOrdersToTriggerFinishToStopDateTime;
		int32_t MaximumNumberOfOrdersPerReplaySession;
		int32_t NumberOfDaysForInitialDataFromBeforeLastSavedDateTime;
		uint32_t SubAccountIdentifier = 0;
		int32_t OptionsPriceSendIntervalInSeconds = 0;

		s_ReplayChartData()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		void Clear()
		{
			memset(this, 0, sizeof(s_ReplayChartData));
			Size = sizeof(s_ReplayChartData);
			Type = MESSAGE_TYPE;
			BaseSize = Size;

			ReplaySpeed = 1.0;
		}

		uint32_t GetRequestID() const;

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_ReplayChartData, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_ReplayChartData, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTimeZone() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TimeZone, offsetof(s_ReplayChartData, TimeZone));
		}

		void AddTimeZone(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TimeZone, StringLength);
		}

		DTC::t_DateTimeWithMillisecondsInt GetStartDateTimeForInitialData() const;
		DTC::t_DateTimeWithMillisecondsInt GetStartDateTime() const;
		DTC::t_DateTimeWithMillisecondsInt GetStopDateTime() const;
		uint16_t GetSessionBeginTimeInSeconds() const;
		uint16_t GetSessionEndTimeInSeconds() const;
		float GetReplaySpeed() const;
		int32_t GetBarTimeInSeconds() const;
		uint8_t GetPauseReplayAfterInitialDataSent() const;
		uint8_t GetUseSavedPriorState() const;
		float GetSymbolVolatility() const;
		float GetInterestRate() const;
		int32_t GetNumberOfOrdersToTriggerFinishToStopDateTime() const;
		int32_t GetMaximumNumberOfOrdersPerReplaySession() const;
		int32_t GetNumberOfDaysForInitialDataFromBeforeLastSavedDateTime() const;
		uint32_t GetSubAccountIdentifier() const;
		int32_t GetOptionsPriceSendIntervalInSeconds() const;
	};

	/*==========================================================================*/
	struct s_ReplayChartDataPerformAction
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::REPLAY_CHART_DATA_PERFORM_ACTION;

		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		uint32_t RequestID = 0;
		n_DTCNonStandard::ReplayChartDataActionEnum Action = n_DTCNonStandard::REPLAY_CHART_DATA_ACTION_NONE;
		float ReplaySpeed = 0;

		s_ReplayChartDataPerformAction()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		void Clear()
		{
			memset(this, 0, sizeof(s_ReplayChartDataPerformAction));
			Size = sizeof(s_ReplayChartDataPerformAction);
			Type = MESSAGE_TYPE;
			BaseSize = Size;
		}

		uint32_t GetRequestID() const;
		n_DTCNonStandard::ReplayChartDataActionEnum GetAction() const;
		float GetReplaySpeed() const;
	};

	/*==========================================================================*/
	struct s_ReplayChartDataStatus
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::REPLAY_CHART_DATA_STATUS;

		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		uint32_t RequestID = 0;
		DTC_VLS::vls_t ErrorMessage;
		n_DTCNonStandard::ReplayChartDataStatusEnum Status = n_DTCNonStandard::REPLAY_CHART_DATA_STATUS_UNSET;
		uint32_t  SubAccountIdentifier = 0;

		s_ReplayChartDataStatus()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		void Clear()
		{
			memset(this, 0, sizeof(s_ReplayChartDataStatus));
			Size = sizeof(s_ReplayChartDataStatus);
			Type = MESSAGE_TYPE;
			BaseSize = Size;
		}

		uint32_t GetRequestID() const;
		n_DTCNonStandard::ReplayChartDataStatusEnum GetStatus() const;
		uint32_t GetSubAccountIdentifier() const;

		const char* GetErrorMessage() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorMessage, offsetof(s_ReplayChartDataStatus, ErrorMessage));
		}

		void AddErrorMessage(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorMessage, StringLength);
		}

	};


	/*==========================================================================*/
	struct s_RequestNumCurrentClientConnections
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::REQUEST_NUM_CURRENT_CLIENT_CONNECTIONS;

		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		uint32_t RequestID = 0;
		DTC_VLS::vls_t Username;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;

		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_RequestNumCurrentClientConnections, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}

	};

	/*==========================================================================*/
	struct s_NumCurrentClientConnectionsResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::NUM_CURRENT_CLIENT_CONNECTIONS_RESPONSE;

		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;

		uint32_t RequestID = 0;
		DTC_VLS::vls_t Username;

		int64_t ClientDeviceIdentifier1 = 0;
		int64_t ClientDeviceIdentifier2 = 0;
		int64_t ClientDeviceIdentifier3 = 0;
		int64_t ClientDeviceIdentifier4 = 0;
		int64_t ClientDeviceIdentifier5 = 0;
		int64_t ClientDeviceIdentifier6 = 0;
		int64_t ClientDeviceIdentifier7 = 0;
		int64_t ClientDeviceIdentifier8 = 0;

		s_NumCurrentClientConnectionsResponse()
		{
			Clear();
		}

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		void Clear()
		{
			memset(this, 0, sizeof(s_NumCurrentClientConnectionsResponse));
			Size = sizeof(s_NumCurrentClientConnectionsResponse);
			Type = MESSAGE_TYPE;
			BaseSize = Size;
		}

		uint32_t GetRequestID() const;

		int64_t GetClientDeviceIdentifier1() const;
		int64_t GetClientDeviceIdentifier2() const;
		int64_t GetClientDeviceIdentifier3() const;
		int64_t GetClientDeviceIdentifier4() const;
		int64_t GetClientDeviceIdentifier5() const;
		int64_t GetClientDeviceIdentifier6() const;
		int64_t GetClientDeviceIdentifier7() const;
		int64_t GetClientDeviceIdentifier8() const;

		/* Get Add functions for VLS================================================*/
		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_NumCurrentClientConnectionsResponse, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}
		/* End of Get Add functions=============================================*/
	};

	/*==========================================================================*/
	struct s_TradeOrder
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::SC_TRADE_ORDER;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint8_t m_IsOrderDeleted = 0;
		uint64_t m_InternalOrderID = 0;

		uint16_t m_OrderStatusCode = 0;
		uint16_t m_OrderStatusBeforePendingModify = 0;
		uint16_t m_OrderStatusBeforePendingCancel = 0;

		DTC_VLS::vls_t m_ServiceOrderID;

		DTC_VLS::vls_t m_ActualSymbol;

		int m_OrderType = 0;
		uint16_t m_BuySell = 0;

		double m_Price1 = 0;
		double m_Price2 = 0;

		double	m_OrderQuantity = 0;
		double	m_FilledQuantity = 0;

		double m_AverageFillPrice = 0;

		int m_RealtimeFillStatus = 0;

		uint8_t m_IsRestingOrderDuringFill = 0;

		int m_OrderRejectType = 0;

		DTC_VLS::vls_t m_TradeAccount;

		uint32_t m_SubAccountIdentifier = 0;

		int m_InternalOrderIDModifierForService = 0;

		DTC_VLS::vls_t m_FIXClientOrderID;

		uint32_t m_SequenceNumberBasedClientOrderID = 0;

		DTC_VLS::vls_t m_ClientOrderIDForDTCServer;
		DTC_VLS::vls_t m_PreviousClientOrderIDForDTCServer;

		DTC_VLS::vls_t m_ExchangeOrderID;

		DTC_VLS::vls_t m_OriginatingClientUsername;

		int64_t	m_EntryDateTime = 0;
		int64_t	m_LastActionDateTime = 0;
		int64_t m_ServiceUpdateDateTimeUTC = 0;

		unsigned int m_OrderEntryTimeForService = 0;
		unsigned int m_LastModifyTimeForService = 0;

		int64_t m_GoodTillDateTime = 0;
		int m_TimeInForce = 0;
		uint16_t m_OpenClose = 0;

		double m_TrailStopOffset1 = 0;
		double m_TrailStopStep = 0;
		double m_TrailTriggerPrice = 0;
		double m_TrailingStopTriggerOffset = 0;

		uint8_t m_TrailTriggerHit = 0;
		double m_TrailToBreakEvenStopOffset = 0;

		double m_MaximumChaseAmountAsPrice = 0;
		double m_InitialChaseOrderPrice1 = 0;
		double m_InitialLastTradePriceForChaseOrders = 0;

		int m_TrailingStopTriggerOCOGroupNumber = 0;

		double m_LastModifyPrice1 = 0;

		double m_LastModifyQuantity = 0;

		double m_CumulativeOrderQuantityFromParentFills = 0;

		double m_PriorFilledQuantity = 0;

		float m_TickSize = 0;

		int m_ValueFormat = 0;

		float m_PriceMultiplier = 0;

		uint64_t m_ParentInternalOrderID = 0;
		uint64_t m_TargetChildInternalOrderID = 0;
		uint64_t m_StopChildInternalOrderID = 0;

		double m_AttachedOrderPriceOffset1 = 0;

		uint64_t m_LinkInternalOrderID = 0;

		uint64_t m_OCOGroupInternalOrderID = 0;

		uint64_t m_OCOSiblingInternalOrderID = 0;

		uint8_t m_DisableChildAndSiblingRelatedActions = 0;

		uint8_t m_OCOManagedByService = 0;
		uint8_t m_BracketOrderServerManaged = 0;

		DTC_VLS::vls_t m_LastOrderActionSource;

		uint8_t m_StopLimitOrderStopPriceTriggered = 0;

		uint8_t m_OCOFullSiblingCancelOnPartialFill = 0;

		uint8_t m_ReverseOnCompleteFill = 0;

		uint8_t m_SupportScaleIn = 0;

		uint8_t m_SupportScaleOut = 0;

		int m_SourceChartNumber = 0;
		DTC_VLS::vls_t m_SourceChartbookFileName;

		uint8_t m_IsAutomatedOrder = 0;
		uint8_t m_SimulatedOrder = 0;
		uint8_t m_IsChartReplaying = 0;
		int m_AttachedOrderOCOGroupNumber = 0;

		DTC_VLS::vls_t m_LastFillExecutionServiceID;

		int m_FillCount = 0;

		double m_LastFillQuantity = 0;

		double m_LastFillPrice = 0;

		int64_t m_LastFillDateTimeUTC = 0;

		uint64_t m_RejectedStopOCOSiblingInternalOrderID = 0;

		double m_RejectedStopReplacementMarketOrderQuantity = 0;

		uint8_t m_EvaluatingForFill = 0;

		unsigned int m_LastProcessedTimeSalesRecordSequenceForPrices = 0;

		uint8_t m_IsMarketDataManagementOfOrderEnabled = 0;

		DTC_VLS::vls_t m_TextTag;

		int64_t m_TimedOutOrderRequestedStatusDateTime = 0;

		uint8_t m_RequestedStatusForTimedOutOrder = 0;

		uint8_t m_SendFlattenMarketOrderWhenRelatedOrdersConfirmedCanceled = 0;

		double m_QuantityToIncreaseFromParentFill = 0;

		double m_MoveToBreakevenStopReferencePrice = 0;

		double m_QuantityTriggeredStop_QuantityForTrigger = 0;
		double m_AccumulatedTradeVolumeForTriggeredStop = 0;
		uint8_t m_BidAskQuantityStopInitialTriggerMet = 0;

		uint8_t m_NeedToOverrideLock = 0;

		double m_CurrentMarketPrice = 0;
		int64_t m_CurrentMarketDateTime = 0;

		uint8_t m_SupportOrderFillBilling = 0;
		uint8_t m_IsBillable = 0;
		int m_QuantityForBilling = 0;

		uint32_t m_NumberOfFailedOrderModifications = 0;
		int32_t m_DTCServerIndex = 0;

		DTC_VLS::vls_t m_ClearingFirmID;
		DTC_VLS::vls_t m_SenderSubID;
		DTC_VLS::vls_t m_SenderLocationId;
		DTC_VLS::vls_t m_SelfMatchPreventionID;
		int32_t m_CTICode = 0;

		uint8_t m_ObtainOrderActionDateTimeFromLastTradeTimeInChart = 0;
		double m_MaximumShowQuantity = 0;

		uint8_t m_OrderSubmitted = 0;

		uint8_t m_IsSnapshot = 0;
		uint8_t m_IsFirstMessageInBatch = 0;
		uint8_t m_IsLastMessageInBatch = 0;

		int64_t m_ExternalLastActionDateTimeUTC = 0;
		double m_LastModifyPrice2 = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint8_t GetIsOrderDeleted() const;
		uint64_t GetInternalOrderID() const;
		uint16_t GetOrderStatusCode() const;
		uint16_t GetOrderStatusBeforePendingModify() const;
		uint16_t GetOrderStatusBeforePendingCancel() const;
		int GetOrderType() const;
		uint16_t GetBuySell() const;
		double GetPrice1() const;
		double GetPrice2() const;
		double	GetOrderQuantity() const;
		double	GetFilledQuantity() const;
		double GetAverageFillPrice() const;
		int GetRealtimeFillStatus() const;
		uint8_t GetIsRestingOrderDuringFill() const;
		int GetOrderRejectType() const;
		uint32_t GetSubAccountIdentifier() const;
		int GetInternalOrderIDModifierForService() const;
		uint32_t GetSequenceNumberBasedClientOrderID() const;
		int64_t	GetEntryDateTime() const;
		int64_t	GetLastActionDateTime() const;
		int64_t GetServiceUpdateDateTimeUTC() const;
		unsigned int GetOrderEntryTimeForService() const;
		unsigned int GetLastModifyTimeForService() const;
		int64_t GetGoodTillDateTime() const;
		int GetTimeInForce() const;
		uint16_t GetOpenClose() const;
		double GetTrailStopOffset1() const;
		double GetTrailStopStep() const;
		double GetTrailTriggerPrice() const;
		double GetTrailingStopTriggerOffset() const;
		uint8_t GetTrailTriggerHit() const;
		double GetTrailToBreakEvenStopOffset() const;
		double GetMaximumChaseAmountAsPrice() const;
		double GetInitialChaseOrderPrice1() const;
		double GetInitialLastTradePriceForChaseOrders() const;
		int GetTrailingStopTriggerOCOGroupNumber() const;
		double GetLastModifyPrice1() const;
		double GetLastModifyQuantity() const;
		double GetCumulativeOrderQuantityFromParentFills() const;
		double GetPriorFilledQuantity() const;
		float GetTickSize() const;
		int GetValueFormat() const;
		float GetPriceMultiplier() const;
		uint64_t GetParentInternalOrderID() const;
		uint64_t GetTargetChildInternalOrderID() const;
		uint64_t GetStopChildInternalOrderID() const;
		double GetAttachedOrderPriceOffset1() const;
		uint64_t GetLinkInternalOrderID() const;
		uint64_t GetOCOGroupInternalOrderID() const;
		uint64_t GetOCOSiblingInternalOrderID() const;
		uint8_t GetDisableChildAndSiblingRelatedActions() const;
		uint8_t GetOCOManagedByService() const;
		uint8_t GetBracketOrderServerManaged() const;
		uint8_t GetStopLimitOrderStopPriceTriggered() const;
		uint8_t GetOCOFullSiblingCancelOnPartialFill() const;
		uint8_t GetReverseOnCompleteFill() const;
		uint8_t GetSupportScaleIn() const;
		uint8_t GetSupportScaleOut() const;
		int GetSourceChartNumber() const;
		uint8_t GetIsAutomatedOrder() const;
		uint8_t GetSimulatedOrder() const;
		uint8_t GetIsChartReplaying() const;
		int GetAttachedOrderOCOGroupNumber() const;
		int GetFillCount() const;
		double GetLastFillQuantity() const;
		double GetLastFillPrice() const;
		int64_t GetLastFillDateTimeUTC() const;
		uint64_t GetRejectedStopOCOSiblingInternalOrderID() const;
		double GetRejectedStopReplacementMarketOrderQuantity() const;
		uint8_t GetEvaluatingForFill() const;
		unsigned int GetLastProcessedTimeSalesRecordSequenceForPrices() const;
		uint8_t GetIsMarketDataManagementOfOrderEnabled() const;
		int64_t GetTimedOutOrderRequestedStatusDateTime() const;
		uint8_t GetRequestedStatusForTimedOutOrder() const;
		uint8_t GetSendFlattenMarketOrderWhenRelatedOrdersConfirmedCanceled() const;
		double GetQuantityToIncreaseFromParentFill() const;
		double GetMoveToBreakevenStopReferencePrice() const;
		double GetQuantityTriggeredStop_QuantityForTrigger() const;
		double GetAccumulatedTradeVolumeForTriggeredStop() const;
		uint8_t GetBidAskQuantityStopInitialTriggerMet() const;
		uint8_t GetNeedToOverrideLock() const;
		double GetCurrentMarketPrice() const;
		int64_t GetCurrentMarketDateTime() const;
		uint8_t GetSupportOrderFillBilling() const;
		uint8_t GetIsBillable() const;
		int GetQuantityForBilling() const;
		uint32_t GetNumberOfFailedOrderModifications() const;
		int32_t GetDTCServerIndex() const;
		int32_t GetCTICode() const;
		uint8_t GetObtainOrderActionDateTimeFromLastTradeTimeInChart() const;
		double GetMaximumShowQuantity() const;
		uint8_t GetOrderSubmitted() const;

		uint8_t GetIsSnapshot() const;
		uint8_t GetIsFirstMessageInBatch() const;
		uint8_t GetIsLastMessageInBatch() const;

		int64_t GetExternalLastActionDateTimeUTC() const;
		double GetLastModifyPrice2() const;

		//Implementing Get Add inline functions------------------------------
		const char* GetServiceOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_ServiceOrderID, offsetof(s_TradeOrder, m_ServiceOrderID));
		}

		void AddServiceOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_ServiceOrderID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetActualSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_ActualSymbol, offsetof(s_TradeOrder, m_ActualSymbol));
		}

		void AddActualSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_ActualSymbol, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccount, offsetof(s_TradeOrder, m_TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFIXClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_FIXClientOrderID, offsetof(s_TradeOrder, m_FIXClientOrderID));
		}

		void AddFIXClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_FIXClientOrderID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetClientOrderIDForDTCServer() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_ClientOrderIDForDTCServer, offsetof(s_TradeOrder, m_ClientOrderIDForDTCServer));
		}

		void AddClientOrderIDForDTCServer(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_ClientOrderIDForDTCServer, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetPreviousClientOrderIDForDTCServer() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_PreviousClientOrderIDForDTCServer, offsetof(s_TradeOrder, m_PreviousClientOrderIDForDTCServer));
		}

		void AddPreviousClientOrderIDForDTCServer(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_PreviousClientOrderIDForDTCServer, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetExchangeOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_ExchangeOrderID, offsetof(s_TradeOrder, m_ExchangeOrderID));
		}

		void AddExchangeOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_ExchangeOrderID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetOriginatingClientUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_OriginatingClientUsername, offsetof(s_TradeOrder, m_OriginatingClientUsername));
		}

		void AddOriginatingClientUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_OriginatingClientUsername, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetLastOrderActionSource() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_LastOrderActionSource, offsetof(s_TradeOrder, m_LastOrderActionSource));
		}

		void AddLastOrderActionSource(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_LastOrderActionSource, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSourceChartbookFileName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SourceChartbookFileName, offsetof(s_TradeOrder, m_SourceChartbookFileName));
		}

		void AddSourceChartbookFileName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SourceChartbookFileName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetLastFillExecutionServiceID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_LastFillExecutionServiceID, offsetof(s_TradeOrder, m_LastFillExecutionServiceID));
		}

		void AddLastFillExecutionServiceID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_LastFillExecutionServiceID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTextTag() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TextTag, offsetof(s_TradeOrder, m_TextTag));
		}

		void AddTextTag(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TextTag, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetClearingFirmID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_ClearingFirmID, offsetof(s_TradeOrder, m_ClearingFirmID));
		}

		void AddClearingFirmID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_ClearingFirmID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderSubID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SenderSubID, offsetof(s_TradeOrder, m_SenderSubID));
		}

		void AddSenderSubID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SenderSubID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderLocationId() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SenderLocationId, offsetof(s_TradeOrder, m_SenderLocationId));
		}

		void AddSenderLocationId(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SenderLocationId, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSelfMatchPreventionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SelfMatchPreventionID, offsetof(s_TradeOrder, m_SelfMatchPreventionID));
		}

		void AddSelfMatchPreventionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SelfMatchPreventionID, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_IndividualTradePosition
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::INDIVIDUAL_TRADE_POSITION;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		DTC_VLS::vls_t m_Symbol;
		uint8_t m_IsSimulated = 0;
		DTC_VLS::vls_t m_TradeAccount;
		double m_Quantity = 0;
		double m_PositionPrice = 0;
		double m_OpenProfitLoss = 0;
		int64_t m_TradeDateTime = 0;
		DTC_VLS::vls_t m_FillExecutionIdentifier;

		uint8_t m_IsSnapshot = 0;
		uint8_t m_IsFirstMessageInBatch = 0;
		uint8_t m_IsLastMessageInBatch = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		uint8_t GetIsSimulated() const;
		double  GetQuantity() const;
		double  GetPositionPrice() const;
		double  GetOpenProfitLoss() const;
		int64_t GetTradeDateTime() const;
		uint8_t GetIsSnapshot() const;
		uint8_t GetIsFirstMessageInBatch() const;
		uint8_t GetIsLastMessageInBatch() const;

		//Implementing Get Add inline functions------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_Symbol, offsetof(s_IndividualTradePosition, m_Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_Symbol, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccount, offsetof(s_IndividualTradePosition, m_TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFillExecutionIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_FillExecutionIdentifier, offsetof(s_IndividualTradePosition, m_FillExecutionIdentifier));
		}

		void AddFillExecutionIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_FillExecutionIdentifier, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradePositionConsolidated
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_POSITION_CONSOLIDATED;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);
	
		//message field variables
		uint8_t m_IsDeleted = 0;
		DTC_VLS::vls_t m_Symbol;
		uint8_t m_IsSimulated = 0;
		DTC_VLS::vls_t m_TradeAccount;
		DTC_VLS::vls_t m_CurrencyCode;
		double m_Quantity;
		double m_AveragePrice = 0;
		double m_OpenProfitLoss = 0;

		double m_DailyProfitLoss = 0;
		int64_t m_LastDailyProfitLossResetDateTimeUTC = 0;

		double m_ServicePositionQuantity = 0;
		uint8_t m_PositionHasBeenUpdatedByService = 0;

		double m_PriceHighDuringPosition = 0;
		double m_PriceLowDuringPosition = 0;
		double m_PriceLastDuringPosition = 0;

		int64_t m_LastProcessedTimeAndSalesSequence = 0;

		double m_TotalMarginRequirement = 0.0;

		int64_t m_InitialEntryDateTimeUTC = 0;

		uint8_t m_IsFromDTCServerReplay = 0;
		int64_t m_MostRecentPositionIncreaseDateTimeUTC = 0;

		uint8_t m_IsSnapshot = 0;
		uint8_t m_IsFirstMessageInBatch = 0;
		uint8_t m_IsLastMessageInBatch = 0;

		double m_MarginRequirementFull = 0;
		double m_MarginRequirementFullPositionsOnly = 0;

		double m_MaxPotentialPositionQuantity = 0;
		double m_QuantityAtEndOfDayCaptureTime = 0;
		double m_MarginRequirementPositionsOnly = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint8_t GetIsDeleted() const;
		uint8_t GetIsSimulated() const;
		double GetQuantity() const;
		double GetAveragePrice() const;
		double GetOpenProfitLoss() const;

		double GetDailyProfitLoss() const;
		int64_t GetLastDailyProfitLossResetDateTimeUTC() const;

		double GetServicePositionQuantity() const;
		uint8_t GetPositionHasBeenUpdatedByService() const;

		double GetPriceHighDuringPosition() const;
		double GetPriceLowDuringPosition() const;
		double GetPriceLastDuringPosition() const;

		int64_t GetLastProcessedTimeAndSalesSequence() const;

		double GetTotalMarginRequirement() const;

		int64_t GetInitialEntryDateTimeUTC() const;
		uint8_t GetIsFromDTCServerReplay() const;
		int64_t GetMostRecentPositionIncreaseDateTimeUTC() const;

		uint8_t GetIsSnapshot() const;
		uint8_t GetIsFirstMessageInBatch() const;
		uint8_t GetIsLastMessageInBatch() const;

		double GetMarginRequirementFull() const;
		double GetMarginRequirementFullPositionsOnly() const;
		double GetMaxPotentialPositionQuantity() const;

		double GetQuantityAtEndOfDayCaptureTime() const;
		double GetMarginRequirementPositionsOnly() const;

		//Implementing Get Add inline functions------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_Symbol, offsetof(s_TradePositionConsolidated, m_Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_Symbol, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccount, offsetof(s_TradePositionConsolidated, m_TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetCurrencyCode() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_CurrencyCode, offsetof(s_TradePositionConsolidated, m_CurrencyCode));
		}

		void AddCurrencyCode(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_CurrencyCode, StringLength);
		}
		//-------------------------------------------------------------------

	};

	/*==========================================================================*/
	struct s_TradeActivityData
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACTIVITY_DATA;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint8_t ActivityType = 0;
		int64_t DataDateTimeUTC = 0;
		DTC_VLS::vls_t Symbol;

		DTC_VLS::vls_t OrderActionSource;
		uint64_t InternalOrderID = 0;
		DTC_VLS::vls_t ServiceOrderID;
		DTC_VLS::vls_t ExchangeOrderID;
		DTC_VLS::vls_t FIXClientOrderID;
		DTC_VLS::vls_t OrderTypeName;

		double Quantity = 0;

		uint8_t BuySell = 0;
		double Price1 = 0;
		double Price2 = 0;
		uint8_t NewOrderStatus = 0;
		double FillPrice = 0.0;
		double OrderFilledQuantity = 0;
		double HighPriceDuringPosition = 0;
		double LowPriceDuringPosition = 0;
		double LastPriceDuringPosition = 0;
		DTC_VLS::vls_t TradeAccount;
		uint64_t ParentInternalOrderID = 0;

		uint8_t OpenClose = 0;

		uint8_t IsSimulated = 0;
		uint8_t IsAutomatedOrder = 0;
		uint8_t IsChartReplaying = 0;

		DTC_VLS::vls_t FillExecutionServiceID;
		double PositionQuantity = 0;

		int SourceChartNumber = 0;
		DTC_VLS::vls_t SourceChartbookFileName;

		int TimeInForce = 0;

		DTC_VLS::vls_t SymbolServiceCode;

		DTC_VLS::vls_t Note;
		DTC_VLS::vls_t OriginatingClientUsername;

		double TradeAccountBalance = 0;

		uint8_t SupportsPositionQuantityField = 0;

		uint8_t IsBillable = 0;
		int32_t QuantityForBilling = 0;
		DTC_VLS::vls_t OrderRoutingServiceCode;
		uint32_t SubAccountIdentifier = 0;

		int64_t AuditTrail_TransactDateTimeUTC = 0;
		int AuditTrail_MessageDirection = 0;
		DTC_VLS::vls_t AuditTrail_OperatorID;
		DTC_VLS::vls_t AuditTrail_SelfMatchPreventionID;
		DTC_VLS::vls_t AuditTrail_SessionID;
		DTC_VLS::vls_t AuditTrail_ExecutingFirmID;
		DTC_VLS::vls_t AuditTrail_FixMessageType;
		int16_t AuditTrail_CustomerTypeIndicator = 0;
		int16_t AuditTrail_CustomerOrFirm = 0;
		DTC_VLS::vls_t AuditTrail_ExecutionReportID;
		DTC_VLS::vls_t AuditTrail_SpreadLegLinkID;
		DTC_VLS::vls_t AuditTrail_SecurityDesc;
		DTC_VLS::vls_t AuditTrail_MarketSegmentID;
		uint8_t AuditTrail_IFMFlag = 0;
		double AuditTrail_DisplayQuantity = 0;
		DTC_VLS::vls_t AuditTrail_CountryOfOrigin;
		double AuditTrail_FillQuantity = 0;
		double AuditTrail_RemainingQuantity = 0;
		uint8_t AuditTrail_AggressorFlag = 0;
		int32_t AuditTrail_SourceOfCancellation = 0;
		DTC_VLS::vls_t AuditTrail_OrdRejReason;

		uint8_t IsSnapshot = 0;
		uint8_t IsFirstMessageInBatch = 0;
		uint8_t IsLastMessageInBatch = 0;

		double AuditTrail_MinimumQuantity = 0.0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		uint8_t GetActivityType() const;
		int64_t GetDataDateTimeUTC() const;
		uint64_t GetInternalOrderID() const;
		double GetQuantity() const;
		uint8_t GetBuySell() const;
		double GetPrice1() const;
		double GetPrice2() const;
		uint8_t GetNewOrderStatus() const;
		double GetFillPrice() const;
		double GetOrderFilledQuantity() const;
		double GetHighPriceDuringPosition() const;
		double GetLowPriceDuringPosition() const;
		double GetLastPriceDuringPosition() const;
		uint64_t GetParentInternalOrderID() const;
		uint8_t GetOpenClose() const;
		uint8_t GetIsSimulated() const;
		uint8_t GetIsAutomatedOrder() const;
		uint8_t GetIsChartReplaying() const;
		double GetPositionQuantity() const;
		int GetSourceChartNumber() const;
		int GetTimeInForce() const;
		double GetTradeAccountBalance() const;
		uint8_t GetSupportsPositionQuantityField() const;
		uint8_t GetIsBillable() const;
		int32_t GetQuantityForBilling() const;
		uint32_t GetSubAccountIdentifier() const;
		int64_t GetAuditTrail_TransactDateTimeUTC() const;
		int GetAuditTrail_MessageDirection() const;
		int16_t GetAuditTrail_CustomerTypeIndicator() const;
		int16_t GetAuditTrail_CustomerOrFirm() const;
		uint8_t GetAuditTrail_IFMFlag() const;
		double GetAuditTrail_DisplayQuantity() const;
		double GetAuditTrail_FillQuantity() const;
		double GetAuditTrail_RemainingQuantity() const;
		uint8_t GetAuditTrail_AggressorFlag() const;
		int32_t GetAuditTrail_SourceOfCancellation() const;
		uint8_t GetIsSnapshot() const;
		uint8_t GetIsFirstMessageInBatch() const;
		uint8_t GetIsLastMessageInBatch() const;
		double GetAuditTrail_MinimumQuantity() const;

		//Implementing Get Add inline functions------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_TradeActivityData, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetOrderActionSource() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OrderActionSource, offsetof(s_TradeActivityData, OrderActionSource));
		}

		void AddOrderActionSource(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, OrderActionSource, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetServiceOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServiceOrderID, offsetof(s_TradeActivityData, ServiceOrderID));
		}

		void AddServiceOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServiceOrderID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetExchangeOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ExchangeOrderID, offsetof(s_TradeActivityData, ExchangeOrderID));
		}

		void AddExchangeOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ExchangeOrderID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFIXClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FIXClientOrderID, offsetof(s_TradeActivityData, FIXClientOrderID));
		}

		void AddFIXClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FIXClientOrderID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetOrderTypeName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OrderTypeName, offsetof(s_TradeActivityData, OrderTypeName));
		}

		void AddOrderTypeName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, OrderTypeName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeActivityData, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFillExecutionServiceID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FillExecutionServiceID, offsetof(s_TradeActivityData, FillExecutionServiceID));
		}

		void AddFillExecutionServiceID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FillExecutionServiceID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSourceChartbookFileName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SourceChartbookFileName, offsetof(s_TradeActivityData, SourceChartbookFileName));
		}

		void AddSourceChartbookFileName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SourceChartbookFileName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbolServiceCode() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SymbolServiceCode, offsetof(s_TradeActivityData, SymbolServiceCode));
		}

		void AddSymbolServiceCode(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SymbolServiceCode, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetNote() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Note, offsetof(s_TradeActivityData, Note));
		}

		void AddNote(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Note, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetOriginatingClientUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OriginatingClientUsername, offsetof(s_TradeActivityData, OriginatingClientUsername));
		}

		void AddOriginatingClientUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, OriginatingClientUsername, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetOrderRoutingServiceCode() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OrderRoutingServiceCode, offsetof(s_TradeActivityData, OrderRoutingServiceCode));
		}

		void AddOrderRoutingServiceCode(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, OrderRoutingServiceCode, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_OperatorID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_OperatorID, offsetof(s_TradeActivityData, AuditTrail_OperatorID));
		}

		void AddAuditTrail_OperatorID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_OperatorID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_SelfMatchPreventionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_SelfMatchPreventionID, offsetof(s_TradeActivityData, AuditTrail_SelfMatchPreventionID));
		}

		void AddAuditTrail_SelfMatchPreventionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_SelfMatchPreventionID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_SessionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_SessionID, offsetof(s_TradeActivityData, AuditTrail_SessionID));
		}

		void AddAuditTrail_SessionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_SessionID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_ExecutingFirmID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_ExecutingFirmID, offsetof(s_TradeActivityData, AuditTrail_ExecutingFirmID));
		}

		void AddAuditTrail_ExecutingFirmID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_ExecutingFirmID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_FixMessageType() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_FixMessageType, offsetof(s_TradeActivityData, AuditTrail_FixMessageType));
		}

		void AddAuditTrail_FixMessageType(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_FixMessageType, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_ExecutionReportID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_ExecutionReportID, offsetof(s_TradeActivityData, AuditTrail_ExecutionReportID));
		}

		void AddAuditTrail_ExecutionReportID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_ExecutionReportID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_SpreadLegLinkID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_SpreadLegLinkID, offsetof(s_TradeActivityData, AuditTrail_SpreadLegLinkID));
		}

		void AddAuditTrail_SpreadLegLinkID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_SpreadLegLinkID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_SecurityDesc() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_SecurityDesc, offsetof(s_TradeActivityData, AuditTrail_SecurityDesc));
		}

		void AddAuditTrail_SecurityDesc(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_SecurityDesc, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_MarketSegmentID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_MarketSegmentID, offsetof(s_TradeActivityData, AuditTrail_MarketSegmentID));
		}

		void AddAuditTrail_MarketSegmentID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_MarketSegmentID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAuditTrail_CountryOfOrigin() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_CountryOfOrigin, offsetof(s_TradeActivityData, AuditTrail_CountryOfOrigin));
		}

		void AddAuditTrail_CountryOfOrigin(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_CountryOfOrigin, StringLength);
		}		

		//-------------------------------------------------------------------
		const char* GetAuditTrail_OrdRejReason() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AuditTrail_OrdRejReason, offsetof(s_TradeActivityData, AuditTrail_OrdRejReason));
		}

		void AddAuditTrail_OrdRejReason(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AuditTrail_OrdRejReason, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataRequest
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_REQUEST;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataRequest, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//--End of Get Add functions----------------------------------------

	};

	/*==========================================================================*/
	struct s_TradeAccountDataResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t m_RequestID = 0;
		uint8_t m_TradeAccountNotExist = 0;

		DTC_VLS::vls_t m_TradeAccount;
		uint8_t m_IsSimulated = false;
		DTC_VLS::vls_t m_CurrencyCode;

		double m_CurrentCashBalance = 0;
		double m_AvailableFundsForNewPositions = 0;
		double m_MarginRequirement = 0;
		double m_AccountValue = 0;
		double m_OpenPositionsProfitLoss = 0;
		double m_DailyProfitLoss = 0;
		uint64_t m_TransactionIdentifierForCashBalanceAdjustment = 0;
		int64_t m_LastTransactionDateTime = 0;
		double m_TrailingAccountValueAtWhichToNotAllowNewPositions = 0;
		double m_CalculatedDailyNetLossLimitInAccountCurrency = 0;
		uint8_t m_DailyNetLossLimitHasBeenReached = 0;
		int64_t m_LastResetDailyNetLossManagementVariablesDateTimeUTC = 0;
		uint8_t m_IsUnderRequiredMargin = 0;

		float m_DailyNetLossLimitInAccountCurrency = 0;

		int32_t m_PercentOfAccountValueForDailyNetLossLimit = 0;

		uint8_t m_UseTrailingAccountValueToNotAllowIncreaseInPositions = false;

		uint8_t m_DoNotAllowIncreaseInPositionsAtDailyLossLimit = false;

		uint8_t m_FlattenPositionsAtDailyLossLimit = false;
		uint8_t m_ClosePositionsAtEndOfDay = false;

		uint8_t m_FlattenPositionsWhenUnderMarginIntraday = true;
		uint8_t m_FlattenPositionsWhenUnderMarginAtEndOfDay = false;

		DTC_VLS::vls_t m_SenderSubID;
		DTC_VLS::vls_t m_SenderLocationId;
		DTC_VLS::vls_t m_SelfMatchPreventionID;
		int32_t m_CTICode = 0;
		uint8_t m_TradeAccountIsReadOnly = false;
		int32_t m_MaximumGlobalPositionQuantity = 0;
		double m_TradeFeePerContract = 0;
		double m_TradeFeePerShare = 0;
		uint8_t m_RequireSufficientMarginForNewPositions = true;
		int32_t m_UsePercentOfMargin = 100;
		int32_t m_UsePercentOfMarginForDayTrading = 100;
		int32_t m_MaximumAllowedAccountBalanceForPositionsAsPercentage = 100;
		DTC_VLS::vls_t m_FirmID;

		uint8_t m_TradingIsDisabled = 0;
		DTC_VLS::vls_t m_DescriptiveName;

		uint8_t m_IsMasterFirmControlAccount = 0;
		double m_MinimumRequiredAccountValue = 0;
		int64_t m_BeginTimeForDayMargin = 0;
		int64_t m_EndTimeForDayMargin = 0;
		DTC_VLS::vls_t m_DayMarginTimeZone;

		uint8_t m_IsSnapshot = 0;
		uint8_t m_IsFirstMessageInBatch = 0;
		uint8_t m_IsLastMessageInBatch = 0;
		uint8_t m_IsDeleted = 0;

		uint8_t m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday = 0;
		uint8_t m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay = 0;
		uint8_t m_Unused1 = 0;
		uint8_t m_UseMasterFirm_TradeFees = 0;
		uint8_t m_Unused2 = 0;
		uint8_t m_UseMasterFirm_RequireSufficientMarginForNewPositions = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMargin = 0;
		uint8_t m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage = 0;
		uint8_t m_UseMasterFirm_MinimumRequiredAccountValue = 0;
		uint8_t m_UseMasterFirm_MarginTimeSettings = 0;
		uint8_t m_UseMasterFirm_TradingIsDisabled = 0;
		
		uint8_t m_IsTradeStatisticsPublicallyShared = 0;
		uint8_t m_IsReadOnlyFollowingRequestsAllowed = 0;
		uint8_t m_IsTradeAccountSharingAllowed = 0;
		uint8_t m_ReadOnlyShareToAllSCUsernames = 0;

		uint8_t m_UseMasterFirm_SymbolCommissionsArray = 0;
		uint8_t m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForDayTrading = 0;
		double m_OpenPositionsProfitLossBasedOnSettlement = 0;
		double m_MarginRequirementFull = 0;
		double m_MarginRequirementFullPositionsOnly = 0;
		// End read only
				
		uint8_t m_UseMasterFirm_TradeFeesFullOverride = 0;
		uint8_t m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginFullOverride = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride = 0;

		double m_PeakMarginRequirement = 0;// Read only

		uint8_t m_LiquidationOnlyMode = 0;

		uint8_t m_FlattenPositionsWhenUnderMarginIntradayTriggered = 0;// Read only
		uint8_t m_FlattenPositionsWhenUnderMinimumAccountValueTriggered = 0;// Read only

		double m_AccountValueAtEndOfDayCaptureTime = 0;// Read only
		int64_t m_EndOfDayCaptureTime = 0;// Read only

		uint8_t m_CustomerOrFirm = 0;
		uint8_t m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMarginIntraday = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay = 0;
		uint32_t m_MasterFirm_MaximumOrderQuantity = 0;

		int64_t m_LastTriggerDateTimeUTCForDailyLossLimit = 0;// Read only
		uint8_t m_OpenPositionsProfitLossIsDelayed = 0;// Unused

		DTC_VLS::vls_t m_ExchangeTraderId;

		int64_t m_ProfitLossForOpenPositionDateTimeUTC = 0;// Read only

		uint8_t m_UseFixedCashOnHandBalance = 0;
		float m_FixedCashOnHandBalance = 0.0f;

		double m_EndOfDayNetLiquidatingValueFromImportFile = 0;// Read only

		DTC_VLS::vls_t m_AdministratorUsernamesOwnAccountAccess;
		DTC_VLS::vls_t m_TradeAccountPrefixForExchange;

		DTC_VLS::vls_t m_IntroducingBroker;

		uint8_t m_RejectCrossingOrders = 0;

		DTC_VLS::vls_t m_SenderSubIDsForUserNames;

		uint32_t m_MessageLimitPerTenSeconds = 0;
		uint32_t m_LastTradeDateSource = 0;
		uint8_t m_DisableTradingForParentAccountOnly = 0;
		uint8_t m_SupportIntendedPositionOrders = 0;

		int64_t m_MarginRecalculationTime1 = 0;
		int64_t m_MarginRecalculationTime2 = 0;
		int64_t m_ClosePositionsAtEndOfDayTime = 0;
		DTC_VLS::vls_t m_MasterSettingsTimeZone;

		int32_t m_UsePercentOfMarginForOvernightTrading = 0;
		int64_t m_BeginTimeForOvernightMargin = 0;
		int64_t m_EndTimeForOvernightMargin = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForOvernightTrading = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride = 0;

		uint8_t m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum = 0;
		uint8_t m_MasterFirm_SupportUserSetProfitLossManagement = 0;

		DTC_VLS::vls_t m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount;

		DTC_VLS::vls_t m_MasterFirm_UsernameGroupDefinitions;
		DTC_VLS::vls_t m_RiskManagerUsernameGroup;

		double m_MarginRequirementPositionsOnly = 0;

		double m_FundsOnHoldToDeductFromAccountBalance = 0;
		int64_t m_FundsOnHoldExpirationDate = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetTradeAccountNotExist() const;
		uint8_t GetIsSimulated() const;
		double GetCurrentCashBalance() const;
		double GetAvailableFundsForNewPositions() const;
		double GetMarginRequirement() const;
		double GetAccountValue() const;
		double GetOpenPositionsProfitLoss() const;
		double GetDailyProfitLoss() const;
		uint64_t GetTransactionIdentifierForCashBalanceAdjustment() const;
		int64_t GetLastTransactionDateTime() const;
		double GetTrailingAccountValueAtWhichToNotAllowNewPositions() const;
		double GetCalculatedDailyNetLossLimitInAccountCurrency() const;
		uint8_t GetDailyNetLossLimitHasBeenReached() const;
		int64_t GetLastResetDailyNetLossManagementVariablesDateTimeUTC() const;
		uint8_t GetIsUnderRequiredMargin() const;
		float GetDailyNetLossLimitInAccountCurrency() const;
		int32_t GetPercentOfAccountValueForDailyNetLossLimit() const;
		uint8_t GetUseTrailingAccountValueToNotAllowIncreaseInPositions() const;
		uint8_t GetDoNotAllowIncreaseInPositionsAtDailyLossLimit() const;
		uint8_t GetFlattenPositionsAtDailyLossLimit() const;
		uint8_t GetClosePositionsAtEndOfDay() const;
		uint8_t GetFlattenPositionsWhenUnderMarginIntraday() const;
		uint8_t GetFlattenPositionsWhenUnderMarginAtEndOfDay() const;
		int32_t GetCTICode() const;
		uint8_t GetTradeAccountIsReadOnly() const;
		int32_t GetMaximumGlobalPositionQuantity() const;
		double GetTradeFeePerContract() const;
		double GetTradeFeePerShare() const;
		uint8_t GetRequireSufficientMarginForNewPositions() const;
		int32_t GetUsePercentOfMargin() const;
		int32_t GetUsePercentOfMarginForDayTrading() const;
		int32_t GetMaximumAllowedAccountBalanceForPositionsAsPercentage() const;
		uint8_t GetTradingIsDisabled() const;
		uint8_t GetIsMasterFirmControlAccount() const;
		double GetMinimumRequiredAccountValue() const;
		int64_t GetBeginTimeForDayMargin() const;
		int64_t GetEndTimeForDayMargin() const;
		uint8_t GetIsSnapshot() const;
		uint8_t GetIsFirstMessageInBatch() const;
		uint8_t GetIsLastMessageInBatch() const;
		uint8_t GetIsDeleted() const;
		uint8_t GetUseMasterFirm_FlattenPositionsWhenUnderMarginIntraday() const;
		uint8_t GetUseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay() const;		
		uint8_t GetUseMasterFirm_TradeFees() const;
		
		uint8_t GetUseMasterFirm_RequireSufficientMarginForNewPositions() const;
		uint8_t GetUseMasterFirm_UsePercentOfMargin() const;
		uint8_t GetUseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage() const;
		uint8_t GetUseMasterFirm_MinimumRequiredAccountValue() const;
		uint8_t GetUseMasterFirm_MarginTimeSettings() const;
		uint8_t GetUseMasterFirm_TradingIsDisabled() const;
		uint8_t GetIsTradeStatisticsPublicallyShared() const;
		uint8_t GetIsReadOnlyFollowingRequestsAllowed() const;
		uint8_t GetIsTradeAccountSharingAllowed() const;
		uint8_t GetReadOnlyShareToAllSCUsernames() const;
		uint8_t GetUseMasterFirm_SymbolCommissionsArray() const;
		uint8_t GetUseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForDayTrading() const;
		double GetOpenPositionsProfitLossBasedOnSettlement() const;
		double GetMarginRequirementFull() const;
		double GetMarginRequirementFullPositionsOnly() const;

		uint8_t GetUseMasterFirm_TradeFeesFullOverride() const;
		uint8_t GetUseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginFullOverride() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForDayTradingFullOverride() const;
		double GetPeakMarginRequirement() const;
		uint8_t GetLiquidationOnlyMode() const;

		uint8_t GetFlattenPositionsWhenUnderMarginIntradayTriggered() const;
		uint8_t GetFlattenPositionsWhenUnderMinimumAccountValueTriggered() const;

		double GetAccountValueAtEndOfDayCaptureTime() const;
		int64_t GetEndOfDayCaptureTime() const;

		uint8_t GetCustomerOrFirm() const;
		uint8_t GetMasterFirm_FlattenCancelAccountWhenDailyLossLimitMet() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMinimumAccountValue() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMarginIntraday() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMarginEndOfDay() const;
		uint32_t GetMasterFirm_MaximumOrderQuantity() const;

		int64_t GetLastTriggerDateTimeUTCForDailyLossLimit() const;

		int64_t GetProfitLossForOpenPositionDateTimeUTC() const;

		uint8_t GetUseFixedCashOnHandBalance() const;
		float GetFixedCashOnHandBalance() const;
		double GetEndOfDayNetLiquidatingValueFromImportFile() const;

		uint8_t GetRejectCrossingOrders() const;

		uint32_t GetMessageLimitPerTenSeconds() const;
		uint32_t GetLastTradeDateSource() const;
		uint8_t GetDisableTradingForParentAccountOnly() const;
		uint8_t GetSupportIntendedPositionOrders() const;

		int64_t GetMarginRecalculationTime1() const;
		int64_t GetMarginRecalculationTime2() const;
		int64_t GetClosePositionsAtEndOfDayTime() const;

		int32_t GetUsePercentOfMarginForOvernightTrading() const;
		int64_t GetBeginTimeForOvernightMargin() const;
		int64_t GetEndTimeForOvernightMargin() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForOvernightTrading() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride() const;

		uint8_t GetUseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum() const;
		uint8_t GetMasterFirmSupportUserSetProfitLossManagement() const;
		double GetMarginRequirementPositionsOnly() const;
		double GetFundsOnHoldToDeductFromAccountBalance() const;
		int64_t GetFundsOnHoldExpirationDate() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccount, offsetof(s_TradeAccountDataResponse, m_TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetCurrencyCode() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_CurrencyCode, offsetof(s_TradeAccountDataResponse, m_CurrencyCode));
		}

		void AddCurrencyCode(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_CurrencyCode, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderSubID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SenderSubID, offsetof(s_TradeAccountDataResponse, m_SenderSubID));
		}

		void AddSenderSubID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SenderSubID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderLocationId() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SenderLocationId, offsetof(s_TradeAccountDataResponse, m_SenderLocationId));
		}

		void AddSenderLocationId(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SenderLocationId, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSelfMatchPreventionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SelfMatchPreventionID, offsetof(s_TradeAccountDataResponse, m_SelfMatchPreventionID));
		}

		void AddSelfMatchPreventionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SelfMatchPreventionID, StringLength);
		}
		//-------------------------------------------------------------------
			const char* GetFirmID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_FirmID, offsetof(s_TradeAccountDataResponse, m_FirmID));
		}

		void AddFirmID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_FirmID, StringLength);
		}
		
		//-------------------------------------------------------------------
			const char* GetDescriptiveName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_DescriptiveName, offsetof(s_TradeAccountDataResponse, m_DescriptiveName));
		}

		void AddDescriptiveName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_DescriptiveName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetDayMarginTimeZone() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_DayMarginTimeZone, offsetof(s_TradeAccountDataResponse, m_DayMarginTimeZone));
		}

		void AddDayMarginTimeZone(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_DayMarginTimeZone, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetExchangeTraderId() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_ExchangeTraderId, offsetof(s_TradeAccountDataResponse, m_ExchangeTraderId));
		}

		void AddExchangeTraderId(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_ExchangeTraderId, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAdministratorUsernamesOwnAccountAccess() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_AdministratorUsernamesOwnAccountAccess, offsetof(s_TradeAccountDataResponse, m_AdministratorUsernamesOwnAccountAccess));
		}

		void AddAdministratorUsernamesOwnAccountAccess(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_AdministratorUsernamesOwnAccountAccess, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccountPrefixForExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccountPrefixForExchange, offsetof(s_TradeAccountDataResponse, m_TradeAccountPrefixForExchange));
		}

		void AddTradeAccountPrefixForExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccountPrefixForExchange, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetIntroducingBroker() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_IntroducingBroker, offsetof(s_TradeAccountDataResponse, m_IntroducingBroker));
		}

		void AddIntroducingBroker(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_IntroducingBroker, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderSubIDsForUserNames() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SenderSubIDsForUserNames, offsetof(s_TradeAccountDataResponse, m_SenderSubIDsForUserNames));
		}

		void AddSenderSubIDsForUserNames(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SenderSubIDsForUserNames, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetMasterSettingsTimeZone() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_MasterSettingsTimeZone, offsetof(s_TradeAccountDataResponse, m_MasterSettingsTimeZone));
		}

		void AddMasterSettingsTimeZone(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_MasterSettingsTimeZone, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetMasterFirm_SuffixesOfSubaccountsToAddForNewAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount, offsetof(s_TradeAccountDataResponse, m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount));
		}

		void AddMasterFirm_SuffixesOfSubaccountsToAddForNewAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount, StringLength);
		}
		
		//-------------------------------------------------------------------
		const char* GetMasterFirm_UsernameGroupDefinitions() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_MasterFirm_UsernameGroupDefinitions, offsetof(s_TradeAccountDataResponse, m_MasterFirm_UsernameGroupDefinitions));
		}

		void AddMasterFirm_UsernameGroupDefinitions(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_MasterFirm_UsernameGroupDefinitions, StringLength);
		}

		//-------------------------------------------------------------------
		const char* GetRiskManagerUsernameGroup() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_RiskManagerUsernameGroup, offsetof(s_TradeAccountDataResponse, m_RiskManagerUsernameGroup));
		}

		void AddRiskManagerUsernameGroup(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_RiskManagerUsernameGroup, StringLength);
		}

		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataUpdate
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_UPDATE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		uint8_t IsNewAccount = 0;

		DTC_VLS::vls_t NewAccountAuthorizedUsername;
		DTC_VLS::vls_t TradeAccount;

		uint8_t CurrencyCodeIsSet = 0;
		DTC_VLS::vls_t CurrencyCode;

		uint8_t DailyNetLossLimitInAccountCurrencyIsSet = 0;
		float DailyNetLossLimitInAccountCurrency = 0;

		uint8_t PercentOfCashBalanceForDailyNetLossLimitIsSet = 0;
		int32_t PercentOfCashBalanceForDailyNetLossLimit = 0;

		uint8_t UseTrailingAccountValueToNotAllowIncreaseInPositionsIsSet = 0;
		uint8_t UseTrailingAccountValueToNotAllowIncreaseInPositions = 0;

		uint8_t DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet = 0;
		uint8_t DoNotAllowIncreaseInPositionsAtDailyLossLimit = 0;

		uint8_t FlattenPositionsAtDailyLossLimitIsSet = 0;
		uint8_t FlattenPositionsAtDailyLossLimit = 0;
		uint8_t ClosePositionsAtEndOfDayIsSet = 0;
		uint8_t ClosePositionsAtEndOfDay = 0;

		uint8_t FlattenPositionsWhenUnderMarginIntradayIsSet = 0;
		uint8_t FlattenPositionsWhenUnderMarginIntraday = 0;
		uint8_t FlattenPositionsWhenUnderMarginAtEndOfDayIsSet = 0;
		uint8_t FlattenPositionsWhenUnderMarginAtEndOfDay = 0;

		uint8_t SenderSubIDIsSet = 0;
		DTC_VLS::vls_t SenderSubID;
		uint8_t SenderLocationIdIsSet = 0;
		DTC_VLS::vls_t SenderLocationId;
		uint8_t SelfMatchPreventionIDIsSet = 0;
		DTC_VLS::vls_t SelfMatchPreventionID;

		uint8_t CTICodeIsSet = 0;
		int32_t CTICode = 0;
		uint8_t TradeAccountIsReadOnlyIsSet = 0;
		uint8_t TradeAccountIsReadOnly = 0;
		uint8_t MaximumGlobalPositionQuantityIsSet = 0;
		int32_t MaximumGlobalPositionQuantity = 0;
		uint8_t TradeFeePerContractIsSet = 0;
		double TradeFeePerContract = 0;
		uint8_t TradeFeePerShareIsSet = 0;
		double TradeFeePerShare = 0;
		uint8_t RequireSufficientMarginForNewPositionsIsSet = 0;
		uint8_t RequireSufficientMarginForNewPositions = 1;
		uint8_t UsePercentOfMarginIsSet = 0;
		int32_t UsePercentOfMargin = 100;
		uint8_t UsePercentOfMarginForDayTradingIsSet = 0;
		int32_t UsePercentOfMarginForDayTrading = 100;
		uint8_t MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet = 0;
		int32_t MaximumAllowedAccountBalanceForPositionsAsPercentage = 100;
		uint8_t FirmIDIsSet = 0;
		DTC_VLS::vls_t FirmID;

		uint8_t TradingIsDisabledIsSet = 0;
		uint8_t TradingIsDisabled = 0;
		uint8_t DescriptiveNameIsSet = 0;
		DTC_VLS::vls_t DescriptiveName;
		uint8_t IsMasterFirmControlAccountIsSet = 0;
		uint8_t IsMasterFirmControlAccount = 0;
		uint8_t MinimumRequiredAccountValueIsSet = 0;
		double MinimumRequiredAccountValue = 0;

		uint8_t BeginTimeForDayMarginIsSet = 0;
		int64_t BeginTimeForDayMargin = 0;
		uint8_t EndTimeForDayMarginIsSet = 0;
		int64_t EndTimeForDayMargin = 0;
		uint8_t DayMarginTimeZoneIsSet = 0;
		DTC_VLS::vls_t DayMarginTimeZone;

		uint8_t m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntradayIsSet = 0;
		uint8_t m_UseMasterFirm_FlattenPositionsWhenUnderMarginIntraday = 0;
		uint8_t m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDayIsSet = 0;
		uint8_t m_UseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay = 0;
		uint8_t m_UseMasterFirm_SymbolLimitsArrayIsSet = 0;// Unused
		uint8_t m_UseMasterFirm_SymbolLimitsArray = 0;// Unused
		uint8_t m_UseMasterFirm_TradeFeesIsSet = 0;
		uint8_t m_UseMasterFirm_TradeFees = 0;
		uint8_t m_UseMasterFirm_TradeFeePerShareIsSet = 0;
		uint8_t m_UseMasterFirm_TradeFeePerShare = 0;
		uint8_t m_UseMasterFirm_RequireSufficientMarginForNewPositionsIsSet = 0;
		uint8_t m_UseMasterFirm_RequireSufficientMarginForNewPositions = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginIsSet = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMargin = 0;
		uint8_t m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet = 0;
		uint8_t m_UseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage = 0;
		uint8_t m_UseMasterFirm_MinimumRequiredAccountValueIsSet = 0;
		uint8_t m_UseMasterFirm_MinimumRequiredAccountValue = 0;
		uint8_t m_UseMasterFirm_MarginTimeSettingsIsSet = 0;
		uint8_t m_UseMasterFirm_MarginTimeSettings = 0;
		uint8_t m_UseMasterFirm_TradingIsDisabledIsSet = 0;
		uint8_t m_UseMasterFirm_TradingIsDisabled = 0;
		
		uint8_t IsTradeStatisticsPublicallySharedIsSet = 0;
		uint8_t IsTradeStatisticsPublicallyShared = 0;
		uint8_t IsReadOnlyFollowingRequestsAllowedIsSet = 0;
		uint8_t IsReadOnlyFollowingRequestsAllowed = 0;
		uint8_t IsTradeAccountSharingAllowedIsSet = 0;
		uint8_t IsTradeAccountSharingAllowed = 0;
		uint8_t ReadOnlyShareToAllSCUsernamesIsSet = 0;
		uint8_t ReadOnlyShareToAllSCUsernames = 0;

		uint8_t m_UseMasterFirm_SymbolCommissionsArrayIsSet = 0;
		uint8_t m_UseMasterFirm_SymbolCommissionsArray = 0;
		uint8_t m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet = 0;
		uint8_t m_UseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForDayTradingIsSet = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForDayTrading = 0;

		uint8_t m_UseMasterFirm_SymbolCommissionsArrayFullOverrideIsSet = 0;
		uint8_t m_UseMasterFirm_SymbolCommissionsArrayFullOverride = 0;
		uint8_t m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrdersIsSet = 0;
		uint8_t m_UseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginFullOverrideIsSet = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginFullOverride = 0;

		uint8_t m_UseMasterFirm_TradeFeesFullOverrideIsSet = 0;
		uint8_t m_UseMasterFirm_TradeFeesFullOverride = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverrideIsSet = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForDayTradingFullOverride = 0;

		uint8_t m_LiquidationOnlyModeIsSet = 0;
		uint8_t m_LiquidationOnlyMode = 0;

		uint8_t m_CustomerOrFirmIsSet = 0;
		uint8_t m_CustomerOrFirm = 0;

		uint8_t m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMetIsSet = 0;
		uint8_t m_MasterFirm_FlattenCancelAccountWhenDailyLossLimitMet = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValueIsSet = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMinimumAccountValue = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMarginIntradayIsSet = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMarginIntraday = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDayIsSet = 0;
		uint8_t m_MasterFirm_FlattenCancelWhenUnderMarginEndOfDay = 0;
		uint32_t m_MasterFirm_MaximumOrderQuantityIsSet = 0;
		uint32_t m_MasterFirm_MaximumOrderQuantity = 0;

		uint8_t m_ExchangeTraderIdIsSet = 0;
		DTC_VLS::vls_t m_ExchangeTraderId;

		uint8_t m_UseFixedCashOnHandBalanceIsSet = 0;
		uint8_t m_UseFixedCashOnHandBalance = 0;

		uint8_t m_FixedCashOnHandBalanceIsSet = 0;
		float m_FixedCashOnHandBalance = 0.0f;

		uint8_t m_AdministratorUsernamesOwnAccountAccessIsSet = 0;
		DTC_VLS::vls_t m_AdministratorUsernamesOwnAccountAccess;

		uint8_t m_TradeAccountPrefixForExchangeIsSet = 0;
		DTC_VLS::vls_t m_TradeAccountPrefixForExchange;

		uint8_t m_IntroducingBrokerIsSet = 0;
		DTC_VLS::vls_t m_IntroducingBroker;

		uint8_t m_RejectCrossingOrdersIsSet = 0;
		uint8_t m_RejectCrossingOrders = 0;

		uint8_t m_SenderSubIDsForUserNamesIsSet = 0;
		DTC_VLS::vls_t m_SenderSubIDsForUserNames;

		uint8_t m_MessageLimitPerTenSecondsIsSet = 0;
		uint32_t m_MessageLimitPerTenSeconds = 0;

		uint8_t m_LastTradeDateSourceIsSet = 0;
		uint32_t m_LastTradeDateSource = 0;

		uint8_t m_DisableTradingForParentAccountOnlyIsSet = 0;
		uint8_t m_DisableTradingForParentAccountOnly = 0;

		uint8_t m_SupportIntendedPositionOrdersIsSet = 0;
		uint8_t m_SupportIntendedPositionOrders = 0;

		uint8_t m_MarginRecalculationTime1IsSet = 0;
		int64_t m_MarginRecalculationTime1 = 0;

		uint8_t m_MarginRecalculationTime2IsSet = 0;
		int64_t m_MarginRecalculationTime2 = 0;

		uint8_t m_ClosePositionsAtEndOfDayTimeIsSet = 0;
		int64_t m_ClosePositionsAtEndOfDayTime = 0;

		uint8_t m_MasterSettingsTimeZoneIsSet = 0;
		DTC_VLS::vls_t m_MasterSettingsTimeZone;


		uint8_t m_UsePercentOfMarginForOvernightTradingIsSet = 0;
		int32_t m_UsePercentOfMarginForOvernightTrading = 0;

		uint8_t m_BeginTimeForOvernightMarginIsSet = 0;
		int64_t m_BeginTimeForOvernightMargin = 0;

		uint8_t m_EndTimeForOvernightMarginIsSet = 0;
		int64_t m_EndTimeForOvernightMargin = 0;

		uint8_t m_UseMasterFirm_UsePercentOfMarginForOvernightTradingIsSet = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForOvernightTrading = 0;

		uint8_t m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverrideIsSet = 0;
		uint8_t m_UseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride = 0;

		uint8_t m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximumIsSet = 0;
		uint8_t m_UseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum = 0;

		uint8_t m_SupportUserSetProfitLossManagementIsSet = 0;
		uint8_t m_SupportUserSetProfitLossManagement = 0;

		uint8_t m_GenerateTradeAccountDataReport = 0;

		uint8_t m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccountIsSet = 0;
		DTC_VLS::vls_t m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount;

		uint8_t m_MasterFirm_UsernameGroupDefinitionsIsSet = 0;
		DTC_VLS::vls_t m_MasterFirm_UsernameGroupDefinitions;

		uint8_t m_RiskManagerUsernameGroupIsSet = 0;
		DTC_VLS::vls_t m_RiskManagerUsernameGroup;

		uint8_t m_ResetDailyNetLossLimitHasBeenReached = 0;

		uint8_t m_FundsOnHoldToDeductFromAccountBalanceIsSet = 0;
		double m_FundsOnHoldToDeductFromAccountBalance = 0;

		uint8_t m_FundsOnHoldExpirationDateIsSet = 0;
		int64_t m_FundsOnHoldExpirationDate = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsNewAccount() const;
		uint8_t GetCurrencyCodeIsSet() const;
		uint8_t GetDailyNetLossLimitInAccountCurrencyIsSet() const;
		float GetDailyNetLossLimitInAccountCurrency() const;
		uint8_t GetPercentOfCashBalanceForDailyNetLossLimitIsSet() const;
		int32_t GetPercentOfCashBalanceForDailyNetLossLimit() const;
		uint8_t GetUseTrailingAccountValueToNotAllowIncreaseInPositionsIsSet() const;
		uint8_t GetUseTrailingAccountValueToNotAllowIncreaseInPositions() const;
		uint8_t GetDoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet() const;
		uint8_t GetDoNotAllowIncreaseInPositionsAtDailyLossLimit() const;
		uint8_t GetFlattenPositionsAtDailyLossLimitIsSet() const;
		uint8_t GetFlattenPositionsAtDailyLossLimit() const;
		uint8_t GetClosePositionsAtEndOfDayIsSet() const;
		uint8_t GetClosePositionsAtEndOfDay() const;
		uint8_t GetFlattenPositionsWhenUnderMarginIntradayIsSet() const;
		uint8_t GetFlattenPositionsWhenUnderMarginIntraday() const;
		uint8_t GetFlattenPositionsWhenUnderMarginAtEndOfDayIsSet() const;
		uint8_t GetFlattenPositionsWhenUnderMarginAtEndOfDay() const;
		uint8_t GetSenderSubIDIsSet() const;
		uint8_t GetSenderLocationIdIsSet() const;
		uint8_t GetSelfMatchPreventionIDIsSet() const;
		uint8_t GetCTICodeIsSet() const;
		int32_t GetCTICode() const;
		uint8_t GetTradeAccountIsReadOnlyIsSet() const;
		uint8_t GetTradeAccountIsReadOnly() const;
		uint8_t GetMaximumGlobalPositionQuantityIsSet() const;
		int32_t GetMaximumGlobalPositionQuantity() const;
		uint8_t GetTradeFeePerContractIsSet() const;
		double GetTradeFeePerContract() const;
		uint8_t GetTradeFeePerShareIsSet() const;
		double GetTradeFeePerShare() const;
		uint8_t GetRequireSufficientMarginForNewPositionsIsSet() const;
		uint8_t GetRequireSufficientMarginForNewPositions() const;
		uint8_t GetUsePercentOfMarginIsSet() const;
		int32_t GetUsePercentOfMargin() const;
		uint8_t GetUsePercentOfMarginForDayTradingIsSet() const;
		int32_t GetUsePercentOfMarginForDayTrading() const;
		uint8_t GetMaximumAllowedAccountBalanceForPositionsAsPercentageIsSet() const;
		int32_t GetMaximumAllowedAccountBalanceForPositionsAsPercentage() const;
		uint8_t GetFirmIDIsSet() const;
		uint8_t GetTradingIsDisabledIsSet() const;
		uint8_t GetTradingIsDisabled() const;
		uint8_t GetDescriptiveNameIsSet() const;
		uint8_t GetIsMasterFirmControlAccountIsSet() const;
		uint8_t GetIsMasterFirmControlAccount() const;
		uint8_t GetMinimumRequiredAccountValueIsSet() const;
		double GetMinimumRequiredAccountValue() const;
		uint8_t GetBeginTimeForDayMarginIsSet() const;
		int64_t GetBeginTimeForDayMargin() const;
		uint8_t GetEndTimeForDayMarginIsSet() const;
		int64_t GetEndTimeForDayMargin() const;
		uint8_t GetDayMarginTimeZoneIsSet() const;

		uint8_t GetUseMasterFirm_FlattenPositionsWhenUnderMarginIntradayIsSet() const;
		uint8_t GetUseMasterFirm_FlattenPositionsWhenUnderMarginIntraday() const;
		uint8_t GetUseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDayIsSet() const;
		uint8_t GetUseMasterFirm_FlattenPositionsWhenUnderMarginAtEndOfDay() const;
		uint8_t GetUseMasterFirm_SymbolLimitsArrayIsSet() const;
		uint8_t GetUseMasterFirm_SymbolLimitsArray() const;
		uint8_t GetUseMasterFirm_TradeFeesIsSet() const;
		uint8_t GetUseMasterFirm_TradeFees() const;
		uint8_t GetUseMasterFirm_TradeFeePerShareIsSet() const;
		uint8_t GetUseMasterFirm_TradeFeePerShare() const;
		uint8_t GetUseMasterFirm_RequireSufficientMarginForNewPositionsIsSet() const;
		uint8_t GetUseMasterFirm_RequireSufficientMarginForNewPositions() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginIsSet() const;
		uint8_t GetUseMasterFirm_UsePercentOfMargin() const;
		uint8_t GetUseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentageIsSet() const;
		uint8_t GetUseMasterFirm_MaximumAllowedAccountBalanceForPositionsAsPercentage() const;
		uint8_t GetUseMasterFirm_MinimumRequiredAccountValueIsSet() const;
		uint8_t GetUseMasterFirm_MinimumRequiredAccountValue() const;
		uint8_t GetUseMasterFirm_MarginTimeSettingsIsSet() const;
		uint8_t GetUseMasterFirm_MarginTimeSettings() const;
		uint8_t GetUseMasterFirm_TradingIsDisabledIsSet() const;
		uint8_t GetUseMasterFirm_TradingIsDisabled() const;

		uint8_t GetIsTradeStatisticsPublicallySharedIsSet() const;
		uint8_t GetIsTradeStatisticsPublicallyShared() const;
		uint8_t GetIsReadOnlyFollowingRequestsAllowedIsSet() const;
		uint8_t GetIsReadOnlyFollowingRequestsAllowed() const;
		uint8_t GetIsTradeAccountSharingAllowedIsSet() const;
		uint8_t GetIsTradeAccountSharingAllowed() const;
		uint8_t GetReadOnlyShareToAllSCUsernamesIsSet() const;
		uint8_t GetReadOnlyShareToAllSCUsernames() const;

		uint8_t GetUseMasterFirm_SymbolCommissionsArrayIsSet() const;
		uint8_t GetUseMasterFirm_SymbolCommissionsArray() const;
		uint8_t GetUseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimitIsSet() const;
		uint8_t GetUseMasterFirm_DoNotAllowIncreaseInPositionsAtDailyLossLimit() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForDayTradingIsSet() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForDayTrading() const;
		uint8_t GetUseMasterFirm_SymbolCommissionsArrayFullOverrideIsSet() const;
		uint8_t GetUseMasterFirm_SymbolCommissionsArrayFullOverride() const;
		uint8_t GetUseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrdersIsSet() const;
		uint8_t GetUseMasterFirm_NumDaysBeforeLastTradingDateToDisallowOrders() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginFullOverrideIsSet() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginFullOverride() const;
		uint8_t GetUseMasterFirm_TradeFeesFullOverrideIsSet() const;
		uint8_t GetUseMasterFirm_TradeFeesFullOverride() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForDayTradingFullOverrideIsSet() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForDayTradingFullOverride() const;
		uint8_t GetLiquidationOnlyModeIsSet() const;
		uint8_t GetLiquidationOnlyMode() const;

		uint8_t GetCustomerOrFirmIsSet() const;
		uint8_t GetCustomerOrFirm() const;

		uint8_t GetMasterFirm_FlattenCancelAccountWhenDailyLossLimitMetIsSet() const;
		uint8_t GetMasterFirm_FlattenCancelAccountWhenDailyLossLimitMet() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMinimumAccountValueIsSet() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMinimumAccountValue() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMarginIntradayIsSet() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMarginIntraday() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMarginEndOfDayIsSet() const;
		uint8_t GetMasterFirm_FlattenCancelWhenUnderMarginEndOfDay() const;
		uint32_t GetMasterFirm_MaximumOrderQuantityIsSet() const;
		uint32_t GetMasterFirm_MaximumOrderQuantity() const;
		uint8_t GetExchangeTraderIdIsSet() const;

		uint8_t GetUseFixedCashOnHandBalanceIsSet() const;
		uint8_t GetUseFixedCashOnHandBalance() const;

		uint8_t GetFixedCashOnHandBalanceIsSet() const;
		float GetFixedCashOnHandBalance() const;

		uint8_t GetAdministratorUsernamesOwnAccountAccessIsSet() const;
		uint8_t GetTradeAccountPrefixForExchangeIsSet() const;

		uint8_t GetIntroducingBrokerIsSet() const;

		uint8_t GetRejectCrossingOrdersIsSet() const;
		uint8_t GetRejectCrossingOrders() const;

		uint8_t GetSenderSubIDsForUserNamesIsSet() const;

		uint8_t GetMessageLimitPerTenSecondsIsSet() const;
		uint32_t GetMessageLimitPerTenSeconds() const;

		uint8_t GetLastTradeDateSourceIsSet() const;
		uint32_t GetLastTradeDateSource() const;

		uint8_t GetDisableTradingForParentAccountOnlyIsSet() const;
		uint8_t GetDisableTradingForParentAccountOnly() const;

		uint8_t GetSupportIntendedPositionOrdersIsSet() const;
		uint8_t GetSupportIntendedPositionOrders() const;

		uint8_t GetMarginRecalculationTime1IsSet() const;
		int64_t GetMarginRecalculationTime1() const;
		uint8_t GetMarginRecalculationTime2IsSet() const;
		int64_t GetMarginRecalculationTime2() const;
		uint8_t GetClosePositionsAtEndOfDayTimeIsSet() const;
		int64_t GetClosePositionsAtEndOfDayTime() const;
		uint8_t GetMasterSettingsTimeZoneIsSet() const;

		uint8_t GetUsePercentOfMarginForOvernightTradingIsSet() const;
		int32_t GetUsePercentOfMarginForOvernightTrading() const;
		uint8_t GetBeginTimeForOvernightMarginIsSet() const;
		int64_t GetBeginTimeForOvernightMargin() const;
		uint8_t GetEndTimeForOvernightMarginIsSet() const;
		int64_t GetEndTimeForOvernightMargin() const;

		uint8_t GetUseMasterFirm_UsePercentOfMarginForOvernightTradingIsSet() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForOvernightTrading() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverrideIsSet() const;
		uint8_t GetUseMasterFirm_UsePercentOfMarginForOvernightTradingFullOverride() const;

		uint8_t GetUseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximumIsSet() const;
		uint8_t GetUseMasterFirm_UseSymbolPositionAndOrderQuantityLimitsAsMaximum() const;
		uint8_t GetSupportUserSetProfitLossManagementIsSet() const;
		uint8_t GetSupportUserSetProfitLossManagement() const;
		uint8_t GetGenerateTradeAccountDataReport() const;
		uint8_t GetMasterFirm_SuffixesOfSubaccountsToAddForNewAccountIsSet() const;
		uint8_t GetMasterFirm_UsernameGroupDefinitionsIsSet() const;
		uint8_t GetRiskManagerUsernameGroupIsSet() const;
		uint8_t GetResetDailyNetLossLimitHasBeenReached() const;
		uint8_t GetFundsOnHoldToDeductFromAccountBalanceIsSet() const;
		double GetFundsOnHoldToDeductFromAccountBalance() const;
		uint8_t GetFundsOnHoldExpirationDateIsSet() const;
		int64_t GetFundsOnHoldExpirationDate() const;

		//-------------------------------------------------------------------
		const char* GetNewAccountAuthorizedUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, NewAccountAuthorizedUsername, offsetof(s_TradeAccountDataUpdate, NewAccountAuthorizedUsername));
		}

		void AddNewAccountAuthorizedUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, NewAccountAuthorizedUsername, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataUpdate, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetCurrencyCode() const
		{
			return GetVariableLengthStringField(Size, BaseSize, CurrencyCode, offsetof(s_TradeAccountDataUpdate, CurrencyCode));
		}

		void AddCurrencyCode(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, CurrencyCode, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderSubID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SenderSubID, offsetof(s_TradeAccountDataUpdate, SenderSubID));
		}

		void AddSenderSubID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SenderSubID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderLocationId() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SenderLocationId, offsetof(s_TradeAccountDataUpdate, SenderLocationId));
		}

		void AddSenderLocationId(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SenderLocationId, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSelfMatchPreventionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SelfMatchPreventionID, offsetof(s_TradeAccountDataUpdate, SelfMatchPreventionID));
		}

		void AddSelfMatchPreventionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SelfMatchPreventionID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFirmID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FirmID, offsetof(s_TradeAccountDataUpdate, FirmID));
		}

		void AddFirmID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FirmID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetDescriptiveName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, DescriptiveName, offsetof(s_TradeAccountDataUpdate, DescriptiveName));
		}

		void AddDescriptiveName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, DescriptiveName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetDayMarginTimeZone() const
		{
			return GetVariableLengthStringField(Size, BaseSize, DayMarginTimeZone, offsetof(s_TradeAccountDataUpdate, DayMarginTimeZone));
		}

		void AddDayMarginTimeZone(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, DayMarginTimeZone, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetExchangeTraderId() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_ExchangeTraderId, offsetof(s_TradeAccountDataUpdate, m_ExchangeTraderId));
		}

		void AddExchangeTraderId(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_ExchangeTraderId, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetAdministratorUsernamesOwnAccountAccess() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_AdministratorUsernamesOwnAccountAccess, offsetof(s_TradeAccountDataUpdate, m_AdministratorUsernamesOwnAccountAccess));
		}

		void AddAdministratorUsernamesOwnAccountAccess(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_AdministratorUsernamesOwnAccountAccess, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccountPrefixForExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccountPrefixForExchange, offsetof(s_TradeAccountDataUpdate, m_TradeAccountPrefixForExchange));
		}

		void AddTradeAccountPrefixForExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccountPrefixForExchange, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetIntroducingBroker() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_IntroducingBroker, offsetof(s_TradeAccountDataUpdate, m_IntroducingBroker));
		}

		void AddIntroducingBroker(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_IntroducingBroker, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderSubIDsForUserNames() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_SenderSubIDsForUserNames, offsetof(s_TradeAccountDataUpdate, m_SenderSubIDsForUserNames));
		}

		void AddSenderSubIDsForUserNames(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_SenderSubIDsForUserNames, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetMasterSettingsTimeZone() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_MasterSettingsTimeZone, offsetof(s_TradeAccountDataUpdate, m_MasterSettingsTimeZone));
		}

		void AddMasterSettingsTimeZone(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_MasterSettingsTimeZone, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetMasterFirm_SuffixesOfSubaccountsToAddForNewAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount, offsetof(s_TradeAccountDataUpdate, m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount));
		}

		void AddMasterFirm_SuffixesOfSubaccountsToAddForNewAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_MasterFirm_SuffixesOfSubaccountsToAddForNewAccount, StringLength);
		}

		//-------------------------------------------------------------------
		const char* GetMasterFirm_UsernameGroupDefinitions() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_MasterFirm_UsernameGroupDefinitions, offsetof(s_TradeAccountDataUpdate, m_MasterFirm_UsernameGroupDefinitions));
		}

		void AddMasterFirm_UsernameGroupDefinitions(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_MasterFirm_UsernameGroupDefinitions, StringLength);
		}

		//-------------------------------------------------------------------
		const char* GetRiskManagerUsernameGroup() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_RiskManagerUsernameGroup, offsetof(s_TradeAccountDataUpdate, m_RiskManagerUsernameGroup));
		}

		void AddRiskManagerUsernameGroup(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_RiskManagerUsernameGroup, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataDelete
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_DELETE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataDelete, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_TradeAccountDataSymbolLimitsResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_SYMBOL_LIMITS_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;

		DTC_VLS::vls_t TradeAccount;

		DTC_VLS::vls_t Symbol;
		double TradePositionLimit = 0;
		double OrderQuantityLimit = 0;
		int32_t UsePercentOfMargin = 0;
		uint8_t OverrideMarginOtherAccounts = 0;
		int32_t UsePercentOfMarginForDayTrading = 0;
		int32_t NumberOfDaysBeforeLastTradingDateToDisallowOrders = 0;
		float FixedMarginCashValue = 0;
		float FixedMarginCashValueForDayTrading = 0;

		int32_t UsePercentOfMarginForOvernightTrading = 0;
		float FixedMarginCashValueForOvernightTrading = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		double GetTradePositionLimit() const;
		double GetOrderQuantityLimit() const;
		int32_t GetUsePercentOfMargin() const;
		uint8_t GetOverrideMarginOtherAccounts() const;
		int32_t GetUsePercentOfMarginForDayTrading() const;
		int32_t GetNumberOfDaysBeforeLastTradingDateToDisallowOrders() const;
		float GetFixedMarginCashValue() const;
		float GetFixedMarginCashValueForDayTrading() const;

		int32_t GetUsePercentOfMarginForOvernightTrading() const;
		float GetFixedMarginCashValueForOvernightTrading() const;


		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataSymbolLimitsResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_TradeAccountDataSymbolLimitsResponse, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataSymbolLimitsUpdate
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_SYMBOL_LIMITS_UPDATE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		uint8_t IsDeleted = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Symbol;
		double TradePositionLimit = 0;
		double OrderQuantityLimit = 0;
		int32_t UsePercentOfMargin = 100;
		uint8_t OverrideMarginOtherAccounts = 0;
		int32_t UsePercentOfMarginForDayTrading = 0;
		int32_t NumberOfDaysBeforeLastTradingDateToDisallowOrders = 0;
		float FixedMarginCashValue = 0;
		float FixedMarginCashValueForDayTrading = 0;

		int32_t UsePercentOfMarginForOvernightTrading = 0;
		float FixedMarginCashValueForOvernightTrading = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsDeleted() const;
		double GetTradePositionLimit() const;
		double GetOrderQuantityLimit() const;
		int32_t GetUsePercentOfMargin() const;
		uint8_t GetOverrideMarginOtherAccounts() const;
		int32_t GetUsePercentOfMarginForDayTrading() const;
		int32_t GetNumberOfDaysBeforeLastTradingDateToDisallowOrders() const;
		float GetFixedMarginCashValue() const;
		float GetFixedMarginCashValueForDayTrading() const;
		int32_t GetUsePercentOfMarginForOvernightTrading() const;
		float GetFixedMarginCashValueForOvernightTrading() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataSymbolLimitsUpdate, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_TradeAccountDataSymbolLimitsUpdate, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataSymbolCommissionResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_SYMBOL_COMMISSION_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Symbol;
		double TradeFeePerContract = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		double GetTradeFeePerContract() const;
		
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataSymbolCommissionResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_TradeAccountDataSymbolCommissionResponse, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataSymbolCommissionUpdate
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_SYMBOL_COMMISSION_UPDATE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		uint8_t IsDeleted = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Symbol;
		double TradeFeePerContract = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsDeleted() const;
		double GetTradeFeePerContract() const;


		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataSymbolCommissionUpdate, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_TradeAccountDataSymbolCommissionUpdate, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataSubAccountResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_SUB_ACCOUNT_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		// message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;

		DTC_VLS::vls_t m_TradeAccountSuffix;
		DTC_VLS::vls_t m_Currency;
		double m_Balance = 0;
		uint8_t m_UseMainAccountForMarginAndBalance = 1;
		uint64_t m_TransactionIdentifierForCashBalanceAdjustment = 0;
		uint8_t m_DisableTrading = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		double GetBalance() const;
		uint8_t GetUseMainAccountForMarginAndBalance() const;
		uint64_t GetTransactionIdentifierForCashBalanceAdjustment() const;
		uint8_t GetDisableTrading() const;


		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataSubAccountResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccountSuffix() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccountSuffix, offsetof(s_TradeAccountDataSubAccountResponse, m_TradeAccountSuffix));
		}

		void AddTradeAccountSuffix(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccountSuffix, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetCurrency() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_Currency, offsetof(s_TradeAccountDataSubAccountResponse, m_Currency));
		}

		void AddCurrency(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_Currency, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataSubAccountUpdate
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_SUB_ACCOUNT_UPDATE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		// message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;

		uint8_t IsDeleted = 0;

		DTC_VLS::vls_t m_TradeAccountSuffix;
		DTC_VLS::vls_t m_Currency;
		double m_Balance = 0;
		uint8_t m_UseMainAccountForMarginAndBalance = 1;
		uint8_t m_DisableTrading = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsDeleted() const;
		double GetBalance() const;
		uint8_t GetUseMainAccountForMarginAndBalance() const;
		uint8_t GetDisableTrading() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataSubAccountUpdate, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccountSuffix() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccountSuffix, offsetof(s_TradeAccountDataSubAccountUpdate, m_TradeAccountSuffix));
		}

		void AddTradeAccountSuffix(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccountSuffix, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetCurrency() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_Currency, offsetof(s_TradeAccountDataSubAccountUpdate, m_Currency));
		}

		void AddCurrency(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_Currency, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataAuthorizedUsernameResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_AUTHORIZED_USERNAME_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Username;

		uint8_t UpdateOperationComplete = 0;
		uint16_t UpdateOperationMessageType = 0;
		DTC_VLS::vls_t UpdateOperationErrorText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetUpdateOperationComplete() const;
		uint16_t GetUpdateOperationMessageType() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataAuthorizedUsernameResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_TradeAccountDataAuthorizedUsernameResponse, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUpdateOperationErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UpdateOperationErrorText, offsetof(s_TradeAccountDataAuthorizedUsernameResponse, UpdateOperationErrorText));
		}

		void AddUpdateOperationErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UpdateOperationErrorText, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataAuthorizedUsernameAdd
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_AUTHORIZED_USERNAME_ADD;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;

		DTC_VLS::vls_t TradeAccount;

		DTC_VLS::vls_t Username;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;


		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataAuthorizedUsernameAdd, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_TradeAccountDataAuthorizedUsernameAdd, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataAuthorizedUsernameRemove
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_AUTHORIZED_USERNAME_REMOVE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Username;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataAuthorizedUsernameRemove, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_TradeAccountDataAuthorizedUsernameRemove, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataUsernameToShareWithResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_USERNAME_TO_SHARE_WITH_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;

		DTC_VLS::vls_t TradeAccount;

		DTC_VLS::vls_t Username;
		uint8_t IsReadOnly = 0;

		uint8_t UpdateOperationComplete = 0;
		uint16_t UpdateOperationMessageType = 0;
		DTC_VLS::vls_t UpdateOperationErrorText;


		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsReadOnly() const;
		uint8_t GetUpdateOperationComplete() const;
		uint16_t GetUpdateOperationMessageType() const;


		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataUsernameToShareWithResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_TradeAccountDataUsernameToShareWithResponse, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUpdateOperationErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UpdateOperationErrorText, offsetof(s_TradeAccountDataUsernameToShareWithResponse, UpdateOperationErrorText));
		}

		void AddUpdateOperationErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UpdateOperationErrorText, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataUsernameToShareWithAdd
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_USERNAME_TO_SHARE_WITH_ADD;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;

		DTC_VLS::vls_t TradeAccount;

		DTC_VLS::vls_t Username;
		uint8_t IsReadOnly = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsReadOnly() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataUsernameToShareWithAdd, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_TradeAccountDataUsernameToShareWithAdd, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataUsernameToShareWithRemove
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_USERNAME_TO_SHARE_WITH_REMOVE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Username;
		uint8_t IsReadOnly = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsReadOnly() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataUsernameToShareWithRemove, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_TradeAccountDataUsernameToShareWithRemove, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};
	
	/*==========================================================================*/
	struct s_TradeAccountDataResponseTrailer
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_RESPONSE_TRAILER;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		uint8_t m_IsSnapshot = 0;
		uint8_t m_IsFirstMessageInBatch = 0;
		uint8_t m_IsLastMessageInBatch = 0;
		DTC_VLS::vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsSnapshot() const;
		uint8_t GetIsFirstMessageInBatch() const;
		uint8_t GetIsLastMessageInBatch() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataResponseTrailer, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataUpdateOperationComplete
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_UPDATE_OPERATION_COMPLETE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		uint8_t IsError = 0;
		DTC_VLS::vls_t ErrorText;
		uint8_t IsDeleteOperation = 0;
		uint8_t IsSymbolLimitsUpdateOperation = 0;
		uint8_t IsSymbolCommissionUpdateOperation = 0;
		DTC_VLS::vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsError() const;
		uint8_t GetIsDeleteOperation() const;
		uint8_t GetIsSymbolLimitsUpdateOperation() const;
		uint8_t GetIsSymbolCommissionUpdateOperation() const;

		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_TradeAccountDataUpdateOperationComplete, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountDataUpdateOperationComplete, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//--End of Get Add functions----------------------------------------

	};

	/*==========================================================================*/
	struct s_TradeAccountTradingIsDisabledRequest
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_TRADING_IS_DISABLED_REQUEST;
		
		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		n_DTCNonStandard::TradingIsDisabledEnum SetTradingIsDisabled = n_DTCNonStandard::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;
		n_DTCNonStandard::TradingIsDisabledEnum SetDisableTradingForParentAccountOnly = n_DTCNonStandard::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		n_DTCNonStandard::TradingIsDisabledEnum GetSetTradingIsDisabled() const;
		n_DTCNonStandard::TradingIsDisabledEnum GetSetDisableTradingForParentAccountOnly() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountTradingIsDisabledRequest, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//--End of Get Add functions----------------------------------------

	};

	/*==========================================================================*/
	struct s_TradeAccountTradingIsDisabledResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_TRADING_IS_DISABLED_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		n_DTCNonStandard::TradingIsDisabledEnum TradingIsDisabled = n_DTCNonStandard::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;
		n_DTCNonStandard::TradingIsDisabledEnum DisableTradingForParentAccountOnly = n_DTCNonStandard::TRADING_IS_DISABLED_RETURN_CURRENT_VALUE;
		DTC_VLS::vls_t ErrorText;


		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		n_DTCNonStandard::TradingIsDisabledEnum GetTradingIsDisabled() const;
		n_DTCNonStandard::TradingIsDisabledEnum GetDisableTradingForParentAccountOnly() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountTradingIsDisabledResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_TradeAccountTradingIsDisabledResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_TradeAccountDataDuplicate
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::TRADE_ACCOUNT_DATA_DUPLICATE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		DTC_VLS::vls_t ExistingTradeAccount;
		DTC_VLS::vls_t NewTradeAccount;
		DTC_VLS::vls_t ReadWriteSharedUsernameToAdd;
		DTC_VLS::vls_t SenderSubID;
		DTC_VLS::vls_t SenderLocationId;
		DTC_VLS::vls_t DescriptiveName;
		uint8_t TradingIsDisabled = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetTradingIsDisabled() const;


		//-------------------------------------------------------------------
		const char* GetExistingTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ExistingTradeAccount, offsetof(s_TradeAccountDataDuplicate, ExistingTradeAccount));
		}

		void AddExistingTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ExistingTradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetNewTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, NewTradeAccount, offsetof(s_TradeAccountDataDuplicate, NewTradeAccount));
		}

		void AddNewTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, NewTradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetReadWriteSharedUsernameToAdd() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ReadWriteSharedUsernameToAdd, offsetof(s_TradeAccountDataDuplicate, ReadWriteSharedUsernameToAdd));
		}

		void AddReadWriteSharedUsernameToAdd(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ReadWriteSharedUsernameToAdd, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderSubID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SenderSubID, offsetof(s_TradeAccountDataDuplicate, SenderSubID));
		}

		void AddSenderSubID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SenderSubID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSenderLocationId() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SenderLocationId, offsetof(s_TradeAccountDataDuplicate, SenderLocationId));
		}

		void AddSenderLocationId(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SenderLocationId, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetDescriptiveName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, DescriptiveName, offsetof(s_TradeAccountDataDuplicate, DescriptiveName));
		}

		void AddDescriptiveName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, DescriptiveName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct  s_UserProfitLossManagementDataResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::USER_PROFIT_LOSS_MANAGEMENT_DATA_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t m_RequestID = 0;
		uint8_t m_IsSnapshot = 0;

		DTC_VLS::vls_t m_TradeAccount;

		//Settings variables
		uint8_t m_FlattenAllPositionsWhenProfitRulesMet = 0;
		double m_ProfitTriggerValueInAccountCurrency = 0.0;
		double m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency = 0.0;

		uint8_t m_TrailDailyNetProfit_IsEnabled = 0;
		double m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency = 0.0;
		double m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency = 0.0;

		uint8_t m_FlattenAllPositionsWhenLossRuleMet = 0;
		double m_LossTriggerValueInAccountCurrency = 0.0;

		uint8_t m_FlattenPositionsAtSetTime = 0;
		int64_t m_FlattenPositionsTime = 0;

		uint8_t m_ActionToPerformWhenProfitTriggerRulesMet = 1;

		//State variables. Read-only.

		uint8_t m_IsProfitTriggerValueInAccountCurrencyMet = 0;
		double m_ProfitLossValueAfterProfitTriggerToFlattenPositionsInAccountCurrency = 0.0;
		double m_MaxProfitReachedForDailyProfitManagement = 0.0;

		double m_CalculatedLossTriggerValueInAccountCurrency = 0.0;

		int64_t m_DateTimeUTCPositionsFlattenedForProfitManagement = 0;
		int64_t m_DateTimeUTCPositionsFlattenedForDailyLossMet = 0;
		int64_t m_DateTimeUTCPositionsFlattenedForAtSetTime = 0;

		uint8_t m_FlattenOperationPerformedForLossManagementInCurrentTradeDate = 0;
		uint8_t m_FlattenOperationPerformedForProfitManagementInCurrentTradeDate = 0;
		uint8_t m_FlattenOperationPerformedForAtSetTimeInCurrentTradeDate = 0;

		uint8_t m_ActionToPerformWhenLossTriggerRuleMet = 0;
		uint8_t m_ActionToPerformWhenAtSetTimeTriggerRuleMet = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsSnapshot() const;
		uint8_t GetFlattenAllPositionsWhenProfitRulesMet() const;
		double GetProfitTriggerValueInAccountCurrency() const;
		double GetProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const;

		uint8_t GetTrailDailyNetProfit_IsEnabled() const;
		double GetTrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency() const;
		double GetTrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const;

		uint8_t GetFlattenAllPositionsWhenLossRuleMet() const;
		double GetLossTriggerValueInAccountCurrency() const;

		uint8_t GetFlattenPositionsAtSetTime() const;
		int64_t GetFlattenPositionsTime() const;

		uint8_t GetActionToPerformWhenProfitTriggerRulesMet() const;

		uint8_t GetIsProfitTriggerValueInAccountCurrencyMet() const;
		double GetProfitLossValueAfterProfitTriggerToFlattenPositionsInAccountCurrency() const;
		double GetMaxProfitReachedForDailyProfitManagement() const;

		double GetCalculatedLossTriggerValueInAccountCurrency() const;

		int64_t GetDateTimeUTCPositionsFlattenedForProfitManagement() const;
		int64_t GetDateTimeUTCPositionsFlattenedForDailyLossMet() const;
		int64_t GetDateTimeUTCPositionsFlattenedForAtSetTime() const;
				
		uint8_t GetFlattenOperationPerformedForLossManagementInCurrentTradeDate() const;
		uint8_t GetFlattenOperationPerformedForProfitManagementInCurrentTradeDate() const;
		uint8_t GetFlattenOperationPerformedForAtSetTimeInCurrentTradeDate() const;

		uint8_t GetActionToPerformWhenLossTriggerRuleMet() const;
		uint8_t GetActionToPerformWhenAtSetTimeTriggerRuleMet() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccount, offsetof(s_UserProfitLossManagementDataResponse, m_TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_UserProfitLossManagementDataUpdate
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::USER_PROFIT_LOSS_MANAGEMENT_DATA_UPDATE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t m_RequestID = 0;
		DTC_VLS::vls_t m_TradeAccount;

		uint8_t m_FlattenAllPositionsWhenProfitRulesMetIsSet = 0;
		uint8_t m_FlattenAllPositionsWhenProfitRulesMet = 0;

		uint8_t m_ProfitTriggerValueInAccountCurrencyIsSet = 0;
		double m_ProfitTriggerValueInAccountCurrency = 0.0;

		uint8_t m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet = 0;
		double m_ProfitValueAfterTriggerToFlattenPositionsInAccountCurrency = 0.0;

		uint8_t m_TrailDailyNetProfit_IsEnabledIsSet = 0;
		uint8_t m_TrailDailyNetProfit_IsEnabled = 0;

		uint8_t m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrencyIsSet = 0;
		double m_TrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency = 0.0;

		uint8_t m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet = 0;
		double m_TrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency = 0.0;

		uint8_t m_FlattenAllPositionsWhenLossRuleMetIsSet = 0;
		uint8_t m_FlattenAllPositionsWhenLossRuleMet = 0;

		uint8_t m_LossTriggerValueInAccountCurrencyIsSet = 0;
		double m_LossTriggerValueInAccountCurrency = 0.0;

		uint8_t m_FlattenPositionsAtSetTimeIsSet = 0;
		uint8_t m_FlattenPositionsAtSetTime = 0;

		uint8_t m_FlattenPositionsTimeIsSet = 0;
		int64_t m_FlattenPositionsTime = 0;

		uint8_t m_ActionToPerformWhenProfitTriggerRulesMetIsSet = 0;
		uint8_t m_ActionToPerformWhenProfitTriggerRulesMet = 1;

		uint8_t m_ActionToPerformWhenLossTriggerRuleMetIsSet = 0;
		uint8_t m_ActionToPerformWhenLossTriggerRuleMet = 0;
		uint8_t m_ActionToPerformWhenAtSetTimeTriggerRuleMetIsSet = 0;
		uint8_t m_ActionToPerformWhenAtSetTimeTriggerRuleMet = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetFlattenAllPositionsWhenProfitRulesMetIsSet() const;
		uint8_t GetFlattenAllPositionsWhenProfitRulesMet() const;

		uint8_t GetProfitTriggerValueInAccountCurrencyIsSet() const;
		double GetProfitTriggerValueInAccountCurrency() const;

		uint8_t GetProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet() const;
		double GetProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const;

		uint8_t GetTrailDailyNetProfit_IsEnabledIsSet() const;
		uint8_t GetTrailDailyNetProfit_IsEnabled() const;

		uint8_t GetTrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrencyIsSet() const;
		double GetTrailDailyNetProfit_AdditionalProfitIncreaseInAccountCurrency() const;

		uint8_t GetTrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrencyIsSet() const;
		double GetTrailDailyNetProfit_AmountToIncreaseProfitValueAfterTriggerToFlattenPositionsInAccountCurrency() const;

		uint8_t GetFlattenAllPositionsWhenLossRuleMetIsSet() const;
		uint8_t GetFlattenAllPositionsWhenLossRuleMet() const;

		uint8_t GetLossTriggerValueInAccountCurrencyIsSet() const;
		double GetLossTriggerValueInAccountCurrency() const;

		uint8_t GetFlattenPositionsAtSetTimeIsSet() const;
		uint8_t GetFlattenPositionsAtSetTime() const;

		uint8_t GetFlattenPositionsTimeIsSet() const;
		int64_t GetFlattenPositionsTime() const;

		uint8_t GetActionToPerformWhenProfitTriggerRulesMetIsSet() const;
		uint8_t GetActionToPerformWhenProfitTriggerRulesMet() const;

		uint8_t GetActionToPerformWhenLossTriggerRuleMetIsSet() const;
		uint8_t GetActionToPerformWhenLossTriggerRuleMet() const;
		uint8_t GetActionToPerformWhenAtSetTimeTriggerRuleMetIsSet() const;
		uint8_t GetActionToPerformWhenAtSetTimeTriggerRuleMet() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, m_TradeAccount, offsetof(s_UserProfitLossManagementDataUpdate, m_TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, m_TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_UserProfitLossManagementDataUpdateOperationComplete
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::USER_PROFIT_LOSS_MANAGEMENT_DATA_UPDATE_OPERATION_COMPLETE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t RequestID = 0;
		uint8_t IsError = 0;
		DTC_VLS::vls_t ErrorText;
		DTC_VLS::vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsError() const;

		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_UserProfitLossManagementDataUpdateOperationComplete, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_UserProfitLossManagementDataUpdateOperationComplete, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ProcessedFillIdentifier
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::PROCESSED_FILL_IDENTIFIER;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		DTC_VLS::vls_t FillIdentifier;

		uint8_t IsSnapshot = 0;
		uint8_t IsFirstMessageInBatch = 0;
		uint8_t IsLastMessageInBatch = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint8_t GetIsSnapshot() const;
		uint8_t GetIsFirstMessageInBatch() const;
		uint8_t GetIsLastMessageInBatch() const;

		//-------------------------------------------------------------------
		const char* GetFillIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FillIdentifier, offsetof(s_ProcessedFillIdentifier, FillIdentifier));
		}

		void AddFillIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FillIdentifier, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_FlattenPositionsForTradeAccount
	{
		static constexpr uint16_t MESSAGE_TYPE = DTC::FLATTEN_POSITIONS_FOR_TRADE_ACCOUNT;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t ClientOrderID;
		DTC_VLS::vls_t FreeFormText;
		uint8_t IsAutomatedOrder = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint8_t GetIsAutomatedOrder() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_FlattenPositionsForTradeAccount, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_FlattenPositionsForTradeAccount, ClientOrderID));
		}

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_FlattenPositionsForTradeAccount, FreeFormText));
		}

		void AddFreeFormText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_UserInformation
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::USER_INFORMATION;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		// Message fields
		DTC_VLS::vls_t OperatorID;
		DTC_VLS::vls_t LocationID;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		//-------------------------------------------------------------------
		const char* GetOperatorID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OperatorID, offsetof(s_UserInformation, OperatorID));
		}

		void AddOperatorID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, OperatorID, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetLocationID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, LocationID, offsetof(s_UserInformation, LocationID));
		}

		void AddLocationID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, LocationID, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_MarginDataRequest
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::MARGIN_DATA_REQUEST;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		int32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Symbol;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_MarginDataRequest, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_MarginDataRequest, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_MarginDataResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::MARGIN_DATA_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		int32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t ErrorText;
		double ExchangeMargin = 0;
		double AccountMargin = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		double GetExchangeMargin() const;
		double GetAccountMargin() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_MarginDataResponse, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_MarginDataResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
	};


	/*==========================================================================*/
	struct s_ConvertPositionToSubAccountBalanceAdjustments
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CONVERT_POSITION_TO_SUB_ACCOUNT_BALANCE_ADJUSTMENTS;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		int32_t RequestID = 0;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Symbol;
		uint8_t IsSimulated = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetRequestID() const;
		uint8_t GetIsSimulated() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_ConvertPositionToSubAccountBalanceAdjustments, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_ConvertPositionToSubAccountBalanceAdjustments, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ConvertPositionToSubAccountBalanceAdjustmentsReject
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CONVERT_POSITION_TO_SUB_ACCOUNT_BALANCE_ADJUSTMENTS_REJECT;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		int32_t RequestID = 0;
		DTC_VLS::vls_t RejectText;
		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Symbol;
		uint8_t IsSimulated = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		int32_t GetRequestID() const;
		uint8_t GetIsSimulated() const;


		//-------------------------------------------------------------------
		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsReject, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsReject, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ConvertPositionToSubAccountBalanceAdjustmentsComplete
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CONVERT_POSITION_TO_SUB_ACCOUNT_BALANCE_ADJUSTMENTS_COMPLETE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		int32_t RequestID = 0;
		int64_t TransactionID = 0;

		DTC_VLS::vls_t TradeAccount;
		DTC_VLS::vls_t Symbol;
		uint8_t IsSimulated = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		int32_t GetRequestID() const;
		int64_t GetTransactionID() const;
		uint8_t GetIsSimulated() const;

		//-------------------------------------------------------------------
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsComplete, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_ConvertPositionToSubAccountBalanceAdjustmentsComplete, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/****************************************************************************/
	// Chartbook Sharing
	/****************************************************************************/

	using t_ChartbookSharingFileID = uint32_t;

	/****************************************************************************/
	// s_MessageBase

	/*==========================================================================*/
	template<typename MESSAGE, uint16_t TYPE>
	struct s_MessageBase
	{
		static constexpr uint16_t MESSAGE_TYPE = TYPE;

		//standard DTC VLS header
		uint16_t Size = sizeof(MESSAGE);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(MESSAGE);

		uint16_t GetMessageSize() const
		{
			return Size;
		}
		uint16_t GetBaseSize() const
		{
			return BaseSize;
		}
	};

	enum class e_ErrorCode : uint16_t
		{ OK = 0
		, NotConnected
		, AlreadyConnected
		, NotShared
		, AlreadyShared
		, AlreadyStopped
		, BusyByAnotherUser
		, FileAlreadyExist
		, FileNotExist
		, NoPermissions
		, AlreadySubscribed
		, NotSubscribed
		, NotSharing
		, AlreadySharing
		, NotResumed
		, AlreadyResumed
		, AlreadyAllowed
		, AlreadyDisAllowed
		, AllowedToEveryone
		, SameInstanceForbidden
		};

	/****************************************************************************/
	// s_MessageBaseWithError

	/*==========================================================================*/
	template<typename MESSAGE, uint16_t TYPE>
	struct s_MessageBaseWithError
		: public s_MessageBase<MESSAGE, TYPE>
	{
		e_ErrorCode ErrorCode;
		DTC_VLS::vls_t ErrorDescription;

		//-------------------------------------------------------------------
		e_ErrorCode GetErrorCode() const
		{
			return ErrorCode;
		}

		//-------------------------------------------------------------------
		const char* GetErrorDescription() const
		{
			return GetVariableLengthStringField(s_MessageBase<MESSAGE, TYPE>::Size, s_MessageBase<MESSAGE, TYPE>::BaseSize, ErrorDescription, offsetof(MESSAGE, ErrorDescription));
		}

		void AddErrorDescription(uint16_t PatternLength)
		{
			AddVariableLengthStringField(s_MessageBase<MESSAGE, TYPE>::Size, ErrorDescription, PatternLength);
		}
	};

	/****************************************************************************/
	// s_BinaryTransfer

	/*==========================================================================*/
	struct s_BinaryTransfer 
		: public s_MessageBase<s_BinaryTransfer, n_DTCNonStandard::CHARTBOOK_BINARY_DATA_TRANSFER>
	{
		uint32_t FileID = 0;
		DTC_VLS::vls_t FileName;
		int64_t TimeStamp = 0;	// In microseconds
		uint32_t BinaryDataSize = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
		int64_t GetTimeStamp() const;

		//-------------------------------------------------------------------
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);

		const char* GetBinaryData() const;
		uint32_t GetBinaryDataLength() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingConnect

	/*==========================================================================*/
	struct s_ChartbookSharingConnect
		: public s_MessageBase<s_ChartbookSharingConnect, n_DTCNonStandard::CHARTBOOK_SHARING_CONNECT>
	{
		int64_t UserTimeStamp;	// In microseconds

		//-------------------------------------------------------------------
		int64_t GetUserTimeStamp() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingConnected

	/*==========================================================================*/
	struct s_ChartbookSharingConnected
		: public s_MessageBaseWithError<s_ChartbookSharingConnected, n_DTCNonStandard::CHARTBOOK_SHARING_CONNECTED>
	{
		int64_t ServerTimeStamp;	// In microseconds

		//-------------------------------------------------------------------
		int64_t GetServerTimeStamp() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingDisconnect

	/*==========================================================================*/
	struct s_ChartbookSharingDisconnect
		: public s_MessageBase<s_ChartbookSharingDisconnect, n_DTCNonStandard::CHARTBOOK_SHARING_DISCONNECT>
	{
	};

	/****************************************************************************/
	// s_ChartbookSharingDisconnected

	/*==========================================================================*/
	struct s_ChartbookSharingDisconnected
		: public s_MessageBaseWithError<s_ChartbookSharingDisconnected, n_DTCNonStandard::CHARTBOOK_SHARING_DISCONNECTED>
	{
	};

	/****************************************************************************/
	// s_ChartbookSharingSearch

	/*==========================================================================*/
	struct s_ChartbookSharingSearch
		: public s_MessageBase<s_ChartbookSharingSearch, n_DTCNonStandard::CHARTBOOK_SHARING_SEARCH>
	{
		static const uint32_t SEARCH_IN_ALL = 0x0000;
		static const uint32_t SEARCH_IN_USER_NAME = 0x0001;
		static const uint32_t SEARCH_IN_FILE_NAME = 0x0002;
		static const uint32_t SEARCH_IS_SHARING_NOW = 0x0004;
		static const uint32_t SEARCH_SUBSCRIBED = 0x0008;
		static const uint32_t SEARCH_IAM_SUBSCRIBED = 0x0010;
		static const uint32_t SEARCH_GET_ALLOWED = 0x0020;

		DTC_VLS::vls_t SearchPattern;
		uint32_t Flags = 0;

		//-------------------------------------------------------------------
		uint32_t GetFlags() const;

		//-------------------------------------------------------------------
		const char* GetSearchPattern() const;
		void AddSearchPattern(uint16_t PatternLength);
	};

	/****************************************************************************/
	// s_ChartbookSharingSearchResult

	/*==========================================================================*/
	struct s_ChartbookSharingSearchResult
		: public s_MessageBaseWithError<s_ChartbookSharingSearchResult, n_DTCNonStandard::CHARTBOOK_SHARING_SHARED_CHARTBOOK>
	{
		static const uint32_t FLAG_IS_SHARING_NOW			= 1 << 0;
		static const uint32_t FLAG_IS_IAM_SUBSCRIBED		= 1 << 1;
		static const uint32_t FLAG_IS_IAM_AUTHOR			= 1 << 2;
		static const uint32_t FLAG_IS_PRIVATE				= 1 << 3;
		static const uint32_t FLAG_IS_IAM_SHARING			= 1 << 4;
		static const uint32_t FLAG_IS_IAM_RESUME_NOW		= 1 << 5;
		static const uint32_t FLAG_IS_ECHO_TEST				= 1 << 6;
		static const uint32_t FLAG_IS_FIRST_MESSAGE			= 1 << 7;
		static const uint32_t FLAG_IS_LAST_MESSAGE			= 1 << 8;

		uint32_t FileID = 0;
		DTC_VLS::vls_t AuthorName;
		DTC_VLS::vls_t FileName;
		DTC_VLS::vls_t Description;
		int64_t FileTimeStamp;	// In microseconds
		uint32_t SubscribedNum = 0;
		uint32_t Flags = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
		int64_t GetFileTimeStamp() const;
		uint32_t GetSubscribedNum() const;
		uint32_t GetFlags() const;

		//-------------------------------------------------------------------
		const char* GetAuthorName() const;
		void AddAuthorName(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
		const char* GetDescription() const;
		void AddDescription(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingGetInfo

	/*==========================================================================*/
	struct s_ChartbookSharingGetInfo
		: public s_MessageBase<s_ChartbookSharingGetInfo, n_DTCNonStandard::CHARTBOOK_SHARING_GET_INFO>
	{
		static const uint32_t FLAG_GET_FILE_CONTENT = 1 << 0;

		uint32_t FileID = 0;
		uint32_t Flags = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
		uint32_t GetFlags() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingGetUpdate

	/*==========================================================================*/
	struct s_ChartbookSharingGetUpdate
		: public s_MessageBase<s_ChartbookSharingGetUpdate, n_DTCNonStandard::CHARTBOOK_SHARING_GET_UPDATE>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingShare

	/*==========================================================================*/
	struct s_ChartbookSharingShare
		: public s_MessageBase<s_ChartbookSharingShare, n_DTCNonStandard::CHARTBOOK_SHARING_SHARE>
	{
		static const uint32_t FLAG_IS_PRIVATE = 0x0001;

		DTC_VLS::vls_t FileName;
		DTC_VLS::vls_t Description;
		uint32_t Flags = 0;

		//-------------------------------------------------------------------
		uint32_t GetFlags() const;

		//-------------------------------------------------------------------
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
		const char* GetDescription() const;
		void AddDescription(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingShared

	/*==========================================================================*/
	struct s_ChartbookSharingShared
		: public s_MessageBaseWithError<s_ChartbookSharingShared, n_DTCNonStandard::CHARTBOOK_SHARING_SHARED>
	{
		DTC_VLS::vls_t FileName;
		DTC_VLS::vls_t Description;
		uint32_t Flags = 0;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFlags() const;
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
		const char* GetDescription() const;
		void AddDescription(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingShareUpdate

	/*==========================================================================*/
	struct s_ChartbookSharingShareUpdate
		: public s_MessageBase<s_ChartbookSharingShareUpdate, n_DTCNonStandard::CHARTBOOK_SHARING_SHARE_UPDATE>
	{
		DTC_VLS::vls_t FileName;
		DTC_VLS::vls_t Description;
		uint32_t Flags = 0;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFlags() const;
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
		const char* GetDescription() const;
		void AddDescription(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingAllowClient

	/*==========================================================================*/
	struct s_ChartbookSharingAllowClient
		: public s_MessageBase<s_ChartbookSharingAllowClient, n_DTCNonStandard::CHARTBOOK_SHARING_ALLOW_CLIENT>
	{
		static const uint32_t FLAG_ALLOW_CLIENT					= 1 << 0;
		static const uint32_t FLAG_ALLOW_CLIENT_FIRST_IN_BATCH	= 1 << 1;
		static const uint32_t FLAG_ALLOW_CLIENT_LAST_IN_BATCH	= 1 << 2;
		static const uint32_t FLAG_ALLOW_CLIENT_EMPTY			= 1 << 3;

		DTC_VLS::vls_t Username;
		uint32_t Flags = 0;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFlags() const;
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingAllowedClient

	/*==========================================================================*/
	struct s_ChartbookSharingAllowedClient
		: public s_MessageBaseWithError<s_ChartbookSharingAllowedClient, n_DTCNonStandard::CHARTBOOK_SHARING_ALLOWED_CLIENT>
	{
		DTC_VLS::vls_t Username;
		uint32_t Flags = 0;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFlags() const;
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingUnShare

	/*==========================================================================*/
	struct s_ChartbookSharingUnShare
		: public s_MessageBase<s_ChartbookSharingUnShare, n_DTCNonStandard::CHARTBOOK_SHARING_UNSHARE>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingUnShared

	/*==========================================================================*/
	struct s_ChartbookSharingUnShared
		: public s_MessageBaseWithError<s_ChartbookSharingUnShared, n_DTCNonStandard::CHARTBOOK_SHARING_UNSHARED>
	{
		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingSubscribe

	/*==========================================================================*/
	struct s_ChartbookSharingSubscribe
		: public s_MessageBase<s_ChartbookSharingSubscribe, n_DTCNonStandard::CHARTBOOK_SHARING_SUBSCRIBE>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingSubscribed

	/*==========================================================================*/
	struct s_ChartbookSharingSubscribed
		: public s_MessageBaseWithError<s_ChartbookSharingSubscribed, n_DTCNonStandard::CHARTBOOK_SHARING_SUBSCRIBED>
	{
		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingUnSubscribe

	/*==========================================================================*/
	struct s_ChartbookSharingUnSubscribe
		: public s_MessageBase<s_ChartbookSharingUnSubscribe, n_DTCNonStandard::CHARTBOOK_SHARING_UNSUBSCRIBE>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingUnSubscribed

	/*==========================================================================*/
	struct s_ChartbookSharingUnSubscribed
		: public s_MessageBaseWithError<s_ChartbookSharingUnSubscribed, n_DTCNonStandard::CHARTBOOK_SHARING_UNSUBSCRIBED>
	{
		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingStart

	/*==========================================================================*/
	struct s_ChartbookSharingStart
		: public s_MessageBase<s_ChartbookSharingStart, n_DTCNonStandard::CHARTBOOK_SHARING_START>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingStarted

	/*==========================================================================*/
	struct s_ChartbookSharingStarted
		: public s_MessageBaseWithError<s_ChartbookSharingStarted, n_DTCNonStandard::CHARTBOOK_SHARING_STARTED>
	{
		static const uint32_t FLAG_START_IAM_SHARING = 1 << 0;

		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;
		uint32_t Flags = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
		uint32_t GetFlags() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingStop

	/*==========================================================================*/
	struct s_ChartbookSharingStop
		: public s_MessageBase<s_ChartbookSharingStop, n_DTCNonStandard::CHARTBOOK_SHARING_STOP>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingStopped

	/*==========================================================================*/
	struct s_ChartbookSharingStopped
		: public s_MessageBaseWithError<s_ChartbookSharingStopped, n_DTCNonStandard::CHARTBOOK_SHARING_STOPPED>
	{
		static const uint32_t FLAG_START_IAM_STOPPED = 1 << 0;

		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;
		uint32_t Flags = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
		uint32_t GetFlags() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingPause

	/*==========================================================================*/
	struct s_ChartbookSharingPause
		: public s_MessageBase<s_ChartbookSharingPause, n_DTCNonStandard::CHARTBOOK_SHARING_SUSPEND>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingPaused

	/*==========================================================================*/
	struct s_ChartbookSharingPaused
		: public s_MessageBaseWithError<s_ChartbookSharingPaused, n_DTCNonStandard::CHARTBOOK_SHARING_SUSPENDED>
	{
		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingResume

	/*==========================================================================*/
	struct s_ChartbookSharingResume
		: public s_MessageBase<s_ChartbookSharingResume, n_DTCNonStandard::CHARTBOOK_SHARING_RESUME>
	{
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;
	};

	/****************************************************************************/
	// s_ChartbookSharingResumed

	/*==========================================================================*/
	struct s_ChartbookSharingResumed
		: public s_MessageBaseWithError<s_ChartbookSharingResumed, n_DTCNonStandard::CHARTBOOK_SHARING_RESUMED>
	{
		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingDelegate

	/*==========================================================================*/
	struct s_ChartbookSharingDelegate
		: public s_MessageBase<s_ChartbookSharingDelegate, n_DTCNonStandard::CHARTBOOK_SHARING_DELEGATE>
	{
		DTC_VLS::vls_t Username;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingDelegated

	/*==========================================================================*/
	struct s_ChartbookSharingDelegated
		: public s_MessageBaseWithError<s_ChartbookSharingDelegated, n_DTCNonStandard::CHARTBOOK_SHARING_DELEGATED>
	{
		DTC_VLS::vls_t Username;
		DTC_VLS::vls_t FileName;
		uint32_t FileID = 0;

		//-------------------------------------------------------------------
		uint32_t GetFileID() const;

		//-------------------------------------------------------------------
		const char* GetUsername() const;
		void AddUsername(uint16_t Length);
		const char* GetFileName() const;
		void AddFileName(uint16_t Length);
	};

	/****************************************************************************/
	// s_ChartbookSharingServerRestarted

	/*==========================================================================*/
	struct s_ChartbookSharingServerRestarted
		: public s_MessageBase<s_ChartbookSharingServerRestarted, n_DTCNonStandard::CHARTBOOK_SHARING_SERVER_RESTARTED>
	{
		static const uint32_t FLAG_SHUTDOWN = 1 << 0;

		uint32_t Flags = 0;

		//-------------------------------------------------------------------
		uint32_t GetFlags() const;
	};

	/*==========================================================================*/
	// Begin of chat related messages.

	/*==========================================================================*/
	struct s_ChatServiceSetProfileSettings
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SET_PROFILE_SETTINGS;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint8_t Searchable = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint8_t GetSearchable() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceSetProfileSettingsResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SET_PROFILE_SETTINGS_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t Result;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;

		//-------------------------------------------------------------------
		const char* GetResult() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Result, offsetof(s_ChatServiceSetProfileSettingsResponse, Result));
		}

		void AddResult(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Result, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceGetProfileSettings
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_PROFILE_SETTINGS;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceGetProfileSettingsResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_PROFILE_SETTINGS_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint8_t Searchable = 0;
		DTC_VLS::vls_t TelegramIdentifier;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint8_t GetSearchable() const;

		//-------------------------------------------------------------------
		const char* GetTelegramIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TelegramIdentifier, offsetof(s_ChatServiceGetProfileSettingsResponse, TelegramIdentifier));
		}

		void AddTelegramIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TelegramIdentifier, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceSendTextMessage
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SEND_TEXT_MESSAGE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables		
		uint64_t RequestID = 0;
		uint64_t ToChatIdentifier = 0;
		int64_t CreationTime = 0;
		DTC_VLS::vls_t Text;
		uint64_t ReplyToMessageIdentifier = 0;
		uint64_t UpdateForMessageIdentifier = 0;
		uint32_t DocumentAttachentIdentifier = 0;
		uint16_t MessageState = 0;
		uint8_t	DeleteMessage = 0;
		uint8_t FinalMessageInBatch = 1;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetToChatIdentifier() const;
		int64_t GetCreationTime() const;
		uint64_t GetReplyToMessageIdentifier() const;
		uint64_t GetUpdateForMessageIdentifier() const;
		uint32_t GetDocumentAttachentIdentifier() const;
		uint16_t GetMessageState() const;
		uint8_t	GetDeleteMessage() const;
		uint8_t GetFinalMessageInBatch() const;


		//-------------------------------------------------------------------
		const char* GetText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Text, offsetof(s_ChatServiceSendTextMessage, Text));
		}

		void AddText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Text, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceSendTextMessageResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SEND_TEXT_MESSAGE_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t ToChatIdentifier = 0;
		int64_t Timestamp = 0;
		uint16_t MessageState = 0;
		uint64_t MessageIdentifier = 0;
		DTC_VLS::vls_t ErrorText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetToChatIdentifier() const;
		int64_t GetTimestamp() const;
		uint16_t GetMessageState() const;
		uint64_t GetMessageIdentifier() const;

		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_ChatServiceSendTextMessageResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_ChatServiceGetTextMessages
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_TEXT_MESSAGE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t ChatIdentifier = 0;
		uint64_t LastDownloadedMessageIdentifier = 0;
		uint32_t LimitDownloadingToDays = 0;


		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetChatIdentifier() const;
		uint64_t GetLastDownloadedMessageIdentifier() const;
		uint32_t GetLimitDownloadingToDays() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceServerToClientTextMessage
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SERVER_TO_CLIENT_TEXT_MESSAGE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t MessageIdentifier = 0;
		uint64_t ChatIdentifier = 0;
		uint64_t FromUserIdentifier = 0;
		int64_t CreationTime = 0;
		int64_t Timestamp = 0;
		DTC_VLS::vls_t Text;
		uint16_t MessageState = 0;	//Originally it was Send, Sending, Delivery, Read
		uint64_t ReplyToMessageIdentifier = 0;
		uint64_t UpdateForMessageIdentifier = 0;
		uint8_t	DeleteMessage = 0;
		uint32_t DocumentAttachentIdentifier = 0;
		uint8_t IsFinal = 0;


		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetMessageIdentifier() const;
		uint64_t GetChatIdentifier() const;
		uint64_t GetFromUserIdentifier() const;
		int64_t GetCreationTime() const;
		int64_t GetTimestamp() const;
		uint16_t GetMessageState() const;
		uint64_t GetReplyToMessageIdentifier() const;
		uint64_t GetUpdateForMessageIdentifier() const;
		uint8_t	GetDeleteMessage() const;
		uint32_t GetDocumentAttachentIdentifier() const;
		uint8_t GetIsFinal() const;


		//-------------------------------------------------------------------
		const char* GetText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Text, offsetof(s_ChatServiceServerToClientTextMessage, Text));
		}

		void AddText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Text, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceCreateChatGroup
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_CREATE_CHAT_GROUP;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t PeerUserIdentifier = 0;
		uint8_t IsPublicGroup = 0;
		uint8_t IsReadOnly= 1;
		DTC_VLS::vls_t GroupDescription;
		uint8_t RelayToTelegram = 0;
		uint8_t RelayOwnMessagesToTelegram = 0;
		uint8_t KeepUserListPrivate = 0;
		uint8_t AllowViewScreenSharing = 0;
		uint8_t AllowSendScreenSharing = 0;
		uint8_t AllowRemoteControl = 0;


		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetPeerUserIdentifier() const;
		uint8_t GetIsPublicGroup() const;
		uint8_t GetIsReadOnly() const;
		uint8_t GetRelayToTelegram() const;
		uint8_t GetRelayOwnMessagesToTelegram() const;
		uint8_t GetKeepUserListPrivate() const;
		uint8_t GetAllowViewScreenSharing() const;
		uint8_t GetAllowSendScreenSharing() const;
		uint8_t GetAllowRemoteControl() const;


		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceCreateChatGroup, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------

		//-------------------------------------------------------------------
		const char* GetGroupDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupDescription, offsetof(s_ChatServiceCreateChatGroup, GroupDescription));
		}

		void AddGroupDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupDescription, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceCreateChatGroupResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_CREATE_CHAT_GROUP_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t PeerUserIdentifier = 0;
		DTC_VLS::vls_t ErrorText;
		uint8_t IsPublicGroup = 0;
		uint8_t IsReadOnly= 1;
		DTC_VLS::vls_t GroupDescription;


		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetPeerUserIdentifier() const;
		uint8_t GetIsPublicGroup() const;
		uint8_t GetIsReadOnly() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceCreateChatGroupResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_ChatServiceCreateChatGroupResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetGroupDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupDescription, offsetof(s_ChatServiceCreateChatGroupResponse, GroupDescription));
		}

		void AddGroupDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupDescription, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceAddChatGroupMember
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_ADD_CHAT_GROUP_MEMBER;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UserIdentifier = 0;
		int32_t AccessRights = 0;

		uint8_t IsFinal = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const; 
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUserIdentifier() const;
		int32_t GetAccessRights() const;
		uint8_t GetIsFinal() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceAddChatGroupMember, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceAddChatGroupMemberResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_ADD_CHAT_GROUP_MEMBER_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UserIdentifier = 0;
		int32_t AccessRights = 0;
		int32_t Result = 0;
		DTC_VLS::vls_t ErrorText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUserIdentifier() const;
		int32_t GetAccessRights() const;
		int32_t GetResult() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceAddChatGroupMemberResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_ChatServiceAddChatGroupMemberResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceUpdateChatGroupMember
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_UPDATE_CHAT_GROUP_MEMBER;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UserIdentifier = 0;
		int32_t AccessRights = 0;
		uint8_t IsFinal = 1;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUserIdentifier() const;
		int32_t GetAccessRights() const;
		uint8_t GetIsFinal() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceUpdateChatGroupMember, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceUpdateChatGroupMemberResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_UPDATE_CHAT_GROUP_MEMBER_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UserIdentifier = 0;
		int32_t AccessRights = 0;
		int32_t Result = 0;
		uint8_t IsFinal = 1;
		DTC_VLS::vls_t ErrorText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUserIdentifier() const;
		int32_t GetAccessRights() const;
		int32_t GetResult() const;
		uint8_t GetIsFinal() const;


		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceUpdateChatGroupMemberResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_ChatServiceUpdateChatGroupMemberResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceDeleteChatGroupMember
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_DELETE_CHAT_GROUP_MEMBER;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UserIdentifier = 0;
		uint8_t IsFinal = 1;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUserIdentifier() const;
		uint8_t GetIsFinal() const;


		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceDeleteChatGroupMember, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceDeleteChatGroupMemberResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_DELETE_CHAT_GROUP_MEMBER_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UserIdentifier = 0;
		int32_t Result = 0;
		uint8_t IsFinal = 1;
		DTC_VLS::vls_t ErrorText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUserIdentifier() const;
		int32_t GetResult() const;
		uint8_t GetIsFinal() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceDeleteChatGroupMemberResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_ChatServiceDeleteChatGroupMemberResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceDeleteChatGroup
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_DELETE_CHAT_GROUP;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceDeleteChatGroup, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceDeleteChatGroupResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_DELETE_CHAT_GROUP_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		int32_t Result = 0;
		DTC_VLS::vls_t ErrorText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetResult() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceDeleteChatGroupResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorText, offsetof(s_ChatServiceDeleteChatGroupResponse, ErrorText));
		}

		void AddErrorText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorText, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceUpdateChatGroup
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_UPDATE_CHAT_GROUP;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		DTC_VLS::vls_t NewGroupName;
		DTC_VLS::vls_t NewGroupDescription;
		uint8_t IsPublicGroup = 0;
		uint8_t IsReadOnly = 0;
		uint8_t RelayToTelegram = 0;
		uint8_t RelayOwnMessagesToTelegram = 0;
		uint8_t KeepUserListPrivate = 0;
		uint8_t AllowViewScreenSharing = 0;
		uint8_t AllowSendScreenSharing = 0;
		uint8_t AllowRemoteControl = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint8_t GetIsPublicGroup() const;
		uint8_t GetIsReadOnly() const;
		uint8_t GetRelayToTelegram() const;
		uint8_t GetRelayOwnMessagesToTelegram() const;
		uint8_t GetKeepUserListPrivate() const;
		uint8_t GetAllowViewScreenSharing() const;
		uint8_t GetAllowSendScreenSharing() const;
		uint8_t GetAllowRemoteControl() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceUpdateChatGroup, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetNewGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, NewGroupName, offsetof(s_ChatServiceUpdateChatGroup, NewGroupName));
		}

		void AddNewGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, NewGroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetNewGroupDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, NewGroupDescription, offsetof(s_ChatServiceUpdateChatGroup, NewGroupDescription));
		}

		void AddNewGroupDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, NewGroupDescription, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceUpdateChatGroupResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_UPDATE_CHAT_GROUP_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		DTC_VLS::vls_t NewGroupName;
		int32_t Result = 0;	
		DTC_VLS::vls_t NewGroupDescription;
		DTC_VLS::vls_t Error;
		uint8_t IsPublicGroup = 0;
		uint8_t IsReadOnly = 0;
		uint8_t RelayToTelegram = 0;
		uint8_t RelayOwnMessagesToTelegram = 0;
		uint8_t KeepUserListPrivate = 0;
		uint8_t AllowViewScreenSharing = 0;
		uint8_t AllowSendScreenSharing = 0;
		uint8_t AllowRemoteControl = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		int32_t GetResult() const;
		int8_t GetIsPublicGroup() const;
		int8_t GetIsReadOnly() const;
		int8_t GetRelayToTelegram() const;
		uint8_t GetRelayOwnMessagesToTelegram() const;
		uint8_t GetKeepUserListPrivate() const;
		uint8_t GetAllowViewScreenSharing() const;
		uint8_t GetAllowSendScreenSharing() const;
		uint8_t GetAllowRemoteControl() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceUpdateChatGroupResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetNewGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, NewGroupName, offsetof(s_ChatServiceUpdateChatGroupResponse, NewGroupName));
		}

		void AddNewGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, NewGroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetNewGroupDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, NewGroupDescription, offsetof(s_ChatServiceUpdateChatGroupResponse, NewGroupDescription));
		}

		void AddNewGroupDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, NewGroupDescription, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetError() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Error, offsetof(s_ChatServiceUpdateChatGroupResponse, Error));
		}

		void AddError(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Error, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceGetChatGroupMembers
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_CHAT_GROUP_MEMBERS;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UpdateId = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUpdateId() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceGetChatGroupMembers, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceGetChatGroupMembersResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_CHAT_GROUP_MEMBERS_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		uint64_t UniqueChatIdentifier = 0;
		uint32_t CurrentGroupMemberIndex = 0;
		uint32_t LastGroupMemberIndex = 0;

		uint64_t UserIdentifier = 0;
		int32_t AccessRights = 0;
		uint8_t IsDeleted = 0;
		uint32_t UpdateIdentifier = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetCurrentGroupMemberIndex() const;
		uint32_t GetLastGroupMemberIndex() const;

		uint64_t GetUserIdentifier() const;
		int32_t GetAccessRights() const;
		uint8_t GetIsDeleted() const;
		uint32_t GetUpdateIdentifier() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceGetChatGroupMembersResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
	};


	/*==========================================================================*/
	struct s_ChatServiceGetChatsList
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_CHATS_LIST;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint32_t UpdateIdentifier = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint32_t GetUpdateIdentifier() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceGetChatsListResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_CHATS_LIST_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint32_t CurrentChatIndex = 0;
		uint32_t LastIndex = 0;

		uint64_t UniqueChatIdentifier = 0;
		DTC_VLS::vls_t GroupName;
		DTC_VLS::vls_t FolderName;
		uint8_t IsDeletedChat = 0;
		uint8_t IsGroupChat = 0;
		uint8_t IsLeftChat = 0;
		uint32_t UpdateIdentifier = 0;
		uint64_t RecordIdentifier = 0;
		uint8_t IsPublicGroup = 0;
		uint8_t IsReadOnly= 1;
		DTC_VLS::vls_t GroupDescription;
		uint8_t RelayToTelegram = 0;
		uint8_t RelayOwnMessagesToTelegram = 0;
		uint8_t KeepUserListPrivate = 0;
		uint8_t AllowViewScreenSharing = 0;
		uint8_t AllowSendScreenSharing = 0;
		uint8_t AllowRemoteControl = 0;


		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint32_t GetCurrentChatIndex() const;
		uint32_t GetLastIndex() const;

		uint64_t GetUniqueChatIdentifier() const;
		uint8_t GetIsDeletedChat() const;
		uint8_t GetIsGroupChat() const;

		uint8_t GetIsLeftChat() const;
		uint32_t GetUpdateIdentifier() const;
		uint64_t GetRecordIdentifier() const;
		uint8_t GetIsPublicGroup() const;
		uint8_t GetIsReadOnly() const;
		uint8_t GetRelayToTelegram() const;
		uint8_t GetRelayOwnMessagesToTelegram() const;
		uint8_t GetKeepUserListPrivate() const;
		uint8_t GetAllowViewScreenSharing() const;
		uint8_t GetAllowSendScreenSharing() const;
		uint8_t GetAllowRemoteControl() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceGetChatsListResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFolderName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FolderName, offsetof(s_ChatServiceGetChatsListResponse, FolderName));
		}

		void AddFolderName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FolderName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetGroupDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupDescription, offsetof(s_ChatServiceGetChatsListResponse, GroupDescription));
		}

		void AddGroupDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupDescription, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceGetUserInformation
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_USER_INFORMATION;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UserIdentifier = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUserIdentifier() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceGetUserInformationResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_USER_INFORMATION_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UserIdentifier = 0;
		DTC_VLS::vls_t UserName;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUserIdentifier() const;

		//-------------------------------------------------------------------
		const char* GetUserName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UserName, offsetof(s_ChatServiceGetUserInformationResponse, UserName));
		}

		void AddUserName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UserName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceFindUserByName
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_FIND_USER_BY_NAME;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t UserNamePattern;
		uint8_t DoSmartSearch = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint8_t GetDoSmartSearch() const;

		//-------------------------------------------------------------------
		const char* GetUserNamePattern() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UserNamePattern, offsetof(s_ChatServiceFindUserByName, UserNamePattern));
		}

		void AddUserNamePattern(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UserNamePattern, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceFindUserByNameResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_FIND_USER_BY_NAME_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint32_t AmountOfItems = 0;
		DTC_VLS::vls_t UserNamePattern;
		uint8_t DoSmartSearch = 0;

		DTC_VLS::vls_t UserName;
		uint64_t UserIdentifier = 0;
		uint32_t CurrentItem = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint32_t GetAmountOfItems() const;
		uint8_t GetDoSmartSearch() const;
		uint64_t GetUserIdentifier() const;
		uint32_t GetCurrentItem() const;

		//-------------------------------------------------------------------
		const char* GetUserNamePattern() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UserNamePattern, offsetof(s_ChatServiceFindUserByNameResponse, UserNamePattern));
		}

		void AddUserNamePattern(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UserNamePattern, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetUserName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UserName, offsetof(s_ChatServiceFindUserByNameResponse, UserName));
		}

		void AddUserName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UserName, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceStartUploadFile
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_START_UPLOAD_FILE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t FileSize = 0;
		DTC_VLS::vls_t FileName;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetFileSize() const;

		//-------------------------------------------------------------------
		const char* GetFileName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChatServiceStartUploadFile, FileName));
		}

		void AddFileName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FileName, StringLength);
		}
		//-------------------------------------------------------------------

	};

	/*==========================================================================*/
	struct s_ChatServiceStartUploadFileResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_START_UPLOAD_FILE_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t FileSize = 0;
		DTC_VLS::vls_t FileName;
		uint32_t DocumentIdentifier = 0;
		DTC_VLS::vls_t ErrorString;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetFileSize() const;
		uint32_t GetDocumentIdentifier() const;

		//-------------------------------------------------------------------
		const char* GetFileName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FileName, offsetof(s_ChatServiceStartUploadFileResponse, FileName));
		}

		void AddFileName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FileName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetErrorString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorString, offsetof(s_ChatServiceStartUploadFileResponse, ErrorString));
		}

		void AddErrorString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorString, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	//This structure must not contain any strings.It has custom direct processing.
	struct s_ChatServiceUploadFile
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_UPLOAD_FILE_FAST;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint32_t DocumentIdentifier = 0;
		uint64_t BlockOffset = 0;
		uint32_t BlockSize = 0;
		//uint8_t FileContent[n_DTCNonStandard::FILE_CONTENT_SIZE];

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetDocumentIdentifier() const;
		uint64_t GetBlockOffset() const;
		uint32_t GetBlockSize() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceUploadFileResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_UPLOAD_FILE_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint32_t DocumentIdentifier = 0;
		uint64_t BlockOffset = 0;
		uint32_t BlockSize = 0;
		uint8_t UploadingResult = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetDocumentIdentifier() const;
		uint64_t GetBlockOffset() const;
		uint32_t GetBlockSize() const;
		uint8_t  GetUploadingResult() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceDownloadFile
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_DOWNLOAD_FILE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint32_t DocumentIdentifier = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetDocumentIdentifier() const;
	};

	/*==========================================================================*/
	//This structure must not contain any strings.It has custom direct processing.
	struct s_ChatServiceDownloadFileResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_DOWNLOAD_FILE_RESPONSE_FAST;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint32_t DocumentIdentifier = 0;
		uint64_t FileSize = 0;
		uint64_t BlockOffset = 0;
		uint32_t BlockSize = 0;
		//uint8_t FileContent[n_DTCNonStandard::FILE_CONTENT_SIZE];

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetDocumentIdentifier() const;
		uint64_t GetFileSize() const;
		uint64_t GetBlockOffset() const;
		uint32_t GetBlockSize() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceGetFileInformation
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_FILE_INFORMATION;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint32_t DocumentIdentifier = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetDocumentIdentifier() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceGetFileInformationResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_FILE_INFORMATION_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint32_t DocumentIdentifier = 0;
		uint64_t FileSize = 0;
		DTC_VLS::vls_t FilePath;
		DTC_VLS::vls_t FileTitle;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint32_t GetDocumentIdentifier() const;
		uint64_t GetFileSize() const;

		//-------------------------------------------------------------------
		const char* GetFilePath() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FilePath, offsetof(s_ChatServiceGetFileInformationResponse, FilePath));
		}

		void AddFilePath(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FilePath, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetFileTitle() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FileTitle, offsetof(s_ChatServiceGetFileInformationResponse, FileTitle));
		}

		void AddFileTitle(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FileTitle, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceSearchPublicGroups
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SEARCH_PUBLIC_GROUPS;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t SearchString;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;

		//-------------------------------------------------------------------
		const char* GetSearchString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SearchString, offsetof(s_ChatServiceSearchPublicGroups, SearchString));
		}

		void AddSearchString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SearchString, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatServiceSearchPublicGroupsResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SEARCH_PUBLIC_GROUPS_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		DTC_VLS::vls_t GroupName;
		DTC_VLS::vls_t GroupDescription;
		uint64_t UniqueChatIdentifier = 0;
		int32_t  CurrentIndex = -1;
		int32_t  ResultArraySize = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		int32_t GetCurrentIndex() const;
		int32_t GetResultArraySize() const;

		//-------------------------------------------------------------------
		const char* GetGroupName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupName, offsetof(s_ChatServiceSearchPublicGroupsResponse, GroupName));
		}

		void AddGroupName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupName, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetGroupDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GroupDescription, offsetof(s_ChatServiceSearchPublicGroupsResponse, GroupDescription));
		}

		void AddGroupDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GroupDescription, StringLength);
		}
		//-------------------------------------------------------------------

	};

	/*==========================================================================*/
	struct s_ChatServiceJoinPublicGroup
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_JOIN_PUBLIC_GROUP;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
	};

	/*==========================================================================*/
	struct s_ScreenShareRemoteControlNegotiation
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_SCREEN_SHARE_REMOTE_CONTROL_NEGOTIATION;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint8_t  State = 0;
		uint8_t  Key[32];
		uint64_t UnixTimeStampMS = 0;
		uint8_t  Role = 0;
		uint64_t ScreenSharingUserIdentifier = 0;
		uint64_t CreatorOfSession = 0;

		uint8_t BitPerSample = 0;
		uint8_t ScreenFormat = 0;
		uint8_t CompressionAlgorithm = 0;

		DTC_VLS::vls_t ErrorString;
		uint64_t UniqueRdpSessionIdentifier = 0;
		int32_t DropVideoFramesIfGreaterEqualMillisecondsOfDataInSendBuffer = 0;

		uint8_t IsDirectPeerToPeer = 0;
		int16_t PeerToPeerServerPortNumber = 0;
		uint32_t PeerToPeerServerIPAddress = 0;
		DTC_VLS::vls_t InitiatorSystemIdentifier;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		//
		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint8_t  GetState() const;
		void     GetKey(uint8_t(*p_Key)[32]) const;
		uint64_t GetUnixTimeStampMS() const;
		uint8_t  GetRole() const;
		uint64_t GetScreenSharingUserIdentifier() const;
		uint64_t GetCreatorOfSession() const;

		uint8_t GetBitPerSample() const;
		uint8_t GetScreenFormat() const;
		uint8_t GetCompressionAlgorithm() const;
		uint64_t GetUniqueRdpSessionIdentifier() const;
		int32_t GetDropVideoFramesIfGreaterEqualMillisecondsOfDataInSendBuffer() const;
		uint8_t GetIsDirectPeerToPeer() const;
		int16_t GetPeerToPeerServerPortNumber() const;
		uint32_t GetPeerToPeerServerIPAddress() const;

		void SetKey(const uint8_t NewKey[32]);

		//-------------------------------------------------------------------
		const char* GetErrorString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ErrorString, offsetof(s_ScreenShareRemoteControlNegotiation, ErrorString));
		}

		void AddErrorString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ErrorString, StringLength);
		}

		//-------------------------------------------------------------------
		const char* GetInitiatorSystemIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, InitiatorSystemIdentifier, offsetof(s_ScreenShareRemoteControlNegotiation, InitiatorSystemIdentifier));
		}

		void AddInitiatorSystemIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, InitiatorSystemIdentifier, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	// This structure must not contain any strings. It has custom direct processing.
	struct s_ChatScreenSharingDirectVideoFrame
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SCREENSHARING_SERVICE_DIRECT_VIDEO_FRAME;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t FromUserIdentifier = 0;

		uint16_t FrameFlags = 0;
		int64_t PresentationTime = 0;
		int64_t Duration = 0;
		uint32_t Width = 0;
		uint32_t Height = 0;
		int Align = 0;
		int RowSize = 0;

		//The frame follows the message. Size member variable is not increased by this FrameSize. Although it is increased by four bytes for this specific integer member only.
		int32_t FrameSize = 0;

		// No get functions used with this for performance reasons.  If member is added both client and server need to both be up-to-date!
	};

	/****************************************************************************/
	// s_ChatRemoteClipboardData
	// This structure must not contain any strings. It has custom direct processing.
	struct s_ChatRemoteClipboardData
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_REMOTE_CLIPBOARD_DATA;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UniqueRdpSessionIdentifier = 0;	//TODO: verify usage. Perhaps it is not used
		uint64_t UserIdentifier = 0;
		uint64_t UniqueClipboardSequenceNumber = 0;	//the pair UserIdentifier and UniqueClipboardSequenceNumber is unique
		uint16_t ClipboardFormat = 0;		//it is non-zero only for the first message if there are a huge amount of data and we split them
		uint32_t TotalDataSize = 0;
		uint32_t BlockDataSize = 0;

		// No get functions used with this for performance reasons.  If member is added both client and server need to both be up-to-date!
	};

	/*==========================================================================*/
	struct s_ChatServiceGetConnectionInformation
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_CONNECTION_INFORMATION;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
	};

	/*==========================================================================*/
	struct s_ChatServiceGetConnectionInformationResponse
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_SERVICE_GET_CONNECTION_INFORMATION_RESPONSE;

		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint64_t RequestID = 0;
		uint64_t UserIdentifier = 0;
		DTC_VLS::vls_t LogonUserName;
		DTC_VLS::vls_t TelegramURL;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUserIdentifier() const;

		//-------------------------------------------------------------------
		const char* GetLogonUserName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, LogonUserName, offsetof(s_ChatServiceGetConnectionInformationResponse, LogonUserName));
		}

		void AddLogonUserName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, LogonUserName, StringLength);
		}		
		
		const char* GetTelegramURL() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TelegramURL, offsetof(s_ChatServiceGetConnectionInformationResponse, TelegramURL));
		}

		void AddTelegramURL(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TelegramURL, StringLength);
		}
		//-------------------------------------------------------------------
	};

	/*==========================================================================*/
	struct s_ChatRemoteControlInputData
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_REMOTE_CONTROL_INPUT_DATA;

		//Standard header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//Fields
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;

		uint8_t InputTypeFlag = 0;	//bit mask: 0x01 - Keyboard input fields valid, 0x02 - Mouse fields input valid

		int32_t MouseX = 0;
		int32_t MouseY = 0;
		uint32_t MouseData = 0;
		uint32_t MouseFlags = 0;
		uint64_t MouseMessage = 0;

		uint32_t KeyboardVirtualKey = 0;
		uint32_t KeyboardScanCode = 0;
		uint32_t KeyboardFlags = 0;
		uint64_t KeyboardMessage = 0;
		int32_t RepeatCount = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;

		uint8_t GetInputTypeFlag() const;

		int32_t GetMouseX() const;
		int32_t GetMouseY() const;
		uint32_t GetMouseData() const;
		uint32_t GetMouseFlags() const;
		uint64_t GetMouseMessage() const;

		uint32_t GetKeyboardVirtualKey() const;
		uint32_t GetKeyboardScanCode() const;
		uint32_t GetKeyboardFlags() const;
		uint64_t GetKeyboardMessage() const;
		int32_t GetRepeatCount() const;
	};

	/*==========================================================================*/
	struct s_ChatRemoteControlSessionState
	{
		static constexpr uint16_t MESSAGE_TYPE = n_DTCNonStandard::CHAT_REMOTE_CONTROL_SESSION_STATE;

		//Standard header
		uint16_t Size = sizeof(*this);
		uint16_t Type = MESSAGE_TYPE;
		uint16_t BaseSize = sizeof(*this);

		//Fields
		uint64_t RequestID = 0;
		uint64_t UniqueChatIdentifier = 0;
		uint64_t UniqueRdpSessionIdentifier = 0;
		uint64_t UserIdentifier = 0;
		uint8_t  Role = 0; //values from ShareRemoteControlNegotiationRolesEnum;
		uint8_t  State = 0;		//values from ShareRemoteControlSessionStateEnum
		uint8_t  Final = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint64_t GetRequestID() const;
		uint64_t GetUniqueChatIdentifier() const;
		uint64_t GetUniqueRdpSessionIdentifier() const;
		uint64_t GetUserIdentifier() const;
		uint8_t  GetRole() const;
		uint8_t  GetState() const;
		uint8_t  GetFinal() const;
	};

#pragma pack(pop)
}



