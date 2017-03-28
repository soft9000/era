#ifndef time_info_hpp1
#define time_info_hpp1
#include "era.hpp"

namespace era01 {

class TimeInfo {
 protected:
  time_t zTime;

 public:
  TimeInfo();
  TimeInfo(time_t atime);
  TimeInfo(const TimeInfo& info);

  time_t epoch() const;
  void assign(const TimeInfo& info);

  TimeLocal getLocal() const;
  TimeGlobal getGlobal() const;
};
}
#endif
