// #include "ATen/native/quantized/cpu/QuantUtils.h" // for the latest pytorch

#include "ATen/native/quantized/cpu/quant_utils.h" // for torch 1.10
#include "ATen/ops/quantize_per_tensor_dynamic.h"  // needs torch>=1.11
#include "torch/script.h"

// See
// https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/cpu/QuantUtils.h#L59
static void TestChooseQuantizationParams() {
  quant_utils::TensorQuantizationParams p;
  p = quant_utils::ChooseQuantizationParams(-1 /*min*/, 2 /*max*/,
                                            -128 /*qmin*/, 127 /*qmax*/);
  std::cout << "zero_point: " << p.zero_point << "\n";
  std::cout << "scale: " << p.scale << "\n";
  /**
   * scale = (max - min) / (qmax - qmin) = 3 / 255 = 0.0117647
   * zero_point_min = qmin - min/scale = -128 - (-1)/scale = -43
   * zero_point_max = qmax - max/scale = 127 - 2/scale = -43
   *
   * min_error = abs(qmin) -abs(min/scale) = 128 - 1/scale = 43
   * max_error = abs(qmax) - abs(max/scale) = 127 - 2/scale = -43
   *
   * zero_point =  (min_error < max_error) ? zero_point_min : zero_point_max
   */
}

// See
// https://github.com/pytorch/pytorch/blob/master/aten/src/ATen/native/quantized/QTensor.cpp#L14
// and
static void TestQuantizePerTensorDynamic() {
  torch::Tensor r = torch::tensor({-1, 0, 2}, torch::kFloat32);
  torch::Tensor q = torch::quantize_per_tensor_dynamic(r, torch::kQInt8, false);
  std::cout << "q: " << q << "\n";
#if 0
q: -1
 0
 2
[ QuantizedCPUQInt8Type{3}, qscheme: per_tensor_affine, scale: 0.0117647, zero_point: -43 ]
#endif
  std::cout << "q.int_repr(): " << q.int_repr() << "\n";
#if 0
q.int_repr(): -128
 -43
 127
[ CPUCharType{3} ]
#endif
}

int main() {
  TestChooseQuantizationParams();
  TestQuantizePerTensorDynamic();
  return 0;
}
