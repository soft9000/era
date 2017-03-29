#include <iostream>
#include "era.hpp"
#include <cassert>

using namespace era01;
using namespace std;

void Log(StatLog log, Stat flag, string msg) {
  cout << msg << endl;
  log.append(flag, msg);
}

bool ScanFor(StatLog log, const LogEntry& ent1, const char *msg) {
  vector<LogEntry*> data = log.list();
  for (auto it = data.begin(); it != data.end(); it++) {
    LogEntry* ent = (*it);
    string str = ent->message();
    if (str.find(msg) != string::npos) {
      if (ent1.sameDate(*ent)) {
        return true;
      }
    }
  }
  log.empty(data);
  return false;
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

  Log(log, Stat::INFO, "STEP: 120 - Deep Recovery Test.");
  TimeInfo hack;
  TimeGlobal local = hack.getGlobal();
  local.year(1978);
  local.month(3);
  local.day(15);
  local.hour(16);
  local.minute(17);
  local.second(18);
  const char *TEST_PTRN02 = "ZTEST_PTRN02";
  LogEntry ent2(local, TEST_PTRN02);
  assert(log.append(ent2));
  assert(ScanFor(log, ent2, TEST_PTRN02));

 
  Log(log, Stat::INFO, "TODO: 130 - Entry Filtering Test.");

  // log.empty(data);

  Log(log, Stat::INFO, "Testing Success!");
  return 0;
}
