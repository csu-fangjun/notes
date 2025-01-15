#include "torch/script.h"
#include "torch/torch.h"

static void TestCommonMethods() {
  torch::Tensor t = torch::rand({2, 3, 4});

  TORCH_CHECK(t.dim() == 3);              // 3-d tensor
  TORCH_CHECK(t.ndimension() == t.dim()); // same
  TORCH_CHECK(t.numel() == 2 * 3 * 4);
  TORCH_CHECK(t.is_contiguous() == true);
  TORCH_CHECK(t.contiguous().is_contiguous() == true);

  t.fill_(10); // fill all entries to 0
  t.zero_();   // zero out all entries

  t = t.to(torch::kInt);
  TORCH_CHECK(t.is_floating_point() == false);
  TORCH_CHECK(t.is_signed() == true);

  TORCH_CHECK(t.size(0) == 2);
  TORCH_CHECK(t.size(1) == 3);
  TORCH_CHECK(t.size(2) == 4);
  TORCH_CHECK(t.sizes() == torch::ArrayRef<int64_t>({2, 3, 4}));

  t = t.contiguous();
  TORCH_CHECK(t.stride(0) == 3 * 4);
  TORCH_CHECK(t.stride(1) == 4);
  TORCH_CHECK(t.stride(2) == 1);
  TORCH_CHECK(t.strides() == torch::ArrayRef<int64_t>({12, 4, 1}));

  TORCH_CHECK(t.defined() == true);
  {
    torch::Tensor a;
    TORCH_CHECK(a.defined() == false);
    a = t;
    TORCH_CHECK(a.defined() == true);
    a.reset();
    TORCH_CHECK(a.defined() == false);
  }

  t = t.to(torch::kShort);
  TORCH_CHECK(t.itemsize() == sizeof(int16_t));
  TORCH_CHECK(t.nbytes() == t.numel() * t.itemsize());
  TORCH_CHECK(t.itemsize() == t.element_size()); // same

  TORCH_CHECK(t.scalar_type() == torch::kShort);
  TORCH_CHECK(t.dtype() == caffe2::TypeMeta::Make<int16_t>());
  TORCH_CHECK(t.dtype().toScalarType() == torch::kShort);

  TORCH_CHECK(t.device() == torch::Device("cpu"));
  TORCH_CHECK(t.device() == torch::Device(torch::kCPU));

  // Note: t.device() return an instance of torch::Device
  // t.get_device() returns the device index.
  TORCH_CHECK(t.get_device() == t.device().index());

  TORCH_CHECK(t.is_cpu() == true);
  TORCH_CHECK(t.is_cuda() == false);

  t = t.to(torch::kInt);
  int32_t *p = t.data_ptr<int32_t>();
  p[0] = 100;

  torch::TensorAccessor<int32_t, 3> acc = t.accessor<int32_t, 3>();
  TORCH_CHECK(acc[0][0][0] == p[0]);
  p[12] = -2;
  TORCH_CHECK(acc[1][0][0] == -2);

  acc[1][1][2] = 3;
  TORCH_CHECK(*(p + 12 + 4 + 2) == 3);

  t = t.to(torch::kFloat);
  t.set_requires_grad(true);
  TORCH_CHECK(t.requires_grad() == true);

  t.set_requires_grad(false);
  TORCH_CHECK(t.requires_grad() == false);

  t = t.cuda();
  TORCH_CHECK(t.device().type() == torch::kCUDA);
  t = t.cpu();

  torch::TensorOptions opts = t.options();
  TORCH_CHECK(opts.device() == t.device());
}

static void TestSlice() {
  auto t = torch::tensor({1, 2, 3, 4, 5}, torch::kInt);
  torch::TensorAccessor<int32_t, 1> acc = t.accessor<int32_t, 1>();

  // t2 = t[1:3]
  torch::Tensor t2 = t.slice(/*dim*/ 0, /*start*/ 1,
                             /*end, exclusive*/ 3); // memory is shared
  torch::TensorAccessor<int32_t, 1> acc2 = t2.accessor<int32_t, 1>();
  TORCH_CHECK(acc2[0] == 2);
  TORCH_CHECK(acc2[1] == 3);

  acc2[0] = 10; // also changes t since the memory is shared
  TORCH_CHECK(acc[1] == 10);
}

