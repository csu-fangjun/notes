// dart --enable-asserts ./test-control.dart

void TestIf() {
  int a = 2;
  int b = 0;
  if (a > 1) {
    b = 3;
  } else {
    b = 4;
  }

  assert(b == 3);

  //like C/C++
  b = (a > 1) ? 10 : 20;
  assert(b == 10);
}

void TestSwitchInt() {
  int a = 1;
  int b;
  switch (a) {
    case 10:
      b = 2;
      break;
    case 1:
      b = 3;
      break;
    default:
      b = 4;
      break;
  }
  assert(b == 3);
}

void TestSwitchString() {
  String s = 'zero';
  int b;
  switch (s) {
    case 'zero':
      b = 0;
      break;
    case 'one':
      b = 1;
      break;
    default:
      b = -1;
      break;
  }

  assert(b == 0);
}

enum MyNumber {
  zero,
  one,
  two,
} // no trailing ;

void TestSwitchEnum() {
  final n = MyNumber.one;

  // counts from 0
  assert(n.index == 1);

  int b = -1;
  switch (n) {
    case MyNumber.zero:
      b = 0;
      break;
    case MyNumber.one:
      b = 1;
      break;
    case MyNumber.two:
      b = 2;
      break;
    // no need to use default
  }

  assert(b == 1);
}

void TestWhile() {
  int i = 0;
  int sum = 0;
  while (i <= 3) {
    sum += i;
    i++;
  }
  assert(sum == 1 + 2 + 3);
}

void TestDoWhile() {
  int i = 0;
  int sum = 0;
  do {
    sum += i;
    i++;
  } while (i <= 3);

  assert(sum == 1 + 2 + 3);
}

void main() {
  TestIf();
  TestSwitchInt();
  TestSwitchString();
  TestSwitchEnum();
  TestWhile();
  TestDoWhile();
}
