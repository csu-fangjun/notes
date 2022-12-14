#include "hello.h"

JNIEXPORT void JNICALL Java_NativeSample_sayHello(JNIEnv *env, jobject obj) {
  std::cout << "hello world\n";
}

JNIEXPORT jfloat JNICALL Java_NativeSample_sum(JNIEnv *env, jobject obj,
                                               jfloatArray array) {
  // the last arg is set to nullptr, which means we are not interested
  // in whether the returned pointer points to a copied region or not.
  jfloat *p = env->GetFloatArrayElements(array, nullptr);
  jsize n = env->GetArrayLength(array);

  jfloat s = 0;
  for (int32_t i = 0; i != n; ++i) {
    s += p[i];
  }
  // See
  // https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/functions.html
  // JNI_ABORT: means to free the buffer pointed by p but don't copy the
  // buffer to array
  env->ReleaseFloatArrayElements(array, p, JNI_ABORT);

  return s;
}
