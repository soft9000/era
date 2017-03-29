
#include "era.hpp"
#include <sstream>
#include <string>

namespace era01 {

LogEntry::LogEntry() {}

LogEntry::LogEntry(const char* msg) {
  this->zMsg.assign(msg);
}

LogEntry::LogEntry(const LogEntry& obj) {
  this->zTime.assign(obj.time());
  this->zMsg.assign(obj.zMsg);
}

LogEntry::LogEntry(const TimeInfo& entry, const string& msg) {
  zTime.assign(entry);
  zMsg.assign(msg);
}

LogEntry::LogEntry(const TimeStruct& entry, const string& msg) {
  zTime.assign(TimeStruct(entry).toTimeInfo());
  zMsg.assign(msg);
}

bool LogEntry::sameDate(const LogEntry& obj) const {
  return (this->zTime.epoch() == obj.zTime.epoch());
}

bool LogEntry::parse(string entry) {
  size_t pos = entry.find("\t");
  if (pos == -1)
    return false;
  TimeStruct zStruct = TimeFormat::Parse(entry.substr(0, pos - 1));
  zTime.assign(zStruct.toTimeInfo());
  zMsg = entry.substr(pos + 1);
  return true;
}

string LogEntry::entry() const {
  stringstream srm;
  srm << TimeFormat::Format(this->zTime.getLocal());
  srm << "\t" << zMsg;
  return srm.str();
}

string LogEntry::message() const {
  return string(zMsg);
}

TimeInfo LogEntry::time() const {
  return this->zTime;
}
}
