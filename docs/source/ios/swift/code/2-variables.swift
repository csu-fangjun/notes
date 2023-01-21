var myVariable = 42
myVariable = 50
let myConstant = 43
print("myVariable is \(myVariable)")
print("myConstant is \(myConstant)")

let implicitInteger = 1
let implicitDouble = 1.0
let explicitDouble: Double = 1

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
