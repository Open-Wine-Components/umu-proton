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
// Regression test for various FST algorithms.

#include <fst/test/algo_test.h>

#include <random>
#include <vector>

#include <fst/flags.h>

// DEFINEs determine which semirings are tested; these are controlled by
// the `defines` attributes of the associated build rules.

DEFINE_uint64(seed, 403, "random seed");
DEFINE_int32(repeat, 25, "number of test repetitions");

namespace {

using ::fst::AlgoTester;
using ::fst::ArcTpl;
using ::fst::GallicArc;
using ::fst::GallicWeight;
using ::fst::LexicographicArc;
using ::fst::LexicographicWeight;
using ::fst::LogArc;
using ::fst::LogWeight;
using ::fst::MinMaxArc;
using ::fst::MinMaxWeight;
using ::fst::PowerWeight;
using ::fst::StdArc;
using ::fst::STRING_LEFT;
using ::fst::STRING_RIGHT;
using ::fst::StringArc;
using ::fst::TropicalWeight;
using ::fst::WeightGenerate;

}  // namespace

int main(int argc, char **argv) {
  FLAGS_fst_verify_properties = true;
  std::set_new_handler(FailedNewHandler);
  SET_FLAGS(argv[0], &argc, &argv, true);

  static const int kCacheGcLimit = 20;

  LOG(INFO) << "Seed = " << FLAGS_seed;

  std::mt19937_64 rand(FLAGS_seed);

  FLAGS_fst_default_cache_gc = std::bernoulli_distribution(.5)(rand);
  FLAGS_fst_default_cache_gc_limit =
      std::uniform_int_distribution<>(0, kCacheGcLimit)(rand);
  VLOG(1) << "default_cache_gc:" << FLAGS_fst_default_cache_gc;
  VLOG(1) << "default_cache_gc_limit:" << FLAGS_fst_default_cache_gc_limit;

#ifdef TEST_TROPICAL
  using TropicalWeightGenerate = WeightGenerate<TropicalWeight>;
  TropicalWeightGenerate tropical_generator(FLAGS_seed, false);
  AlgoTester<StdArc, TropicalWeightGenerate> tropical_tester(tropical_generator,
                                                             FLAGS_seed);
  tropical_tester.Test();
#endif  // TEST_TROPICAL

#ifdef TEST_LOG
  using LogWeightGenerate = WeightGenerate<LogWeight>;
  LogWeightGenerate log_generator(FLAGS_seed, false);
  AlgoTester<LogArc, LogWeightGenerate> log_tester(log_generator, FLAGS_seed);
  log_tester.Test();
#endif  // TEST_LOG

#ifdef TEST_MINMAX
  using MinMaxWeightGenerate = WeightGenerate<MinMaxWeight>;
  MinMaxWeightGenerate minmax_generator(FLAGS_seed, false);
  AlgoTester<MinMaxArc, MinMaxWeightGenerate> minmax_tester(minmax_generator,
                                                            FLAGS_seed);
  minmax_tester.Test();
#endif

#ifdef TEST_LEFT_STRING
  using StringWeightGenerate = WeightGenerate<StringWeight<int, STRING_LEFT>>;
  StringWeightGenerate left_string_generator(FLAGS_seed, false);
  AlgoTester<StringArc<>, StringWeightGenerate> left_string_tester(
      left_string_generator, FLAGS_seed);
  left_string_tester.Test();
#endif  // TEST_LEFT_STRING

#ifdef TEST_RIGHT_STRING
  using StringWeightGenerate = WeightGenerate<StringWeight<int, STRING_RIGHT>>;
  StringWeightGenerate right_string_generator(FLAGS_seed, false);
  AlgoTester<StringArc<STRING_RIGHT>, StringWeightGenerate> right_string_tester(
      right_string_generator, FLAGS_seed);
  right_string_tester.Test();
#endif  // TEST_RIGHT_STRING

#ifdef TEST_GALLIC
  using StdGallicArc = GallicArc<StdArc>;
  using TropicalGallicWeightGenerate =
      WeightGenerate<GallicWeight<int, TropicalWeight>>;
  TropicalGallicWeightGenerate tropical_gallic_generator(FLAGS_seed, false);
  AlgoTester<StdGallicArc, TropicalGallicWeightGenerate> gallic_tester(
      tropical_gallic_generator, FLAGS_seed);
  gallic_tester.Test();
#endif  // TEST_GALLIC

#ifdef TEST_LEXICOGRAPHIC
  using TropicalLexicographicArc =
      LexicographicArc<TropicalWeight, TropicalWeight>;
  using TropicalLexicographicWeightGenerate =
      WeightGenerate<LexicographicWeight<TropicalWeight, TropicalWeight>>;
  TropicalLexicographicWeightGenerate lexicographic_generator(FLAGS_seed,
                                                              false);
  AlgoTester<TropicalLexicographicArc, TropicalLexicographicWeightGenerate>
      lexicographic_tester(lexicographic_generator, FLAGS_seed);
  lexicographic_tester.Test();
#endif  // TEST_LEXICOGRAPHIC

#ifdef TEST_POWER
  using TropicalCubeWeight = PowerWeight<TropicalWeight, 3>;
  using TropicalCubeArc = ArcTpl<TropicalCubeWeight>;
  using TropicalCubeWeightGenerate = WeightGenerate<TropicalCubeWeight>;
  TropicalCubeWeightGenerate tropical_cube_generator(FLAGS_seed, false);
  AlgoTester<TropicalCubeArc, TropicalCubeWeightGenerate> tropical_cube_tester(
      tropical_cube_generator, FLAGS_seed);
  tropical_cube_tester.Test();
#endif  // TEST_POWER

  return 0;
}
