#include "torch/script.h"

static void TestSize() {
  static_assert(sizeof(caffe2::TypeMeta) == sizeof(int16_t), "");
}

static void TestConstructor() {
  caffe2::TypeMeta t = caffe2::TypeMeta::Make<int32_t>();
  TORCH_CHECK(t.Match<int32_t>());

  TORCH_CHECK(t.isScalarType());

  TORCH_CHECK(t.isScalarType(torch::kInt));
  TORCH_CHECK(t.isScalarType(torch::kFloat) == false);

  TORCH_CHECK(t.name() == "int");
}

static void TestFromScalarType() {
  caffe2::TypeMeta t = caffe2::TypeMeta::fromScalarType(torch::kDouble);

  TORCH_CHECK(t.isScalarType(torch::kDouble));
  TORCH_CHECK(t.name() == "double");

  TORCH_CHECK(t.toScalarType() == torch::kDouble);
  TORCH_CHECK(t == torch::kDouble);
  TORCH_CHECK(t != torch::kFloat);
  TORCH_CHECK(torch::kInt != t);

  TORCH_CHECK(torch::scalarTypeToTypeMeta(torch::kFloat) ==
              caffe2::TypeMeta::Make<float>());
}

int main() {
  TestSize();
  TestConstructor();
  TestFromScalarType();
  return 0;
}
