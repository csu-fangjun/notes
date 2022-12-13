#ifndef ONLINE_FEATURE_H_
#define ONLINE_FEATURE_H_
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_FbankComputer_new(JNIEnv *env, jobject obj,
                                               jobject opts);

JNIEXPORT void JNICALL Java_FbankComputer_delete(JNIEnv *env, jobject obj,
                                                 jlong ptr);

#ifdef __cplusplus
}
#endif

#endif // ONLINE_FEATURE_H_
