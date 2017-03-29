#include "era.hpp"

namespace era01 {

const char* FORMAT_STRING = "%04d/%02d/%02d: %02d.%02d.%02d (%s)";

const char* ZONE_LOCAL = "LOCAL";
const char* ZONE_GLOBAL = "GLOBAL";

string TimeFormat::Format(const TimeStruct& time, FormatType ft) {
  char* zone = (char*)"?";
  switch (ft) {
    case FormatType::ftLocal:
      zone = (char*)ZONE_LOCAL;
      break;

    default:
    case FormatType::ftGlobal:
      zone = (char*)ZONE_GLOBAL;
      break;
  }
  char buf[50];
  sprintf(&buf[0], FORMAT_STRING, time.year(), time.month(), time.day(),
          time.hour(), time.minute(), time.second(), zone);

  return string(buf);
}

TimeStruct TimeFormat::Parse(string str) {
  TimeStruct result;
  int year = 0;
  int month = 0;
  int day = 0;
  int hour = 0;
  int minute = 0;
  int second = 0;
  char zone[50];
  int count = sscanf(str.c_str(), FORMAT_STRING, &year, &month, &day, &hour,
                     &minute, &second, &zone);
  TimeStruct* pzone = nullptr;

  TimeInfo hack;
  if (::strcmp(&zone[0], ZONE_LOCAL) == 0) {
    auto pzone = hack.getLocal();
    result.assign(pzone);
  } else {
    auto pzone = hack.getGlobal();
    result.assign(pzone);
  }
  result.year(year);
  result.month(month);
  result.day(day);
  result.hour(hour);
  result.minute(minute);
  result.second(second);
  return result;
}

string TimeFormat::Format(const TimeGlobal& time) {
  return Format(time, FormatType::ftGlobal);
}

string TimeFormat::Format(const TimeLocal& time) {
  return Format(time, FormatType::ftLocal);
}

}  // namespace
