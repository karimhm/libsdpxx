///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_BASE_STRING_UTILS_HH
#define LIBSDPXX_BASE_STRING_UTILS_HH

#include <optional>
#include <string>
#include <vector>

#include "config.hh"
#include "constants.hh"

namespace libsdpxx {
namespace internal {

LIBSDPXX_INLINE
std::optional<std::string_view> next_line(const std::string_view str, size_t* pos) {
  if (pos == nullptr || *pos >= str.size()) {
    return std::nullopt;
  }
  size_t line_back = str.find(constants::lf, *pos);
  if (line_back == std::string_view::npos) {
    return std::nullopt;
  }
  std::string_view line = str.substr(*pos, line_back - *pos);
  if (!line.empty() && line.back() == constants::cr) {
    line.remove_suffix(1);
  }
  *pos = line_back + 1;
  return line;
}

} // namespace internal
} // namespace libsdpxx

#endif /* LIBSDPXX_BASE_STRING_UTILS_HH */
