#include <iostream>

#include "onnxruntime_cxx_api.h" // NOLINT

void TestCApi();
void TestCppApi();
void TestCustomModel();
void TestCustomModel2();
void TestCustomModel3();

int main() {
  TestCApi();
  TestCppApi();

  std::cout << "---test custom model---\n";
  TestCustomModel();

  std::cout << "---test custom model2---\n";
  TestCustomModel2();

  std::cout << "---test custom model3---\n";
  TestCustomModel3();

  std::cout << "ORT_API_VERSION: " << ORT_API_VERSION << "\n";
  return 0;
}
/*
GetVersionString(): 1.18.0
Available providers: CoreMLExecutionProvider, CPUExecutionProvider
allocator name: Cpu
---test custom model---
110
 220
 330
 ---test custom model2---
11.5
 2.5
 3.5
 44.5
 ---test custom model3---
11
 22
 ORT_API_VERSION: 18
 */
