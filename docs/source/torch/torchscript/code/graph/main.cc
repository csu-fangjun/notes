#include "torch/script.h"

static void TestConv2d() {
  torch::jit::Module m("m");
  m.define(R"(
    def __init__(self):
      self.conv = torch.nn.Conv2d(2, 3)
    def forward(self, x: torch.Tensor):
      return self.conv(x)
  )");
  torch::jit::Method method = m.get_method("forward");
  std::shared_ptr<torch::jit::Graph> g = method.graph();
  torch::ArrayRef<torch::jit::Value *> inputs = g->inputs();
  torch::ArrayRef<torch::jit::Value *> outputs = g->outputs();
  TORCH_CHECK(inputs.size() == 1);
  TORCH_CHECK(outputs.size() == 1);

  torch::jit::Value *in = inputs[0];
  std::cout << in->type()->str() << "\n";
  std::cout << in->debugName() << "\n";
}

int main() {
  TestConv2d();
  return 0;
}
