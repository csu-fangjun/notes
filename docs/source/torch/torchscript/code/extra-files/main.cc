#include "torch/script.h"

std::vector<float> ToFloat(const std::string &s) {
  const float *p = reinterpret_cast<const float *>(s.data());
  int32_t n = s.size() / 4;

  // assume little endian
  return {p, p + n};
}

int main() {
  // see torch/csrc/jit/module.h
  // see
  // https://github.com/pytorch/pytorch/blob/main/test/cpp/jit/test_save_load.cpp#L76
  torch::jit::ExtraFilesMap extra_files{{"window_size", ""},
                                        {"cmvn_mean", ""},
                                        {"cmvn_inv_std", ""},
                                        {"cmvn_dim", ""}};
  torch::jit::Module m = torch::jit::load("./m.pt", torch::kCPU, extra_files);

  int32_t dim = atoi(extra_files["cmvn_dim"].c_str());
  if (dim != extra_files["cmvn_mean"].size() / 4 ||
      dim != extra_files["cmvn_inv_std"].size() / 4) {
    std::cout << "corrupted data!\n";
    return -1;
  }

  auto cmvn_mean = ToFloat(extra_files["cmvn_mean"]);
  auto cmvn_inv_std = ToFloat(extra_files["cmvn_inv_std"]);
  int32_t window_size = atoi(extra_files["window_size"].c_str());
  std::cout << "int window size: " << window_size << "\n";

  for (const auto &p : extra_files) {
    std::cout << p.first << ": " << p.second << "\n";
  }
  std::cout << "cmvn_mean: ";
  for (auto f : cmvn_mean) {
    std::cout << f << " ";
  }
  std::cout << "\n";

  std::cout << "cmvn_inv_std: ";
  for (auto f : cmvn_inv_std) {
    std::cout << f << " ";
  }
  std::cout << "\n";

  std::cout << "is training: " << m.is_training() << "\n";
  m.eval();
  std::cout << "after m.eval(): is training: " << m.is_training() << "\n";
  torch::Tensor x = torch::tensor({1, 2, 3}, torch::kFloat);
  torch::Tensor y = m.run_method("forward", x).toTensor();
  std::cout << y << "\n";

  return 0;
}
/*
int window size: 20
cmvn_inv_std:  @aCC
cmvn_mean: ?@33s
cmvn_dim: 3
window_size: 20
cmvn_mean: 1.5 2.25 -3.8
cmvn_inv_std: 2.5 225 380
is training: 1
after m.eval(): is training: 0
 3.5000
 4.5000
 5.5000
[ CPUFloatType{3} ]
 */
