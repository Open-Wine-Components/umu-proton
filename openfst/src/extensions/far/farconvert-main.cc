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
// Converts FST and container type of FARs.

#include <cstring>
#include <string>

#include <fst/flags.h>
#include <fst/log.h>
#include <fst/extensions/far/farscript.h>
#include <fst/extensions/far/getters.h>

DECLARE_string(far_type);
DECLARE_string(fst_type);

int farconvert_main(int argc, char *argv[]) {
  namespace s = fst::script;

  std::string usage = "Converts FST and container types.\n\n Usage:";
  usage += argv[0];
  usage += " [in.far [out.far]]\n";

  std::set_new_handler(FailedNewHandler);
  SET_FLAGS(usage.c_str(), &argc, &argv, true);

  if (argc > 3) {
    ShowUsage();
    return 1;
  }

  // 0 file args means read from stdin and write to stdout.
  // 1 file arg means read from in.far and write to stdout.
  // Only STList can be written to stdout; there will be
  // an error in Write() when another format is used.
  const std::string in_far =
      argc > 1 && std::strcmp(argv[1], "-") != 0 ? argv[1] : "";
  const std::string out_far =
      argc > 2 && std::strcmp(argv[2], "-") != 0 ? argv[2] : "";

  fst::FarType far_type;
  if (!s::GetFarType(FLAGS_far_type, &far_type)) {
    LOG(ERROR) << "Unknown --far_type " << FLAGS_far_type;
    return 1;
  }

  // We use a different meaning of far_type. DEFAULT means "same as input",
  // so snoop the input far_type.
  if (far_type == fst::FarType::DEFAULT) {
    fst::FarHeader hdr;
    if (!hdr.Read(in_far)) {
      LOG(ERROR) << "Couldn't open " << in_far;
      return 1;
    }
    // GetFarType returns STLIST for stdin, regardless of the actual FAR type.
    // If the input actually has another type, it Open() will fail later.
    if (!s::GetFarType(hdr.FarType(), &far_type)) {
      LOG(ERROR) << "Failed to retrieve archive type from " << in_far;
      return 1;
    }
  }

  // LoadArcTypeFromFar returns arc_type=="standard" for stdin. As above
  // with FarType, Open() will fail later if it actually has a different type.
  const std::string arc_type = s::LoadArcTypeFromFar(in_far);
  if (arc_type.empty()) {
    LOG(ERROR) << "Could not determine arc type for " << in_far;
    return 1;
  }

  // Empty fst_type means use input fst type for each fst individually.
  s::FarConvert(in_far, out_far, arc_type, FLAGS_fst_type, far_type);

  return 0;
}
