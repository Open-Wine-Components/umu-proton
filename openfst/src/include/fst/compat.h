// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// See www.openfst.org for extensive documentation on this weighted
// finite-state transducer library.

#ifndef FST_LIB_COMPAT_H_
#define FST_LIB_COMPAT_H_

#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#if defined(__GNUC__) || defined(__clang__)
#define OPENFST_DEPRECATED(message) __attribute__((deprecated(message)))
#elif defined(_MSC_VER)
#define OPENFST_DEPRECATED(message) __declspec(deprecated(message))
#else
#define OPENFST_DEPRECATED(message)
#endif

#include <fst/config.h>
#include <fst/types.h>
#include <fst/lock.h>
#include <fst/flags.h>
#include <fst/log.h>
#include <fst/icu.h>

void FailedNewHandler();

namespace fst {

// Downcasting.

template <typename To, typename From>
inline To down_cast(From *f) {
  return static_cast<To>(f);
}

template <typename To, typename From>
inline To down_cast(From &f) {
  return static_cast<To>(f);
}

// Bitcasting.
template <class Dest, class Source>
inline Dest bit_cast(const Source &source) {
  static_assert(sizeof(Dest) == sizeof(Source),
                "Bitcasting unsafe for specified types");
  Dest dest;
  memcpy(&dest, &source, sizeof(dest));
  return dest;
}

namespace internal {

template <typename T>
struct identity {
  typedef T type;
};

template <typename T>
using identity_t = typename identity<T>::type;

}  // namespace internal

template <typename To>
constexpr To implicit_cast(typename internal::identity_t<To> to) {
  return to;
}

// Checksums.
class CheckSummer {
 public:
  CheckSummer();

  void Reset();

  void Update(void const *data, int size);

  void Update(std::string const &data);

  std::string Digest() { return check_sum_; }

 private:
  constexpr static int kCheckSumLength = 32;
  int count_;
  std::string check_sum_;

  CheckSummer(const CheckSummer &) = delete;
  CheckSummer &operator=(const CheckSummer &) = delete;
};

// Defines make_unique and make_unique_default_init using a standard definition
// that should be compatible with the C++14 and C++20 (respectively)
// definitions.
// TODO(kbg): Remove these once we migrate to C++14 and C++20.

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
std::unique_ptr<T[]> make_unique(size_t n) {
  return std::unique_ptr<T>(new typename std::remove_extent<T>::type[n]());
}

template <typename T>
std::unique_ptr<T> make_unique_default_init() {
  return std::unique_ptr<T>(new T);
}

template <typename T>
std::unique_ptr<T[]> make_unique_default_init(size_t n) {
  return std::unique_ptr<T>(new typename std::remove_extent<T>::type[n]);
}

template <typename T>
std::unique_ptr<T> WrapUnique(T *ptr) {
  return std::unique_ptr<T>(ptr);
}

// Range utilities

// A range adaptor for a pair of iterators.
//
// This just wraps two iterators into a range-compatible interface. Nothing
// fancy at all.
template <typename IteratorT>
class iterator_range {
 public:
  using iterator = IteratorT;
  using const_iterator = IteratorT;
  using value_type = typename std::iterator_traits<IteratorT>::value_type;

  iterator_range() : begin_iterator_(), end_iterator_() {}
  iterator_range(IteratorT begin_iterator, IteratorT end_iterator)
      : begin_iterator_(std::move(begin_iterator)),
        end_iterator_(std::move(end_iterator)) {}

  IteratorT begin() const { return begin_iterator_; }
  IteratorT end() const { return end_iterator_; }

 private:
  IteratorT begin_iterator_, end_iterator_;
};

// Convenience function for iterating over sub-ranges.
//
// This provides a bit of syntactic sugar to make using sub-ranges
// in for loops a bit easier. Analogous to std::make_pair().
template <typename T>
iterator_range<T> make_range(T x, T y) {
  return iterator_range<T>(std::move(x), std::move(y));
}

// String munging.

std::string StringJoin(const std::vector<std::string> &elements,
                       const std::string &delim);

std::string StringJoin(const std::vector<std::string> &elements,
                       const char *delim);

std::string StringJoin(const std::vector<std::string> &elements, char delim);

std::vector<std::string> StringSplit(const std::string &full,
                                     const std::string &delim);

std::vector<std::string> StringSplit(const std::string &full,
                                     const char *delim);

std::vector<std::string> StringSplit(const std::string &full, char delim);

void StripTrailingAsciiWhitespace(std::string *full);

std::string StripTrailingAsciiWhitespace(const std::string &full);

}  // namespace fst

#endif  // FST_LIB_COMPAT_H_
