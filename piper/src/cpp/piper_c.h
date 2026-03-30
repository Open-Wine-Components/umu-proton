/* Piper C API header file. */

#ifndef PIPER_C_H_
#define PIPER_C_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int64_t PiperSpeakerId;

struct Piper;
typedef struct Piper Piper;

struct PiperVoice;
typedef struct PiperVoice PiperVoice;

typedef struct PiperSynthesisConfig {
  float noiseScale;
  float lengthScale;
  float noiseW;

  int sampleRate;
  int sampleWidth;
  int channels;

  PiperSpeakerId speakerId;

  float sentenceSilenceSeconds;
} PiperSynthesisConfig;

typedef struct PiperSynthesisResult {
  double inferSeconds;
  double audioSeconds;
  double realTimeFactor;
} PiperSynthesisResult;

Piper *piperInitialize(const char *eSpeakDataPath);

void piperTerminate(Piper *piper);

PiperVoice *piperLoadVoice(Piper *piper, const char *modelPath, const char *modelConfigPath,
                           PiperSpeakerId speakerId, bool useCuda);

void piperFreeVoice(PiperVoice *voice);

void piperGetVoiceSynthesisConfig(const PiperVoice *voice, PiperSynthesisConfig *config);

void piperSetVoiceSynthesisConfig(PiperVoice *voice,
                                  const float *noiseScale,
                                  const float *lengthScale,
                                  const float *noiseW,
                                  const PiperSpeakerId *speakerId,
                                  const float *sentenceSilenceSeconds);

bool piperTextToAudio(Piper *piper, PiperVoice *voice, const char *text,
                      PiperSynthesisResult *result,
                      void *userData,
                      bool (*audioCallback)(const int16_t *data, size_t length, void *userData));

#ifdef __cplusplus
}
#endif

#endif /* PIPER_C_H_ */