// https://pytorch.org/docs/stable/generated/torch.topk.html
static void TestTopK() {
  auto t = torch::tensor({1, 0, 3, -1}, torch::kInt).to(torch::kFloat);
  torch::Tensor values, indexes;
  std::tie(values, indexes) =
      t.topk(/*k*/ 2, /*dim*/ 0, /*largest*/ true, /*sorted*/ true);
  auto values_acc = values.accessor<float, 1>();
  auto indexes_acc = indexes.accessor<int64_t, 1>(); // Note: it is int64_t

  TORCH_CHECK(values.numel() == 2); // k in topk is 2
  TORCH_CHECK(values_acc[0] == 3);  // the largest value is 3, at t[2]
  TORCH_CHECK(values_acc[1] == 1);  // the second largest value is 1, at t[0]
                                    //
  TORCH_CHECK(indexes_acc[0] == 2); // the largest value is t[2]
  TORCH_CHECK(indexes_acc[1] == 0); // the second largest value is t[0]
}

static void TestFloorDivide() {
  auto t = torch::tensor({1, 0, 3, 5, 9}, torch::kInt);
  auto p = torch::floor_divide(t, 2);
  auto acc = p.accessor<int32_t, 1>();
  TORCH_CHECK(acc[0] == 1 / 2);
  TORCH_CHECK(acc[1] == 0 / 2);
  TORCH_CHECK(acc[2] == 3 / 2);
  TORCH_CHECK(acc[3] == 5 / 2);
  TORCH_CHECK(acc[4] == 9 / 2);
}

// https://pytorch.org/docs/stable/generated/torch.div.html
static void TestDiv() {
  auto t = torch::tensor({1, 0, 3, 5, 9}, torch::kInt);
  // the rounding mode is supported in torch >= 1.8.0
  auto p = torch::div(t, 2, /*rounding_mode*/ "trunc");
  auto acc = p.accessor<int32_t, 1>();
  TORCH_CHECK(acc[0] == 1 / 2);
  TORCH_CHECK(acc[1] == 0 / 2);
  TORCH_CHECK(acc[2] == 3 / 2);
  TORCH_CHECK(acc[3] == 5 / 2);
  TORCH_CHECK(acc[4] == 9 / 2);
}

// https://pytorch.org/docs/1.6.0/generated/torch.remainder.html
static void TestRemainder() {
  auto t = torch::tensor({1, 3, 8}, torch::kInt);
  auto p = torch::remainder(t, 3);
  auto acc = p.accessor<int32_t, 1>();
  TORCH_CHECK(acc[0] == 1);
  TORCH_CHECK(acc[1] == 0);
  TORCH_CHECK(acc[2] == 2);
}

static void TestEmpty() {
  auto t = torch::empty({3}, torch::kInt);
  TORCH_CHECK(t.scalar_type() == torch::kInt);
  TORCH_CHECK(t.numel() == 3);
}

static void TestStack() {
  auto t = torch::empty({6, 5}, torch::kInt);
  auto a = torch::stack({t, t}, /*dim*/ 1);
  TORCH_CHECK(a.sizes() == torch::ArrayRef<int64_t>({6, 2, 5}));

  a = torch::stack({t, t}, /*dim*/ 0);
  TORCH_CHECK(a.sizes() == torch::ArrayRef<int64_t>({2, 6, 5}));

  a = torch::stack({t, t}, /*dim*/ 2);
  TORCH_CHECK(a.sizes() == torch::ArrayRef<int64_t>({6, 5, 2}));
}

