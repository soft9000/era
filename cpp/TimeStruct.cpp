#include "era.hpp"

namespace era01 {

using namespace std;

void prep(const struct tm& info) {
  ((struct tm&)info).tm_isdst = -1;
}

TimeStruct::TimeStruct() {
  ::memset(&zData, 0, sizeof(struct tm));
  prep(zData);
}

TimeStruct::TimeStruct(const TimeStruct& info) {
  prep(info.zData);
  assign(info);
}

TimeInfo TimeStruct::toTimeInfo() {
  prep(zData);
  TimeInfo result(::mktime(&zData));
  return result;
}

void TimeStruct::assign(const TimeStruct& info) {
  prep(info.zData);
  ::memcpy(&zData, &(info.zData), sizeof(struct tm));
}

bool TimeStruct::sameDate(const TimeStruct& info) const {
  if (day() == info.day()) {
    if (month() == info.month()) {
      if (year() == info.year()) {
        return true;
      }
    }
  }
  return false;
}

bool TimeStruct::isDST(void) const {
  return ((zData.tm_isdst == 1) ? true : false);
}

int TimeStruct::weekDay(void) const {
  return zData.tm_wday + 1;
}

int TimeStruct::julianDay(void) const {
  return zData.tm_yday + 1;
}

int TimeStruct::month(void) const {
  return (zData.tm_mon + 1);
}
void TimeStruct::month(int month) {
  zData.tm_mon = month - 1;
}

int TimeStruct::day(void) const {
  return zData.tm_mday;
}
void TimeStruct::day(int day) {
  zData.tm_mday = day;
}

int TimeStruct::year(void) const {
  return (zData.tm_year + 1900);
}

void TimeStruct::year(int year) {
  zData.tm_year = year - 1900;
}

int TimeStruct::hour(void) const {
  return zData.tm_hour;
}

void TimeStruct::hour(int hour24) {
  zData.tm_hour = hour24;
}

int TimeStruct::minute(void) const {
  return zData.tm_min;
}
void TimeStruct::minute(int minute) {
  zData.tm_min = minute;
}
int TimeStruct::second(void) const {
  return zData.tm_sec;
}

void TimeStruct::second(int sec) {
  zData.tm_sec = sec;
}
}
