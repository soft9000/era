#include "era.hpp"

namespace era01 {

using namespace std;

TimeInfo::TimeInfo() {
  this->zTime = ::time(NULL);
}

time_t TimeInfo::epoch() const {
  return this->zTime;
}

TimeInfo::TimeInfo(time_t atime) {
  this->zTime = atime;
}

TimeInfo::TimeInfo(const TimeInfo& info) {
  assign(info);
}
void TimeInfo::assign(const TimeInfo& info) {
  zTime = info.zTime;
}

TimeLocal TimeInfo::getLocal() const {
  TimeLocal result;
  ::memcpy(&(result.zData), localtime(&zTime), sizeof(struct tm));
  return result;
}

TimeGlobal TimeInfo::getGlobal() const {
  TimeGlobal result;
  ::memcpy(&(result.zData), gmtime(&zTime), sizeof(struct tm));
  return result;
}
}
