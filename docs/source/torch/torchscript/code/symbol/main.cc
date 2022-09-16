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

  // c10::_keys is an enum class.
  int32_t max_num_symbols = int32_t(c10::_keys::num_symbols);

  // max num symbols: 1535. (as of 2022-08-02)
  std::cout << "max num symbols: " << max_num_symbols << "\n";

  c10::_keys k = c10::_keys::namespaces_prim;
  k = c10::_keys::namespaces_aten;
  k = c10::_keys::prim_Constant;
}

static void TestSymbol() {
  // Symbol contains only an integer, which is from an Enum
  c10::Symbol s = c10::Symbol::fromQualString("prim::Constant");
  TORCH_CHECK(s == c10::prim::Constant);
  TORCH_CHECK(s.is_prim() == true);
  TORCH_CHECK(s.is_aten() == false);
  TORCH_CHECK(s.ns() == c10::namespaces::prim);
  TORCH_CHECK(s.toUnqualString() == std::string("Constant"));
  TORCH_CHECK(s.toQualString() == std::string("prim::Constant"));

  TORCH_CHECK(s == c10::Symbol::prim("Constant"));

  // Register a new symbol
  // It will first register the namespace k2 as the symbol "namespaces::k2"
  s = c10::Symbol::fromQualString("k2::Foo");

  TORCH_CHECK(s.ns() == c10::Symbol::fromQualString("namespaces::k2"));
  TORCH_CHECK(s.toUnqualString() == std::string("Foo"));
  TORCH_CHECK(s.toQualString() == std::string("k2::Foo"));
}

int main() {
  TestHello();
  TestSymbol();
  return 0;
}
