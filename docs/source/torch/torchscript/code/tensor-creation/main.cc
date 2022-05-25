#include "torch/script.h"

static void FromStdVecotr() {
  torch::Tensor t1 = torch::tensor(std::vector<int32_t>{1, 2, 3});
  TORCH_CHECK(t1.scalar_type() == torch::kLong);
  t1 = t1.to(torch::kInt);
  const int32_t *p1 = t1.data_ptr<int32_t>();
  TORCH_CHECK(p1[0] == 1);
  TORCH_CHECK(p1[1] == 2);
  TORCH_CHECK(p1[2] == 3);

  torch::Tensor t2 = torch::tensor(std::vector<float>{1, 2, 3});
  TORCH_CHECK(t2.scalar_type() == torch::kFloat);

  torch::Tensor t3 =
      torch::tensor(std::vector<double>{1, 2, 3}, torch::kDouble);
  TORCH_CHECK(t3.scalar_type() == torch::kDouble);

  torch::Tensor t4 =
      torch::tensor(std::vector<double>{1, 2, 3},
                    torch::dtype(torch::kDouble).device("cuda:0"));
  TORCH_CHECK(t4.is_cuda());
}

static void FromScalar() {
  torch::Tensor t = torch::tensor(3);
  TORCH_CHECK(t.item<int64_t>() == 3);

  torch::Tensor t2 = torch::tensor(0.5);
  TORCH_CHECK(t2.scalar_type() == torch::kFloat);
}

static void FromInitializerList() {
  torch::Tensor t1 = torch::tensor({1, 2, 3});
  torch::Tensor t2 = torch::tensor(std::vector<int32_t>{1, 2, 3});
  TORCH_CHECK(torch::allclose(t1, t2));

  torch::Tensor t3 = torch::tensor({{1, 2, 3}, {4, 5, 6}});
  TORCH_CHECK(t3.dim() == 2);

  torch::Tensor t4 = torch::tensor({1, 2, 3});
  torch::Tensor t5 = torch::tensor({4, 5, 6});
  TORCH_CHECK(torch::allclose(t3[0], t4));
  TORCH_CHECK(torch::allclose(t3[1], t5));
}

static void FromArrayRef() {
  int32_t i[] = {1, 2, 3};
  torch::ArrayRef<int32_t> a(i);
  torch::Tensor t = torch::tensor(a);
  // Data is copied to t

  TORCH_CHECK(t[0].item<int64_t>(), 1);
  TORCH_CHECK(t[1].item<int64_t>(), 2);
  TORCH_CHECK(t[2].item<int64_t>(), 3);
}

int main() {
  // FromStdVecotr();
  FromScalar();
  FromInitializerList();
  FromArrayRef();
  return 0;
}
