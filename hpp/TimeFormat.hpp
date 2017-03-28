#ifndef TimeFormat_hpp1
#define TimeFormat_hpp1

#include "era.hpp"

namespace era01 {

enum FormatType { ftGlobal, ftLocal };

class TimeFormat {
 public:
  static TimeStruct Parse(string str);

  static string Format(const TimeStruct& time, FormatType ft);
  static string Format(const TimeGlobal& time);
  static string Format(const TimeLocal& time);
};
}

#endif
