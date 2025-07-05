// dart run --enable-asserts ./test-string.dart

// there is no char type
// both '' and "" are ok
void test1() {
  var s = 'hello';
  s = "hello";
}

void test2() {
  var s = 'hello';
  var s2 = s.toUpperCase();
  assert(s2 == 'HELLO');

  var s3 = s2.toLowerCase();
  assert(s3 == 'hello');

  // trim
  s = ' hello ';
  s2 = s.trim();
  assert(s2 == 'hello');

  // trim can also trim \n \r \t
  s = ' hello\n\r\t';
  s2 = s.trim();
  assert(s2 == 'hello');

  s = ' hello\n\r\t';
  s2 = s.trimLeft();
  assert(s2 == 'hello\n\r\t');

  s = ' hello\n\r\t';
  s2 = s.trimRight();
  assert(s2 == ' hello');
}

void test3() {
  var s = '1'.padLeft(2, '0');
  assert(s == '01');

  // 11 is already of length 2, so the pad is a no-op
  s = '11'.padLeft(2, '0');
  assert(s == '11');
}

// several ways to convert an integer to a string
void test4() {
  var s = 11.toString();
  assert(s == '11');

  // string interpolation
  var i = 11;
  s = '$i';
  assert(s == '11');
}

// split a string
// join a list of string
void test5() {
  var s = '1,2,3,4';
  var a = s.split(',');
  assert(a is List<String>);

  s = a.join('-');
  assert(s == '1-2-3-4');
}

void test6() {
  var a = '1,2,3';
  var b = a.replaceAll(',', '-');
  assert(b == '1-2-3');

  a = '1,2,3';
  b = a.replaceFirst(',', '-');
  assert(b == '1-2,3');
}

// use a string buffer to build a string
void test7() {
  var s = '0,1,2,3';
  final buffer = StringBuffer();
  var sep = '';
  for (int i = 0; i < 4; i++) {
    buffer.write(sep);
    buffer.write('$i');
    sep = ',';
  }
  var s2 = buffer.toString();
  assert(s == s2);
}

void test8() {
  var s = 'hello';
  assert(s.startsWith('h') == true);
  assert(s.startsWith('hel') == true);
  assert(s.startsWith('hi') == false);

  assert(s.endsWith('o') == true);
  assert(s.endsWith('lo') == true);
  assert(s.endsWith('alo') == false);

  assert(s.contains('ll'));
  assert(s.contains('lol') == false);
}

void main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
}
