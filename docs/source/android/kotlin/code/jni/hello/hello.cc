#include "hello.h"
#include <iostream>

JNIEXPORT void JNICALL Java_NativeSample_sayHello(JNIEnv *env, jobject obj) {
  std::cout << "hello world\n";
}
