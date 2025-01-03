///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#include <gtest/gtest.h>
#include <libsdpxx/string_utils.hh>

using namespace libsdpxx;
using namespace libsdpxx::internal;

TEST(libsdpxx_tests, next_line_empty) {
  size_t pos = 0;
  EXPECT_EQ(std::nullopt, next_line("", pos));
  EXPECT_EQ(0, pos);
}

TEST(libsdpxx_tests, next_line_no_crlf) {
  size_t pos = 0;
  EXPECT_EQ(std::nullopt, next_line("v=1", pos));
  EXPECT_EQ(0, pos);
}

TEST(libsdpxx_tests, next_line_single) {
  const std::string line = "v=0\r\n";
  size_t pos = 0;
  EXPECT_EQ("v=0", next_line(line, pos));
  EXPECT_EQ(5, pos);
  EXPECT_EQ(std::nullopt, next_line(line, pos));
}

TEST(libsdpxx_tests, next_line_multiple) {
  const std::string line = "v=0\r\na=1\r\n";
  size_t pos = 0;
  EXPECT_EQ("v=0", next_line(line, pos));
  EXPECT_EQ(5, pos);
  EXPECT_EQ("a=1", next_line(line, pos));
  EXPECT_EQ(10, pos);
  EXPECT_EQ(std::nullopt, next_line(line, pos));
}

TEST(libsdpxx_tests, next_line_single_no_cr) {
  const std::string line = "v=0\n";
  size_t pos = 0;
  EXPECT_EQ("v=0", next_line(line, pos));
  EXPECT_EQ(4, pos);
  EXPECT_EQ(std::nullopt, next_line(line, pos));
  EXPECT_EQ(std::nullopt, next_line(line, pos));
}

TEST(libsdpxx_tests, next_line_multiple_no_cr) {
  const std::string line = "v=0\na=1\n";
  size_t pos = 0;
  EXPECT_EQ("v=0", next_line(line, pos));
  EXPECT_EQ(4, pos);
  EXPECT_EQ("a=1", next_line(line, pos));
  EXPECT_EQ(8, pos);
  EXPECT_EQ(std::nullopt, next_line(line, pos));
}

TEST(libsdpxx_tests, format_empty) {
  EXPECT_EQ("", format(""));
}

TEST(libsdpxx_tests, format_no_params) {
  EXPECT_EQ("static", format("static"));
}

TEST(libsdpxx_tests, format_with_string_param) {
  EXPECT_EQ("static param", format("static %s", "param"));
}

TEST(libsdpxx_tests, format_with_string_param_only) {
  EXPECT_EQ("param", format("%s", "param"));
}

TEST(libsdpxx_tests, format_with_multiple_params) {
  EXPECT_EQ("static param c 1 2.0", format("static %s %c %i %.1f", "param", 'c', 1, 2.0));
}
