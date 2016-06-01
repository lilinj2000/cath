// Copyright (c) 2010
// All rights reserved.

#include <memory>
#include "CathConfig.hh"
#include "MDServer.hh"
#include "soil/Pause.hh"

int main(int argc, char* argv[]) {
  std::unique_ptr<cath::CathConfig> config;
  config.reset(new cath::CathConfig(argc, argv));

  cath::CathOptions* cath_options = config->cathOptions();

  std::unique_ptr<cath::MDServer> server;
  server.reset(new cath::MDServer(config->cataMDOptions(),
                                   cath_options->instrument_id,
                                   cath_options->md_file,
                                   cath_options->speed_md_file));

  std::unique_ptr<soil::Pause> pause(soil::Pause::create());

  return 0;
}
