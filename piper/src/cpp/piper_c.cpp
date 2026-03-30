#include "piper_c.h"
#include "piper.hpp"
#include <spdlog/spdlog.h>

struct Piper {
  piper::PiperConfig config;
};

struct PiperVoice {
  piper::Voice voice;
};

Piper *piperInitialize(const char *eSpeakDataPath) {
  Piper *piper = new Piper;

  if (eSpeakDataPath)
    piper->config.eSpeakDataPath = eSpeakDataPath;

  try {
    piper::initialize(piper->config);
  } catch (...) {
    delete piper;
    return NULL;
  }


  return piper;
}

void piperTerminate(Piper *piper) {
  piper::terminate(piper->config);
  delete piper;
}

PiperVoice *piperLoadVoice(Piper *piper, const char *modelPath, const char *modelConfigPath,
                           PiperSpeakerId speakerId, bool useCuda) {
  PiperVoice *voice = new PiperVoice;

  std::optional<piper::SpeakerId> speakerIdOpt(speakerId);
  std::string modelConfigPathStr;

  if (modelConfigPath)
    modelConfigPathStr = modelConfigPath;
  else
    modelConfigPathStr = modelPath + std::string(".json");

  try {
    piper::loadVoice(piper->config, modelPath, modelConfigPathStr,
                     voice->voice, speakerIdOpt, useCuda);
  } catch (...) {
    delete voice;
    return NULL;
  }

  return voice;
}

void piperFreeVoice(PiperVoice *voice) {
  delete voice;
}

void piperGetVoiceSynthesisConfig(const PiperVoice *voice, PiperSynthesisConfig *config) {
  config->noiseScale  = voice->voice.synthesisConfig.noiseScale;
  config->lengthScale = voice->voice.synthesisConfig.lengthScale;
  config->noiseW      = voice->voice.synthesisConfig.noiseW;

  config->sampleRate  = voice->voice.synthesisConfig.sampleRate;
  config->sampleWidth = voice->voice.synthesisConfig.sampleWidth;
  config->channels    = voice->voice.synthesisConfig.channels;

  config->speakerId = voice->voice.synthesisConfig.speakerId.value_or(0);

  config->sentenceSilenceSeconds = voice->voice.synthesisConfig.sentenceSilenceSeconds;
}

void piperSetVoiceSynthesisConfig(PiperVoice *voice,
                                  const float *noiseScale,
                                  const float *lengthScale,
                                  const float *noiseW,
                                  const PiperSpeakerId *speakerId,
                                  const float *sentenceSilenceSeconds) {
    if (noiseScale) voice->voice.synthesisConfig.noiseScale = *noiseScale;
    if (lengthScale) voice->voice.synthesisConfig.lengthScale = *lengthScale;
    if (noiseW) voice->voice.synthesisConfig.noiseW = *noiseW;

    if (speakerId) voice->voice.synthesisConfig.speakerId = *speakerId;

    if (sentenceSilenceSeconds)
        voice->voice.synthesisConfig.sentenceSilenceSeconds = *sentenceSilenceSeconds;
}

bool piperTextToAudio(Piper *piper, PiperVoice *voice, const char *text,
                      PiperSynthesisResult *result, void *userData,
                      bool (*audioCallback)(const int16_t *data, size_t length, void *userData)) {
  std::vector<int16_t> audioBuffer;
  piper::SynthesisResult synthesisResult;

  try {
    piper::textToAudio(piper->config, voice->voice, text, audioBuffer, synthesisResult,
                       [&]() { return audioCallback(audioBuffer.data(), audioBuffer.size(), userData); });
  } catch (...) {
    return false;
  }

  if (result) {
    result->inferSeconds = synthesisResult.inferSeconds;
    result->audioSeconds = synthesisResult.audioSeconds;
    result->realTimeFactor = synthesisResult.realTimeFactor;
  }

  return true;
}
