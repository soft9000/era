#ifndef EraFile_hpp1
#define EraFile_hpp1

#include "era.hpp"

namespace era01 {

enum FileType { AT_TEXT, AT_BINARY, AT_NONE };

class File {
 private:
  string sFQName;
  FileType type = FileType::AT_NONE;
  fstream* pIOStream = nullptr;

 public:
  File();
  File(string fname);
  File(const File& file);
  virtual ~File();

  virtual void assign(const File& file);

  virtual string home(string node);

  bool exists();
  const char* name();
  FileType mode();

  istream& openRead(FileType at = FileType::AT_TEXT);
  ostream& openWrite(FileType at = FileType::AT_TEXT);
  ostream& openAppend(FileType at = FileType::AT_TEXT);
  iostream& openReadWrite(FileType at = FileType::AT_TEXT);
  void close();
  bool remove();
};
}

#endif