static void TestUnbind() {
  auto t = torch::empty({4, 6, 5}, torch::kInt);
  std::vector<torch::Tensor> v = torch::unbind(t, /*dim*/ 1);
  TORCH_CHECK(v.size() == t.size(1));
  for (int32_t i = 0; i != v.size(); ++i) {
    TORCH_CHECK(v[i].sizes() == torch::ArrayRef<int64_t>({4, 5}));
  }
}

static void TestFull() {
  auto t = torch::full({2, 3}, 10, torch::kInt);
  const int32_t *p = t.data_ptr<int32_t>();
  for (int32_t i = 0; i != t.numel(); ++i) {
    TORCH_CHECK(p[i] == 10);
  }
}

static void TestSplit() {
  auto t = torch::arange(6).reshape({2, 3});
  std::vector<torch::Tensor> s = t.split(1);
  TORCH_CHECK(s.size() == 2);
  TORCH_CHECK(s[0].sizes() == torch::ArrayRef<int64_t>({1, 3}));
  TORCH_CHECK(s[1].sizes() == torch::ArrayRef<int64_t>({1, 3}));

  s = t.split(1, /*dim*/ 1);
  TORCH_CHECK(s.size() == 3);
  TORCH_CHECK(s[0].sizes() == torch::ArrayRef<int64_t>({2, 1}));
  TORCH_CHECK(s[1].sizes() == torch::ArrayRef<int64_t>({2, 1}));
  TORCH_CHECK(s[2].sizes() == torch::ArrayRef<int64_t>({2, 1}));
}

static void TestZeros() {
  auto t = torch::zeros({2, 3}, torch::kFloat);
  std::cout << t << "\n";
}

static void TestCat() {
  auto t = torch::arange(24).reshape({2, 3, 4});
  std::vector<torch::Tensor> v(5, t);
  auto p = torch::cat(v, /*dim*/ 1);
  TORCH_CHECK(p.sizes() == torch::ArrayRef<int64_t>({2, 3 * 5, 4}));
}

static void TestDivision() {
  auto t = torch::arange(4).to(torch::kInt);
  auto b = t / 2;
  TORCH_CHECK(b.scalar_type() == torch::kFloat);

  const float *p = b.data_ptr<float>();
  TORCH_CHECK(p[0] == 0 / 2.);
  TORCH_CHECK(p[1] == 1 / 2.);
  TORCH_CHECK(p[2] == 2 / 2.);
  TORCH_CHECK(p[3] == 3 / 2.);

  auto c = b.to(torch::kInt);

  const int32_t *q = c.data_ptr<int32_t>();
  TORCH_CHECK(q[0] == 0 / 2);
  TORCH_CHECK(q[1] == 1 / 2);
  TORCH_CHECK(q[2] == 2 / 2);
  TORCH_CHECK(q[3] == 3 / 2);
}

void TestDefaultConstructed() {
  torch::Tensor t;
  TORCH_CHECK(t.size(0) == 0);
}

void TestCopy() {
  auto t0 = torch::tensor({1, 2, 3, 4, 5, 6}, torch::kFloat).reshape({2, 3});
  auto t = torch::empty({4, 3}, torch::kFloat);

  t.slice(/*dim*/ 0, 0, 1) = t0.slice(0, 0, 1);
  t.slice(/*dim*/ 0, 1, 2) = t0.slice(0, 1, 2);
  t.slice(/*dim*/ 0, 2, 3) = t0.slice(0, 0, 1) + 10;
  t.slice(/*dim*/ 0, 3, 4) = t0.slice(0, 1, 2) + 10;

  std::cout << t << "\n";
}

void TestAddmm() {
  std::cout << "---TestAddmm---\n";
  // 1 2 3
  // 4 5 6
  torch::Tensor m =
      torch::tensor({1, 2, 3, 4, 5, 6}, torch::kFloat).reshape({2, 3});

  torch::Tensor v = torch::tensor({1, 1, -1}, torch::kFloat).unsqueeze(1);

  // 10 20 30
  torch::Tensor a = torch::tensor({10, 20}, torch::kFloat).unsqueeze(1);
  a.addmm_(m, v);
  std::cout << a << "\n";
  std::cout << a.squeeze(1) << "\n";
}

