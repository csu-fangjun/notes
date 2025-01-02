// run it with
// dart --enable-asserts ./test1.dart

void testDouble() {
  // control the number of decimal points when converting it to a string
  double i = 2.354;
  assert(i.toString() == '2.354');
  assert(i.toStringAsPrecision(1) == '2');
  assert(i.toStringAsPrecision(2) == '2.4');
  assert(i.toStringAsPrecision(3) == '2.35');
  assert(i.toStringAsPrecision(4) == '2.354');

  i = double.parse('2.32');
  assert(i == 2.32);

  assert(i.ceil() == 3);
  assert(i.floor() == 2);

  int a = i.toInt();
  assert(a == 2);
}

void testInt() {
  int i = int.parse('23');
  assert(i == 23);

  // note that i/2 is a double
  assert(i / 2 == 11.5);
  assert((i / 2) is double);

  assert((i / 1) is double);
  assert((i / 1) == 23.0);

  // truncation division: ~/
  assert((i ~/ 2) is int);
  assert((i ~/ 2) == 11);

  // see https://api.flutter.dev/flutter/dart-core/int/tryParse.html
  // int.tryParse() returns null if the input is not an integer
  int a = int.tryParse('30a') ?? -1;
  assert(a == -1);

  a = 10;

  a += 1;
  assert(a == 11);

  a -= 1;
  assert(a == 10);

  // note that both ++a and a++ are valid
  a++;
  assert(a == 11);

  ++a;
  assert(a == 12);
}

// the type is String, not string
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

  String a = 'abc';
  assert(a.toUpperCase() == 'ABC');

  a = 'ABC';

  // we can print a string on assertion failure
  assert(a.toLowerCase() == 'abc', "${a.toLowerCase()}");
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

  // we can also use final if we don't change value inside the loop
  for (final value in li) {
    assert(value == li[value]);
  }
}

void testList2() {
  // type is List<String>
  final aListOfStrings = ['one', 'two', 'three'];
  assert(aListOfStrings is List<String>);
  assert(aListOfStrings.isNotEmpty);

  // type is Set<String>
  final aSetOfStrings = {'one', 'two', 'three'};
  assert(aSetOfStrings is Set<String>);
  assert(aSetOfStrings.length == 3);
  assert(aSetOfStrings.contains('one'));
  assert(aSetOfStrings.contains('two'));
  assert(aSetOfStrings.contains('three'));

  // type is Map<String, int>
  final aMapOfStringsToInts = {
    'one': 1,
    'two': 2,
    'three': 3,
  };
  assert(aMapOfStringsToInts is Map<String, int>);
  assert(aMapOfStringsToInts.length == 3);
  assert(aMapOfStringsToInts['one'] == 1);
  assert(aMapOfStringsToInts['two'] == 2);
  assert(aMapOfStringsToInts['three'] == 3);

  final aListOfInt = <int>[];
  assert(aListOfInt is List<int>);

  assert(aListOfInt.isEmpty);

  aListOfInt.add(10);
  aListOfInt.add(20);
  assert(aListOfInt.length == 2);
  assert(aListOfInt[0] == 10);
  assert(aListOfInt[1] == 20);

  final aSetOfInt = <int>{};
  assert(aSetOfInt is Set<int>);

  final aMapOfIntToDouble = <int, double>{};
  assert(aMapOfIntToDouble is Map<int, double>);

  // final aListOfBaseType = <BaseType>[SubType(), SubType()];
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

void testTypeInference() {
  var a = 1;
  assert(a is int);

  var b = 's';
  assert(b is String);

  var c = 3.7;
  assert(c is double);

  var d = ['1', '2', '3'];
  assert(d is List<String>);

  var f = {
    'one': 1,
    'two': 2,
  };
  assert(f is Map<String, int>);
}

void testDynamic() {
  dynamic a = 1;
  assert(a is int);

  a = 2.5;
  assert(a is double);

  a = 'a';
  assert(a is String);
}

void testObject() {
  Object a = 1;
  assert(a is int);
  assert(a.runtimeType == int);

  int i = a as int; // type casting
  assert(i == 1);

  a = 2.5;
  assert(a is double);

  a = 'a';
  assert(a is String);
}

void testCompileTimeConstant() {
  const a = 1;
  assert(a is int);

  // specify the type explicitly
  const String b = 'hello';
  assert(b == 'hello');
}

void testRuntimeConstant() {
  double a = 5;
  final b = a / 2;
  assert(b is double);
  assert(b == 2.5);

  final int c = 3;
  assert(c == 3);
}

void main() {
  testDouble();
  testInt();
  testString();
  testBoolean();
  testList();
  testList2();
  testNuallable();
  testTypeInference();
  testDynamic();
  testObject();
  testCompileTimeConstant();
  testRuntimeConstant();
}
