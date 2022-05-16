#include "torch/script.h"

void TestDeviceType() {
  torch::DeviceType d = torch::kCPU;
  std::ostringstream os;
  os << d;
  TORCH_CHECK(os.str() == "cpu");

  TORCH_CHECK(DeviceTypeName(d /*,lower_case=false*/) == "CPU");
  TORCH_CHECK(DeviceTypeName(d, /*lower_case*/ true) == "cpu");
}

void TestDeviceConstructorCPU() {
  torch::Device d(torch::kCPU);
  TORCH_CHECK(d.is_cpu() == true);
  TORCH_CHECK(d.is_cuda() == false);
  TORCH_CHECK(d.type() == torch::kCPU);
  TORCH_CHECK(d.has_index() == false);
  TORCH_CHECK(d.index() == -1);
  TORCH_CHECK(d.str() == "cpu");
}

void TestDeviceConstructorCUDA() {
  torch::Device d(torch::kCUDA, 3);
  TORCH_CHECK(d.is_cpu() == false);
  TORCH_CHECK(d.is_cuda() == true);
  TORCH_CHECK(d.type() == torch::kCUDA);
  TORCH_CHECK(d.has_index() == true);
  TORCH_CHECK(d.index() == 3);
  TORCH_CHECK(d.str() == "cuda:3");

  d.set_index(2);
  TORCH_CHECK(d.index() == 2);
  TORCH_CHECK(d.str() == "cuda:2");

  d = torch::Device("cpu");
  TORCH_CHECK(d.is_cpu() == true);

  d = torch::Device("CPU");
  TORCH_CHECK(d.is_cpu() == true);

  d = torch::Device("cuda:1");
  TORCH_CHECK(d.is_cuda() == true);
  TORCH_CHECK(d.index() == 1);

  d = torch::Device("CUDA:1");
  TORCH_CHECK(d.is_cuda() == true);
  TORCH_CHECK(d.index() == 1);
}

int main() {
  TestDeviceType();
  TestDeviceConstructorCPU();
  return 0;
}
