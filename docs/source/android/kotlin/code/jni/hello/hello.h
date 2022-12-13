#ifndef HELLO_H
#define HELLO_H
#include "jni.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_NativeSample_sayHello(JNIEnv *env, jobject obj);

#ifdef __cplusplus
}
#endif

#endif // HELLO_H
