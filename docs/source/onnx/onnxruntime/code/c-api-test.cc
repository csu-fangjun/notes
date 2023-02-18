#include "onnxruntime_c_api.h" // NOLINT
#include <stdio.h>

static void TestOrtApiBase() {
  const OrtApiBase *api_base = OrtGetApiBase();
  fprintf(stderr, "GetVersionString(): %s\n", api_base->GetVersionString());
}

void TestCApi() {
  TestOrtApiBase();
  //
}
