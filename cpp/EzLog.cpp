#include <iostream>
#include "era.hpp"
#include "EzLog.hpp"
#include <exception>
#include <sstream>

namespace era01 {
using namespace std;

bool EzLog::append(string message) {
  TimeInfo info;
  LogEntry entry(info, message);
  return append(entry);
}

bool EzLog::append(const LogEntry& ref) {
  ostream* pos;
  if (file.exists())
    pos = &(file.openAppend());
  else
    pos = &(file.openWrite());
  auto message = ref.entry();
  (*pos) << message << endl;
  file.close();
  return file.exists();
}

vector<LogEntry*> EzLog::list() {
  vector<LogEntry*> results;
  if (file.exists()) {
    istream& is = file.openRead();
    string str;
    while (getline(is, str)) {
      LogEntry* entry = new LogEntry();
      if (entry->parse(str) == false)
        throw "Log Format Error";
      else
        results.push_back(entry);
    }
  }
  return results;
}

vector<LogEntry*> EzLog::filter(TimeStruct info, int plus_minus_days) {}

void EzLog::empty(vector<LogEntry*> data) {
  for (auto it = data.begin(); it != data.end(); it++) {
    delete (*it);
  }
  data.empty();
}

}  // namespace
