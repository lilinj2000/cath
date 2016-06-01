// Copyright (c) 2010
// All rights reserved.

#ifndef CATH_MDSERVER_HH
#define CATH_MDSERVER_HH

#include <string>
#include "cata/MDService.hh"
#include "air/MDataFile.hh"

namespace cath {

class MDServer : public cata::ServiceCallback {
 public:
  MDServer(soil::Options* options,
           const std::string& instru,
           const std::string& md_file,
           const std::string& speed_file);

  virtual ~MDServer();

  virtual void onRspMessage(const std::string& msg);

  virtual void onRtnMessage(const std::string& msg);

 private:
  std::unique_ptr<cata::MDService> md_service_;

  std::unique_ptr<air::MDataFile> md_file_;
  std::unique_ptr<air::MDataFile> speed_file_;
};

};  // namespace cath

#endif
