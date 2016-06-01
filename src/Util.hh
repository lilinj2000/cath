// Copyright (c) 2010
// All rights reserved.

#ifndef CATH_UTIL_HH
#define CATH_UTIL_HH

#include "air/MDataFile.hh"
#include "json/json.hh"

namespace cath {

class Util {
 public:
  static air::SpeedMData* toSpeedMData(const json::Document& doc);

  static air::ShfeMData* toShfeMData(const json::Document& doc);
};

};  // namespace cath

#endif
