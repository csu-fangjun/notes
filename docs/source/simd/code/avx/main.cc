#include <cassert>
#include <immintrin.h>

// ps means packed signle precision
static void TestLoadStore() {
  alignas(16) float a[4] = {1, 2, 3, 4};
  alignas(16) float b[4];
  __m128 f = _mm_load_ps(a);
  // f = _mm_loadu_ps(a); // if a not aligned
  _mm_store_ps(b, f);
  // _mm_storeu_ps(b, f); // if b is not aligned
  assert(b[0] == a[0]);
  assert(b[1] == a[1]);
  assert(b[2] == a[2]);
  assert(b[3] == a[3]);

  // set manually
  f = _mm_set_ps(a[3], a[2], a[1], a[0]);
  _mm_store_ps(b, f);
  assert(b[0] == a[0]);
  assert(b[1] == a[1]);
  assert(b[2] == a[2]);
  assert(b[3] == a[3]);

  // for double
  alignas(32) double k[4] = {1, 2, 3, 4};
  __m256d d = _mm256_load_pd(k);
  // d = _mm256_loadu_pd(k); // if k is not aligned
  alignas(32) double m[4];
  _mm256_store_pd(m, d);
  // _mm256_storeu_pd(m, d); // if m is not aligned
  assert(m[0] == k[0]);
  assert(m[1] == k[1]);
  assert(m[2] == k[2]);
  assert(m[3] == k[3]);

  d = _mm256_set_pd(k[3], k[2], k[1], k[0]);
  _mm256_store_pd(m, d);
  assert(m[0] == k[0]);
  assert(m[1] == k[1]);
  assert(m[2] == k[2]);
  assert(m[3] == k[3]);
}

static void TestLoadStore1() {
  float a = 10;
  float b[4];
  __m128 f = _mm_load_ps1(&a);
  _mm_store_ps(b, f);
  assert(b[0] == a);
  assert(b[1] == a);
  assert(b[2] == a);
  assert(b[3] == a);
}

static void TestAdd() {
  float a[4] = {1, 2, 3, 4};
  float b[4] = {10, 20, 30, 40};
  __m128 f = _mm_load_ps(a);
  __m128 g = _mm_load_ps(b);
  __m128 h = _mm_add_ps(f, g);
  float c[4];
  _mm_store_ps(c, h);
  assert(c[0] == a[0] + b[0]);
  assert(c[1] == a[1] + b[1]);
  assert(c[2] == a[2] + b[2]);
  assert(c[3] == a[3] + b[3]);
}

static void AddIndex1(double *x, int32_t n) {
  for (int32_t i = 0; i < n; ++i) {
    x[i] = x[i] + i;
  }
}

// assume n % 4 == 0
static void AddIndex2(double *x, int32_t n) {
  assert(n % 4 == 0);
  __m256d index, x_vec;
  for (int32_t i = 0; i < n; i += 4) {
    x_vec = _mm256_load_pd(x + i);
    // x_vec[0] = x[i]
    // x_vec[1] = x[i+1]
    // x_vec[2] = x[i+2]
    // x_vec[3] = x[i+3]

    index = _mm256_set_pd(i + 3, i + 2, i + 1, i);
    // index[0] = i
    // index[1] = i+1
    // index[2] = i+2
    // index[3] = i+3

    x_vec = _mm256_add_pd(x_vec, index);
    // x_vec[0] = x_vec[0] + index[0]
    // x_vec[1] = x_vec[1] + index[1]
    // x_vec[2] = x_vec[2] + index[2]
    // x_vec[3] = x_vec[3] + index[3]

    _mm256_store_pd(x + i, x_vec);
    // (x+i)[0] = x_vec[0]
    // (x+i)[1] = x_vec[1]
    // (x+i)[2] = x_vec[2]
    // (x+i)[3] = x_vec[3]
  }
}

static void TestAddIndex() {
  alignas(32) double a[64];
  alignas(32) double b[64];
  for (int32_t i = 0; i != 64; ++i) {
    a[i] = b[i] = i;
  }
  AddIndex1(a, 64);
  AddIndex2(b, 64);
  for (int32_t i = 0; i != 64; ++i) {
    assert(a[i] == b[i]);
  }
}

int main() {
  TestLoadStore();
  TestLoadStore1();
  TestAdd();
  TestAddIndex();
  return 0;
}
