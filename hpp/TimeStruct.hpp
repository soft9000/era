#ifndef time_struct_hpp1
#define time_struct_hpp1
#include "era.hpp"

namespace era01 {

using namespace std;

class TimeStruct {
 protected:
  struct tm zData;

 public:
  TimeStruct();
  bool isDST(void) const;   // Daylight Savings Time
  int weekDay(void) const;  // Sunday as first day of week
  int julianDay(void);      // January 1st as first day of year
  int month(void) const;    // month number - [1 - 12]
  int day(void) const;      // day of the month - [1 - 31]
  int year(void) const;     // years since 1900
  int hour(void) const;     // hours since midnight - [0 - 23]
  int minute(void) const;   // minutes after hour - [0 - 59]
  int second(void) const;   // seconds after minute - [0 - 59]
};

class TimeLocal : public TimeStruct {
 public:
  friend class TimeInfo;
};

class TimeGlobal : public TimeStruct {
 public:
  friend class TimeInfo;
};
}
#endif
