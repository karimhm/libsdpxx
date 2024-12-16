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
#include <libsdpxx/serialization.hh>

using namespace libsdpxx;

TEST(libsdpxx_tests, serialize_unknown_field) {
  const auto field = sdp_field_unknown{"y", "0"};
  const session_description session_description = {{field}};
  EXPECT_EQ("y=0\r\n", serialize(session_description));
}
