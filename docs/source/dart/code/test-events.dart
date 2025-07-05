// dart run --enable-asserts ./test-events.dart

/*
There are two queues:
 - event queue (low priority)
 - micro task queue (high priority)

*/

/*
it prints
first
third
second
*/
void test1() {
  print('first');

  // add task to the event queue
  Future(() => print('second'));
  print('third');
}

/*
it prints
first
fourth
third
second
*/
void test2() {
  print('first');

  // add task to the event queue
  Future(() => print('second'));

  // add task to the micro task queue
  Future.microtask(() => print('third'));
  print('fourth');
}

void main() {
  // test1();
  test2();
}
