var myVariable = 42
myVariable = 50
let myConstant = 43
print("myVariable is \(myVariable)")
print("myConstant is \(myConstant)")

let implicitInteger = 1
let implicitDouble = 1.0
let explicitDouble: Double = 1
let myFloat: Float = 1.2

let label = "The width is "
let width = 100
var widthLabel = label + String(width)
widthLabel = "\(label)\(width)"
print(widthLabel)


// """
let s = """
  abc
  def
  """
// Note: there are leading spaces before the ending """
print(s)

/*
myVariable is 50
myConstant is 43
The width is 100
abc
def
*/
