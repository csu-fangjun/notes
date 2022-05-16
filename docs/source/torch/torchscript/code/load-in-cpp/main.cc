#include "torch/script.h"

int main() {
  // see torch/csrc/jit/module.h
  torch::jit::Module m = torch::jit::load("../foo.pt");
  std::cout << "is training: " << m.is_training() << "\n";
  m.eval();
  std::cout << "after m.eval(): is training: " << m.is_training() << "\n";
  torch::Tensor x = torch::tensor({1, 2, 3}, torch::kFloat);
  torch::Tensor y = m.run_method("baz", x).toTensor();
  std::cout << y << "\n";

  return 0;
}
