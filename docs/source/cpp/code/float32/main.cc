#include <assert.h>
#include <cmath>
#include <iostream>
#include <limits>

// 1 sign
// 8 exp
// 23 significand, or mantissa
//
// bias is 127

bool IsInfinity(float x) {
  // exp: all 1
  // significant: all 0
  // when sign is 0 -> positive infinity
  // when sign is 1 -> negative infinity
  union {
    float f;
    int32_t i;
  } w;
  w.f = x;
  int32_t exp = (w.i >> 23) & 0xff;
  int32_t significand = w.i & 0x7fffff;
  return exp == 0xff && significand == 0;
}

bool IsNaN(float x) {
  // exp: all 1
  // significant: non-zero
  //
  // quiet nan: the leftmost significand is 1
  // signaling nan: the leftmost significand is 0
  union {
    float f;
    int32_t i;
  } w;
  w.f = x;
  int32_t exp = (w.i >> 23) & 0xff;
  int32_t significand = w.i & 0x7fffff;
  return exp == 0xff && significand != 0;
}

bool IsDenormalized(float x) {
  // exp, all 0
  // significand is not 0
  union {
    float f;
    int32_t i;
  } w;
  w.f = x;
  int32_t exp = (w.i >> 23) & 0xff;
  int32_t significand = w.i & 0x7fffff;
  return exp == 0 && significand != 0;
}

int32_t main() {
  float pos_inf = std::numeric_limits<float>::infinity();  // 0x7f80_0000
  float neg_inf = -std::numeric_limits<float>::infinity(); // 0xff80_0000
  assert(IsInfinity(pos_inf));
  assert(IsInfinity(neg_inf));
  assert(std::fpclassify(pos_inf) == FP_INFINITE);
  assert(std::fpclassify(neg_inf) == FP_INFINITE);

  float quiet_nan = std::numeric_limits<float>::quiet_NaN(); // 0x7fc0_0000
  float signaling_nan =
      std::numeric_limits<float>::signaling_NaN(); // 0x7fa0_0000

  assert(IsNaN(quiet_nan));
  assert(IsNaN(signaling_nan));
  assert(std::fpclassify(quiet_nan) == FP_NAN);
  assert(std::fpclassify(signaling_nan) == FP_NAN);

  // the smallest positive normal value
  //
  // Note the bias is 127
  float d1 = std::numeric_limits<float>::min(); // 0x80_0000, 1/(1<<126)

  float d2 = std::numeric_limits<float>::min() / 2; // 0x40_0000

  assert(std::fpclassify(d1) == FP_NORMAL);
  assert(std::fpclassify(d2) == FP_SUBNORMAL);
  assert(IsDenormalized(d1) == false);
  assert(IsDenormalized(d2) == true);
}
