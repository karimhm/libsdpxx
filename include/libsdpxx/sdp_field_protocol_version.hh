///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_SDP_FIELD_PROTOCOL_VERSION_HH
#define LIBSDPXX_SDP_FIELD_PROTOCOL_VERSION_HH

#include <cstdint>

namespace libsdpxx {

class sdp_field_protocol_version {
public:
  /*!
   *  @abstract
   *  Construct an SDP Protocol Version ("v=") field.
   *
   *  @param version
   *  The SDP protocol version value.
   */
  sdp_field_protocol_version(const int64_t version) noexcept
      : version_(version) {}

  /*!
   *  @abstract
   *  Get the protocol version field value.
   */
  LIBSDPXX_NODISCARD
  int64_t get_version() const noexcept { return version_; }

private:
  int64_t version_;
};

} // namespace libsdpxx

#endif /* LIBSDPXX_SDP_FIELD_PROTOCOL_VERSION_HH */
