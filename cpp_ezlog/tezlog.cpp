#include <iostream>
#include "era.hpp"
#include <cassert>

using namespace era01;
using namespace std;

void Log(StatLog log, Stat flag, string msg) {
  cout << msg << endl;
  log.append(flag, msg);
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

  bool recovered = false;
  vector<LogEntry*> data = log.list();
  for (auto it = data.begin(); it != data.end(); it++) {
    LogEntry* ent = (*it);
    string str = ent->message();
    if (str.find(TEST_PTRN01) != string::npos) {
      if (ent1.sameDate(*ent)) {
        recovered = true;
        cout << "RECOVERED: " << str << endl;
      }
    }
  }
  assert(recovered);

  Log(log, Stat::INFO, "STEP: 120 - Entry Filtering Test.");

  log.empty(data);

  return 0;
}
