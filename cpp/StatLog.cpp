#include "era.hpp"
#include <sstream>

namespace era01 {
using namespace std;

StatLog::StatLog(const File& file) : EzLog(file) {}

bool StatLog::append(Stat stat, string message) {
  stringstream srm;
  switch (stat) {
    default:
    case INFO:
      srm << "[INFO]";
      break;
    case WARNING:
      srm << "[WARNING]";
      break;
    case DEBUG:
      srm << "[DEBUG]";
      break;
    case ERROR:
      srm << "[ERROR]";
      break;
  }
  srm << "," << message;  // << ends;
  return EzLog::append(srm.str());
}

}  // namespace
