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

template <typename T> class expected {
public:
  expected(const std::runtime_error &&error)
      : value_(tl::make_unexpected(std::move(error))) {}

  expected(T &&value) : value_(value) {}

  bool has_value() const { return value_.has_value(); }

  constexpr explicit operator bool() const { return has_value(); }

  bool has_error() const { return !value_.has_value(); }

  T value() const { return value_.value(); }

  constexpr T& operator*() & { return *value_; }

  T &&release_value() { return std::move(value_.value()); }

  const std::runtime_error &error() const { return value_.error(); }

  char* what() const { return value_.error().what(); }

  std::runtime_error &&release_error() { return std::move(value_.error()); }

private:
  tl::expected<T, std::runtime_error> value_;
};

template <> class expected<void> {
public:
  expected() = default;

  expected(std::runtime_error &&error)
      : value_(tl::make_unexpected(std::move(error))) {}

  bool has_error() const { return !value_.has_value(); }

  const std::runtime_error &error() const { return value_.error(); }

  std::runtime_error &&release_error() { return std::move(value_.error()); }

private:
  tl::expected<void, std::runtime_error> value_;
};

} // namespace libsdpxx

#endif /* LIBSDPXX_EXPECTED_HH */
