#include <iostream>
#include "era.hpp"
#include <cassert>

using namespace era01;
using namespace std;

void Log(StatLog& log, Stat flag, const string& msg) {
  cout << msg << endl;
  log.append(flag, msg);
}

bool ScanFor(StatLog& log, const LogEntry& ent1, const char* msg) {
  bool br = false;
  vector<LogEntry*> data = log.list();
  for (auto it = data.begin(); it != data.end(); it++) {
    LogEntry* ent = (*it);
    string str = ent->message();
    if (str.find(msg) != string::npos) {
      if (ent1.sameDate(*ent)) {
        br = true;
        break;
      }
    }
  }
  log.empty(data);
  return br;
}

int countEntries(StatLog& log, TimeStruct& row) {
  FindDate target(row);
  log.filter(target);
  return target.size();
}

int main(int argc, char** argv) {
  StatLog log(File("MainTest.log"));

  Log(log, Stat::INFO, "STEP: 100 - Basic Log Testing.");

  if (log.exists() == false) {
    Log(log, Stat::ERROR, "Error: File not found! (100)");
    return 100;
  }

  log.remove();
  if (log.exists() == true) {
    Log(log, Stat::ERROR, "Error: Deleted file found! (100)");
    return 100;
  }
  Log(log, Stat::INFO, "SUCCESS: File deletion okay!");

  Log(log, Stat::INFO, "STEP: 105 - File Deletion Recovery Test.");
  if (log.exists() == false) {
    Log(log, Stat::ERROR, "Error: File not found! (105)");
    return 105;
  }

  Log(log, Stat::INFO, "STEP: 110 - Entry Recovery Test.");
  const char* TEST_PTRN01 = "TEST_PTRN01";
  LogEntry ent1(TEST_PTRN01);
  if (log.append(ent1) == false) {
    Log(log, Stat::ERROR, "Error: File not found! (110)");
    return 110;
  }
  assert(ScanFor(log, ent1, TEST_PTRN01));

  Log(log, Stat::INFO, "STEP: 120 - Deep Entry Recovery Test.");
  TimeInfo hack;
  TimeGlobal local = hack.getGlobal();
  local.year(1978);
  local.month(3);
  local.day(15);
  local.hour(16);
  local.minute(17);
  local.second(18);
  const char* TEST_PTRN02 = "ZTEST_PTRN02";
  LogEntry ent2(local, TEST_PTRN02);
  assert(log.append(ent2));
  assert(ScanFor(log, ent2, TEST_PTRN02));

  const char* TEST_130 = "TODO: 130 - Entry Filtering Test.";
  Log(log, Stat::INFO, TEST_130);
  vector<TimeLocal> nuck;
  for (int mm = 1; mm <= 12; mm++) {
    for (int ss = 1; ss <= mm; ss++) {
      auto local = hack.getLocal();
      local.year(1970 + mm);
      local.month(mm);
      local.day(mm);
      local.hour(mm);
      local.minute(mm + ss);
      local.second(mm + ss);
      if (ss == 1)
        nuck.push_back(local);
      log.append(LogEntry(local, TEST_130));
    }
  }

  int count = nuck.size();
  for (int ss = 0; ss < count; ss++) {
    TimeLocal row = nuck[ss];
    assert(countEntries(log, row) == ss + 1);
  }

  // log.empty(data);

  Log(log, Stat::INFO, "Testing Success!");
  return 0;
}
