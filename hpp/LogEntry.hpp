#ifndef LogEntry_hpp1
#define LogEntry_hpp1

#include "era.hpp"

namespace era01 {

class LogEntry {
 private:
  TimeInfo zTime;
  string zMsg;

 public:
  LogEntry();
  LogEntry(const char* msg);
  LogEntry(const LogEntry& obj);
  LogEntry(const TimeInfo& entry, const string& msg);
  LogEntry(const TimeStruct& entry, const string& msg);
  virtual ~LogEntry() {}

  bool parse(string);
  bool sameDate(const LogEntry& ref) const;

  virtual TimeInfo time() const;
  virtual string entry() const;
  virtual string message() const;
};
}

#endif
