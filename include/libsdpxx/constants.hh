///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_SDP_CONSTANTS_HH
#define LIBSDPXX_SDP_CONSTANTS_HH

namespace libsdpxx {
namespace constants {

static const int line_prefix_size = 2;

static const char cr = '\r'; // Carriage return (ASCII : 13, hex : 0x0d)
static const char lf = '\n'; // Line Feed (ASCII : 10, hex : 0x0a)
static const char sp = ' ';  // Space (ASCII : 32, hex : 0x20)
static const char equals = '=';
static const char slash = '/';
static const char colon = ':';
// RFC 5234. CRLF = %d13.10
static const char newline[] = {cr, lf, 0};

// RFC 8866
static const char sdp_line_type_protocol_version = 'v';
static const char sdp_line_type_origin = 'o';
static const char sdp_line_type_session_name = 's';
static const char sdp_line_type_session_information = 'i';
static const char sdp_line_type_uri = 'u';
static const char sdp_line_type_email_address = 'e';
static const char sdp_line_type_phone_number = 'p';
static const char sdp_line_type_connection_data = 'c';
static const char sdp_line_type_bandwidth = 'b';
static const char sdp_line_type_timing = 't';
static const char sdp_line_type_repeat_time = 'r';
static const char sdp_line_type_time_zone = 'z';
static const char sdp_line_type_encryption_key = 'k';
static const char sdp_line_type_attribute = 'a';
static const char sdp_line_type_media_description = 'm';

} // namespace constants
} // namespace libsdpxx

#endif /* LIBSDPXX_SDP_CONSTANTS_HH */
