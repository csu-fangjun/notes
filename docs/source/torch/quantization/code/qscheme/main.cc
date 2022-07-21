#include "torch/script.h"

static void TestQScheme() {
  TORCH_CHECK(torch::toString(torch::kPerTensorAffine) == "per_tensor_affine");

  TORCH_CHECK(torch::toString(torch::kPerChannelAffine) ==
              "per_channel_affine");

  TORCH_CHECK(torch::toString(torch::kPerTensorSymmetric) ==
              "per_tensor_symmetric");

  TORCH_CHECK(torch::toString(torch::kPerChannelSymmetric) ==
              "per_channel_symmetric");

  TORCH_CHECK(torch::toString(torch::kPerChannelAffineFloatQParams) ==
              "per_channel_affine_float_qparams");
}

int main() {
  TestQScheme();
  return 0;
}
