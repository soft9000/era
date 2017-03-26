#ifndef LogEntry_hpp1
#define LogEntry_hpp1

#include "era.hpp"

namespace era01 {

class LogEntry {
 private:
  TimeInfo zTime;
  string zMsg;

 public:
  LogEntry(const char* msg);
  LogEntry(const LogEntry& obj);
  virtual ~LogEntry() {}

  virtual TimeInfo time();
  virtual string entry();
  virtual string message();
};
}

#endif
