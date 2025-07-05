// dart run --enable-asserts ./test-set.dart

// two ways to define an empty set
void test1() {
  final Set<int> a = {};
  assert(a.isEmpty == true);

  final b = <int>{};
  assert(b.isEmpty == true);
}

void test2() {
  var a = {1, 2, 1};
  assert(a.length == 2);

  assert(a.contains(1)); // 1 is inside the set
  assert(a.contains(10) == false); // 10 is not inside the set

  a.add(10);
  assert(a.contains(10)); // now 10 is inside the set
  assert(a.length == 3);

  a.remove(2);
  assert(a.length == 2);
  assert(a.contains(2) == false); // now 2 is not inside the set

  var b = [5, 1];
  a.addAll(b);
  print(a); // {1, 10, 5}

  // iterating a set
  var sum = 0;
  for (final i in a) {
    sum += i;
  }
  assert(sum == 1 + 10 + 5);
}

// convert a list to a set
// convert a set to a list
void test3() {
  var a = [1, 2, 1];
  var b = a.toSet();
  print(b); // {1, 2}
  a = b.toList(); // [1, 2]
  print(a);
}

void test4() {
  var a = <int>{1, 2};
  var b = a; // reference assigment
  b.add(3);
  assert(a.contains(3));

  b = a.toSet(); // real copy
  b.add(4);
  assert(a.contains(4) == false);
}

void main() {
  test1();
  test2();
  test3();
  test4();
}
