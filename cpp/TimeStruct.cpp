#include "era.hpp"

namespace era01 {

using namespace std;

TimeStruct::TimeStruct() {
  ::memset(&zData, 0, sizeof(struct tm));
}

bool TimeStruct::isDST(void) const {
  return ((zData.tm_isdst == 1) ? true : false);
}

int TimeStruct::weekDay(void) const {
  return zData.tm_wday + 1;
}

int TimeStruct::julianDay(void) {
  return zData.tm_yday + 1;
}

int TimeStruct::month(void) const {
  return (zData.tm_mon + 1);
}

int TimeStruct::day(void) const {
  return zData.tm_mday;
}

int TimeStruct::year(void) const {
  return (zData.tm_year + 1900);
}

int TimeStruct::hour(void) const {
  return zData.tm_hour;
}

int TimeStruct::minute(void) const {
  return zData.tm_min;
}

int TimeStruct::second(void) const {
  return zData.tm_sec;
}
}
