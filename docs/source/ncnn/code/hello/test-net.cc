#include "datareader.h"
#include "layer/relu.h"
#include "layer_type.h"
#include "net.h"
#include <fstream>
#include <iostream>

#ifndef MY_CHECK
#define MY_CHECK(x, y)                                                         \
  do {                                                                         \
    if (x != y) {                                                              \
      NCNN_LOGE(#x " != " #y);                                                 \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
  } while (0)
#endif

class DataReaderFromEmpty : public ncnn::DataReader {
public:
  virtual int scan(const char *format, void *p) const { return 0; }
  virtual size_t read(void *buf, size_t size) const {
    memset(buf, 0, size);
    return size;
  }
};

ncnn::Layer *MyLayerCreator(void * /*userdata*/) { return new ncnn::ReLU(); }
void MyLayerDestoryer(ncnn::Layer *layer, void * /*userdata*/) { delete layer; }

static void TestCustomLayer() {
  static const char *s = R"(
7767517
2 2
Input        data                            0 1 data
MyLayer      my_layer                        1 1 data out
)";
  std::ofstream of("filename.param");
  of << s;
  of.close();

  ncnn::Net net;
  net.register_custom_layer("MyLayer", MyLayerCreator, MyLayerDestoryer,
                            nullptr);
  // This is the first custom layer, so its index is 0
  MY_CHECK(net.custom_layer_to_index("MyLayer"), 0);

  DataReaderFromEmpty dr;

  // return 0 on success
  // What does load_param() do?
  // If we need to set options, we have to set it before calling load_param()
  // (1) Read the magic number
  // (2) Allocate space for layers and blobs
  auto ret = net.load_param("filename.param");
  MY_CHECK(ret, 0);

  // load_model() is optional if there are no parameters to read
  // ret = net.load_model(dr);
  // MY_CHECK(ret, 0);

  ncnn::Mat m(2, 3);
  float *p = m;
  for (int32_t i = 0; i != m.total(); ++i) {
    p[i] = i - float(m.total()) / 2;
  }

  for (int32_t i = 0; i != m.total(); ++i) {
    std::cout << p[i] << ", ";
  }
  std::cout << "\n";

  ncnn::Extractor ex = net.create_extractor();
  ex.input("data", m);
  ncnn::Mat out;
  ex.extract("out", out);
  p = out;
  for (int32_t i = 0; i != out.total(); ++i) {
    std::cout << p[i] << ", ";
  }
  std::cout << "\n";
}

/*
ncnn::Net uses pimpl

std::vector<Layer*> layers;
std::vector<Blob> blobs;
 */
void TestNet() {
  TestCustomLayer();
  NCNN_LOGE("Test net\n");
  /*
  77675157 ->  magic number
  3 3 -> layer_count, blob_count

Input            data                             0 1 data
->
layer type: Input
Layer name: data
bottom count: 0
top count: 1
It uses ncnn::create_layer(layer_type) to create a layer

If create_layer() returns a nullptr, it invokes
create_custom_layer(layer_type)

note: create_layer() is a global function, while create_custom_layer()
is a method of `ncnn::Net`.

It will also invoke layer->load_param(paramdict);

Input layer has index 0 since it is the first row
0 1 data -> data is the output blob of Input layer. It has index 0 since
it is the first blob


   */
  static const char *s = R"(
7767517
3 3
Input            data                             0 1 data
Convolution      conv0_fwd                        1 1 data conv0_fwd 0=3 1=3 11=3 2=1 12=1 3=1 13=1 4=0 14=0 5=1 6=81
InnerProduct     dense0_fwd                       1 1 conv0_fwd output 0=1 1=1 2=151875
)";
  std::ofstream of("filename.param");
  of << s;
  of.close();

  ncnn::Net net;
  DataReaderFromEmpty dr;

  // return 0 on success
  // What does load_param() do?
  // If we need to set options, we have to set it before calling load_param()
  // (1) Read the magic number
  // (2) Allocate space for layers and blobs
  auto ret = net.load_param("filename.param");
  MY_CHECK(ret, 0);

  ret = net.load_model(dr);
  MY_CHECK(ret, 0);

  MY_CHECK(net.blobs().size(), 3);
  MY_CHECK(net.layers().size(), 3);

  // test layer 0
  // every layer has a type
  MY_CHECK(net.layers()[0]->type, "Input");
  MY_CHECK(net.layers()[0]->typeindex, ncnn::LayerType::Input);

  // every layer has a name
  MY_CHECK(net.layers()[0]->name, "data");

  // every layer has an input vector
  MY_CHECK(net.layers()[0]->bottoms.size(), 0);

  // every layer has an output vector
  MY_CHECK(net.layers()[0]->tops.size(), 1);
  // indexes in tops are indexes into the global blobs vector
  MY_CHECK(net.layers()[0]->tops[0], 0);

  // every blob has a name
  MY_CHECK(net.blobs()[0].name, "data");

  // every blob has a producer (layer index)
  MY_CHECK(net.blobs()[0].producer, 0); // producer is layer 0

  // every blob has a consumer (layer index)
  MY_CHECK(net.blobs()[0].consumer, 1); // consumer is layer 1
}
