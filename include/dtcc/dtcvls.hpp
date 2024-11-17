
// Data and Trading Communications Protocol Variable Length String Encoding (DTC Protocol VLS)

// This protocol is in the public domain and freely usable by anyone.

// Documentation: http://DTCprotocol.org/index.php?page=doc_DTCMessageDocumentation.php

// The uint8_t ordering is little endian.

#pragma once

#include "dtcc/dtc.hpp"
#include <assert.h>
#include <limits>
#include <cstddef> // offsetof

namespace DTC_VLS
{
#pragma pack(8)

	struct s_MessageHeader {
		uint16_t Size;
		uint16_t Type;
		uint16_t BaseSize;
	};

	// see DTCProtocol.h for constants and enum values

	/*==========================================================================*/
	enum TradeModeEnum : int8_t
	{ TRADE_MODE_UNSET = 0
	, TRADE_MODE_DEMO = 1
	, TRADE_MODE_SIMULATED = 2
	, TRADE_MODE_LIVE = 3
	};

	/*==========================================================================*/
	struct s_VariableLengthStringField
	{
		uint16_t Offset = 0;
		uint16_t Length = 0;
	};

	typedef s_VariableLengthStringField vls_t;

	/*==========================================================================*/
	inline void AddVariableLengthStringField(uint16_t& r_StructureSizeField, vls_t& r_VariableLengthStringField, uint16_t SizeToAdd)
	{
		//If this string will put the size of the structure at or greater than the maximum size possible for a DTC message, then do not add.
		if ((static_cast<int32_t>(r_StructureSizeField) + r_VariableLengthStringField.Length) >= 65536)
		{
			SizeToAdd = 0;
			assert(false);
		}

		if (SizeToAdd == 0)
		{
			r_VariableLengthStringField.Offset = 0;
			r_VariableLengthStringField.Length = 0;
		}
		else
		{
			r_VariableLengthStringField.Offset = r_StructureSizeField;
			r_VariableLengthStringField.Length = SizeToAdd + 1;
			r_StructureSizeField += r_VariableLengthStringField.Length;
		}
	}

	/*==========================================================================*/
	inline const char* GetVariableLengthStringField( 
		const uint16_t& MessageSizeField
		, uint16_t BaseStructureSizeField
		, const vls_t& VariableLengthStringField
		, const uint16_t VariableLengthStringFieldOffset
	)
	{
		if (BaseStructureSizeField < VariableLengthStringFieldOffset + sizeof(vls_t))
			return "";
		else if (VariableLengthStringField.Offset == 0 || VariableLengthStringField.Length <= 1)
			return "";
		else if ((VariableLengthStringField.Offset + VariableLengthStringField.Length) > MessageSizeField)
			return "";
		else
		{
			const int MaximumLength = 50 * 1024;
			int Length = VariableLengthStringField.Length;
			if (Length > MaximumLength)
			{
				Length = MaximumLength;
			}

			char * BaseMessage = reinterpret_cast< char *>( const_cast<uint16_t *>(&MessageSizeField));
			char * TerminatorCharacter = BaseMessage + VariableLengthStringField.Offset + Length - 1;

			*TerminatorCharacter = 0;//Make sure there is a null terminator here.

			return (const char*) BaseMessage + VariableLengthStringField.Offset;

		}
	}

	/*==========================================================================*/
	inline uint16_t GetStringFieldSendLength(uint32_t SendLength)
	{
		uint16_t ActualSendLength = static_cast<uint16_t>(SendLength);
		
		++ActualSendLength;

		return ActualSendLength;
	}

