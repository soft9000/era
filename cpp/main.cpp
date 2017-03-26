#include <iostream>
#include "era.hpp"

using namespace era01;
using namespace std;

int main(int argc, char** argv) {
  TimeInfo info;
  auto local = info.getLocal();
  cout << TimeFormat::Format(local) << endl;
  auto global = info.getGlobal();
  cout << TimeFormat::Format(global) << endl;

  LogEntry entry("This is a test.");
  cout << entry.entry() << endl;
  cout << entry.message() << endl;
  {
    File file;
    puts(file.name());
    ostream& os = file.openWrite();
    os << entry.entry() << endl;
  }
  File file("drongo.log");
  puts(file.name());
  ostream& os = file.openWrite();
  os << entry.entry() << endl;

  if (file.exists() == false) {
    cerr << "Error: File not found!" << endl;
  }
  file.remove();
  if (file.exists() == true) {
    cerr << "Error: File found!" << endl;
  }
}
