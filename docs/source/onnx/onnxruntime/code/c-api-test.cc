#include "onnxruntime_c_api.h" // NOLINT
#include <cassert>
#include <stdio.h>

static void TestOrtStatus() {
  const OrtApiBase *api_base = OrtGetApiBase();
  const OrtApi *api = api_base->GetApi(ORT_API_VERSION);
  OrtErrorCode code = ORT_OK;
  const char *msg = "this is a message";

  OrtStatus *status = api->CreateStatus(code, msg);
  assert(api->GetErrorCode(status) == code);

  const char *msg2 = api->GetErrorMessage(status);
  assert(strcmp(msg, msg2) == 0);

  // status addr: 0x600001e54040, msg2 addr: 0x600001e54044
  fprintf(stderr, "status addr: %p, msg2 addr: %p\n", status, msg2);

  // note that sizeof(code) is 4 in my test
  assert((intptr_t)status + sizeof(code) == (intptr_t)msg2);

  // we have to free the status to avoid memory leak
  api->ReleaseStatus(status);
}

static void TestOrtApiBase() {

  // OrtApiBase only has two method
  const OrtApiBase *api_base = OrtGetApiBase();
  fprintf(stderr, "GetVersionString(): %s\n", api_base->GetVersionString());

  const OrtApi *api = api_base->GetApi(ORT_API_VERSION);
  fprintf(stderr, "OrtApi: %p\n", api);

  const char *info = api->GetBuildInfoString();
  fprintf(stderr, "info: %s\n", info);
}

void TestCApi() {
  TestOrtApiBase();
  TestOrtStatus();
}
