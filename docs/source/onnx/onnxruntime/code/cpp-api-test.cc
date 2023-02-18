#include "onnxruntime_cxx_api.h" // NOLINT
#include <assert.h>
#include <iostream>
#include <sstream>

static void TestOrtGetApi() {
  const OrtApi &api = Ort::GetApi(); // it returns a const reference
}

static void PrintAvailableProviders() {
  std::vector<std::string> providers = Ort::GetAvailableProviders();
  std::ostringstream os;
  os << "Available providers: ";
  std::string sep = "";
  for (const auto &p : providers) {
    os << sep << p;
    sep = ", ";
  }
  std::cout << os.str() << "\n";
}

static void TestCreateTensorFromBuffer() {
  std::vector<int32_t> v = {1, 2, 3, 4, 5, 6};
  std::array<int64_t, 2> shape = {2, 3};
  auto memory_info =
      Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeDefault);

  Ort::Value x = Ort::Value::CreateTensor<int32_t>(
      memory_info, v.data(), v.size(), shape.data(), shape.size());

  // memory is shared between x and v
  int32_t *p = x.GetTensorMutableData<int32_t>();
  p[0] = 10;
  assert(v[0] == 10);

  v[1] = 20;
  assert(p[1] == 20);
}

static void TestCreateTensor() {
  Ort::AllocatorWithDefaultOptions allocator;

  std::array<int64_t, 2> shape = {2, 3};
  auto memory_info =
      Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeDefault);

  Ort::Value x =
      Ort::Value::CreateTensor<int32_t>(allocator, shape.data(), shape.size());
  assert(x.IsTensor());
  assert(x.HasValue());
  Ort::TypeInfo type_info = x.GetTypeInfo();
  auto tensor_type_and_shape_info = type_info.GetTensorTypeAndShapeInfo();
  assert(tensor_type_and_shape_info.GetElementCount() == 2 * 3);
  assert(tensor_type_and_shape_info.GetDimensionsCount() == 2);
  std::vector<int64_t> x_shape = tensor_type_and_shape_info.GetShape();
  assert(x_shape.size() == shape.size());
  assert(x_shape[0] == shape[0]);
  assert(x_shape[1] == shape[1]);

  assert(tensor_type_and_shape_info.GetElementType() ==
         ONNX_TENSOR_ELEMENT_DATA_TYPE_INT32);

  Ort::ConstMemoryInfo memory_info = x.GetTensorMemoryInfo();
  std::cout << "allocator name: " << memory_info.GetAllocatorName() << "\n";
}

void TestCppApi() {
  TestOrtGetApi();
  PrintAvailableProviders();
  TestCreateTensorFromBuffer();
  TestCreateTensor();
}
