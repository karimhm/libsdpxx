///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_SERIALIZATION_HH
#define LIBSDPXX_SERIALIZATION_HH

#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

#include "config.hh"
#include "session_description.hh"

namespace libsdpxx {
namespace internal {

LIBSDPXX_PRIVATE
void serialize_unknown(sdp_field_unknown const & unknown, std::ostringstream & os) {
  os << unknown.get_type()
     << constants::equals
     << unknown.get_value()
     << constants::newline;
}

LIBSDPXX_PRIVATE
std::string serialize(session_description const & session_description) noexcept {
  std::ostringstream os;

  for (const auto field : session_description.get_fields()) {
    switch (field.get_field_type()) {
      default:
        serialize_unknown(*field.get_unknown_field(), os);
        continue;
    }
  }

  return os.str();
}

} // namespace internal

LIBSDPXX_EXPORT
std::string serialize(session_description const & session_description) noexcept {
  return internal::serialize(session_description);
}

} // namespace libsdpxx

#endif /* LIBSDPXX_SERIALIZATION_HH */
