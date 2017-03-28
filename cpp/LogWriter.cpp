#include <iostream>
#include "era.hpp"
#include <exception>
#include <sstream>

namespace era01 {
using namespace std;

LogWriter::LogWriter(const File& file) {
  this->file.assign(file);
}

bool LogWriter::exists() {
  return file.exists();
}

bool LogWriter::remove() {
  return file.remove();
}

int LogWriter::count() {
  int tally = 0;
  istream& is = file.openRead();
  string str;
  while (getline(is, str)) {
    tally++;
  }
  file.close();
  return tally;
}

bool LogWriter::append(string message) {
  ostream* pos;
  if (file.exists())
    pos = &(file.openAppend());
  else
    pos = &(file.openWrite());
  TimeInfo info;
  TimeLocal zstruct = info.getLocal();
  string ztime = TimeFormat::Format(zstruct);
  (*pos) << ztime << "\t" << message << endl;
  file.close();
  return file.exists();
}

}  // namespace
