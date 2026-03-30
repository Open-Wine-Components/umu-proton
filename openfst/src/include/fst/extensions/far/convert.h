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
#ifndef FST_EXTENSIONS_FAR_CONVERT_H_
#define FST_EXTENSIONS_FAR_CONVERT_H_

#include <memory>
#include <string>

#include <fst/extensions/far/far.h>
#include <fst/extensions/far/getters.h>
#include <fst/register.h>

namespace fst {

template <class Arc>
void FarConvert(const std::string &in_source, const std::string &out_source,
                const std::string &fst_type, const FarType &far_type) {
  std::unique_ptr<FarReader<Arc>> reader(FarReader<Arc>::Open(in_source));
  if (!reader) {
    FSTERROR() << "FarConvert: Cannot open input FAR: " << in_source;
    return;
  }

  std::unique_ptr<FarWriter<Arc>> writer(
      FarWriter<Arc>::Create(out_source, far_type));
  if (!writer) {
    FSTERROR() << "FarConvert: Cannot open output FAR as type "
               << GetFarTypeString(far_type) << " : " << out_source;
    return;
  }

  for (; !reader->Done(); reader->Next()) {
    const std::string key = reader->GetKey();
    const Fst<Arc> *const fst = reader->GetFst();

    if (fst_type.empty() || fst->Type() == fst_type) {
      writer->Add(key, *fst);
    } else {
      auto converted_fst = fst::WrapUnique(Convert(*fst, fst_type));
      if (!converted_fst) {
        FSTERROR() << "FarConvert: Cannot convert FST with key " << key
                   << " to " << fst_type;
        return;
      }

      writer->Add(key, *converted_fst);
    }
  }

  if (reader->Error()) {
    FSTERROR() << "FarConvert: Error reading FAR: " << in_source;
  }
  if (writer->Error()) {
    FSTERROR() << "FarConvert: Error writing FAR: " << out_source;
  }
}

}  // namespace fst

#endif  // FST_EXTENSIONS_FAR_CONVERT_H_
