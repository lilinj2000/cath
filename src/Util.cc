#include "Util.hh"

namespace cath
{

air::SpeedMData* Util::toSpeedMData(const cata::DepthMarketData* data)
{
  std::unique_ptr<air::SpeedMData> speed_data(new air::SpeedMData());
  
  speed_data->instru = data->InstrumentID;
  speed_data->update_time = data->UpdateTime;
  speed_data->update_millisec = data->UpdateMillisec;
  speed_data->time_stamp = data->time_stamp;

  return speed_data.release();
}


air::ShfeMData* Util::toShfeMData(const cata::DepthMarketData* data)
{
  std::unique_ptr<air::ShfeMData> shfe_data(new air::ShfeMData());

  shfe_data->TradingDay = data->TradingDay;
  shfe_data->InstrumentID = data->InstrumentID;
  shfe_data->ExchangeID = data->ExchangeID;
  shfe_data->ExchangeInstID = data->ExchangeInstID;
  shfe_data->LastPrice = data->LastPrice;
  shfe_data->PreSettlementPrice = data->PreSettlementPrice;
  shfe_data->PreClosePrice = data->PreClosePrice;
  shfe_data->PreOpenInterest = data->PreOpenInterest;
  shfe_data->OpenPrice = data->OpenPrice;
  shfe_data->HighestPrice = data->HighestPrice;
  shfe_data->LowestPrice = data->LowestPrice;
  shfe_data->Volume = data->LastPrice;
  shfe_data->Turnover = data->Turnover;
  shfe_data->OpenInterest = data->OpenInterest;  
  shfe_data->ClosePrice = data->ClosePrice;
  shfe_data->SettlementPrice = data->SettlementPrice;  
  shfe_data->UpperLimitPrice = data->UpperLimitPrice;
  shfe_data->LowerLimitPrice = data->LowerLimitPrice;
  shfe_data->PreDelta = data->PreDelta;
  shfe_data->CurrDelta = data->CurrDelta;
  shfe_data->UpdateTime = data->UpdateTime;
  shfe_data->UpdateMillisec = data->UpdateMillisec;

  shfe_data->BidPrice1 = data->BidPrice1;
  shfe_data->BidVolume1 = data->BidVolume1;
  shfe_data->AskPrice1 = data->AskPrice1;
  shfe_data->AskVolume1 = data->AskVolume1;
  
  shfe_data->BidPrice2 = data->BidPrice2;
  shfe_data->BidVolume2 = data->BidVolume2;
  shfe_data->AskPrice2 = data->AskPrice2;
  shfe_data->AskVolume2 = data->AskVolume2;

  shfe_data->BidPrice3 = data->BidPrice3;
  shfe_data->BidVolume3 = data->BidVolume3;
  shfe_data->AskPrice3 = data->AskPrice3;
  shfe_data->AskVolume3 = data->AskVolume3;

  shfe_data->BidPrice4 = data->BidPrice4;
  shfe_data->BidVolume4 = data->BidVolume4;
  shfe_data->AskPrice4 = data->AskPrice4;
  shfe_data->AskVolume4 = data->AskVolume4;

  shfe_data->BidPrice5 = data->BidPrice5;
  shfe_data->BidVolume5 = data->BidVolume5;
  shfe_data->AskPrice5 = data->AskPrice5;
  shfe_data->AskVolume5 = data->AskVolume5;

  shfe_data->AveragePrice = data->AveragePrice;
  shfe_data->ActionDay = data->ActionDay;

  return shfe_data.release();

}

};
