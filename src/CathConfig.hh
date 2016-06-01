// Copyright (c) 2010
// All rights reserved.

#ifndef CATH_CONFIG_HH
#define CATH_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace cath {

namespace po = boost::program_options;

class CathOptions : public soil::Options {
 public:
  CathOptions();

  virtual ~CathOptions();

  virtual po::options_description* configOptions();

  std::string instrument_id;
  std::string md_file;
  std::string speed_md_file;
  std::string log_cfg;

 private:
  boost::program_options::options_description config_options_;
};

class CathConfig {
 public:
  explicit CathConfig(int argc = 0, char* argv[] = nullptr);
  ~CathConfig();

  CathOptions* cathOptions() {
    return cath_options_.get();
  }

  soil::Options* cataMDOptions() {
    return cata_md_options_.get();
  }

 private:
  std::unique_ptr<CathOptions> cath_options_;

  std::unique_ptr<soil::Options> cata_md_options_;
};

}  // namespace cath
#endif
