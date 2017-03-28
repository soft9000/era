#include "era.hpp"
#include <algorithm>

namespace era01 {

class AsciiChar {
 public:
  static bool IsWhite(char ch) {  // char_t
    if (ch <= ' ')                // 0x20
      return true;
    if (ch > '~')  // 0x7E
      return true;
    return false;
  }

  static int MkWhite(string str) {
    stringstream srm;
    int tally = 0;
    for (auto pos = str.begin(); pos < str.end(); pos++) {
      if (IsWhite(*pos) == false) {
        tally++;
        srm << ' ';
        continue;
      }
      srm << (*pos);
    }
    srm << ends;
    str.assign(srm.str());
    return tally;
  }

  static int LTrim(string str) {
    int tally = 0;
    for (auto pos = str.begin(); pos < str.end(); pos++) {
      if (IsWhite(*pos) == false) {
        str.erase(pos);
        tally++;
        continue;
      }
      break;
    }
    return tally;
  }

  static int RTrim(string str) {
    reverse(str.begin(), str.end());
    int tally = LTrim(str);
    reverse(str.begin(), str.end());
    return tally;
  }

  static int Trim(string str) {
    int tally = LTrim(str);
    tally += RTrim(str);
    return tally;
  }
};
}
