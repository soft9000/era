#ifndef LogSearch_hpp1
#define LogSearch_hpp1

#include "era.hpp"
#include <vector>

namespace era01 {

class LogSearch {
 public:
  virtual ~LogSearch() {}

  // Return `true` to continue, `false` to stop.
  virtual bool onFind(const LogEntry& ref) { return true; }
};

class FindDate : public LogSearch {
 protected:
  vector<LogEntry*>* found = nullptr;

  TimeStruct zStruct;

 public:
  FindDate(const TimeStruct& day);
  virtual ~FindDate();
  virtual int size();
  virtual bool onFind(const LogEntry& ref);
};

class FindDates : public FindDate {
 protected:
  TimeStruct zStructEnd;

 public:
  FindDates(const TimeStruct& dayStart, const TimeStruct& dayEnd);
  virtual ~FindDates() {}

  virtual bool onFind(const LogEntry& ref);
};
}
#endif
