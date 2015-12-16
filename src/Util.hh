#ifndef CATH_UTIL_HH
#define CATH_UTIL_HH

#include "air/MDataFile.hh"
#include "cata/CataDef.hh"

namespace cath
{

class Util
{
 public:
  air::SpeedMData* toSpeedMData(const cata::DepthMarketData* data);

  air::ShfeMData* toShfeMData(const cata::DepthMarketData* data);
};

};

#endif
