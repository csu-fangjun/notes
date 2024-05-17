// run it with
// dart --enable-asserts ./test1.dart

void testDouble() {
  // control the number of decimal pointer when converting it to a string
  double i = 2.354;
  assert(i.toStringAsPrecision(1) == '2');
  assert(i.toStringAsPrecision(2) == '2.4');
  assert(i.toStringAsPrecision(3) == '2.35');
  assert(i.toStringAsPrecision(4) == '2.354');

  i = double.parse('2.32');
  assert(i == 2.32);

  assert(i.ceil() == 3);
  assert(i.floor() == 2);
}

void testInt() {
  int i = int.parse('23');
  assert(i == 23);
}

void testString() {
  var s = 'hello';
  var s2 = s + " world";
  assert(s2 == "hello world");

  assert("${s} world" == s2); // string interpolation
  assert("$s world" == s2); //  string interpolation

  s = '''like
python. multi line string
      ''';
  print(s);

  s = """another
      multi-line string
      """;
  print(s);
}

void testBoolean() {
  bool a = true;
  assert(a);
  bool c = 1 == 2;
  assert(!c);
}

void testList() {
  var a = [1, 2, 'a'];
  assert(a[0] == 1);
  assert(a[1] == 2);
  assert(a[2] == 'a');
  a.add(40.5);
  assert(a[3] == 40.5);
  print(a);

  var b = List.filled(3, 0); // b's capacity is fixed, cannot be changed.
  assert(b.length == 3);
  assert(b[0] == 0);
  assert(b[1] == 0);
  assert(b[2] == 0);
  // b.add(3); // compile time error. cannot change the size of b

  var c = [1, 3, 5];
  List<String> d = [];
  c.forEach((i) {
    d.add(i.toString());
  });
  assert(d.length == c.length);
  assert(d[0] == c[0].toString());
  assert(d[1] == c[1].toString());
  assert(d[2] == c[2].toString());

  // map returns an iterable; we use .toList() to convert it to a list
  List<String> f = c.map((i) {
    return i.toString();
  }).toList();
  assert(f.length == c.length);
  assert(f[0] == d[0]);
  assert(f[1] == d[1]);
  assert(f[2] == d[2]);

  List<int> li = [0, 1, 2, 3];
  for (int i = 0; i != li.length; ++i) {
    assert(i == li[i]);
  }

  for (var value in li) {
    assert(value == li[value]);
  }
}

void testNuallable() {
  int? a;
  assert(a == null);
  a = 3;
  assert(a == 3);
  int b = a!; // kotlin uses two !, while dart uses only one
  assert(b == 3);

  a = null;

  b = a ?? 10; // if a is null ,then assign 10 to b, else assign a to b
  assert(b == 10);

  a = 20;
  b = a ?? 10;
  assert(b == 20);
}

void main() {
  testDouble();
  testInt();
  testString();
  testBoolean();
  testList();
  testNuallable();
}
