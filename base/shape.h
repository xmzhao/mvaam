//
// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#ifndef MVAAM_BASE_SHAPE_H_
#define MVAAM_BASE_SHAPE_H_

#include <string>
#include <vector>

#include "thirdparty/opencv2/opencv.hpp"

#include "mvaam/base/mvaam.pb.h"

namespace mvaam {

class Shape {
 public:
  Shape() {}
  ~Shape() {}

  int32_t LoadPTS(const std::string& path);
  int32_t SavePTS(const std::string& path) const;

  int32_t ParseFrom(const ShapePB& pb);
  int32_t SerializeTo(ShapePB* pb) const;

  int32_t NumPoints() const;

 private:
  std::vector<cv::Point2d> points_;
};  // class Shape

}  // namespace mvaam

#endif  // MVAAM_BASE_SHAPE_H_

