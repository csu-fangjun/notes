// dart run --enable-asserts ./test-isolate.dart

import 'dart:isolate';

void test1Isolate(SendPort sendPort) {
  sendPort.send('hello');
  sendPort.send('world');
  sendPort.send(null);
}

Future<void> test1() async {
  final receivePort = ReceivePort();
  final isolate = await Isolate.spawn<SendPort>(
    test1Isolate,
    receivePort.sendPort,
  );

  receivePort.listen((Object? message) {
    if (message is String) {
      print('message: $message');
    } else if (message == null) {
      receivePort.close();
      isolate.kill();
    }
  });
}

void main() {
  test1();
}
