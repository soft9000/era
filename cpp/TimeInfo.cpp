#include "era.hpp"

namespace era01 {

using namespace std;

TimeInfo::TimeInfo() {
  this->zTime = ::time(NULL);
}

TimeLocal TimeInfo::getLocal() {
  TimeLocal result;
  ::memcpy(&(result.zData), localtime(&zTime), sizeof(struct tm));
  return result;
}

TimeGlobal TimeInfo::getGlobal() {
  TimeGlobal result;
  ::memcpy(&(result.zData), gmtime(&zTime), sizeof(struct tm));
  return result;
}
}
