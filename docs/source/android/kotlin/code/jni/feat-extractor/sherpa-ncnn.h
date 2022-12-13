#ifndef SHERPA_NCNN_H_
#define SHERPA_NCNN_H_
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jfloatArray JNICALL Java_WaveReader_00024Companion_readWave(
    JNIEnv *env, jclass cls, jstring filename, jfloat expected_sample_rate);

#ifdef __cplusplus
}
#endif

#endif // SHERPA_NCNN_H_
