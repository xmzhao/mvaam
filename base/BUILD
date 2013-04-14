# Author       : Xuemin Zhao <xmzhao1986@gmail.com>
# Created Time : 2013-03-24
# Description  :

proto_library(
  name = "mvaam_proto",
  srcs = "mvaam.proto",
)

cc_library(
  name = "utils",
  srcs = "utils.cc",
)

cc_test(
  name = "utils_test",
  srcs = [
    "utils_test.cc"
  ],
  deps = [
    ":utils",
  ],
)

cc_library(
  name = "shape",
  srcs = "shape.cc",
  deps = [
    ":mvaam_proto",
    ":utils",
    "//thirdparty/glog:glog",
  ],
  warning = "no"
)
