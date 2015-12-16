#include "MDServer.hh"
#include "CathLog.hh"
#include "Util.hh"

namespace cath
{

MDServer::MDServer(soil::Options* options,
                   const std::string& instru,
                   const std::string& md_file,
                   const std::string& speed_file)
{
  CATH_TRACE <<"MDServer::MDServer()";

  util_.reset( new Util() );
  
  if( !md_file.empty() )
    md_file_.reset( new air::MDataFile(md_file) );

  if( !speed_file.empty() )
    speed_file_.reset( new air::MDataFile(speed_file) );
  
  md_service_.reset( cata::MDService::createService(options, this) );

  cata::InstrumentSet instrus;
  instrus.insert( instru );
  md_service_->subMarketData( instrus );
}

MDServer::~MDServer()
{
  CATH_TRACE <<"MDServer::~MDServer()";
}

void MDServer::onRspSubMarketData(const std::string& instru, bool success)
{
  CATH_TRACE <<"MDServer::onRspSubMarketData()";
}

void MDServer::onRspUnsubMarketData(const std::string& instru, bool success)
{
  CATH_TRACE <<"MDServer::onRspUnsubMarketData()";
}

void MDServer::onRtnMarketData(const cata::DepthMarketData* data)
{
  CATH_TRACE <<"MDServer::onRtnMarketData()";

  if( speed_file_.get() )
  {
    speed_file_->putData( util_->toSpeedMData(data) );
  }

  if( md_file_.get() )
  {
    md_file_->putData( util_->toShfeMData(data) );
  }

}

void MDServer::onRspError(int errord_id, const std::string& error_msg)
{
  CATH_TRACE <<"MDServer::onRspError()";
}


};
