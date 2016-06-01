// Copyright (c) 2010
// All rights reserved.

#include <cstdlib>
#include "Util.hh"
#include "soil/DateTime.hh"
#include "CathLog.hh"

namespace cath {

air::SpeedMData* Util::toSpeedMData(const json::Document& doc) {
  std::unique_ptr<air::SpeedMData> speed_data(new air::SpeedMData());

  if (doc.HasMember("OnRtnDepthMarketData")) {
    const json::Value& rtn_depth_data = doc["OnRtnDepthMarketData"];

    if (rtn_depth_data.HasMember("CThostFtdcDepthMarketDataField")) {
      const json::Value& data = rtn_depth_data["CThostFtdcDepthMarketDataField"];  // NOLINT(*)

      speed_data->instru = data["InstrumentID"].GetString();
      speed_data->update_time = data["UpdateTime"].GetString();
      speed_data->update_millisec = atoi(data["UpdateMillisec"].GetString());
      speed_data->time_stamp = soil::DateTime(rtn_depth_data["timestamp"].GetString());  // NOLINT(*)
    }
  }

  return speed_data.release();
}

air::ShfeMData* Util::toShfeMData(const json::Document& doc) {
  std::unique_ptr<air::ShfeMData> shfe_data(new air::ShfeMData());

  if (doc.HasMember("OnRtnDepthMarketData")) {
    const json::Value& rtn_depth_data = doc["OnRtnDepthMarketData"];

    if (rtn_depth_data.HasMember("CThostFtdcDepthMarketDataField")) {
      const json::Value& data = rtn_depth_data["CThostFtdcDepthMarketDataField"];  // NOLINT(*)
      shfe_data->TradingDay = data["TradingDay"].GetString();
      shfe_data->InstrumentID = data["InstrumentID"].GetString();
      shfe_data->ExchangeID = data["ExchangeID"].GetString();
      shfe_data->ExchangeInstID = data["ExchangeInstID"].GetString();
      shfe_data->LastPrice = atof(data["LastPrice"].GetString());
      shfe_data->PreSettlementPrice = atof(data["PreSettlementPrice"].GetString()); // NOLINT(*)
      shfe_data->PreClosePrice = atof(data["PreClosePrice"].GetString());
      shfe_data->PreOpenInterest = atof(data["PreOpenInterest"].GetString());
      shfe_data->OpenPrice = atof(data["OpenPrice"].GetString());
      shfe_data->HighestPrice = atof(data["HighestPrice"].GetString());
      shfe_data->LowestPrice = atof(data["LowestPrice"].GetString());
      shfe_data->Volume = atoi(data["Volume"].GetString());
      shfe_data->Turnover = atof(data["Turnover"].GetString());
      shfe_data->OpenInterest = atof(data["OpenInterest"].GetString());
      shfe_data->ClosePrice = atof(data["ClosePrice"].GetString());
      shfe_data->SettlementPrice = atof(data["SettlementPrice"].GetString());
      shfe_data->UpperLimitPrice = atof(data["UpperLimitPrice"].GetString());
      shfe_data->LowerLimitPrice = atof(data["LowerLimitPrice"].GetString());
      shfe_data->PreDelta = atof(data["PreDelta"].GetString());
      shfe_data->CurrDelta = atof(data["CurrDelta"].GetString());
      shfe_data->UpdateTime = data["UpdateTime"].GetString();
      shfe_data->UpdateMillisec = atoi(data["UpdateMillisec"].GetString());

      shfe_data->BidPrice1 = atof(data["BidPrice1"].GetString());
      shfe_data->BidVolume1 = atoi(data["BidVolume1"].GetString());
      shfe_data->AskPrice1 = atof(data["AskPrice1"].GetString());
      shfe_data->AskVolume1 = atoi(data["AskVolume1"].GetString());

      shfe_data->BidPrice2 = atof(data["BidPrice2"].GetString());
      shfe_data->BidVolume2 = atoi(data["BidVolume2"].GetString());
      shfe_data->AskPrice2 = atof(data["AskPrice2"].GetString());
      shfe_data->AskVolume2 = atoi(data["AskVolume2"].GetString());

      shfe_data->BidPrice3 = atof(data["BidPrice3"].GetString());
      shfe_data->BidVolume3 = atoi(data["BidVolume3"].GetString());
      shfe_data->AskPrice3 = atof(data["AskPrice3"].GetString());
      shfe_data->AskVolume3 = atoi(data["AskVolume3"].GetString());

      shfe_data->BidPrice4 = atof(data["BidPrice4"].GetString());
      shfe_data->BidVolume4 = atoi(data["BidVolume4"].GetString());
      shfe_data->AskPrice4 = atof(data["AskPrice4"].GetString());
      shfe_data->AskVolume4 = atoi(data["AskVolume4"].GetString());

      shfe_data->BidPrice5 = atof(data["BidPrice5"].GetString());
      shfe_data->BidVolume5 = atoi(data["BidVolume5"].GetString());
      shfe_data->AskPrice5 = atof(data["AskPrice5"].GetString());
      shfe_data->AskVolume5 = atoi(data["AskVolume5"].GetString());

      shfe_data->AveragePrice = atof(data["AveragePrice"].GetString());
      shfe_data->ActionDay = data["ActionDay"].GetString();
    }
  }


  return shfe_data.release();
}

};  // namespace cath
