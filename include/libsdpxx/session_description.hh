///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_SESSION_DESCRIPTION_HH
#define LIBSDPXX_SESSION_DESCRIPTION_HH

#include <variant>
#include <vector>

#include "sdp_field_unknown.hh"

namespace libsdpxx {

enum class sdp_field_type {
  unknown,             /// Unknown SDP field
  protocol_version,    /// Version ("v=")
  origin,              /// Origin ("o=")
  session_name,        /// Session Name ("s=")
  session_information, /// Session Information ("i=")
  uri,                 /// URI ("u=")
  email_address,       /// Email Address ("e=")
  phone_number,        /// Phone Number ("p=")
  connection_data,     /// Connection Data ("c=")
  bandwidth,           /// Bandwidth ("b=")
  timing,              /// Timing ("t=")
  repeat_time,         /// Repeat Times ("r=")
  time_zone,           /// Time Zones ("z=")
  encryption_key,      /// Encryption Keys ("k=")
  attribute,           /// Attributes ("a=")
  media_description    /// Media Descriptions ("m=")
};

class sdp_field_variant {
public:
  /*!
   *  @abstract
   *  Construct an unknown SDP field variant.
   *
   *  @param unknown
   *  The unknown field value.
   */
  sdp_field_variant(const sdp_field_unknown& unknown) noexcept
      : field_type_(sdp_field_type::unknown)
      , field_(unknown) {}

  /*!
   *  @abstract
   *  Get the SDP field type.
   */
  LIBSDPXX_NODISCARD
  sdp_field_type get_field_type() const noexcept { return field_type_; }

  /*!
   *  @abstract
   *  Get the unknown field variant.
   */
  LIBSDPXX_NODISCARD
  sdp_field_unknown get_unknown_field() const noexcept {
    return std::get<sdp_field_unknown>(field_);
  }

private:
  sdp_field_type field_type_;
  std::variant<sdp_field_unknown> field_;
};

class session_description {
public:
  session_description(const std::vector<sdp_field_variant>& fields) noexcept
      : fields_(fields) {}

  LIBSDPXX_NODISCARD
  std::vector<sdp_field_variant> get_fields() const noexcept {
    return fields_;
  }

private:
  std::vector<sdp_field_variant> fields_;
};

} // namespace libsdpxx

#endif /* LIBSDPXX_SESSION_DESCRIPTION_HH */
