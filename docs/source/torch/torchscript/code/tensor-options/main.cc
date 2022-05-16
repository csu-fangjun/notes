#include "torch/script.h"

void TestConstructor() {
  // not recommended
  torch::TensorOptions opt1(torch::kCPU);
  torch::TensorOptions opt2(torch::Device(torch::kCPU));
  torch::TensorOptions opt3(torch::Device({torch::kCUDA, 1}));
  torch::TensorOptions opt4("cpu");
  // torch::TensorOptions opt5("CPU") // error;
  torch::TensorOptions opt6("cuda:1");
  // torch::TensorOptions opt7("CUDA:1"); // error

  // not recommended, from a scalar type (implicit)
  torch::TensorOptions opt8(torch::kInt32);
}

void TestConstructor2() {
  // recommended
  torch::TensorOptions opt1 = torch::dtype(torch::kFloat);
  torch::TensorOptions opt2 = torch::dtype(caffe2::TypeMeta::Make<float>());
  torch::TensorOptions opt3 = torch::device(torch::kCPU);
  torch::TensorOptions opt4 = torch::device({torch::kCUDA, 1});
  // Note: torch::device() returns a TensorOptions
  // while torch::Device() is the constructor of a class

  torch::TensorOptions opt5 = torch::requires_grad(true);
  std::cout << opt5 << "\n";
  // TensorOptions(dtype=float (default), device=cpu (default), layout=Strided
  // (default), requires_grad=true, pinned_memory=false (default),
  // memory_format=(nullopt))

  torch::TensorOptions opt6 = torch::dtype<float>();
  std::cout << torch::toString(opt6) << "\n";
  // TensorOptions(dtype=float, device=cpu (default), layout=Strided (default),
  // requires_grad=false (default), pinned_memory=false (default),
  // memory_format=(nullopt))

  std::cout << "default:" << torch::TensorOptions() << "\n";
  // default:TensorOptions(dtype=float (default), device=cpu (default),
  // layout=Strided (default), requires_grad=false (default),
  // pinned_memory=false (default), memory_format=(nullopt))
}

void TestMethods() {
  torch::TensorOptions opts = torch::dtype<float>();
  TORCH_CHECK(opts.device() == torch::Device(torch::kCPU));
  // It has not device_type()!
  TORCH_CHECK(opts.device() == torch::kCPU);
  TORCH_CHECK(opts.device().type() == torch::kCPU);
  TORCH_CHECK(opts.requires_grad() == false);

  torch::TensorOptions opts2 =
      opts.device("cuda:2").dtype(torch::kInt).requires_grad(false);

  TORCH_CHECK(opts2.dtype() == caffe2::TypeMeta::Make<int32_t>());
  TORCH_CHECK(opts2.dtype() == torch::kInt32);
  TORCH_CHECK(opts2.requires_grad() == false);
}

int main() {
  TestConstructor();
  TestConstructor2();
  return 0;
}
