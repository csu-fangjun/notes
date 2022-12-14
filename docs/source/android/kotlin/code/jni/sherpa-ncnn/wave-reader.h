#ifndef WAVE_READER_H_
#define WAVE_READER_H_
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jfloatArray JNICALL Java_WaveReader_00024Companion_readWave(
    JNIEnv *env, jclass /*cls*/, jstring filename, jfloat expected_sample_rate);

#ifdef __cplusplus
}
#endif

#endif  // WAVE_READER_H_
