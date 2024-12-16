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
#include <libsdpxx/deserialization.hh>

using namespace libsdpxx;
using namespace libsdpxx::internal;

TEST(libsdpxx_tests, line_type) {
  // 'y' is not a valid sdp field type.
  EXPECT_EQ(sdp_field_type::unknown, line_type("y"));

  EXPECT_EQ(sdp_field_type::protocol_version, line_type("v"));
  EXPECT_EQ(sdp_field_type::origin, line_type("o"));
  EXPECT_EQ(sdp_field_type::session_name, line_type("s"));
  EXPECT_EQ(sdp_field_type::session_information, line_type("i"));
  EXPECT_EQ(sdp_field_type::uri, line_type("u"));
  EXPECT_EQ(sdp_field_type::email_address, line_type("e"));
  EXPECT_EQ(sdp_field_type::phone_number, line_type("p"));
  EXPECT_EQ(sdp_field_type::connection_data, line_type("c"));
  EXPECT_EQ(sdp_field_type::bandwidth, line_type("b"));
  EXPECT_EQ(sdp_field_type::timing, line_type("t"));
  EXPECT_EQ(sdp_field_type::repeat_time, line_type("r"));
  EXPECT_EQ(sdp_field_type::time_zone, line_type("z"));
  EXPECT_EQ(sdp_field_type::encryption_key, line_type("k"));
  EXPECT_EQ(sdp_field_type::attribute, line_type("a"));
  EXPECT_EQ(sdp_field_type::media_description, line_type("m"));
}

TEST(libsdpxx_tests, deserialize_unknown_field) {
  const auto session_description = libsdpxx::deserialize("y=0\r\n");
  EXPECT_EQ(1, session_description.get_fields().size());
  const auto unknown = session_description.get_fields()[0].get_unknown_field();
  EXPECT_EQ("y", unknown.get_type());
  EXPECT_EQ("0", unknown.get_value());
}

TEST(libsdpxx_tests, line_value) {
  EXPECT_EQ("0", line_value("v=0"));
  EXPECT_EQ(" ", line_value("s= "));
}

TEST(libsdpxx_tests, is_valid_line) {
  EXPECT_TRUE(is_valid_line("v=0"));
  EXPECT_FALSE(is_valid_line("v_0"));
  EXPECT_TRUE(is_valid_line("s= "));
  EXPECT_FALSE(is_valid_line("s="));
}
