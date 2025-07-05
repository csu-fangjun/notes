// dart --enable-asserts ./test-function.dart
int add(int a, int b) {
  return a + b;
}

// b is optional.
// if b is not passed, it is null by default
// optional arguments must be placed at the end
int add2(int a, [int? b]) {
  if (b == null) {
    return a + 2;
  }
  return a + b;
}

// multiple optional arguments
int add3(int a, [int? b, int? c]) {
  return a + (b ?? 1) + (c ?? 2);
}

// optional argument with a default value
int add4(int a, [int b = 10]) {
  return a + b;
}

// b must be passed by name
int add5(int a, {required int b}) {
  return a + b;
}

// b is an optional name parameter
int add6(int a, {int? b}) {
  return a + (b ?? 3);
}

void main() {
  int c = add(2, 3);
  assert(c == 5);

  c = add2(10);
  assert(c == 12);

  c = add2(10, 5);
  assert(c == 15);

  c = add3(10);
  assert(c == 13);

  c = add3(10, 2);
  assert(c == 14);

  c = add4(2);
  assert(c == 12);

  c = add5(2, b: 3);
  assert(c == 5);

  c = add6(5);
  assert(c == 8);

  c = add6(6);
  assert(c == 9);
}
