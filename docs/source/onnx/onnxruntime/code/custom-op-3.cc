/*
references:
https://onnxruntime.ai/docs/reference/operators/add-custom-op.html

 */
#include "onnxruntime_lite_custom_op.h"
#include <iostream>
#include <utility>
#include <vector>

static void KernelOne(const Ort::Custom::Tensor<uint8_t> &X,
                      const Ort::Custom::Tensor<float> &scale_tensor,
                      Ort::Custom::Tensor<float> &Y) {
  auto input_shape = X.Shape();
  auto x_raw = X.Data();
  auto scale = scale_tensor.Data()[0];
  auto y_raw = Y.Allocate(input_shape);
  for (int64_t i = 0; i < Y.NumberOfElement(); ++i) {

    // scale each uint8 number by
    y_raw[i] = x_raw[i] * scale;
  }
}

static Ort::CustomOpDomain TestCustomOp3() {
  Ort::CustomOpDomain v1_domain{"com.k2fsa.org"};
  // please make sure that custom_op_one has the same lifetime as the consuming
  // session
  //
  // Here we use a static variable so it is never released.
  // in practice, we can move it to a member variable of a class
  static std::unique_ptr<Ort::Custom::OrtLiteCustomOp> custom_op_one{
      Ort::Custom::CreateLiteCustomOp("MyCast", "CPUExecutionProvider",
                                      KernelOne)};
  v1_domain.Add(custom_op_one.get());

  return v1_domain;
}

void TestCustomModel3() {
  Ort::Env env;
  Ort::SessionOptions sess_opts;
  sess_opts.SetIntraOpNumThreads(1);
  sess_opts.SetInterOpNumThreads(1);

  Ort::CustomOpDomain v1_domain = TestCustomOp3();

  Ort::SessionOptions session_options;
  sess_opts.Add(v1_domain);
  // create a session with the session_options ...

  std::unique_ptr<Ort::Session> sess =
      std::make_unique<Ort::Session>(env, "./g.onnx", sess_opts);

  auto memory_info =
      Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeDefault);
  // foo is [10, 20]
  //

  std::vector<float> x = {1, 2};

  std::array<int64_t, 1> shape = {2};

  Ort::Value x_tensor = Ort::Value::CreateTensor(
      memory_info, x.data(), x.size(), shape.data(), shape.size());

  std::vector<Ort::Value> inputs;
  inputs.push_back(std::move(x_tensor));

  std::vector<const char *> input_names = {"l_x_"};
  std::vector<const char *> output_names = {"add"};
  auto out = sess->Run({}, input_names.data(), inputs.data(), inputs.size(),
                       output_names.data(), output_names.size());
  const float *p = out[0].GetTensorData<float>();
  for (int i = 0; i < 2; ++i) {
    std::cout << p[i] << "\n ";
  }
}
