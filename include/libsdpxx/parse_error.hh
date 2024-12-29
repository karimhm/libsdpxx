///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_EXPECTED_HH
#define LIBSDPXX_EXPECTED_HH

#include <stdexcept>

#include "expected.hpp"

namespace libsdpxx {

class parse_error;

template <class T>
using error_or = tl::expected<T, parse_error>;

class parse_error final : public std::runtime_error {
public:
  parse_error(std::string line, const std::string& what) noexcept
    : std::runtime_error(what)
    , line_(std::move(line)) {}

  parse_error(const std::string_view& line, const std::string& what) noexcept
    : std::runtime_error(what)
    , line_(std::string{line}) {}

  LIBSDPXX_NODISCARD
  std::string line() const noexcept { return line_; }

  template<typename T>
  constexpr operator error_or<T>() const noexcept {
    return tl::unexpected(*this);
  }

private:
  std::string line_;
};

} // namespace libsdpxx

#endif /* LIBSDPXX_EXPECTED_HH */
