// dart run --enable-asserts ./test-list.dart

void test1() {
  var a = [1, 2, 3]; // infer types automatically

  List<int> b = [1, 2, 3]; // Use List<int> explicitly
  print(b);

  var c = <int>[]; // an empty list with a specified type
  assert(c.isEmpty == true);
  c.add(1);

  assert(c.isEmpty == false);

  c.add(3);
  c.add(2);
  assert(c.length == b.length); // get number of elements
  print(c); // [1, 3, 2]
  c.sort(); // sort in-place
  print(c); // [1, 2, 3]
}

// use a for loop like c/c++
void test2() {
  var a = [1, 2, 3];
  var sum = 0;
  for (int i = 0; i < a.length; i++) {
    sum += a[i];
  }
  assert(sum == 6);
}

void test3() {
  var a = [1, 2, 3];
  var sum = 0;
  for (final i in a) {
    sum += i;
  }
  assert(sum == 6);
}

// the spread operator
void test4() {
  var a = [1, 2];
  var b = [3];
  var c = [...a, ...b];
  print(c); // 1, 2, 3

  c = [10, ...b, ...a];
  print(c); // 10, 3, 1, 2
}

// collection for
void test5() {
  var a = [1, 2, 3];

  // add all elements from a
  var b = [10, for (final i in a) i];
  print(b); // [10, 1, 2, 3]

  // add elements from a whose value > 1
  b = [
    10,
    for (final i in a)
      if (i > 1) i
  ];
  print(b); // [10, 2, 3]

  // convert a list of integers to a list of strings
  var s = [for (final i in a) i.toString()];
  print(s); // [1, 2, 3]
}

void main() {
  test1();
  test2();
  test3();
  test4();
  test5();
}
