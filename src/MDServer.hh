#ifndef CATH_MDSERVER_HH
#define CATH_MDSERVER_HH

#include "cata/MDService.hh"
#include "air/MDataFile.hh"

namespace cath
{

class Util;

class MDServer : public cata::MDServiceCallback
{
 public:
  MDServer(soil::Options* options,
           const std::string& instru,
           const std::string& md_file,
           const std::string& speed_file);

  virtual ~MDServer();
  
  virtual void onRspSubMarketData(const std::string& instru, bool success);

  virtual void onRspSubQuoteData(const std::string& instru, bool success) {}
  
  virtual void onRspUnsubMarketData(const std::string& instru, bool success);

  virtual void onRspUnsubQuoteData(const std::string& instru, bool success) {}
  
  virtual void onRtnMarketData(const cata::DepthMarketData* data);

  virtual void onRtnQuoteData() {}
  
  virtual void onRspError(int errord_id, const std::string& error_msg);

 private:

  std::unique_ptr<cata::MDService> md_service_;

  std::unique_ptr<air::MDataFile> md_file_;
  std::unique_ptr<air::MDataFile> speed_file_;

  std::unique_ptr<Util> util_;
};

};

#endif
