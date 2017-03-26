#ifndef time_info_hpp1
#define time_info_hpp1
#include "era.hpp"

namespace era01 {

class TimeInfo {
 protected:
  time_t zTime;

 public:
  TimeInfo();
  TimeLocal getLocal();
  TimeGlobal getGlobal();
};
}
#endif
