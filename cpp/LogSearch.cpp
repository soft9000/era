#include "era.hpp"

namespace era01 {

FindDate::FindDate(const TimeStruct& day) {
  found = new (vector<LogEntry*>);
  zStruct.assign(day);
}

int FindDate::size() {
  if (found != nullptr)
    return found->size();
  return 0;
}

FindDate::~FindDate() {
  if (found != nullptr) {
    for (auto it = (*found).begin(); it != (*found).end(); it++) {
      delete (*it);  // just do it!
    }
  }
  delete found;
  found = nullptr;  // better core debug info
}

bool FindDate::onFind(const LogEntry& ref) {
  TimeInfo info = ref.time();
  if (zStruct.sameDate(info.getLocal())) {
    found->push_back(new LogEntry(ref));
  }
  return true;
}
}
