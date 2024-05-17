// run it with
// dart --enable-asserts ./test2.dart

int add(int a, int b) {
  return a + b;
}

// if it contains a single return statement, it can be simplified
int add2(int a, int b) => a + b;

// optional positional arguments.
// we usually don't use positional arguments
int func(int a, [int? b, int? c]) {
  return a - (b ?? 0) + (c ?? 0);
}

int func2(int a, {int? b, int? c}) {
  return a - (b ?? 0) + (c ?? 0);
}

// both ways are fine to define a function type
typedef int MyAdd(int a, int b); // argument names cannot be omitted

// argument names can be omitted
typedef MyAdd2 = int Function(int, int);
// typedef MyAdd2 = int Function(int a, int b);

void main() {
  assert(add(2, 3) == 5);
  assert(add2(2, 3) == 5);

  // for positional arguments, we cannot ignore b if we want to pass c,
  assert(func(10) == 10); //a i 10
  assert(func(10, 3) == 7); // a is 10, b is 3, c is null
  assert(func(10, null, 5) == 15); // a is 10, b is null, c is 5
  assert(func(10, 3, 5) == 12); // a is 10, b is 3, c is 5

  assert(func2(10) == 10);
  assert(func2(10, c: 3) == 13);
  assert(func2(10, b: 2) == 8);
  assert(func2(10, c: 3, b: 2) == 11);
  assert(func2(10, b: 2, c: 3) == 11);

  MyAdd myAdd = add;
  assert(myAdd(2, 3) == 5);

  MyAdd2 myAdd2 = add;
  assert(myAdd2(2, 3) == 5);

  // define a function type

  var f = (a, b) => a + b;
  assert(f(2, 3) == 5);
}
