#include "torch/script.h"

static void TestHello() {
  torch::jit::Module m("m");
  m.define(R"(
    def forward(self, x: torch.Tensor, y: torch.Tensor):
      return x + y
  )");

  torch::jit::Method method = m.get_method("forward");
  TORCH_CHECK(method.name() == "forward");

  const std::vector<std::string> &names = method.getArgumentNames();
  TORCH_CHECK(names.size() == 2);
  TORCH_CHECK(names[0] == "x");
  TORCH_CHECK(names[1] == "y");

  std::vector<torch::IValue> args;
  auto x = torch::tensor({1, 2});
  auto y = torch::tensor({1, 2});
  args.emplace_back(x);
  args.emplace_back(y);
  auto z = method(args).toTensor();

  TORCH_CHECK(torch::equal(z, x + y));

  std::shared_ptr<torch::jit::Graph> g = method.graph();
  // see graph/main.cc
}

int main() {
  TestHello();
  return 0;
}
