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

static void TestVectorOfTensor3() {
  torch::jit::Module m("m");
  m.define(R"(
    def forward(self, x: List[torch.Tensor]):
      return x[0] + x[1]
  )");

  std::vector<torch::Tensor> v;
  v.push_back(torch::tensor({1, 2}));
  v.push_back(torch::tensor({3, 4}));
  c10::List<torch::Tensor> ilist(v);

  c10::impl::GenericList generic_list = c10::impl::toList(ilist);

  c10::List<torch::Tensor> l2 =
      c10::impl::toTypedList<torch::Tensor>(generic_list);

  TORCH_CHECK(torch::allclose(l2[0], v[0]));
  TORCH_CHECK(torch::allclose(l2[1], v[1]));

  auto r = m.run_method("forward", generic_list);
  TORCH_CHECK(torch::allclose(r.toTensor(), v[0] + v[1]));

  // Note: We can pass a vector directly
  r = m.run_method("forward", v);
  TORCH_CHECK(torch::allclose(r.toTensor(), v[0] + v[1]));

  r = m.run_method("forward", ilist); // also OK
  TORCH_CHECK(torch::allclose(r.toTensor(), v[0] + v[1]));
}

static void TestVectorOfTensor4() {
  torch::jit::Module m("m");
  m.define(R"(
    def forward(self, x: Tuple[List[torch.Tensor]]):
      return x[0][0] + x[0][1]
  )");

  std::vector<torch::Tensor> v;
  v.push_back(torch::tensor({1, 2}));
  v.push_back(torch::tensor({3, 4}));
  auto t = torch::ivalue::Tuple::create(v);

  auto r = m.run_method("forward", t);
  TORCH_CHECK(torch::allclose(r.toTensor(), v[0] + v[1]));
}

static void TestVectorOfTensor5() {
  torch::jit::Module m("m");
  m.define(R"(
    def forward(self, x: Tuple[List[List[torch.Tensor]], List[torch.Tensor]]):
      return x[0][0][0] + x[0][0][1] + x[1][0] + x[1][1]
  )");

  std::vector<torch::Tensor> v;
  v.push_back(torch::tensor({1, 2}));
  v.push_back(torch::tensor({3, 4}));

  std::vector<std::vector<torch::Tensor>> vv;
  vv.push_back(v);
  vv.push_back(v);

  auto t = torch::ivalue::Tuple::create(vv, v);

  auto r = m.run_method("forward", t);
  TORCH_CHECK(torch::allclose(r.toTensor(), v[0] + v[1] + v[0] + v[1]));
}

static void TestVectorOfTensor6() {
  // List[List[Tensor]]
  std::vector<torch::Tensor> v;
  v.push_back(torch::tensor({1, 2}));
  v.push_back(torch::tensor({3, 4}));

  c10::List<torch::Tensor> ilist(v);
  torch::IValue ivalue(ilist);
  TORCH_CHECK(ivalue.tagKind() == "GenericList");

  c10::List<c10::List<torch::Tensor>> ilist2(ilist);
  ilist2.push_back(ilist);
  ilist2.push_back(ilist);

  torch::IValue ivalue2(ilist2);
  TORCH_CHECK(ivalue2.tagKind() == "GenericList");

  c10::List<torch::IValue> a0 = ivalue2.toList();
  c10::List<c10::List<torch::Tensor>> a1 =
      c10::impl::toTypedList<c10::List<torch::Tensor>>(a0);

  c10::ArrayRef<torch::IValue> a = ivalue2.toListRef();

  torch::List<torch::Tensor> b =
      c10::impl::toTypedList<torch::Tensor>(a[0].toList());
  for (int32_t i = 0; i != b.size(); ++i) {
    std::cout << b[i] << "\n";
  }
  std::vector<std::vector<torch::Tensor>> v2{v};
  torch::List<torch::List<torch::Tensor>> c;
  for (auto k : v2) {
    c10::List<torch::Tensor> dd{torch::ArrayRef<torch::Tensor>(k)};
    c.push_back(std::move(dd));
  }
}

int main() {
  TestVectorOfTensor();
  TestVectorOfTensor2();
  TestVectorOfTensor3();
  TestVectorOfTensor4();
  TestVectorOfTensor5();
  TestVectorOfTensor6();
  return 0;
}
