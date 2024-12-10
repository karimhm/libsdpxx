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

TEST(libsdpxx_tests, line_type) {
  // 'y' is not a valid sdp field type.
  EXPECT_EQ(sdp_field_type::unknown, internal::line_type("y"));
  EXPECT_EQ(sdp_field_type::protocol_version, internal::line_type("v"));
  EXPECT_EQ(sdp_field_type::origin, internal::line_type("o"));
  EXPECT_EQ(sdp_field_type::session_name, internal::line_type("s"));
  EXPECT_EQ(sdp_field_type::session_information, internal::line_type("i"));
  EXPECT_EQ(sdp_field_type::uri, internal::line_type("u"));
  EXPECT_EQ(sdp_field_type::email_address, internal::line_type("e"));
  EXPECT_EQ(sdp_field_type::phone_number, internal::line_type("p"));
  EXPECT_EQ(sdp_field_type::connection_data, internal::line_type("c"));
  EXPECT_EQ(sdp_field_type::bandwidth, internal::line_type("b"));
  EXPECT_EQ(sdp_field_type::timing, internal::line_type("t"));
  EXPECT_EQ(sdp_field_type::repeat_time, internal::line_type("r"));
  EXPECT_EQ(sdp_field_type::time_zone, internal::line_type("z"));
  EXPECT_EQ(sdp_field_type::encryption_key, internal::line_type("k"));
  EXPECT_EQ(sdp_field_type::attribute, internal::line_type("a"));
  EXPECT_EQ(sdp_field_type::media_description, internal::line_type("m"));
}

TEST(libsdpxx_tests, deserialize_unknown_field) {
    const auto session_description = deserialize("y=0\r\n");
    EXPECT_EQ(1, session_description.get_fields().size());
    const auto unknown = session_description.get_fields()[0].get_unknown_field();
    EXPECT_EQ("y", unknown->get_type());
    EXPECT_EQ("0", unknown->get_value());
}