	/*==========================================================================*/
	struct s_LogonRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::LOGON_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t ProtocolVersion = DTC::CURRENT_VERSION;
		vls_t Username;
		vls_t Password;
		vls_t GeneralTextData;
		int32_t Integer_1 = 0;
		int32_t Integer_2 = 0;
		int32_t HeartbeatIntervalInSeconds = 0;
		int32_t Unused1 = 0;
		vls_t TradeAccount; 
		vls_t HardwareIdentifier;
		vls_t ClientName;
		int32_t MarketDataTransmissionInterval = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetProtocolVersion() const;

		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_LogonRequest, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}

		const char* GetPassword() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Password, offsetof(s_LogonRequest, Password));
		}

		void AddPassword(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Password, StringLength);
		}

		const char* GetGeneralTextData() const
		{
			return GetVariableLengthStringField(Size, BaseSize, GeneralTextData, offsetof(s_LogonRequest, GeneralTextData));
		}

		void AddGeneralTextData(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, GeneralTextData, StringLength);
		}

		int32_t GetInteger_1() const;
		int32_t GetInteger_2() const;
		int32_t GetHeartbeatIntervalInSeconds() const;
		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_LogonRequest, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetHardwareIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, HardwareIdentifier, offsetof(s_LogonRequest, HardwareIdentifier));
		}

		void AddHardwareIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, HardwareIdentifier, StringLength);
		}

		const char* GetClientName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientName, offsetof(s_LogonRequest, ClientName));
		}

		void AddClientName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientName, StringLength);
		}

		int32_t GetMarketDataTransmissionInterval() const;

	};

	/*==========================================================================*/
	struct s_LogonResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::LOGON_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		int32_t ProtocolVersion = DTC::CURRENT_VERSION;
		DTC::LogonStatusEnum Result = DTC::LOGON_SUCCESS;
		vls_t ResultText;
		vls_t ReconnectAddress;
		int32_t Integer_1 = 0;
		vls_t ServerName;
		uint8_t MarketDepthUpdatesBestBidAndAsk = 0;
		uint8_t TradingIsSupported = 0;
		uint8_t OCOOrdersSupported = 0;
		uint8_t OrderCancelReplaceSupported = 1;
		vls_t SymbolExchangeDelimiter;
		uint8_t SecurityDefinitionsSupported = 0;
		uint8_t HistoricalPriceDataSupported = 0;
		uint8_t ResubscribeWhenMarketDataFeedAvailable = 0;
		uint8_t MarketDepthIsSupported = 1;
		uint8_t OneHistoricalPriceDataRequestPerConnection = 0;
		uint8_t BracketOrdersSupported = 0;
		uint8_t Unused_1 = 0;
		uint8_t UsesMultiplePositionsPerSymbolAndTradeAccount = 0;
		uint8_t MarketDataSupported = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		int32_t GetProtocolVersion() const;
		DTC::LogonStatusEnum GetResult() const;
		int32_t GetInteger_1() const;
		uint8_t GetMarketDepthUpdatesBestBidAndAsk() const;
		uint8_t GetTradingIsSupported() const;
		uint8_t GetOCOOrdersSupported() const;
		uint8_t GetOrderCancelReplaceSupported() const;
		uint8_t GetSecurityDefinitionsSupported() const;
		uint8_t GetHistoricalPriceDataSupported() const;
		uint8_t GetResubscribeWhenMarketDataFeedAvailable() const;
		uint8_t GetMarketDepthIsSupported() const;
		uint8_t GetOneHistoricalPriceDataRequestPerConnection() const;
		uint8_t GetBracketOrdersSupported() const;
		uint8_t GetUsesMultiplePositionsPerSymbolAndTradeAccount() const;
		uint8_t GetMarketDataSupported() const;

		const char* GetResultText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ResultText, offsetof(s_LogonResponse, ResultText));
		}

		void AddResultText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ResultText, StringLength);
		}

		const char* GetReconnectAddress() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ReconnectAddress, offsetof(s_LogonResponse, ReconnectAddress));
		}

		void AddReconnectAddress(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ReconnectAddress, StringLength);
		}

		const char* GetServerName() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerName, offsetof(s_LogonResponse, ServerName));
		}

		void AddServerName(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServerName, StringLength);
		}

		const char* GetSymbolExchangeDelimiter() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SymbolExchangeDelimiter, offsetof(s_LogonResponse, SymbolExchangeDelimiter));
		}

		void AddSymbolExchangeDelimiter(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SymbolExchangeDelimiter, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_Logoff
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::LOGOFF;
		uint16_t BaseSize = sizeof(*this);

		vls_t Reason;
		uint8_t DoNotReconnect = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		const char* GetReason() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Reason, offsetof(s_Logoff, Reason));
		}

		void AddReason(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Reason, StringLength);
		}

		uint8_t GetDoNotReconnect() const;
	};


	/*==========================================================================*/
	struct s_MarketDataRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::MARKET_DATA_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		DTC::RequestActionEnum RequestAction = DTC::SUBSCRIBE;
		uint32_t SymbolID = 0;
		vls_t Symbol;
		vls_t Exchange;
		uint32_t IntervalForSnapshotUpdatesInMilliseconds = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		DTC::RequestActionEnum GetRequestAction() const;
		uint32_t GetSymbolID() const;

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_MarketDataRequest, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_MarketDataRequest, Symbol));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		uint32_t GetIntervalForSnapshotUpdatesInMilliseconds() const;
	};

	/*==========================================================================*/
	struct s_MarketDepthRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::MARKET_DEPTH_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		DTC::RequestActionEnum RequestAction = DTC::SUBSCRIBE;
		uint32_t SymbolID = 0;
		vls_t Symbol;
		vls_t Exchange;
		int32_t NumLevels = 10;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		DTC::RequestActionEnum GetRequestAction() const;
		uint32_t GetSymbolID() const;

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_MarketDepthRequest, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_MarketDepthRequest, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		int32_t GetNumLevels() const;
	};

	/*==========================================================================*/
	struct s_MarketDataReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::MARKET_DATA_REJECT;
		uint16_t BaseSize = sizeof(*this);

		uint32_t SymbolID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		uint32_t GetSymbolID() const;

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_MarketDataReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};


	/*==========================================================================*/
	struct s_MarketDepthReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::MARKET_DEPTH_REJECT;
		uint16_t BaseSize = sizeof(*this);

		uint32_t SymbolID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetSymbolID() const;

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_MarketDepthReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_MarketOrdersRequest
	{
		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::MARKET_ORDERS_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		DTC::RequestActionEnum RequestAction = DTC::SUBSCRIBE;
		uint32_t SymbolID = 0;
		vls_t Symbol;
		vls_t Exchange;
		uint32_t SendQuantitiesGreaterOrEqualTo = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		DTC::RequestActionEnum GetRequestAction() const;
		uint32_t GetSymbolID() const;
		uint32_t GetSendQuantitiesGreaterOrEqualTo() const;

		//Implementing Get Add inline functions------------------------------
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_MarketOrdersRequest, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
		//-------------------------------------------------------------------
		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_MarketOrdersRequest, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_MarketOrdersReject
	{
		//standard DTC VLS header
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::MARKET_ORDERS_REJECT;
		uint16_t BaseSize = sizeof(*this);

		//message field variables
		uint32_t SymbolID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		uint32_t GetSymbolID() const;

		//Implementing Get Add inline functions------------------------------
		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_MarketOrdersReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
		//--End of Get Add functions----------------------------------------
	};

	/*==========================================================================*/
	struct s_SubmitNewSingleOrder
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SUBMIT_NEW_SINGLE_ORDER;
		uint16_t BaseSize = sizeof(*this);

		vls_t Symbol;
		vls_t Exchange;

		vls_t TradeAccount;
		vls_t ClientOrderID;

		DTC::OrderTypeEnum OrderType = DTC::ORDER_TYPE_UNSET;

		DTC::BuySellEnum BuySell = DTC::BUY_SELL_UNSET;

		double Price1 = 0;
		double Price2 = 0;

		double Quantity = 0;

		DTC::TimeInForceEnum TimeInForce = DTC::TIF_UNSET;

		DTC::t_DateTime GoodTillDateTime = 0;
		
		uint8_t IsAutomatedOrder = 0;

		uint8_t IsParentOrder = 0;

		vls_t FreeFormText;

		DTC::OpenCloseTradeEnum OpenOrClose = DTC::TRADE_UNSET;
		double MaxShowQuantity = 0;

		vls_t Price1AsString;
		vls_t Price2AsString;

		double IntendedPositionQuantity = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SubmitNewSingleOrder, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SubmitNewSingleOrder, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_SubmitNewSingleOrder, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_SubmitNewSingleOrder, ClientOrderID));
		}

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		DTC::OrderTypeEnum GetOrderType() const;
		DTC::BuySellEnum GetBuySell() const;
		double GetPrice1() const;
		double GetPrice2() const;
		double GetQuantity() const;
		DTC::TimeInForceEnum GetTimeInForce() const;
		DTC::t_DateTime GetGoodTillDateTime() const;
		void SetTradeAccount(const char* NewValue);
		uint8_t GetIsAutomatedOrder() const;
		uint8_t GetIsParentOrder() const;

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_SubmitNewSingleOrder, FreeFormText));
		}

		void AddFreeFormText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}
		
		DTC::OpenCloseTradeEnum GetOpenOrClose() const;
		double GetMaxShowQuantity() const;

		const char* GetPrice1AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price1AsString, offsetof(s_SubmitNewSingleOrder, Price1AsString));
		}

		void AddPrice1AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price1AsString, StringLength);
		}

		const char* GetPrice2AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price2AsString, offsetof(s_SubmitNewSingleOrder, Price2AsString));
		}

		void AddPrice2AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price2AsString, StringLength);
		}

		double GetIntendedPositionQuantity() const;
	};

	/*==========================================================================*/
	struct s_SubmitFlattenPositionOrder
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SUBMIT_FLATTEN_POSITION_ORDER;
		uint16_t BaseSize = sizeof(*this);

		vls_t Symbol;
		vls_t Exchange;

		vls_t TradeAccount;
		vls_t ClientOrderID;
		vls_t FreeFormText;
		uint8_t IsAutomatedOrder = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		const char* GetSymbol()
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SubmitFlattenPositionOrder, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange()
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SubmitFlattenPositionOrder, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetTradeAccount()
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_SubmitFlattenPositionOrder, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetClientOrderID()
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_SubmitFlattenPositionOrder, ClientOrderID));
		}

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		const char* GetFreeFormText()
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_SubmitFlattenPositionOrder, FreeFormText));
		}

		void AddFreeFormText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		uint8_t GetIsAutomatedOrder() const;
	};

	/*==========================================================================*/
	struct s_CancelReplaceOrder
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::CANCEL_REPLACE_ORDER;
		uint16_t BaseSize = sizeof(*this);

		vls_t ServerOrderID;
		vls_t ClientOrderID;

		double Price1 = 0;
		double Price2 = 0;

		double Quantity = 0;

		int8_t Price1IsSet = 1;
		int8_t Price2IsSet = 1;

		int32_t Unused = 0;
		DTC::TimeInForceEnum TimeInForce = DTC::TIF_UNSET;
		DTC::t_DateTime GoodTillDateTime = 0;
		uint8_t UpdatePrice1OffsetToParent = 0;
		vls_t TradeAccount;

		vls_t Price1AsString;
		vls_t Price2AsString;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_CancelReplaceOrder, ServerOrderID));
		}

		void AddServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_CancelReplaceOrder, ClientOrderID));
		}

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_CancelReplaceOrder, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetPrice1AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price1AsString, offsetof(s_CancelReplaceOrder, Price1AsString));
		}

		void AddPrice1AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price1AsString, StringLength);
		}

		const char* GetPrice2AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price2AsString, offsetof(s_CancelReplaceOrder, Price2AsString));
		}

		void AddPrice2AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price2AsString, StringLength);
		}

		double GetPrice1() const;
		double GetPrice2() const;
		double GetQuantity() const;
		int8_t GetPrice1IsSet() const;
		int8_t GetPrice2IsSet() const;
		DTC::TimeInForceEnum GetTimeInForce() const;
		DTC::t_DateTime GetGoodTillDateTime() const;
		uint8_t GetUpdatePrice1OffsetToParent() const;		
	};

	/*==========================================================================*/
	struct s_CancelOrder
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::CANCEL_ORDER;
		uint16_t BaseSize = sizeof(*this);
		
		vls_t ServerOrderID;
		vls_t ClientOrderID;
		vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_CancelOrder, ServerOrderID));
		}

		void AddServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_CancelOrder, ClientOrderID));
		}

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_CancelOrder, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SubmitNewOCOOrder
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SUBMIT_NEW_OCO_ORDER;
		uint16_t BaseSize = sizeof(*this);

		vls_t Symbol;
		vls_t Exchange;

		vls_t ClientOrderID_1;
		DTC::OrderTypeEnum OrderType_1 = DTC::ORDER_TYPE_UNSET;
		DTC::BuySellEnum BuySell_1 = DTC::BUY_SELL_UNSET;
		double Price1_1 = 0;
		double Price2_1 = 0;
		double Quantity_1 = 0;

		vls_t ClientOrderID_2;
		DTC::OrderTypeEnum OrderType_2 = DTC::ORDER_TYPE_UNSET;
		DTC::BuySellEnum BuySell_2 = DTC::BUY_SELL_UNSET;
		double Price1_2 = 0;
		double Price2_2 = 0;
		double Quantity_2 = 0;

		DTC::TimeInForceEnum TimeInForce = DTC::TIF_UNSET;
		DTC::t_DateTime GoodTillDateTime = 0;

		vls_t TradeAccount;

		uint8_t IsAutomatedOrder = 0;

		vls_t ParentTriggerClientOrderID;

		vls_t FreeFormText;

		DTC::OpenCloseTradeEnum OpenOrClose = DTC::TRADE_UNSET;

		DTC::PartialFillHandlingEnum PartialFillHandling = DTC::PARTIAL_FILL_UNSET;

		uint8_t UseOffsets = 0;
		double OffsetFromParent1 = 0;
		double OffsetFromParent2 = 0;
		uint8_t MaintainSamePricesOnParentFill = 0;

		vls_t Price1_1AsString;
		vls_t Price2_1AsString;
		vls_t Price1_2AsString;
		vls_t Price2_2AsString;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		const char* GetClientOrderID_1() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID_1, offsetof(s_SubmitNewOCOOrder, ClientOrderID_1));
		}

		void AddClientOrderID_1(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID_1, StringLength);
		}

		const char* GetClientOrderID_2() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID_2, offsetof(s_SubmitNewOCOOrder, ClientOrderID_2));
		}

		void AddClientOrderID_2(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID_2, StringLength);
		}

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_SubmitNewOCOOrder, FreeFormText));
		}

		void AddFreeFormText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SubmitNewOCOOrder, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SubmitNewOCOOrder, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		void AddParentTriggerClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ParentTriggerClientOrderID, StringLength);
		}

		const char* GetParentTriggerClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ParentTriggerClientOrderID, offsetof(s_SubmitNewOCOOrder, ParentTriggerClientOrderID));
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_SubmitNewOCOOrder, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetPrice1_1AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price1_1AsString, offsetof(s_SubmitNewOCOOrder, Price1_1AsString));
		}

		void AddPrice1_1AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price1_1AsString, StringLength);
		}

		const char* GetPrice2_1AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price2_1AsString, offsetof(s_SubmitNewOCOOrder, Price2_1AsString));
		}

		void AddPrice2_1AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price2_1AsString, StringLength);
		}

		const char* GetPrice1_2AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price1_2AsString, offsetof(s_SubmitNewOCOOrder, Price1_2AsString));
		}

		void AddPrice1_2AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price1_2AsString, StringLength);
		}

		const char* GetPrice2_2AsString() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Price2_2AsString, offsetof(s_SubmitNewOCOOrder, Price2_2AsString));
		}

		void AddPrice2_2AsString(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Price2_2AsString, StringLength);
		}

		DTC::OrderTypeEnum GetOrderType_1() const;
		DTC::OrderTypeEnum GetOrderType_2() const;
		DTC::BuySellEnum GetBuySell_1() const;
		DTC::BuySellEnum GetBuySell_2() const;
		DTC::TimeInForceEnum GetTimeInForce() const;
		DTC::t_DateTime GetGoodTillDateTime() const;
		uint8_t GetIsAutomatedOrder() const;
		double GetPrice1_1() const;
		double GetPrice2_1() const;
		double GetPrice1_2() const;
		double GetPrice2_2() const;
		double GetQuantity_1() const;
		double GetQuantity_2() const;
		DTC::OpenCloseTradeEnum GetOpenOrClose() const;
		DTC::PartialFillHandlingEnum GetPartialFillHandling() const;
		uint8_t GetUseOffsets() const;
		double GetOffsetFromParent1() const;
		double GetOffsetFromParent2() const;
		uint8_t GetMaintainSamePricesOnParentFill() const;
	};

	/*==========================================================================*/
	struct s_OpenOrdersRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::OPEN_ORDERS_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		int32_t RequestAllOrders = 1;

		vls_t ServerOrderID;
		vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		int32_t GetRequestAllOrders() const;

		void AddServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_OpenOrdersRequest, ServerOrderID));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_OpenOrdersRequest, TradeAccount));
		}
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillsRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_ORDER_FILLS_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		vls_t ServerOrderID;

		int32_t NumberOfDays = 0;

		vls_t TradeAccount;

		DTC::t_DateTime StartDateTime = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		int32_t GetNumberOfDays() const;
		DTC::t_DateTime GetStartDateTime() const;

		void AddServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_HistoricalOrderFillsRequest, ServerOrderID));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalOrderFillsRequest, TradeAccount));
		}
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillsReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_ORDER_FILLS_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_HistoricalOrderFillsReject, RejectText));
		}
	};

	/*==========================================================================*/
	struct s_CurrentPositionsRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::CURRENT_POSITIONS_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t  TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_CurrentPositionsRequest, TradeAccount));
		}
	};

	/*==========================================================================*/
	struct s_CurrentPositionsReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::CURRENT_POSITIONS_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_CurrentPositionsReject, RejectText));
		}
	};

	/*==========================================================================*/
	struct s_OrderUpdate
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ORDER_UPDATE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		int32_t TotalNumMessages = 0;
		int32_t MessageNumber = 0;

		vls_t Symbol;
		vls_t Exchange;

		vls_t PreviousServerOrderID;

		vls_t ServerOrderID;

		vls_t ClientOrderID;

		vls_t ExchangeOrderID;

		DTC::OrderStatusEnum OrderStatus = DTC::ORDER_STATUS_UNSPECIFIED;

		DTC::OrderUpdateReasonEnum OrderUpdateReason = DTC::ORDER_UPDATE_REASON_UNSET;

		DTC::OrderTypeEnum OrderType = DTC::ORDER_TYPE_UNSET;

		DTC::BuySellEnum BuySell = DTC::BUY_SELL_UNSET;

		double Price1 = DBL_MAX;
		double Price2 = DBL_MAX;

		DTC::TimeInForceEnum TimeInForce = DTC::TIF_UNSET;
		DTC::t_DateTime GoodTillDateTime = 0;
		double OrderQuantity = DBL_MAX;
		double FilledQuantity = DBL_MAX;
		double RemainingQuantity = DBL_MAX;
		double AverageFillPrice = DBL_MAX;

		double LastFillPrice = DBL_MAX;
		DTC::t_DateTimeWithMillisecondsInt LastFillDateTime = 0;
		double LastFillQuantity = DBL_MAX;
		vls_t LastFillExecutionID;

		vls_t TradeAccount;
		vls_t InfoText;

		uint8_t NoOrders = 0;
		vls_t ParentServerOrderID;
		vls_t OCOLinkedOrderServerOrderID;

		DTC::OpenCloseTradeEnum OpenOrClose = DTC::TRADE_UNSET;

		vls_t PreviousClientOrderID;
		vls_t FreeFormText;

		DTC::t_DateTimeWithMillisecondsInt OrderReceivedDateTime = 0;
		DTC::t_DateTimeWithMilliseconds LatestTransactionDateTime = 0;

		vls_t Username;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_OrderUpdate, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_OrderUpdate, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetPreviousServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, PreviousServerOrderID, offsetof(s_OrderUpdate, PreviousServerOrderID));
		}

		void AddPreviousServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, PreviousServerOrderID, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_OrderUpdate, ServerOrderID));
		}

		void AddServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_OrderUpdate, ClientOrderID));
		}

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		const char* GetExchangeOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ExchangeOrderID, offsetof(s_OrderUpdate, ExchangeOrderID));
		}

		void AddExchangeOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ExchangeOrderID, StringLength);
		}

		void AddLastFillExecutionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, LastFillExecutionID, StringLength);
		}

		const char* GetLastFillExecutionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, LastFillExecutionID, offsetof(s_OrderUpdate, LastFillExecutionID));
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_OrderUpdate, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetInfoText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, InfoText, offsetof(s_OrderUpdate, InfoText));
		}

		void AddInfoText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, InfoText, StringLength);
		}

		const char* GetParentServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ParentServerOrderID, offsetof(s_OrderUpdate, ParentServerOrderID));
		}

		void AddParentServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ParentServerOrderID, StringLength);
		}

		const char* GetOCOLinkedOrderServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, OCOLinkedOrderServerOrderID, offsetof(s_OrderUpdate, OCOLinkedOrderServerOrderID));
		}

		void AddOCOLinkedOrderServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, OCOLinkedOrderServerOrderID, StringLength);
		}

		const char* GetPreviousClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, PreviousClientOrderID, offsetof(s_OrderUpdate, PreviousClientOrderID));
		}

		void AddPreviousClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, PreviousClientOrderID, StringLength);
		}

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_OrderUpdate, FreeFormText));
		}

		void AddFreeFormText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_OrderUpdate, Username));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}

		double GetOrderQuantity() const;
		double GetFilledQuantity() const;
		double GetRemainingQuantity() const;
		double GetLastFillQuantity() const;
		int32_t GetRequestID() const;
		int32_t GetMessageNumber() const;
		int32_t GetTotalNumMessages() const;
		DTC::OrderStatusEnum GetOrderStatus() const;
		DTC::OrderUpdateReasonEnum GetOrderUpdateReason() const;
		DTC::OrderTypeEnum GetOrderType() const;
		DTC::BuySellEnum GetBuySell() const;
		double GetPrice1() const;
		double GetPrice2() const;
		DTC::TimeInForceEnum GetTimeInForce() const;
		DTC::t_DateTime GetGoodTillDateTime() const;
		double GetAverageFillPrice() const;
		double GetLastFillPrice() const;
		DTC::t_DateTime GetLastFillDateTime() const;
		uint8_t GetNoOrders() const;
		DTC::OpenCloseTradeEnum GetOpenOrClose() const;
		DTC::t_DateTime GetOrderReceivedDateTime() const;
		DTC::t_DateTimeWithMilliseconds GetLatestTransactionDateTime() const;
	};
	
	/*==========================================================================*/
	struct s_OpenOrdersReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::OPEN_ORDERS_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;
				
		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_OpenOrdersReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_HistoricalOrderFillResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_ORDER_FILL_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0; 

		int32_t TotalNumberMessages = 0;

		int32_t MessageNumber = 0;

		vls_t Symbol;
		vls_t Exchange;
		vls_t ServerOrderID;
		DTC::BuySellEnum BuySell = DTC::BUY_SELL_UNSET;
		double Price = 0;
		DTC::t_DateTime DateTime = 0;
		double Quantity = 0;
		vls_t UniqueExecutionID;
		vls_t TradeAccount;

		DTC::OpenCloseTradeEnum OpenClose = DTC::TRADE_UNSET; 

		uint8_t NoOrderFills = 0;

		vls_t InfoText;

		double HighPriceDuringPosition = 0;
		double LowPriceDuringPosition = 0;
		double PositionQuantity = DBL_MAX;

		vls_t Username;
		vls_t ExchangeOrderID;
		vls_t SenderSubID;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_HistoricalOrderFillResponse, Symbol));
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_HistoricalOrderFillResponse, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetServerOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ServerOrderID, offsetof(s_HistoricalOrderFillResponse, ServerOrderID));
		}

		void AddServerOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ServerOrderID, StringLength);
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalOrderFillResponse, TradeAccount));
		}

		void AddUniqueExecutionID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UniqueExecutionID, StringLength);
		}

		const char* GetUniqueExecutionID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UniqueExecutionID, offsetof(s_HistoricalOrderFillResponse, UniqueExecutionID));
		}

		void AddInfoText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, InfoText, StringLength);
		}

		const char* GetInfoText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, InfoText, offsetof(s_HistoricalOrderFillResponse, InfoText));
		}

		void AddUsername(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Username, StringLength);
		}

		const char* GetUsername() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Username, offsetof(s_HistoricalOrderFillResponse, Username));
		}

		void AddExchangeOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ExchangeOrderID, StringLength);
		}

		const char* GetExchangeOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ExchangeOrderID, offsetof(s_HistoricalOrderFillResponse, ExchangeOrderID));
		}

		void AddSenderSubID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SenderSubID, StringLength);
		}

		const char* GetSenderSubID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SenderSubID, offsetof(s_HistoricalOrderFillResponse, SenderSubID));
		}

		int32_t GetRequestID() const;
		int32_t GetMessageNumber() const;
		int32_t GetTotalNumberMessages() const;
		DTC::BuySellEnum GetBuySell() const;
		double GetPrice() const;
		DTC::t_DateTime GetDateTime() const;
		double GetQuantity() const;
		DTC::OpenCloseTradeEnum GetOpenClose() const;
		uint8_t GetNoOrderFills() const;
		double GetHighPriceDuringPosition() const;
		double GetLowPriceDuringPosition() const;
		double GetPositionQuantity() const;
	};

	/*==========================================================================*/
	struct s_PositionUpdate
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::POSITION_UPDATE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		int32_t TotalNumberMessages = 0;

		int32_t MessageNumber = 0;

		vls_t Symbol;
		vls_t Exchange;

		double Quantity = 0;
		double AveragePrice = 0;

		vls_t PositionIdentifier;

		vls_t TradeAccount;
		uint8_t NoPositions = 0;
		uint8_t Unsolicited = 0;

		double MarginRequirement = 0;
		DTC::t_DateTime4Byte EntryDateTime = 0;
		double OpenProfitLoss = 0;
		double HighPriceDuringPosition = 0;
		double LowPriceDuringPosition = 0;
		double QuantityLimit = 0;
		double MaxPotentialPostionQuantity = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_PositionUpdate, Symbol));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_PositionUpdate, Exchange));
		}

		void AddPositionIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, PositionIdentifier, StringLength);
		}

		const char* GetPositionIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, PositionIdentifier, offsetof(s_PositionUpdate, PositionIdentifier));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_PositionUpdate, TradeAccount));
		}

		int32_t GetRequestID() const;
		int32_t GetTotalNumberMessages() const;
		int32_t GetMessageNumber() const;
		double GetQuantity() const;
		double GetAveragePrice() const;
		uint8_t GetNoPositions() const;
		uint8_t GetUnsolicited() const;

		double GetMarginRequirement() const;
		DTC::t_DateTime4Byte GetEntryDateTime() const;

		double GetOpenProfitLoss() const;
		double GetHighPriceDuringPosition() const;
		double GetLowPriceDuringPosition() const;
		double GetQuantityLimit() const;
		double GetMaxPotentialPostionQuantity() const;
	};

	/*==========================================================================*/
	struct s_AddCorrectingOrderFill
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ADD_CORRECTING_ORDER_FILL;
		uint16_t BaseSize = sizeof(*this);

		vls_t Symbol;
		vls_t Exchange;
		vls_t TradeAccount;
		vls_t ClientOrderID;
		DTC::BuySellEnum BuySell = DTC::BUY_SELL_UNSET;
		double FillPrice = 0;
		double FillQuantity = 0;
		vls_t FreeFormText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_AddCorrectingOrderFill, Symbol));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_AddCorrectingOrderFill, Exchange));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AddCorrectingOrderFill, TradeAccount));
		}

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_AddCorrectingOrderFill, ClientOrderID));
		}

		void AddFreeFormText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, FreeFormText, StringLength);
		}

		const char* GetFreeFormText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, FreeFormText, offsetof(s_AddCorrectingOrderFill, FreeFormText));
		}

		DTC::BuySellEnum GetBuySell() const;
		double GetFillPrice() const;
		double GetFillQuantity() const;

	};

	/*==========================================================================*/
	struct s_CorrectingOrderFillResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::CORRECTING_ORDER_FILL_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		vls_t ClientOrderID;
		vls_t ResultText;
		uint8_t IsError = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		void AddClientOrderID(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ClientOrderID, StringLength);
		}

		const char* GetClientOrderID() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ClientOrderID, offsetof(s_CorrectingOrderFillResponse, ClientOrderID));
		}

		void AddResultText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ResultText, StringLength);
		}

		const char* GetResultText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ResultText, offsetof(s_CorrectingOrderFillResponse, ResultText));
		}

		uint8_t GetIsError() const;

	};


	/*==========================================================================*/
	struct s_TradeAccountResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::TRADE_ACCOUNT_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		int32_t TotalNumberMessages = 0;

		int32_t MessageNumber = 0;

		vls_t TradeAccount;

		int32_t RequestID = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetTotalNumberMessages() const;
		int32_t GetMessageNumber() const;

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_TradeAccountResponse, TradeAccount));
		}

		int32_t GetRequestID() const;
	};

	/*==========================================================================*/
	struct s_ExchangeListResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::EXCHANGE_LIST_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t Exchange;
		uint8_t IsFinalMessage = 0;
		vls_t Description;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		uint8_t GetIsFinalMessage() const;

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_ExchangeListResponse, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_ExchangeListResponse, Description));
		}

		void AddDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Description, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SymbolsForExchangeRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SYMBOLS_FOR_EXCHANGE_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType = DTC::SECURITY_TYPE_UNSET;
		DTC::RequestActionEnum RequestAction = DTC::SUBSCRIBE;

		vls_t Symbol;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		DTC::SecurityTypeEnum GetSecurityType() const;
		DTC::RequestActionEnum GetRequestAction() const;

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SymbolsForExchangeRequest, Exchange));
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SymbolsForExchangeRequest, Symbol));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_UnderlyingSymbolsForExchangeRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::UNDERLYING_SYMBOLS_FOR_EXCHANGE_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType = DTC::SECURITY_TYPE_UNSET;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		DTC::SecurityTypeEnum GetSecurityType() const;

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_UnderlyingSymbolsForExchangeRequest, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SymbolsForUnderlyingRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SYMBOLS_FOR_UNDERLYING_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		vls_t UnderlyingSymbol;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType = DTC::SECURITY_TYPE_UNSET;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		DTC::SecurityTypeEnum GetSecurityType() const;

		const char* GetUnderlyingSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UnderlyingSymbol, offsetof(s_SymbolsForUnderlyingRequest, UnderlyingSymbol));
		}

		void AddUnderlyingSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UnderlyingSymbol, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SymbolsForUnderlyingRequest, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SymbolSearchRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SYMBOL_SEARCH_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t SearchText;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType = DTC::SECURITY_TYPE_UNSET;
		DTC::SearchTypeEnum SearchType = DTC::SEARCH_TYPE_UNSET;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		DTC::SecurityTypeEnum GetSecurityType() const;
		DTC::SearchTypeEnum GetSearchType() const;

		const char* GetSearchText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, SearchText, offsetof(s_SymbolSearchRequest, SearchText));
		}

		void AddSearchText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, SearchText, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SymbolSearchRequest, Exchange));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionForSymbolRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SECURITY_DEFINITION_FOR_SYMBOL_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		vls_t Symbol;
		vls_t Exchange;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const 
		{ 
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SecurityDefinitionForSymbolRequest, Symbol)); 
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SecurityDefinitionForSymbolRequest, Exchange));
		}
	};

	/*==========================================================================*/
	struct s_SecurityDefinitionResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SECURITY_DEFINITION_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		vls_t Symbol;
		vls_t Exchange;

		DTC::SecurityTypeEnum SecurityType = DTC::SECURITY_TYPE_UNSET;
		
		vls_t Description;
		float MinPriceIncrement = 0;
		DTC::PriceDisplayFormatEnum PriceDisplayFormat = DTC::PRICE_DISPLAY_FORMAT_UNSET;
		float CurrencyValuePerIncrement = 0;

		uint8_t IsFinalMessage = 0;

		float FloatToIntPriceMultiplier = 1.0;
		float IntToFloatPriceDivisor = 1.0;
		vls_t UnderlyingSymbol;

		uint8_t UpdatesBidAskOnly = 0;
		float StrikePrice = 0;

		DTC::PutCallEnum PutOrCall = DTC::PC_UNSET;

		uint32_t ShortInterest = 0;

		DTC::t_DateTime4Byte SecurityExpirationDate = 0;

		float BuyRolloverInterest = 0;
		float SellRolloverInterest = 0;

		float EarningsPerShare = 0;
		uint32_t SharesOutstanding = 0;

		float IntToFloatQuantityDivisor = 0;

		uint8_t HasMarketDepthData = 1;

		float DisplayPriceMultiplier = 1.0;

		vls_t ExchangeSymbol;

		float InitialMarginRequirement = 0;
		float MaintenanceMarginRequirement = 0;

		vls_t Currency;
		float ContractSize = 0;
		uint32_t OpenInterest = 0;
		DTC::t_DateTime4Byte RolloverDate = 0;
		uint8_t IsDelayed = 0;
		int64_t SecurityIdentifier = 0;
		vls_t ProductIdentifier;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_SecurityDefinitionResponse, Symbol));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_SecurityDefinitionResponse, Exchange));
		}

		void AddDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Description, StringLength);
		}

		const char* GetDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_SecurityDefinitionResponse, Description));
		}

		int32_t GetRequestID() const;
		DTC::SecurityTypeEnum GetSecurityType() const;
		float GetMinPriceIncrement() const;
		DTC::PriceDisplayFormatEnum GetPriceDisplayFormat() const;
		float GetCurrencyValuePerIncrement() const;
		uint8_t GetIsFinalMessage() const;
		float GetFloatToIntPriceMultiplier() const;
		float GetIntToFloatPriceDivisor() const;

		void AddUnderlyingSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UnderlyingSymbol, StringLength);
		}

		const char* GetUnderlyingSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UnderlyingSymbol, offsetof(s_SecurityDefinitionResponse, UnderlyingSymbol));
		}

		uint8_t GetUpdatesBidAskOnly() const;
		float GetStrikePrice() const;
		DTC::PutCallEnum GetPutOrCall() const;
		uint32_t GetShortInterest() const;
		DTC::t_DateTime4Byte GetSecurityExpirationDate() const;
		float GetBuyRolloverInterest() const;
		float GetSellRolloverInterest() const;
		float GetEarningsPerShare() const;
		uint32_t GetSharesOutstanding() const;
		float GetIntToFloatQuantityDivisor() const;
		uint8_t GetHasMarketDepthData() const;
		float GetDisplayPriceMultiplier() const;

		void AddExchangeSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ExchangeSymbol, StringLength);
		}

		const char* GetExchangeSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ExchangeSymbol, offsetof(s_SecurityDefinitionResponse, ExchangeSymbol));
		}

		float GetInitialMarginRequirement() const;
		float GetMaintenanceMarginRequirement() const;

		void AddCurrency(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Currency, StringLength);
		}

		const char* GetCurrency() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Currency, offsetof(s_SecurityDefinitionResponse, Currency));
		}

		float GetContractSize() const;
		uint32_t GetOpenInterest() const;
		DTC::t_DateTime4Byte GetRolloverDate() const;
		uint8_t GetIsDelayed() const;
		int64_t GetSecurityIdentifier() const;

		void AddProductIdentifier(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, ProductIdentifier, StringLength);
		}

		const char* GetProductIdentifier() const
		{
			return GetVariableLengthStringField(Size, BaseSize, ProductIdentifier, offsetof(s_SecurityDefinitionResponse, ProductIdentifier));
		}
	};


	/*==========================================================================*/
	struct s_SecurityDefinitionReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::SECURITY_DEFINITION_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_SecurityDefinitionReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_AccountBalanceRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ACCOUNT_BALANCE_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AccountBalanceRequest, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_AccountBalanceReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ACCOUNT_BALANCE_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_AccountBalanceReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_AccountBalanceUpdate
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ACCOUNT_BALANCE_UPDATE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		double CashBalance = 0;

		double BalanceAvailableForNewPositions = 0;

		vls_t AccountCurrency;

		vls_t TradeAccount;
		double SecuritiesValue = 0;  // Not including cash
		double MarginRequirement = 0;

		int32_t TotalNumberMessages = 0;
		int32_t MessageNumber = 0;
		uint8_t NoAccountBalances = 0;
		uint8_t Unsolicited = 0;

		double OpenPositionsProfitLoss = 0;
		double DailyProfitLoss = 0;

		vls_t InfoText;

		uint64_t TransactionIdentifier = 0;
		double DailyNetLossLimit = 0;
		double TrailingAccountValueToLimitPositions = 0;

		uint8_t DailyNetLossLimitReached = 0;
		uint8_t IsUnderRequiredMargin = 0;

		uint8_t ClosePositionsAtEndOfDay = 0;
		uint8_t TradingIsDisabled = 0;
		vls_t Description;
		uint8_t IsUnderRequiredAccountValue = 0;

		DTC::t_DateTimeWithMicrosecondsInt TransactionDateTime = 0;

		double MarginRequirementFull = 0;
		double MarginRequirementFullPositionsOnly = 0;
		double PeakMarginRequirement = 0;
		double EndOfDayAccountValue = 0;
		vls_t IntroducingBroker;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddAccountCurrency(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AccountCurrency, StringLength);
		}

		const char* GetAccountCurrency() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AccountCurrency, offsetof(s_AccountBalanceUpdate, AccountCurrency));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AccountBalanceUpdate, TradeAccount));
		}

		double GetCashBalance() const;
		double GetBalanceAvailableForNewPositions() const;
		double GetSecuritiesValue() const;
		double GetMarginRequirement() const;

		int32_t GetTotalNumberMessages() const;
		int32_t GetMessageNumber() const;
		uint8_t GetNoAccountBalances() const;
		uint8_t GetUnsolicited() const;

		double GetOpenPositionsProfitLoss() const;
		double GetDailyProfitLoss() const;

		void AddInfoText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, InfoText, StringLength);
		}

		const char* GetInfoText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, InfoText, offsetof(s_AccountBalanceUpdate, InfoText));
		}

		uint64_t GetTransactionIdentifier() const;
		double GetDailyNetLossLimit() const;
		double GetTrailingAccountValueToLimitPositions() const;

		uint8_t GetDailyNetLossLimitReached() const;
		uint8_t GetIsUnderRequiredMargin() const;

		uint8_t GetClosePositionsAtEndOfDay() const;
		uint8_t GetTradingIsDisabled() const;

		void AddDescription(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Description, StringLength);
		}

		const char* GetDescription() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Description, offsetof(s_AccountBalanceUpdate, Description));
		}

		uint8_t GetIsUnderRequiredAccountValue() const;
		DTC::t_DateTimeWithMicrosecondsInt GetTransactionDateTime() const;

		double GetMarginRequirementFull() const;
		double GetMarginRequirementFullPositionsOnly() const;
		double GetPeakMarginRequirement() const;
		double GetEndOfDayAccountValue() const;

		void AddIntroducingBroker(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, IntroducingBroker, StringLength);
		}

		const char* GetIntroducingBroker() const
		{
			return GetVariableLengthStringField(Size, BaseSize, IntroducingBroker, offsetof(s_AccountBalanceUpdate, IntroducingBroker));
		}
	};


	/*==========================================================================*/
	struct s_AccountBalanceAdjustment
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ACCOUNT_BALANCE_ADJUSTMENT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t TradeAccount;
		double CreditAmount = 0;
		double DebitAmount = 0;
		vls_t Currency;

		vls_t Reason;

		uint8_t RecalculateDailyLossLimit = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AccountBalanceAdjustment, TradeAccount));
		}

		double GetCreditAmount() const;
		double GetDebitAmount() const;

		void AddCurrency(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Currency, StringLength);
		}

		const char* GetCurrency() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Currency, offsetof(s_AccountBalanceAdjustment, Currency));
		}

		void AddReason(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Reason, StringLength);
		}

		const char* GetReason() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Reason, offsetof(s_AccountBalanceAdjustment, Reason));
		}

		uint8_t GetRecalculateDailyLossLimit() const;

	};

	/*==========================================================================*/
	struct s_AccountBalanceAdjustmentReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ACCOUNT_BALANCE_ADJUSTMENT_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;

		vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_AccountBalanceAdjustmentReject, RejectText));
		}

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AccountBalanceAdjustmentReject, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_AccountBalanceAdjustmentComplete
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ACCOUNT_BALANCE_ADJUSTMENT_COMPLETE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		int64_t TransactionID = 0;

		vls_t TradeAccount;

		double NewBalance = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;

		int32_t GetRequestID() const;
		int64_t GetTransactionID() const;

		double GetNewBalance() const;


		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AccountBalanceAdjustmentComplete, TradeAccount));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}
	};

	/*==========================================================================*/
	struct s_HistoricalAccountBalancesRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_ACCOUNT_BALANCES_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t TradeAccount;

		DTC::t_DateTime StartDateTime = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalAccountBalancesRequest, TradeAccount));
		}

		DTC::t_DateTime GetStartDateTime() const;
	};

	/*==========================================================================*/
	struct s_HistoricalAccountBalancesReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_ACCOUNT_BALANCES_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		uint32_t GetRequestID() const;

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_HistoricalAccountBalancesReject, RejectText));
		}
	};

	/*==========================================================================*/
	struct s_HistoricalAccountBalanceResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_ACCOUNT_BALANCE_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		DTC::t_DateTimeWithMilliseconds DateTime = 0;
		double CashBalance = 0;
		vls_t AccountCurrency;
		vls_t TradeAccount;
		uint8_t IsFinalResponse = 0;
		uint8_t NoAccountBalances = 0;
		vls_t InfoText;
		vls_t TransactionId;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		DTC::t_DateTimeWithMilliseconds GetDateTime() const;
		double GetCashBalance() const;

		void AddAccountCurrency(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, AccountCurrency, StringLength);
		}

		const char* GetAccountCurrency() const
		{
			return GetVariableLengthStringField(Size, BaseSize, AccountCurrency, offsetof(s_HistoricalAccountBalanceResponse, AccountCurrency));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_HistoricalAccountBalanceResponse, TradeAccount));
		}

		uint8_t GetIsFinalResponse() const;
		uint8_t GetNoAccountBalances() const;

		void AddInfoText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, InfoText, StringLength);
		}

		const char* GetInfoText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, InfoText, offsetof(s_HistoricalAccountBalanceResponse, InfoText));
		}

		void AddTransactionId(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TransactionId, StringLength);
		}

		const char* GetTransactionId() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TransactionId, offsetof(s_HistoricalAccountBalanceResponse, TransactionId));
		}
	};

	/*==========================================================================*/
	struct s_UserMessage
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::USER_MESSAGE;
		uint16_t BaseSize = sizeof(*this);

		vls_t UserMessage;

		uint8_t IsPopupMessage = 1;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		uint8_t GetIsPopupMessage() const;

		void AddUserMessage(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, UserMessage, StringLength);
		}

		const char* GetUserMessage() const
		{
			return GetVariableLengthStringField(Size, BaseSize, UserMessage, offsetof(s_UserMessage, UserMessage));
		}
	};

	/*==========================================================================*/
	struct s_GeneralLogMessage
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::GENERAL_LOG_MESSAGE;
		uint16_t BaseSize = sizeof(*this);

		vls_t MessageText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		void AddMessageText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, MessageText, StringLength);
		}

		const char* GetMessageText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, MessageText, offsetof(s_GeneralLogMessage, MessageText));
		}
	};

	/*==========================================================================*/
	struct s_AlertMessage
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::ALERT_MESSAGE;
		uint16_t BaseSize = sizeof(*this);

		vls_t MessageText;
		vls_t TradeAccount;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		void AddMessageText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, MessageText, StringLength);
		}

		const char* GetMessageText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, MessageText, offsetof(s_AlertMessage, MessageText));
		}

		void AddTradeAccount(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, TradeAccount, StringLength);
		}

		const char* GetTradeAccount() const
		{
			return GetVariableLengthStringField(Size, BaseSize, TradeAccount, offsetof(s_AlertMessage, TradeAccount));
		}
	};

	/*==========================================================================*/
	struct s_JournalEntryAdd
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::JOURNAL_ENTRY_ADD;
		uint16_t BaseSize = sizeof(*this);

		vls_t JournalEntry;
		DTC::t_DateTime DateTime = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		void AddJournalEntry(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, JournalEntry, StringLength);
		}

		const char* GetJournalEntry() const
		{
			return GetVariableLengthStringField(Size, BaseSize, JournalEntry, offsetof(s_JournalEntryAdd, JournalEntry));
		}

		DTC::t_DateTime GetDateTime() const;
	};

	/*==========================================================================*/
	struct s_JournalEntriesReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::JOURNAL_ENTRIES_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t RejectText;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_JournalEntriesReject, RejectText));
		}
	};

	/*==========================================================================*/
	struct s_JournalEntryResponse
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::JOURNAL_ENTRY_RESPONSE;
		uint16_t BaseSize = sizeof(*this);

		vls_t JournalEntry;
		DTC::t_DateTime DateTime = 0;
		uint8_t IsFinalResponse = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		void AddJournalEntry(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, JournalEntry, StringLength);
		}

		const char* GetJournalEntry() const
		{
			return GetVariableLengthStringField(Size, BaseSize, JournalEntry, offsetof(s_JournalEntryResponse, JournalEntry));
		}

		DTC::t_DateTime GetDateTime() const;
		uint8_t GetIsFinalResponse() const;
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_PRICE_DATA_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t Symbol;
		vls_t Exchange;
		DTC::HistoricalDataIntervalEnum RecordInterval = DTC::INTERVAL_TICK;
		DTC::t_DateTime StartDateTime = 0;
		DTC::t_DateTime EndDateTime = 0;
		uint32_t MaxDaysToReturn = 0;
		uint8_t UseZLibCompression = 0;
		uint8_t RequestDividendAdjustedStockData = 0;
		uint16_t Integer_1 = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_HistoricalPriceDataRequest, Symbol));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_HistoricalPriceDataRequest, Exchange));
		}

		DTC::HistoricalDataIntervalEnum GetRecordInterval() const;
		DTC::t_DateTime GetStartDateTime() const;
		DTC::t_DateTime GetEndDateTime() const;
		uint32_t GetMaxDaysToReturn() const;
		uint8_t GetUseZLibCompression() const;
		uint8_t GetRequestDividendAdjustedStockData() const;
		uint16_t GetInteger_1() const;
	};

	/*==========================================================================*/
	struct s_HistoricalPriceDataReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_PRICE_DATA_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		vls_t RejectText;

		DTC::HistoricalPriceDataRejectReasonCodeEnum RejectReasonCode = DTC::HPDR_UNSET;
		uint16_t RetryTimeInSeconds = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		DTC::HistoricalPriceDataRejectReasonCodeEnum GetRejectReasonCode() const;
		uint16_t GetRetryTimeInSeconds() const;

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_HistoricalPriceDataReject, RejectText));
		}
	};

	/*==========================================================================*/
	struct s_HistoricalMarketDepthDataRequest
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_MARKET_DEPTH_DATA_REQUEST;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;
		vls_t Symbol;
		vls_t Exchange;
		DTC::t_DateTimeWithMicrosecondsInt StartDateTime = 0;
		DTC::t_DateTimeWithMicrosecondsInt EndDateTime = 0;
		uint8_t  UseZLibCompression = 0;
		uint8_t Integer_1 = 0;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;
		
		void AddSymbol(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Symbol, StringLength);
		}

		const char* GetSymbol() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Symbol, offsetof(s_HistoricalMarketDepthDataRequest, Symbol));
		}

		void AddExchange(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, Exchange, StringLength);
		}

		const char* GetExchange() const
		{
			return GetVariableLengthStringField(Size, BaseSize, Exchange, offsetof(s_HistoricalMarketDepthDataRequest, Exchange));
		}

		DTC::t_DateTimeWithMicrosecondsInt GetStartDateTime() const;
		DTC::t_DateTimeWithMicrosecondsInt GetEndDateTime() const;
		uint8_t GetUseZLibCompression() const;
		uint8_t GetInteger_1() const;
	};

	/*==========================================================================*/
	struct s_HistoricalMarketDepthDataReject
	{
		uint16_t Size = sizeof(*this);
		uint16_t Type = DTC::HISTORICAL_MARKET_DEPTH_DATA_REJECT;
		uint16_t BaseSize = sizeof(*this);

		int32_t RequestID = 0;

		vls_t RejectText;

		DTC::HistoricalPriceDataRejectReasonCodeEnum RejectReasonCode = DTC::HPDR_UNSET;

		uint16_t GetMessageSize() const;
		uint16_t GetBaseSize() const;
		
		int32_t GetRequestID() const;

		void AddRejectText(uint16_t StringLength)
		{
			AddVariableLengthStringField(Size, RejectText, StringLength);
		}

		const char* GetRejectText() const
		{
			return GetVariableLengthStringField(Size, BaseSize, RejectText, offsetof(s_HistoricalMarketDepthDataReject, RejectText));
		}

		DTC::HistoricalPriceDataRejectReasonCodeEnum GetRejectReasonCode() const;
	};

#pragma pack()
}
