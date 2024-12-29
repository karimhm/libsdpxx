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

#include <sstream>
#include <vector>

#include "config.hh"
#include "constants.hh"
#include "session_description.hh"

namespace libsdpxx {
namespace internal {

LIBSDPXX_PRIVATE
void serialize(const sdp_field_unknown& unknown, std::ostringstream& os) noexcept {
  os << unknown.get_type()
     << constants::equals
     << unknown.get_value();
}

LIBSDPXX_PRIVATE
void serialize(const sdp_field_protocol_version& protocol_version, std::ostringstream& os) {
  os << constants::sdp_line_type_protocol_version
     << constants::equals
     << std::to_string(protocol_version.get_version());
}

LIBSDPXX_PRIVATE
std::string serialize(const session_description& session_description) noexcept {
  std::ostringstream os;

  for (const auto& field : session_description.get_fields()) {
    switch (field.get_field_type()) {
      case sdp_field_type::protocol_version:
        serialize(field.get_protocol_version_field(), os);
        break;
      case sdp_field_type::unknown:
        serialize(field.get_unknown_field(), os);
        break;
      default:
        std::abort();
    }
    os << constants::newline;
  }

  return os.str();
}

} // namespace internal

LIBSDPXX_EXPORT
std::string serialize(const session_description& session_description) noexcept {
  return internal::serialize(session_description);
}

} // namespace libsdpxx

#endif /* LIBSDPXX_SERIALIZATION_HH */
