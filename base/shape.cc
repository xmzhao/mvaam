//
// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#include "mvaam/base/shape.h"

#include <fstream>

#include "glog/logging.h"
#include "google/protobuf/text_format.h"

#include "mvaam/base/utils.h"

namespace mvaam {

int32_t Shape::LoadPTS(const std::string& path) {
  std::string buf;
  if (LoadToString(path, &buf) < 0) {
    LOG(ERROR) << "Failed to load file `" << path << "`";
    return -1;
  }

  ShapePB pb;
  if (!google::protobuf::TextFormat::ParseFromString(buf, &pb)) {
    LOG(ERROR) << "Failed to parse from debug string: " << buf;
    return -1;
  }
  return ParseFrom(pb);
}

int32_t Shape::SavePTS(const std::string& path) const {
  std::ofstream ofs(path.c_str());
  if (ofs.fail()) {
    LOG(ERROR) << "Failed to create file `" << path << "`";
    return -1;
  }

  ShapePB pb;
  if (SerializeTo(&pb) != 0) {
    LOG(ERROR) << "Failed to serialize to pb";
    return -1;
  }

  ofs << pb.DebugString();
  ofs.close();
  return 0;
}

int32_t Shape::ParseFrom(const ShapePB& pb) {
  points_.resize(pb.points_size());
  for (int i = 0; i < pb.points_size(); ++i) {
    points_[i].x = pb.points(i).x();
    points_[i].y = pb.points(i).y();
  }
  return 0;
}

int32_t Shape::SerializeTo(ShapePB* pb) const {
  pb->Clear();
  for (size_t i = 0; i < points_.size(); ++i) {
    PointPB* pt = pb->add_points();
    pt->set_x(points_[i].x);
    pt->set_y(points_[i].y);
  }
  return 0;
}

int32_t Shape::NumPoints() const {
  return static_cast<int32_t>(points_.size());
}

}  // namespace mvaam

