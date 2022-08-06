#include "torch/script.h"

static void TestHello() {
  // defined in
  // https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/core/interned_strings.h
  c10::Symbol s = c10::namespaces::prim;
  TORCH_CHECK(int(s) == 0);

  s = c10::namespaces::aten;
  s = c10::namespaces::cuda;
  s = c10::namespaces::onnx;
  s = c10::namespaces::scope;
  s = c10::namespaces::_caffe2;
  s = c10::namespaces::namespaces;

  s = c10::prim::Assign;
  TORCH_CHECK(int(s) == 10);

  s = c10::prim::Constant;
  s = c10::prim::device;
  s = c10::prim::dtype;

  s = c10::aten::Bool;
  s = c10::aten::sorted;

  s = c10::onnx::Add;

  int32_t max_num_symbols = int32_t(c10::_keys::num_symbols);

  // max num symbols: 1535. (as of 2022-08-02)
  std::cout << "max num symbols: " << max_num_symbols << "\n";
}

int main() {
  TestHello();
  return 0;
}
