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

#include <cstdarg>
#include <optional>
#include <string>

#include "config.hh"
#include "constants.hh"

namespace libsdpxx {
namespace internal {

LIBSDPXX_INLINE
std::optional<std::string_view> next_line(const std::string_view& str, size_t& pos) noexcept {
  if (pos >= str.size()) {
    return std::nullopt;
  }
  const size_t line_back = str.find(constants::lf, pos);
  if (line_back == std::string_view::npos) {
    return std::nullopt;
  }
  std::string_view line = str.substr(pos, line_back - pos);
  if (!line.empty() && line.back() == constants::cr) {
    line.remove_suffix(1);
  }
  pos = line_back + 1;
  return line;
}

LIBSDPXX_PRIVATE
LIBSDPXX_PRINTFLIKE(1, 2)
static std::string format(const char* format, ...) noexcept {
  va_list args;
  va_start(args, format);
  const size_t size = std::vsnprintf(nullptr, 0, format, args) + 1; // +1 for null terminator
  va_end(args);
  if(size <= 0) {
    return "{{Error during formatting. std::vsnprintf failed}}";
  }
  auto buffer = std::vector<char>(size);
  va_start(args, format);
  std::vsnprintf(buffer.data(), size, format, args);
  va_end(args);
  return {buffer.data(), buffer.data() + size - 1}; // -1 to exclude the null terminator
}

} // namespace internal
} // namespace libsdpxx

#endif /* LIBSDPXX_BASE_STRING_UTILS_HH */
