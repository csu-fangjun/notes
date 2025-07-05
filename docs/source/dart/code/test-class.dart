// dart run --enable-asserts ./test-class.dart

class User {
  int id = 0;
  String name = '';

  @override
  String toString() {
    return 'User(id: $id, name: $name)';
  }

  String toJson() {
    return '{"id":$id, "name":"$name"}';
  }
} // no trailing ;

void testUser() {
  final user = User();
  print(user); // User(id: 0, name: )

  user.id = 20;
  print(user); // User(id: 20, name: )
  print(user.toJson()); // {"id":20, "name":""}

  var user2 = User();
  user2.name = 'hello';
  user2.id = 10;
  print(user2); // User(id: 10, name: hello)

  // cascade notation
  user2 = User()
    ..name = 'hello'
    ..id = 10;
  print(user2); // User(id: 10, name: hello)

  // assign by reference
  var user3 = user2;
  user3.id = 100;
  assert(user2.id == 100);
}

class Point {
  int _x = 0;

  // getter
  int get x => _x;

  // getter
  int get x2 => _x + 2;

  // computed property
  int get x3 {
    return _x + 3;
  }

  // setter
  set myX(int v) => _x = v;

  // define another getter
  int get myX => _x;

  // validate the value
  set myX2(int v) {
    if (v < 10) {
      print('v should be >= 10. Given: $v');
      return;
    }

    _x = v;
  }
}

void testPoint() {
  final p = Point();
  assert(p._x == 0);
  assert(p.x == 0);
  assert(p.x2 == 2);

  p._x = 100;
  assert(p.x == 100);
  assert(p.x2 == 102);
  assert(p.x3 == 103);

  p.myX = 5;
  assert(p._x == 5);
  assert(p.x == 5);
  assert(p.myX == 5);

  p.myX2 = 12;
  assert(p.x == 12);

  p.myX2 = 9; // we have required the value should be >= 10
  assert(p.x == 12);

  p.myX2 = 13;
  assert(p.x == 13);
}

class Point2 {
  // long form constructor
  // x and y are required positional arguments
  Point2(int x, int y) {
    this.x = x;
    this.y = y;
  }
  int x = 0;
  int y = 0;
}

void testPoint2() {
  final p = Point2(10, 20);
  assert(p.x == 10);
  assert(p.y == 20);
}

class Point3 {
  // short form constructor
  Point3(this.x, this.y);
  int x = 0;
  int y = 0;
}

void testPoint3() {
  final p = Point3(100, 200);
  assert(p.x == 100);
  assert(p.y == 200);
}

// we can have many named constructors
class Point4 {
  Point4(this.x, this.y);

  // named constructor
  Point4.myPoint() {
    x = 10;
    y = 20;
  }

  Point4.myPoint2(int x) {
    this.x = x;
    y = 200;
  }

  // forwarding constructor, this(1, 2) is Point4(1, 2)
  Point4.myPoint3() : this(1, 2);

  factory Point4.myPoint4(int x, int y) {
    // there is no this inside the factory constructor
    // we need to create and return an object

    // we can validate, and even change the passed argument
    return Point4(x + 2, y + 3);
  }

  int x = 0;
  int y = 0;
}

void testPoint4() {
  var p = Point4.myPoint();
  assert(p.x == 10);
  assert(p.y == 20);

  p = Point4.myPoint2(-1);
  assert(p.x == -1);
  assert(p.y == 200);

  p = Point4.myPoint3();
  assert(p.x == 1);
  assert(p.y == 2);

  p = Point4.myPoint4(11, 22);
  assert(p.x == 11 + 2);
  assert(p.y == 22 + 3);
}

void main() {
  testUser();
  testPoint();
  testPoint2();
  testPoint3();
  testPoint4();
}
