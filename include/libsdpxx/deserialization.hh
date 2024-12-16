///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_DESERIALIZATION_HH
#define LIBSDPXX_DESERIALIZATION_HH

#include <cassert>
#include <vector>

#include "config.hh"
#include "parse_error.hh"
#include "string_utils.hh"
#include "session_description.hh"

namespace libsdpxx {
namespace internal {

template <typename F>
LIBSDPXX_PRIVATE
bool push_back(std::vector<sdp_field_variant>& sdp_fields, const error_or<F>& field) noexcept {
  if (field.has_value()) {
    sdp_fields.push_back(field.value());
    return true;
  } else {
    return false;
  }
}

LIBSDPXX_PRIVATE
sdp_field_type line_type(const std::string_view& line) noexcept {
  switch (line[0]) {
    case constants::sdp_line_type_protocol_version:
      return sdp_field_type::protocol_version;
    case constants::sdp_line_type_origin:
      return sdp_field_type::origin;
    case constants::sdp_line_type_session_name:
      return sdp_field_type::session_name;
    case constants::sdp_line_type_session_information:
      return sdp_field_type::session_information;
    case constants::sdp_line_type_uri:
      return sdp_field_type::uri;
    case constants::sdp_line_type_email_address:
      return sdp_field_type::email_address;
    case constants::sdp_line_type_phone_number:
      return sdp_field_type::phone_number;
    case constants::sdp_line_type_connection_data:
      return sdp_field_type::connection_data;
    case constants::sdp_line_type_bandwidth:
      return sdp_field_type::bandwidth;
    case constants::sdp_line_type_timing:
      return sdp_field_type::timing;
    case constants::sdp_line_type_repeat_time:
      return sdp_field_type::repeat_time;
    case constants::sdp_line_type_time_zone:
      return sdp_field_type::time_zone;
    case constants::sdp_line_type_encryption_key:
      return sdp_field_type::encryption_key;
    case constants::sdp_line_type_attribute:
      return sdp_field_type::attribute;
    case constants::sdp_line_type_media_description:
      return sdp_field_type::media_description;
    default:
      return sdp_field_type::unknown;
  }
}

LIBSDPXX_INLINE
std::string_view line_value(const std::string_view& line) noexcept {
  return line.substr(constants::line_prefix_size);
}

LIBSDPXX_INLINE
bool is_valid_line(const std::string_view& line) noexcept {
  return line.size() > constants::line_prefix_size &&
         line[1] == constants::equals;
}

LIBSDPXX_PRIVATE
error_or<sdp_field_unknown> deserialize_unknown(const std::string_view& line) noexcept {
  return sdp_field_unknown{std::string{line[0]}, std::string{line_value(line)}};
}

LIBSDPXX_PRIVATE
std::vector<sdp_field_variant> deserialize(const std::string_view& sdp) noexcept {
  std::vector<sdp_field_variant> fields;
  size_t pos = 0;
  std::optional<std::string_view> line;
  while ((line = next_line(sdp, pos)).has_value()) {
    if (!is_valid_line(*line)) {
      continue;
    }

    switch (line_type(*line)) {
      case sdp_field_type::unknown:
        push_back(fields, deserialize_unknown(*line));
        break;
      default:
        std::abort();
    }
  }
  return fields;
}

} // namespace internal

LIBSDPXX_EXPORT
session_description deserialize(const std::string& sdp) noexcept {
  return session_description{internal::deserialize(sdp)};
}

} // namespace libsdpxx

#endif /* LIBSDPXX_DESERIALIZATION_HH */
