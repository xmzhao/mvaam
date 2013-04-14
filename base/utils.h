//
// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#ifndef MVAAM_BASE_UTILS_H_
#define MVAAM_BASE_UTILS_H_

#include <inttypes.h>
#include <string>

namespace mvaam {

inline char* string_as_array(std::string* s) {
  return s->empty() ? NULL : &*s->begin();
}

int32_t LoadToString(const std::string& filepath, std::string* s);

}  // namespace mvaam

#endif  // MVAAM_BASE_UTILS_H_

