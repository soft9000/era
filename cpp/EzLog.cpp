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
      if (entry->parse(str) == false) {
        file.close();
        throw "Log Format Error";
      } else {
        results.push_back(entry);
      }
    }
    file.close();
  }
  return results;
}

long EzLog::filter(LogSearch& search) {
  long tally = 0L;
  if (file.exists()) {
    istream& is = file.openRead();
    string str;
    LogEntry* entry = new LogEntry();
    while (getline(is, str)) {
      if (entry->parse(str) == false) {
        file.close();
        throw "Log Format Error";
      } else {
        if (search.onFind(*entry) == false) {
          break;  // stop requested (protocol)
        }
        tally++;
      }
    }  // while
    delete entry;
    file.close();
  }
  return tally;
}

void EzLog::empty(vector<LogEntry*> data) {
  for (auto it = data.begin(); it != data.end(); it++) {
    delete (*it);
  }
  data.empty();
}

}  // namespace
