#ifndef EzLog_hpp1
#define EzLog_hpp1

#include <iostream>
#include <vector>
#include "era.hpp"

namespace era01 {

class EzLog : public LogWriter {
 public:
  EzLog(const File& file) : LogWriter(file){};

  bool append(string messsage);
  bool append(const LogEntry& messsage);
  vector<LogEntry*> list();
  long filter(LogSearch& search);
  void empty(vector<LogEntry*> data);
};
}

#endif
