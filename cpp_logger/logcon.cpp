#include "era.hpp"

using namespace era01;
using namespace std;

void usage() {
  cout << "Usage: logger.run \"message\"" << endl;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    usage();
    return 0;
  }

  // When folks - like me - forget to use those quotes:
  stringstream ssrm;
  for(int ss = 1; ss < argc; ss++) {
    if(ss != 1)
      ssrm << " ";
    ssrm << argv[ss];
  }
  LogWriter writer(File("./logger.log"));
  if (writer.append(ssrm.str()) == false) {
    cerr << "Error: Unable to write \"" << argv[0] << "\"" << ends;
  } else {
    cout << "Success: There are " << writer.count() << " log entries." << endl;
  }
  return 0;
}
