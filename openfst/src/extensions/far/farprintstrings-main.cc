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
// Outputs as strings the string FSTs in a finite-state archive.

#include <string>
#include <vector>

#include <fst/flags.h>
#include <fst/extensions/far/farscript.h>
#include <fst/script/getters.h>

DECLARE_string(filename_prefix);
DECLARE_string(filename_suffix);
DECLARE_int32(generate_filenames);
DECLARE_string(begin_key);
DECLARE_string(end_key);
DECLARE_bool(print_key);
DECLARE_bool(print_weight);
DECLARE_string(entry_type);
DECLARE_string(token_type);
DECLARE_string(symbols);
DECLARE_bool(initial_symbols);

int farprintstrings_main(int argc, char **argv) {
  namespace s = fst::script;

  std::string usage =
      "Print as std::string the std::string FSTs in an archive.\n\n  Usage:";
  usage += argv[0];
  usage += " [in1.far in2.far ...]\n";

  std::set_new_handler(FailedNewHandler);
  SET_FLAGS(usage.c_str(), &argc, &argv, true);
  s::ExpandArgs(argc, argv, &argc, &argv);

  std::vector<std::string> in_sources;
  for (int i = 1; i < argc; ++i) in_sources.push_back(argv[i]);
  if (in_sources.empty()) in_sources.push_back("");

  const auto arc_type = s::LoadArcTypeFromFar(in_sources[0]);
  if (arc_type.empty()) return 1;

  fst::FarEntryType entry_type;
  if (!s::GetFarEntryType(FLAGS_entry_type, &entry_type)) {
    LOG(ERROR) << "Unknown or unsupported FAR entry type: " << FLAGS_entry_type;
    return 1;
  }

  fst::TokenType token_type;
  if (!s::GetTokenType(FLAGS_token_type, &token_type)) {
    LOG(ERROR) << "Unknown or unsupported FAR token type: " << FLAGS_token_type;
    return 1;
  }

  s::FarPrintStrings(in_sources, arc_type, entry_type, token_type,
                     FLAGS_begin_key, FLAGS_end_key, FLAGS_print_key,
                     FLAGS_print_weight, FLAGS_symbols, FLAGS_initial_symbols,
                     FLAGS_generate_filenames, FLAGS_filename_prefix,
                     FLAGS_filename_suffix);

  return 0;
}
