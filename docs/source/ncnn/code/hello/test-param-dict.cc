#include "paramdict.h"
#ifndef MY_CHECK
#define MY_CHECK(x, y)                                                         \
  do {                                                                         \
    if (x != y) {                                                              \
      NCNN_LOGE(#x " != " #y);                                                 \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)
#endif

/*
It has an array of struct.
The size of the array is 32, so the maximum number of parameters is 32
 */
void TestParamDict() {
  NCNN_LOGE("Test param dict\n");
  ncnn::ParamDict pd;

  // int 2
  pd.set(0, 10);
  MY_CHECK(pd.type(0), 2);
  MY_CHECK(pd.get(0, 0), 10);

  // float 3
  pd.set(1, 10.5f);
  MY_CHECK(pd.type(1), 3);
  // Caution: The type of the default value (the second argument) is very
  // important. It determines which overload to invoke
  MY_CHECK(pd.get(1, 0.f), 10.5);

  // mat 4
  ncnn::Mat m(1);
  m[0] = 10.25;
  pd.set(2, m);
  MY_CHECK(pd.type(2), 4);
  MY_CHECK(pd.get(2, ncnn::Mat())[0], 10.25);
}
