class Shape {
  var numberOfSides = 0
  func simpleDescription() -> String {
    return "A shape with \(numberOfSides) sides."
  }
}

var shape = Shape()
print(shape.numberOfSides) // 0
shape.numberOfSides = 4
print(shape.numberOfSides) // 4
var simpleDescription = shape.simpleDescription()
print(simpleDescription) // A shape with 4 sides

// with constructor
class NamedShape {
  var numberOfSides = 0
  var name: String

  init(name: String, numberOfSides: Int) {
    self.name = name
    self.numberOfSides = numberOfSides
  }

  func simpleDescription() -> String {
    return "\(name): A shape with \(numberOfSides) sides"
  }
}

var namedShape = NamedShape(name: "Hello", numberOfSides: 10)
print(namedShape.simpleDescription())

class Square: NamedShape {
  var sideLength: Double

  init(sideLength: Double, name: String) {
    self.sideLength = sideLength
    super.init(name: name, numberOfSides: 4)
  }

  func area() -> Double {
    return sideLength * sideLength
  }

  override func simpleDescription() -> String {
    return "A square with side length \(sideLength)"
  }
}
var square = Square(sideLength: 10, name: "MySquare")
print(square.simpleDescription()) // A square with side length 10.0
print(square.area()) // 100.0

// property getter/setter

class EquilateralTriangle: NamedShape {
  var sideLength: Double = 0.0

  init(sideLength: Double, name: String) {
    self.sideLength = sideLength
    super.init(name: name, numberOfSides: 3)
  }

  var perimeter: Double {
    get {
      return 3.0 * sideLength
    }
    set {
      // note: the new value has the implicit name newValue
      sideLength = newValue / 3.0
    }
  }

  override func simpleDescription() -> String {
    return "An equilateral triangle with side of length \(sideLength)."
  }
}
var triangle = EquilateralTriangle(sideLength: 10, name: "MyTriangle")
print(triangle.perimeter) // 30.0
triangle.perimeter = 15
print(triangle.perimeter) // 15.0
print(triangle.sideLength) // 5.0
