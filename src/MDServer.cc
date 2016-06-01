// Copyright (c) 2010
// All rights reserved.

#include "MDServer.hh"
#include "CathLog.hh"
#include "Util.hh"
#include "json/json.hh"

namespace cath {

MDServer::MDServer(soil::Options* options,
                   const std::string& instru,
                   const std::string& md_file,
                   const std::string& speed_file) {
  CATH_TRACE <<"MDServer::MDServer()";

  if (!md_file.empty())
    md_file_.reset(new air::MDataFile(md_file));

  if (!speed_file.empty())
    speed_file_.reset(new air::MDataFile(speed_file));

  md_service_.reset(cata::MDService::createService(options, this));

  cata::InstrumentSet instrus;
  instrus.insert(instru);
  md_service_->subMarketData(instrus);
}

MDServer::~MDServer() {
  CATH_TRACE <<"MDServer::~MDServer()";
}

void MDServer::onRspMessage(const std::string& msg) {
  CATH_TRACE <<"MDServer::onRspMessage()";

  CATH_INFO <<msg;
}

void MDServer::onRtnMessage(const std::string& msg) {
  CATH_TRACE <<"MDServer::onRtnMessage()";

  CATH_INFO <<msg;
  json::Document doc;
  json::fromString(msg, &doc);

  if (speed_file_.get()) {
    speed_file_->putData(Util::toSpeedMData(doc));
  }

  if (md_file_.get()) {
    md_file_->putData(Util::toShfeMData(doc));
  }
}

};  // namespace cath
