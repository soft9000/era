
#include "era.hpp"
#include <sstream>

namespace era01 {

LogEntry::LogEntry(const char* msg) {
  stringstream srm;
  srm << TimeFormat::Format(this->zTime.getLocal());
  srm << "\t" << msg;
  zMsg.assign(srm.str());
}

LogEntry::LogEntry(const LogEntry& obj) {
  this->zMsg = string(obj.zMsg);
}

string LogEntry::entry() {
  return zMsg;
}

string LogEntry::message() {
  size_t pos = zMsg.find("\t");
  if (pos == -1)
    return string();
  return string(zMsg.substr(pos + 1));
}

TimeInfo LogEntry::time() {
  return this->zTime;
}
}
