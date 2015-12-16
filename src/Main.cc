#include <memory>
#include "CathConfig.hh"
#include "MDServer.hh"
#include "soil/STimer.hh"

int main(int argc, char* argv[])
{

  std::unique_ptr<cath::CathConfig> config;
  config.reset(new cath::CathConfig(argc, argv));

  cath::CathOptions* cath_options = config->cathOptions();

  std::unique_ptr<cath::MDServer> server;
  server.reset(new cath::MDServer(config->cataMDOptions(),
                                   cath_options->instrument_id,
                                   cath_options->md_file,
                                   cath_options->speed_md_file));
  
  std::unique_ptr<soil::STimer> cond;
  cond.reset( soil::STimer::create() );

  do
  {
    cond->wait(2000);
  }while(true);
  
  return 0;
}
