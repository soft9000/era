#ifndef LogWriter_hpp1
#define LogWriter_hpp1

#include <era.hpp>

namespace era01 {

class LogWriter {
 protected:
  File file;

 public:
  LogWriter(const File& file);
  int count();
  bool exists();
  bool remove();
  bool append(string messsage);
};
}

#endif