void TestElementwiseOp() {
  std::cout << "---TestElementwiseOp---\n";
  torch::Tensor a = torch::tensor({1, 2, 3, 40}, torch::kFloat).reshape({2, 2});
  torch::Tensor b =
      torch::tensor({10, 20, 30, 4}, torch::kFloat).reshape({2, 2});
  torch::Tensor c = a * b;
  torch::Tensor d = a / b;
  torch::Tensor e = 1.0 / a;
  std::cout << c << "\n"; // [[10, 40], [90, 160]]
  std::cout << d << "\n"; // [[0.1, 0.1], [0.1, 10]]
  std::cout << e << "\n"; // [[1.0, 0.5], [0.3333, 0.0250]], float32
}

void TestRoll() {
  // 1 2 3
  // 4 5 6
  torch::Tensor a =
      torch::tensor({1, 2, 3, 4, 5, 6}, torch::kFloat).reshape({2, 3});
  torch::Tensor b = a.roll(1 /*shift right 1 column*/, 1 /*dim*/);
  // Now b is
  // 3 2 1
  // 6 4 5

  // ----------
  // 1 2 3 4
  // 5 6 7 8
  //
  // 9 10 11 12
  // 13 14 15 16
  a = torch::tensor({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
                    torch::kInt)
          .reshape({2, 2, 4});
  b = a.roll(1 /*shift right 1 column*/, 2 /*dim*/);
  // now b is
  // 4 1 2 3
  // 8 5 6 7
  //
  // 12 9 10 11
  // 16 13 14 15
  std::cout << b;
}

void TestMean() {
  // 1 2 3
  // 4 5 6
  torch::Tensor a =
      torch::tensor({1, 2, 3, 4, 5, 6}, torch::kFloat).reshape({2, 3});
  torch::Tensor b = a.mean(1 /*dim*/, true /*keep_dim*/);
  std::cout << b;
  // Now b is:
  // 2
  // 5
  //----------
  b = a.mean(1 /*dim*/, false /*keep_dim*/);
  std::cout << b << "\n";
}

void TestSlice2() {
  auto t = torch::full({2, 3}, -1);
  std::cout << t << "\n";

  // set the last column to 0
  t.index({torch::indexing::Slice(), -1}) = 0;
  std::cout << t << "\n";
}

void TestAsStrided() {
  /*
   0 1 2 3 4 5 6 7 8 9
   */

  /*
    0 1 2
    2 3 4
    4 5 6
    6 7 8
   */
  torch::Tensor a = torch::arange(0, 10).to(torch::kFloat);
  // (10 - 3) // 2 + 1 = 4
  torch::Tensor b = a.as_strided({4, 3}, {2, 1});
  std::cout << a << "\n";
  std::cout << b << "\n";
}

void TestArgMax() {
  std::vector<float> v = {
      //
      0.2, 0.5, 0.1, 0.4,
      //
      0.9, 0.2, 0.0, 0.3,
      //
      0.8, 0.99, 0.1, 0.3
      //
  };
  torch::Tensor a = torch::from_blob(v.data(), {3, 4}, torch::kFloat);
  std::cout << a << "\n"; // shape (3, 4)

  torch::Tensor b = a.argmax(1);
  std::cout << b << "\n"; // 1-d, shape: (3,)
  // 1, 0, 1

  // test 3-d
  a = torch::from_blob(v.data(), {2, 3, 2}, torch::kFloat);
  std::cout << a << "\n"; // shape (2, 3, 2)

  b = a.argmax(-1);
  std::cout << b << "\n"; // 1-d, shape: (2, 3)
                          // 1, 1, 0
                          // 1, 1, 1
}

void TestNonZero() {
  auto t = torch::tensor({0, 2, 0, 0, 5, 0, 1}, torch::kInt);
  std::cout << t << "\n";       // 1-d, shape (7,)
  auto indexes = t.nonzero();   //
  std::cout << indexes << "\n"; // 2-d, shape (3, 1) 1 4 6

  indexes = indexes.squeeze();
  auto v = t.index_select(0, indexes);
  std::cout << v << "\n";
}

void TestIndex() {
  // see https://pytorch.org/cppdocs/notes/tensor_indexing.html
  std::vector<float> v = {
      //
      0.2, 0.5, 0.1, 0.4,
      //
      0.9, 0.2, 0.0, 0.3,
      //
      0.8, 0.99, 0.1, 0.3
      //
  };
  torch::Tensor a = torch::from_blob(v.data(), {3, 4}, torch::kFloat);
  std::cout << a << "\n"; // shape (3, 4)

  torch::Tensor b = a.index({0});
  std::cout << b << "\n"; // 1-d, shape (4,) 0.2, 0.5, 0.1, 0.4
                          //
  b = a.index({2});
  std::cout << b << "\n"; // 1-d, shape (4,) 0.8, 0.99, 0.1, 0.3

  torch::Tensor c = b.slice(/*dim*/ 0, /*start*/ 0, /*end*/ 2);
  std::cout << c << "\n"; // 1-d, shape (2,) 0.8, 0.99
}

void TestPad() {
  std::vector<float> v = {0, 1, 2, 3, 4, 5};
  torch::Tensor a = torch::from_blob(v.data(), {2, 3}, torch::kFloat);

  int32_t padding = 1;

  // pad dim 1
#ifdef __ANDROID__
  auto padding_value = torch::zeros(
      {a.size(0), padding}, torch::dtype(torch::kFloat).device(a.device()));

  torch::Tensor b = torch::cat({a, padding_value}, 1);
#else
  torch::Tensor b = torch::nn::functional::pad(
      a, torch::nn::functional::PadFuncOptions({0, padding})
             .mode(torch::kConstant)
             .value(0));
#endif
  /*
   0 1 2 0
   3 4 5 0
   */
  std::cout << b << "\n";

  // pad dim 1
#ifdef __ANDROID__
  padding_value = torch::zeros({padding, a.size(1)},
                               torch::dtype(torch::kFloat).device(a.device()));

  torch::Tensor c = torch::cat({a, padding_value}, 0);
#else
  torch::Tensor c = torch::nn::functional::pad(
      a, torch::nn::functional::PadFuncOptions({0, 0, 0, padding})
             .mode(torch::kConstant)
             .value(0));
#endif
  /*
    0 1 2
    3 4 5
    0 0 0
   */
  std::cout << c << "\n";
}

void TestIndexPut() {
  // https://pytorch.org/cppdocs/notes/tensor_indexing.html#setter
  std::vector<float> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  torch::Tensor a = torch::from_blob(v.data(), {12}, torch::kFloat);
  torch::Tensor indexes =
      torch::tensor({0, 1, 3, 5}, torch::dtype(torch::kLong));

  a.index_put_({indexes}, 0);
  std::cout << a << "\n";
  /*
   0 0 2 0 4 0 6 7 8 9 10 11

   */

  // 2-d

  v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  /*
   0 1 2
   3 4 5
   6 7 8
   9 10 11
   */
  a = torch::from_blob(v.data(), {4, 3}, torch::kFloat);

  indexes = torch::tensor({0, 2}, torch::dtype(torch::kLong));
  a.index_put_({indexes}, 100);

  /*
    100 100 100
    3   4   5
    100 100 100
    9   10  11
   */
  std::cout << a << "\n";

  v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  a = torch::from_blob(v.data(), {4, 3}, torch::kFloat);

  indexes = torch::tensor({0, 2}, torch::dtype(torch::kLong));
  a.index_put_({"...", indexes}, 99);

  /*
   99 1 99
   99 4 99
   99 7 99
   99 10 99
   */
  std::cout << a << "\n";

  v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  a = torch::from_blob(v.data(), {4, 3}, torch::kFloat);

  indexes = torch::tensor({0, 2}, torch::dtype(torch::kLong));
  a.index_put_({"...", 1}, 6666);
  /*
   0 6666 2
   3 6666 5
   6 6666 8
   9 6666 11
   */
  std::cout << a << "\n";

  // 3-d
  v = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
  a = torch::from_blob(v.data(), {2, 3, 4}, torch::kFloat);

  /*
    0 1 2 3
    4 5 6 7
    8 9 10 11

    ---

    12 13 14 15
    16 17 18 19
    20 21 22 23
   */
  std::cout << a << "\n";

  indexes = torch::tensor({0}, torch::dtype(torch::kLong));
  a.index_put_({indexes}, 88); // dim 0
  std::cout << a << "\n";
  /*
    88 88 88 88
    88 88 88 88
    88 88 88 88

    ---

    12 13 14 15
    16 17 18 19
    20 21 22 23
   */

  v = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
  a = torch::from_blob(v.data(), {2, 3, 4}, torch::kFloat);
  indexes = torch::tensor({0, 3}, torch::dtype(torch::kLong));
  a.index_put_({"...", indexes}, 66); // the last dim, i.e., dim 2
  std::cout << a << "\n";
  /*
    66 1 2 66
    66 5 6 66
    66 9 10 66

    ---

    66 13 14 66
    66 17 18 66
    66 21 22 66
   */
  v = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
  a = torch::from_blob(v.data(), {2, 3, 4}, torch::kFloat);
  indexes = torch::tensor({1}, torch::dtype(torch::kLong));
  a.index_put_({torch::indexing::None, indexes}, 55); // dim 1
  std::cout << a << "\n";
  /*
    0 1 2 3
    4 5 6 7
    8 9 10 11

    ---

    55 55 55 55
    55 55 55 55
    55 55 55 55
   */

  v = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
  a = torch::from_blob(v.data(), {2, 3, 4}, torch::kFloat);
  indexes = torch::tensor({1}, torch::dtype(torch::kLong));
  a.index_put_(
      {torch::indexing::Slice(torch::indexing::None, torch::indexing::None,
                              torch::indexing::None),
       torch::indexing::Slice(torch::indexing::None, torch::indexing::None,
                              torch::indexing::None),
       indexes},
      33); // dim 2
  std::cout << a << "\n";
  /*
    0 33 2 3
    4 33 6 7
    8 33 10 11

    ---

    12 33 14 15
    16 33 18 19
    20 33 22 23
   */
}

void TestNonZero2() {
  auto a = torch::tensor({1, 5, 5}, torch::dtype(torch::kInt)).reshape({3, 1});
  torch::Tensor b = (a == 5).nonzero();
  // 1 0
  // 2 0
  std::cout << b << "\n"; // shape is (2, 2)

  torch::Tensor c = (a.squeeze() == 5).nonzero();
  // 1
  // 2
  std::cout << c << "\n"; // shape is (2, 1)

  torch::Tensor d = (a == 50).nonzero();
  std::cout << d.numel() << "\n";
}

int main() {
  // TestCommonMethods();
  TestSlice();
  TestTopK();
  TestFloorDivide(); // deprecated
  TestDiv();         // rounding_mode is in torch>=1.8.0
  TestRemainder();
  TestEmpty();
  TestStack();
  TestUnbind();
  TestFull();
  TestSplit();
  TestZeros();
  TestCat();
  TestDivision();
  TestDefaultConstructed();
  TestCopy();
  TestAddmm();
  TestElementwiseOp();
  TestRoll();
  TestMean();
  TestSlice2();
  TestAsStrided();
  TestArgMax();
  TestNonZero();
  TestIndex();
  TestPad();
  TestIndexPut();
  TestNonZero2();

  return 0;
}
