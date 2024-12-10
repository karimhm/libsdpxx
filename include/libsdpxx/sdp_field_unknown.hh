///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_SDP_FIELD_UNKNOWN_HH
#define LIBSDPXX_SDP_FIELD_UNKNOWN_HH

#include <string>

namespace libsdpxx {

class sdp_field_unknown {
public:
  /*!
   *  @abstract
   *  Construct an unknown SDP field.
   *
   *  @param type
   *  The raw SDP field.
   *
   *  @param value
   *  The raw SDP value.
   */
  sdp_field_unknown(std::string type, std::string value) noexcept
    : type_(type)
    , value_(value) {}

  /*!
   *  @abstract
   *  Get the raw SDP type.
   */
  std::string get_type() const noexcept { return type_; }

  /*!
   *  @abstract
   *  Get the raw SDP value.
   */
  std::string get_value() const noexcept { return value_; }

private:
  const std::string type_;
  const std::string value_;
};

} // namespace libsdpxx

#endif /* LIBSDPXX_SDP_FIELD_UNKNOWN_HH */
