///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#include <iostream>

#include <gtest/gtest.h>
#include <libsdpxx/serialization.hh>

using namespace libsdpxx;

TEST(libsdpxx_tests, serialize_unknown_field) {
  const auto field = sdp_field_unknown{"y", "0"};
  const session_description session_description = {{field}};
  EXPECT_EQ("y=0\r\n", serialize(session_description));
}

TEST(libsdpxx_tests, serialize_protocol_version_line) {
  std::ostringstream os;
  const auto field = sdp_field_protocol_version{0};
  internal::serialize(field, os);
  EXPECT_EQ("v=0", os.str());
}

TEST(libsdpxx_tests, serialize) {
  const std::vector<sdp_field_variant> sdp_fields = {
    sdp_field_unknown{"y", "0"},
    sdp_field_protocol_version{0}
  };
  EXPECT_EQ("y=0\r\nv=0\r\n", serialize(sdp_fields));
}

TEST(libsdpxx_tests, serialize_empty) {
  EXPECT_EQ("", serialize(std::vector<sdp_field_variant>()));
}
