#include "torch/script.h"

int main(int argc, char *argv[]) {
  TORCH_CHECK(argc == 2, "argc is ", argc);
  std::cout << "Loading " << argv[1] << "\n";
  auto m = torch::jit::load(argv[1]);
  auto graph = m.get_method("forward").graph();
  for (const auto &n : graph->nodes()) {
    std::cout << "kind: " << n->kind().toDisplayString() << "\n";
  }
  return 0;
}
