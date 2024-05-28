// run it with
// dart --enable-asserts ./test_record.dart

// records requires dart>=3.0
void test1() {
  (int, int) a;

  // (2, 3) is immutable
  a = (2, 3);
  assert(a.$1 == 2); // count from 1
  assert(a.$2 == 3);

  // for named fields in a record, we must use named assignment
  ({int a, int b}) c = (a: 10, b: 20);
  assert(c.a == 10);
  assert(c.b == 20);

  // mix of positional and named
  (int, {int a, int b}) d;
  d = (10, a: 20, b: 30);
  assert(d.$1 == 10);
  assert(d.a == 20);
  assert(d.b == 30);

  var f = (100, a: 200, b: 300, 400);
  assert(f == (100, 400, a: 200, b: 300));

  (int, int, {int a, int b}) h;

  // named fields can appear any where
  h = (a: 1, b: 2, 0, 3);

  assert(h.$1 == 0);
  assert(h.$2 == 3);
  assert(h.a == 1);
  assert(h.b == 2);

  (num, Object) k = (42, 'a');
  assert(k.$1 is int);
  assert(k.$2 is String);

  // as kotlin, to convert types
  int k1 = k.$1 as int;
  String k2 = k.$2 as String;

  assert(k1 == k.$1);
  assert(k2 == k.$2);
}

void main() {
  test1();
}
