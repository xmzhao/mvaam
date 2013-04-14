//
// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#include "mvaam/base/utils.h"

#include <fstream>

namespace mvaam {

int32_t LoadToString(const std::string& filepath, std::string* s) {
  s->clear();

  std::ifstream ifs(filepath.c_str(), std::ios::binary);
  if (ifs.fail()) {
    return -1;
  }

  int32_t res = 0;

  std::filebuf* buf = ifs.rdbuf();
  std::streamsize size = buf->pubseekoff(0, ifs.end);
  buf->pubseekoff(0, ifs.beg);
  if (size > 0) {
    s->resize(size);
    if (size != buf->sgetn(string_as_array(s), size)) {
      s->clear();
      res = -1;
    }
  }
  ifs.close();
  return res;
}

}  // namespace mvaam
