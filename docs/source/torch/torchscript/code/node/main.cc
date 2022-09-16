#include "torch/csrc/jit/passes/quantization/helper.h" // for removeTorchMangle
#include "torch/script.h"

static void TestRemoveTorchMangle() {
  std::string s = torch::jit::removeTorchMangle("a.___torch_mangle_1.foo");
  TORCH_CHECK(s == "a.foo");

  s = torch::jit::removeTorchMangle("a.___torch_mangle_123.foo");
  TORCH_CHECK(s == "a.foo");
}

static void TestSimple() {
  torch::jit::Module m("m");
  m.define(R"(
    def forward(self, x: torch.Tensor, y: torch.Tensor):
      a = x + 2
      b = y * 3
      return a + b
  )");
  std::shared_ptr<torch::jit::Graph> graph = m.get_method("forward").graph();
  std::cout << "graph string: \n" << graph->toString() << "\n";
  // Or we can use graph->dump();
  torch::jit::Block *block = graph->block();
  for (auto it = block->nodes().begin(), end = block->nodes().end();
       it != end;) {
    torch::jit::Node *n = *it++;
    torch::jit::NodeKind k = n->kind();
    std::cout << "node kind: " << k << " " << k.toQualString() << "\n";
  }
#if 0
graph string:
graph(%self : __torch__.m,
      %x.1 : Tensor,
      %y.1 : Tensor):
  %5 : int = prim::Constant[value=1]()
  %4 : int = prim::Constant[value=2]() # <string>:3:14
  %8 : int = prim::Constant[value=3]() # <string>:4:14
  %a.1 : Tensor = aten::add(%x.1, %4, %5) # <string>:3:10
  %b.1 : Tensor = aten::mul(%y.1, %8) # <string>:4:10
  %13 : Tensor = aten::add(%a.1, %b.1, %5) # <string>:5:13
  return (%13)

node kind: 14 prim::Constant
node kind: 14 prim::Constant
node kind: 14 prim::Constant
node kind: 534 aten::add
node kind: 241 aten::mul
node kind: 534 aten::add
#endif
}

static void TestFunctionCall() {
  torch::jit::Module m("m");
  m.define(R"(
    def add(self, x: torch.Tensor, y: torch.Tensor):
      '''my add doc'''
      return x + y + 3

    def forward(self, x: torch.Tensor, y: torch.Tensor):
      c = self.add(x, y)
      return c
  )");
  std::shared_ptr<torch::jit::Graph> graph = m.get_method("forward").graph();
  std::cout << "graph string: \n" << graph->toString() << "\n";
  torch::jit::Block *block = graph->block();
  for (auto it = block->nodes().begin(), end = block->nodes().end();
       it != end;) {
    torch::jit::Node *n = *it++;
    torch::jit::NodeKind k = n->kind();
    std::cout << "node kind: " << k << " " << k.toQualString() << "\n";
  }
#if 0
graph string:
graph(%self.1 : __torch__.m,
      %x.1 : Tensor,
      %y.1 : Tensor):
  %c.1 : Tensor = prim::CallMethod[name="add"](%self.1, %x.1, %y.1) # <string>:6:10
  return (%c.1)

node kind: 149 prim::CallMethod
#endif
  for (auto it = block->nodes().begin(), end = block->nodes().end();
       it != end;) {
    torch::jit::Node *n = *it++;
    torch::jit::NodeKind k = n->kind();
    if (k == c10::prim::CallMethod) {
      torch::ArrayRef<torch::jit::Value *> inputs = n->inputs();
      TORCH_CHECK(inputs.size() == 3);

      torch::jit::TypePtr type = inputs[0]->type();

      auto class_type = type->cast<torch::jit::ClassType>();
      TORCH_CHECK(class_type->str() == "__torch__.m");
      if (!class_type) {
        std::cout << "Not a class type: " << type->str() << "\n";
        continue;
      }
      // defined by the macro "CREATE_ACCESSOR()" in ir/ir.h
      const std::string &function_name = n->s(c10::attr::name);
      // const std::string &function_name = n->s(torch::jit::attr::name);
      TORCH_CHECK(function_name == "add");

      TORCH_CHECK(torch::jit::attr::name == c10::attr::name);

      torch::jit::Function &function = class_type->getMethod(function_name);
      if (!function.isGraphFunction()) {
        std::cout << function_name << " is not a graph function"
                  << "\n";
        continue;
      }
      std::string class_type_str =
          torch::jit::removeTorchMangle(class_type->str());
      // remove __torch__., which is 10 characters long
      std::string no_torch_class_type_str = class_type_str.substr(10);
    }
  }
}

int main() {
  // TestRemoveTorchMangle();
  // TestSimple();
  TestFunctionCall();
  return 0;
}
