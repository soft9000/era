#ifndef StatLog_hpp1
#define StatLog_hpp1

#include <iostream>
#include <vector>
#include "era.hpp"

namespace era01 {

enum Stat { DEBUG, WARNING, ERROR, INFO };

// Opportunities abound for Stat filtering, Stat counts, (etc.)

class StatLog : public EzLog {
 public:
  StatLog(const File& file);

  bool append(Stat stat, string message);
  bool append(const LogEntry& ref) { return EzLog::append(ref); }  // eh?
};
}

#endif
