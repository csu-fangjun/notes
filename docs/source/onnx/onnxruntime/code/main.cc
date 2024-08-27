#include <iostream>

#include "onnxruntime_cxx_api.h" // NOLINT

void TestCApi();
void TestCppApi();
void TestCustomModel();

int main() {
  TestCApi();
  TestCppApi();

  TestCustomModel();

  std::cout << "ORT_API_VERSION: " << ORT_API_VERSION << "\n";
  return 0;
}
