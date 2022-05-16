#include "torch/script.h"

struct Foo {
  const int32_t *p;
  size_t len;
};

static void TestSize() {
  // Note: The data pointer in ArrayRef is const!
  static_assert(sizeof(torch::ArrayRef<int32_t>) == sizeof(Foo), "");
}

static void TestDefaultConstructor() {
  torch::ArrayRef<int32_t> a;
  TORCH_CHECK(a.data() == nullptr);
  TORCH_CHECK(a.size() == 0);
  TORCH_CHECK(a.empty() == true);

  TORCH_CHECK(a.begin() == nullptr);
  TORCH_CHECK(a.end() == nullptr);
}

static void TestFromSingleElement() {
  int32_t a = 10;
  torch::ArrayRef<int32_t> b(a);
  TORCH_CHECK(b[0] == a);
  TORCH_CHECK(b.data() == &a);
  TORCH_CHECK(b.size() == 1);
}

static void TestFromInitializerList() {
  torch::ArrayRef<int32_t> a = {1, 2, 3};
  TORCH_CHECK(a.size() == 3);
  TORCH_CHECK(a[0] == 1);
  TORCH_CHECK(a[1] == 2);
  TORCH_CHECK(a[2] == 3);
}

int main() {
  TestSize();
  TestDefaultConstructor();
  TestFromSingleElement();
  TestFromInitializerList();
  return 0;
}
