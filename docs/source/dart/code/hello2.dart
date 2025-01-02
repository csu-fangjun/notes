// run it with
// dart ./hello2.dart
// or
// dart run ./hello2.dart
void main(List<String> args) {
  print('args: $args');
}
/*
dart hello2.dart --> args: []
dart hello2.dart a --> args: [a]

Note that arg[0] is not the exe name!

dart hello2.dart a bc --> args: [a, bc]
*/
