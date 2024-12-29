///
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#ifndef LIBSDPXX_CONFIG_HH
#define LIBSDPXX_CONFIG_HH

#if __cplusplus > 201402L
#define LIBSDPXX_CXX17
#endif

#define LIBSDPXX_EXPORT __attribute__((visibility("default")))
#define LIBSDPXX_PRIVATE __attribute__((visibility("hidden")))
#define LIBSDPXX_INLINE inline

#ifdef LIBSDPXX_CXX17
#define LIBSDPXX_NODISCARD [[nodiscard]]
#else
#define LIBSDPXX_NODISCARD
#endif

#define LIBSDPXX_PRINTFLIKE(fmt, args) __attribute__((format(printf, fmt, args)))

#endif /* LIBSDPXX_CONFIG_HH */
