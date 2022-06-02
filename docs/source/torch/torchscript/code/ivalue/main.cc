#include "torch/script.h"

static void TestVectorOfTensor() {
  torch::jit::Module m("m");
  m.define(R"(
    def forward(self, x, y):
      return [x, y]
  )");
  auto x = torch::tensor({1, 2, 3});
  auto y = torch::tensor({4, 5, 6});
  auto i = m.run_method("forward", x, y);

  assert(i.tagKind() == "GenericList");

  torch::ArrayRef<torch::IValue> tensor_list = i.toListRef();
  TORCH_CHECK(torch::allclose(x, tensor_list[0].toTensor()));
  TORCH_CHECK(torch::allclose(y, tensor_list[1].toTensor()));

  torch::List<torch::IValue> k = i.toList();

  torch::List<torch::Tensor> o =
      c10::impl::toTypedList<torch::Tensor>(std::move(k));

  TORCH_CHECK(torch::allclose(o[0], x));
  TORCH_CHECK(torch::allclose(o[1], y));

  std::vector<torch::Tensor> p = o.vec();
  TORCH_CHECK(torch::allclose(p[0], x));
  TORCH_CHECK(torch::allclose(p[1], y));
}

static void TestVectorOfTensor2() {
  torch::jit::Module m("m");
  m.define(R"(
    def forward(self, x):
      return [[x], [x,x]]
  )");
  auto x = torch::tensor({1, 2, 3});
  auto i = m.run_method("forward", x);
  TORCH_CHECK(i.tagKind() == "GenericList");

  torch::List<torch::IValue> list = i.toList();
  torch::Tensor a = list.get(0).toListRef()[0].toTensor();
  TORCH_CHECK(torch::allclose(a, x));

  std::vector<torch::Tensor> b =
      c10::impl::toTypedList<torch::Tensor>(list.get(1).toList()).vec();
  TORCH_CHECK(torch::allclose(b[0], x));
  TORCH_CHECK(torch::allclose(b[1], x));
}

int main() {
  TestVectorOfTensor();
  TestVectorOfTensor2();
  return 0;
}
