#include "era.hpp"
#include <unistd.h>  // getcwd
#include <sys/stat.h>

namespace era01 {

File::File() {
  sFQName.assign(home("default_era.log"));
}

File::File(string fname) {
  if (fname.find("\\") == -1) {
    if (fname.find("/") == -1) {
      fname = home(fname);
    }
  }
  sFQName.assign(fname);
}

File::File(const File& file) {
  this->sFQName.assign(file.sFQName);
  this->type = file.type;
}

File::~File() {
  close();
}

const char* File::name() {
  return this->sFQName.c_str();
}

FileType File::mode() {
  return this->type;
}

void File::assign(const File& file) {
  close();
  sFQName.assign(file.sFQName);
  type = file.type;
}

string File::home(string node) {
  string cwd = getcwd(nullptr, 0);
  stringstream srm;
  srm << cwd;
  if (cwd.find("\\") != -1) {
    srm << "\\";
  } else {
    srm << "/";
  }
  srm << node << ends;
  return srm.str();
}

istream& File::openRead(FileType at) {
  close();
  pIOStream = new fstream;

  if (at == AT_BINARY)
    pIOStream->open(sFQName.c_str(), ios::in | ios::binary);
  else
    pIOStream->open(sFQName.c_str(), ios::in);
  return *pIOStream;
}

ostream& File::openWrite(FileType at) {
  close();
  remove();  // For the benefit of Microsoft's legacy.
  pIOStream = new fstream;

  if (at == AT_BINARY)
    pIOStream->open(sFQName.c_str(), ios::out | ios::binary);
  else
    pIOStream->open(sFQName.c_str(), ios::out);
  return *pIOStream;
}

ostream& File::openAppend(FileType at) {
  close();
  delete pIOStream;
  pIOStream = nullptr;
  pIOStream = new fstream;

  if (at == AT_BINARY)
    pIOStream->open(sFQName.c_str(), ios::out | ios::app | ios::binary);
  else
    pIOStream->open(sFQName.c_str(), ios::out | ios::app);
  return *pIOStream;
}

iostream& File::openReadWrite(FileType at) {
  close();
  delete pIOStream;
  pIOStream = nullptr;
  pIOStream = new fstream;

  if (at == AT_BINARY)
    pIOStream->open(sFQName.c_str(), ios::in | ios::out | ios::binary);
  else
    pIOStream->open(sFQName.c_str(), ios::in | ios::out);
  return *pIOStream;
}

void File::close(void) {
  if (pIOStream != nullptr)
    pIOStream->close();
  pIOStream = nullptr;
}

bool File::remove(void) {
  close();
  if (sFQName.size() == 0)
    return true;
  if (::remove(sFQName.c_str()))
    return false;
  return true;
}

bool File::exists() {
  struct stat info;
  if (::stat(sFQName.c_str(), &info) != 0)
    return false;
  return true;
}

}  // namespace
