#ifndef ONLINE_FEATURE_H_
#define ONLINE_FEATURE_H_
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_OnlineFbank_new(JNIEnv *env, jobject obj,
                                             jobject opts);

JNIEXPORT void JNICALL Java_OnlineFbank_delete(JNIEnv *env, jobject obj,
                                               jlong ptr);

JNIEXPORT jint JNICALL Java_OnlineFbank_dim(JNIEnv *env, jobject obj,
                                            jlong ptr);

JNIEXPORT jfloat JNICALL Java_OnlineFbank_frameShiftInSeconds(JNIEnv *env,
                                                              jobject obj,
                                                              jlong ptr);

JNIEXPORT jint JNICALL Java_OnlineFbank_numFramesReady(JNIEnv *env, jobject obj,
                                                       jlong ptr);

JNIEXPORT jboolean JNICALL Java_OnlineFbank_isLastFrame(JNIEnv *env,
                                                        jobject obj, jlong ptr,
                                                        jint i);

JNIEXPORT void JNICALL Java_OnlineFbank_inputFinished(JNIEnv *env, jobject obj,
                                                      jlong ptr);

JNIEXPORT void JNICALL Java_OnlineFbank_acceptWaveform(JNIEnv *env, jobject obj,
                                                       jlong ptr,
                                                       jfloatArray samples,
                                                       jfloat sample_rate);

JNIEXPORT jfloatArray JNICALL Java_OnlineFbank_getFrame(JNIEnv *env,
                                                        jobject obj, jlong ptr,
                                                        jint i);

#ifdef __cplusplus
}
#endif

#endif // ONLINE_FEATURE_H_
