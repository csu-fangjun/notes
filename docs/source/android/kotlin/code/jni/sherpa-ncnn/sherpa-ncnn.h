#ifndef SHERPA_NCNN_H_
#define SHERPA_NCNN_H_
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_SherpaNcnn_new(JNIEnv *env, jobject /*obj*/,
                                            jobject _model_config,
                                            jobject _fbank_config,
                                            jstring tokens);

JNIEXPORT void JNICALL Java_SherpaNcnn_delete(JNIEnv *env, jobject /*obj*/,
                                              jlong ptr);

JNIEXPORT void JNICALL Java_SherpaNcnn_decodeSamples(JNIEnv *env,
                                                     jobject /*obj*/, jlong ptr,
                                                     jfloatArray samples,
                                                     jfloat sample_rate);

JNIEXPORT void JNICALL Java_SherpaNcnn_inputFinished(JNIEnv *env,
                                                     jobject /*obj*/,
                                                     jlong ptr);

JNIEXPORT jbyteArray JNICALL Java_SherpaNcnn_getText(JNIEnv *env,
                                                     jobject /*obj*/,
                                                     jlong ptr);
#ifdef __cplusplus
}
#endif

#endif  // SHERPA_NCNN_H_
