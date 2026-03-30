// Copyright 2005-2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the 'License');
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an 'AS IS' BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// See www.openfst.org for extensive documentation on this weighted
// finite-state transducer library.
//
// Compatibility file for old-style Map() functions and MapFst class that have
// been renamed to ArcMap (cf. StateMap).

#ifndef FST_MAP_H_
#define FST_MAP_H_


#include <fst/arc-map.h>

namespace fst {

template <class A, class C>
OPENFST_DEPRECATED("Use `ArcMap` instead.")
void Map(MutableFst<A> *fst, C *mapper) {
  ArcMap(fst, mapper);
}

template <class A, class C>
OPENFST_DEPRECATED("Use `ArcMap` instead.")
void Map(MutableFst<A> *fst, C mapper) {
  ArcMap(fst, mapper);
}

template <class A, class B, class C>
OPENFST_DEPRECATED("Use `ArcMap` instead.")
void Map(const Fst<A> &ifst, MutableFst<B> *ofst, C *mapper) {
  ArcMap(ifst, ofst, mapper);
}

template <class A, class B, class C>
OPENFST_DEPRECATED("Use `ArcMap` instead.")
void Map(const Fst<A> &ifst, MutableFst<B> *ofst, C mapper) {
  ArcMap(ifst, ofst, mapper);
}

using MapFstOptions OPENFST_DEPRECATED("Use `ArcMapFstOptions` instead.") =
    ArcMapFstOptions;

template <class A, class B, class C>
using MapFst OPENFST_DEPRECATED("Use `ArcMapFst` instead.") = ArcMapFst<A, B, C>;

template <class A>
using IdentityMapper OPENFST_DEPRECATED("Use `IdentityArcMapper` instead.") =
    IdentityArcMapper<A>;

}  // namespace fst

#endif  // FST_MAP_H_
