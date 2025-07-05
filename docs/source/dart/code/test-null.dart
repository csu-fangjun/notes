// dart run --enable-asserts ./test-null.dart

class User {
  int id = 1;
}

void test1() {
  int? a; // default to null

  assert(a == null);

  a ??= 3;
  assert(a == 3);

  a ??= 5; // a is not null, so it is a no-op
  assert(a == 3);

  a = null;

  int b = a ?? 10; // a is null, so 10 is assigned to b
  assert(b == 10);

  a = 1;
  b = a ?? 5; // a is not null, so a is assigned to b
  assert(b == 1);

  a = null;
  // b = a; // compile time error since a is null

  // b = a!; // runtime exception: Null check operator used on a null value

  User? u;
  int id = u?.id ?? 10;
  assert(id == 10);

  u = User();
  id = u?.id ?? 10;
  assert(id == 1);
}

void main() {
  test1();
}
