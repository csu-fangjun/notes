// dart run --enable-asserts ./test-map.dart

// two ways to create an empty map
void test1() {
  final Map<String, int> a = {};
  final b = <String, int>{};
  assert(a.isEmpty);
  assert(b.isEmpty);
}

// create a map from literals
void test2() {
  final a = {
    'apple': 20,
    'cat': 10,
  };

  assert(a['cat'] == 10);
  assert(a['dog'] == null); // return null if the key does not exist

  a['dog'] = 50;
  assert(a['dog'] == 50);

  a['dog'] = 1;
  assert(a['dog'] == 1);

  a.remove('dog'); // remove an element from a map
  assert(a['dog'] == null);

  print(a); // {apple: 20, cat: 10}
  assert(a.length == 2);
  assert(a.isEmpty == false);
  assert(a.isNotEmpty == true);

  assert(a.containsKey('dog') == false);
}

void test3() {
  var a = <String, int>{
    'one': 1,
    'two': 2,
  };

  var sum = 0;

  // iterate the keys
  //
  // a[k] is of type int?
  for (final k in a.keys) {
    sum += a[k]!;
  }
  assert(sum == 3);

  sum = 0;

  // iterate the values
  for (final v in a.values) {
    sum += v;
  }
  assert(sum == 3);

  sum = 0;

  // iterate with key and value
  for (final entry in a.entries) {
    sum += entry.key.length + entry.value;
  }
  assert(sum == 3 + 3 + 1 + 2);
}

void main() {
  test1();
  test2();
  test3();
}
