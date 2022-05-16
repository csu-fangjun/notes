#include "c10/core/ScalarType.h"
#include "torch/script.h"
#include <type_traits>

static void TestScalarTypeToCppType() {
  static_assert(
      std::is_same<
          int32_t, //
          c10::impl::ScalarTypeToCPPType<c10 ::ScalarType::Int>::type>::value,
      "");
}

static void TestCppTypeToScalarType() {
  static_assert(
      c10::CppTypeToScalarType<float>::value == c10::ScalarType::Float, "");
}

static void TestAlias() {
  static_assert(c10::ScalarType::Int == c10::kInt, "");
  static_assert(c10::ScalarType::Byte == c10::kByte, "");
}

int main() {
  TestScalarTypeToCppType();
  TestCppTypeToScalarType();
  TestAlias();
  return 0;
}
