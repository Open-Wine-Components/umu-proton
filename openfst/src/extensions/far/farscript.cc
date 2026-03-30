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
// Definitions of 'scriptable' versions of FAR operations, that is,
// those that can be called with FstClass-type arguments.

#include <fst/extensions/far/farscript.h>

#include <fst/extensions/far/far.h>
#include <fst/arc.h>
#include <fst/script/script-impl.h>

#define REGISTER_FST_OPERATION_4ARCS(Op, ArgPack) \
  REGISTER_FST_OPERATION_3ARCS(Op, ArgPack);      \
  REGISTER_FST_OPERATION(Op, ErrorArc, ArgPack)

namespace fst {
namespace script {

void FarCompileStrings(const std::vector<std::string> &in_sources,
                       const std::string &out_source,
                       const std::string &arc_type, const std::string &fst_type,
                       const FarType &far_type, int32 generate_keys,
                       FarEntryType fet, TokenType tt,
                       const std::string &symbols_source,
                       const std::string &unknown_symbol, bool keep_symbols,
                       bool initial_symbols, bool allow_negative_labels,
                       const std::string &key_prefix,
                       const std::string &key_suffix) {
  FarCompileStringsArgs args{in_sources, out_source, fst_type, far_type,
                             generate_keys, fet, tt, symbols_source,
                             unknown_symbol, keep_symbols, initial_symbols,
                             allow_negative_labels, key_prefix, key_suffix};
  Apply<Operation<FarCompileStringsArgs>>("FarCompileStrings", arc_type, &args);
}

REGISTER_FST_OPERATION_4ARCS(FarCompileStrings, FarCompileStringsArgs);

void FarConvert(const std::string &in_source, const std::string &out_source,
                const std::string &arc_type, const std::string &fst_type,
                const FarType &far_type) {
  FarConvertArgs args{in_source, out_source, fst_type, far_type};
  Apply<Operation<FarConvertArgs>>("FarConvert", arc_type, &args);
}

REGISTER_FST_OPERATION_4ARCS(FarConvert, FarConvertArgs);

void FarCreate(const std::vector<std::string> &in_sources,
               const std::string &out_source, const std::string &arc_type,
               const int32 generate_keys, const FarType &far_type,
               const std::string &key_prefix, const std::string &key_suffix) {
  FarCreateArgs args{in_sources, out_source, generate_keys, far_type,
                     key_prefix, key_suffix};
  Apply<Operation<FarCreateArgs>>("FarCreate", arc_type, &args);
}

REGISTER_FST_OPERATION_4ARCS(FarCreate, FarCreateArgs);

bool FarEqual(const std::string &source1, const std::string &source2,
              const std::string &arc_type, float delta,
              const std::string &begin_key, const std::string &end_key) {
  FarEqualInnerArgs args{source1, source2, delta, begin_key, end_key};
  FarEqualArgs args_with_retval(args);
  Apply<Operation<FarEqualArgs>>("FarEqual", arc_type, &args_with_retval);
  return args_with_retval.retval;
}

REGISTER_FST_OPERATION_4ARCS(FarEqual, FarEqualArgs);

void FarExtract(const std::vector<std::string> &isources,
                const std::string &arc_type, int32 generate_sources,
                const std::string &keys, const std::string &key_separator,
                const std::string &range_delimiter,
                const std::string &source_prefix,
                const std::string &source_suffix) {
  FarExtractArgs args{isources, generate_sources, keys, key_separator,
                      range_delimiter, source_prefix, source_suffix};
  Apply<Operation<FarExtractArgs>>("FarExtract", arc_type, &args);
}

REGISTER_FST_OPERATION_4ARCS(FarExtract, FarExtractArgs);

void FarInfo(const std::vector<std::string> &sources,
             const std::string &arc_type, const std::string &begin_key,
             const std::string &end_key, bool list_fsts) {
  FarInfoArgs args{sources, begin_key, end_key, list_fsts};
  Apply<Operation<FarInfoArgs>>("FarInfo", arc_type, &args);
}

REGISTER_FST_OPERATION_4ARCS(FarInfo, FarInfoArgs);

void GetFarInfo(const std::vector<std::string> &sources,
                const std::string &arc_type, const std::string &begin_key,
                const std::string &end_key, bool list_fsts, FarInfoData *data) {
  GetFarInfoArgs args{sources, begin_key, end_key, list_fsts, data};
  Apply<Operation<GetFarInfoArgs>>("GetFarInfo", arc_type, &args);
}

REGISTER_FST_OPERATION_4ARCS(GetFarInfo, GetFarInfoArgs);

bool FarIsomorphic(const std::string &source1, const std::string &source2,
                   const std::string &arc_type, float delta,
                   const std::string &begin_key, const std::string &end_key) {
  FarIsomorphicInnerArgs args{source1, source2, delta, begin_key, end_key};
  FarIsomorphicArgs args_with_retval(args);
  Apply<Operation<FarIsomorphicArgs>>("FarIsomorphic", arc_type,
                                      &args_with_retval);
  return args_with_retval.retval;
}

REGISTER_FST_OPERATION_4ARCS(FarIsomorphic, FarIsomorphicArgs);

void FarPrintStrings(const std::vector<std::string> &isources,
                     const std::string &arc_type, const FarEntryType entry_type,
                     const TokenType token_type, const std::string &begin_key,
                     const std::string &end_key, bool print_key,
                     bool print_weight, const std::string &symbols_source,
                     bool initial_symbols, const int32 generate_sources,
                     const std::string &source_prefix,
                     const std::string &source_suffix) {
  FarPrintStringsArgs args{isources, entry_type, token_type, begin_key, end_key,
                           print_key, print_weight, symbols_source,
                           initial_symbols, generate_sources, source_prefix,
                           source_suffix};
  Apply<Operation<FarPrintStringsArgs>>("FarPrintStrings", arc_type, &args);
}

REGISTER_FST_OPERATION_4ARCS(FarPrintStrings, FarPrintStringsArgs);

}  // namespace script
}  // namespace fst
