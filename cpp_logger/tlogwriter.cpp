#include "era.hpp"
#include <sstream>
#include <cassert>

using namespace era01;
using namespace std;


bool Log(LogWriter& log, const string& msg) {
  cout << msg << endl;
  return log.append(msg);
}


int main(int argc, char** argv) {

// Relative pathing - must be okay!
LogWriter log(File("./LogWriter.log"));

// STEP: Test log removal
log.remove();
assert(log.exists() == false);

// STEP: Test log operations
assert(Log(log, "Just did it"));
assert(log.exists());
assert(log.count() == 1);
assert(log.remove());
assert(log.exists() == false);

// STEP: Extended logging operations
stringstream srm;
for(int ss = 1; ss < 10; ss++) {
   Log(log, "Extended Logging");
   assert(log.count() == ss);
}

// STEP: Leave it for diagnostics / proof
assert(log.exists() == true);

Log(log, "Testing Success!");
}
