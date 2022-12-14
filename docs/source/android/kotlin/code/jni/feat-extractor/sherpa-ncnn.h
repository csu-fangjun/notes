#ifndef SHERPA_NCNN_H_
#define SHERPA_NCNN_H_
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jfloatArray JNICALL Java_WaveReader_00024Companion_readWave(
    JNIEnv *env, jclass cls, jstring filename, jfloat expected_sample_rate);

JNIEXPORT jlong JNICALL Java_Model_new(JNIEnv *env, jobject /*obj*/,
                                       jobject config);

JNIEXPORT void JNICALL Java_Model_delete(JNIEnv *env, jobject /*obj*/,
                                         jlong ptr);

JNIEXPORT jint JNICALL Java_Model_segment(JNIEnv *env, jobject /*obj*/,
                                          jlong ptr);

JNIEXPORT jint JNICALL Java_Model_offset(JNIEnv *env, jobject /*obj*/,
                                         jlong ptr);

#ifdef __cplusplus
}
#endif

#endif // SHERPA_NCNN_H_
