#include "CathConfig.hh"
#include "CathLog.hh"
#include "cata/MDService.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace cath
{

CathOptions::CathOptions():
    config_options_("CathConfigOptions")
{

  namespace po = boost::program_options;

  config_options_.add_options()
      ("cath.instrument_id", po::value<std::string>(&instrument_id), 
       "instrument id")
      ("cath.md_file", po::value<std::string>(&md_file), 
       " md file")
      ("cath.speed_md_file", po::value<std::string>(&speed_md_file), 
       "speed md file")

      ("cath.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")
      ;

  return;
  
}

CathOptions::~CathOptions()
{
}

po::options_description* CathOptions::configOptions()
{
  return &config_options_;
}

CathConfig::CathConfig(int argc, char* argv[])
{
  cath_options_.reset(new CathOptions());
  cata_md_options_.reset( cata::MDService::createOptions() );
      
  std::unique_ptr<soil::Config> config( soil::Config::create() );
  config->registerOptions( cath_options_.get() );
  config->registerOptions( cata_md_options_.get() );

  config->configFile() = "cath.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  CATH_LOG_INIT( cath_options_->log_cfg );
  
  return;
}

CathConfig::~CathConfig()
{
}

};  
