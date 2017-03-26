#include "era.hpp"

namespace era01 {

string TimeFormat::Format(const TimeStruct& time, FormatType ft) {
  char* zone = (char*)"?";
  switch (ft) {
    case FormatType::ftLocal:
      zone = (char*)"LOCAL";
      break;

    default:
    case FormatType::ftGlobal:
      zone = (char*)"GLOBAL";
      break;
  }
  char buf[50];
  sprintf(&buf[0], "%04d/%02d/%02d: %02d.%02d.%02d (%s)", time.year(),
          time.month(), time.day(), time.hour(), time.minute(), time.second(),
          zone);

  return string(buf);
}
string TimeFormat::Format(const TimeGlobal& time) {
  return Format(time, FormatType::ftGlobal);
}
string TimeFormat::Format(const TimeLocal& time) {
  return Format(time, FormatType::ftLocal);
}

}  // namespace
