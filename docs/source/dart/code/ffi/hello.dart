import 'dart:ffi' as ffi;
import 'dart:io' show Platform, Directory;
import 'package:path/path.dart' as path;

typedef HelloWorldFunc = ffi.Int Function(ffi.Int, ffi.Int);

typedef HelloWorld = int Function(int, int);

void main() {
  var libraryPath = path.join(Directory.current.path, 'libfoo.so');
  if (Platform.isMacOS) {
    libraryPath = path.join(Directory.current.path, 'libfoo.dylib');
  }
  final dylib = ffi.DynamicLibrary.open(libraryPath);

  // Look up the C function 'hello_world'
  final HelloWorld hello =
      dylib.lookup<ffi.NativeFunction<HelloWorldFunc>>('add').asFunction();
  print(hello(2, 3));
}
