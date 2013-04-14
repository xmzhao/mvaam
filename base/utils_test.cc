//
// Author: Xuemin Zhao (xmzhao1986@gmail.com)

#include "mvaam/base/utils.h"

#include <fstream>

#include "gtest/gtest.h"

namespace mvaam {

TEST(UtilsTest, LoadToString) {
  std::string s = "init";

  // not exists
  EXPECT_EQ(-1, LoadToString("not-exists", &s));
  EXPECT_EQ("", s);

  // empty
  std::ofstream ofs("test.txt");
  EXPECT_FALSE(ofs.fail());
  ofs.close();

  EXPECT_EQ(0, LoadToString("test.txt", &s));
  EXPECT_EQ("", s);

  // normal
  const std::string kContent = "北京天气真差 我勒个去！\t\n";
  ofs.open("test.txt");
  EXPECT_FALSE(ofs.fail());
  ofs << kContent;
  ofs.close();

  EXPECT_EQ(0, LoadToString("test.txt", &s));
  EXPECT_EQ(kContent, s);
}

}  // namespace mvaam
