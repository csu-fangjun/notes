var fruits = ["strawberries", "limes", "apples"]
fruits[1] = "grapes"

print(fruits) // ["strawberries", "grapes", "apples"]
precondition(fruits.isEmpty == false)
precondition(fruits.count == 3)

// resized automatically
fruits.append("blueberries")
precondition(fruits.count == 4)
precondition(fruits.first == "strawberries")
precondition(fruits.last == "blueberries")

// assign by copy!
var fruits2 = fruits
fruits2.append("banana")
precondition(fruits.last == "blueberries")
precondition(fruits2.last == "banana")

print(fruits) // ["strawberries", "grapes", "apples", "blueberries"]
print(fruits2) // ["strawberries", "grapes", "apples", "blueberries", "banana"]

var intArray: [Int] = [1, 2, 3]
precondition(intArray.count == 3)
precondition(intArray[0] == 1)
precondition(intArray[1] == 2)
precondition(intArray[2] == 3)
intArray = []
precondition(intArray.isEmpty)

var floatArray = Array(repeating: Float(0), count: 3)
precondition(floatArray.count == 3)
precondition(floatArray[0] == 0)
precondition(floatArray[1] == 0)
precondition(floatArray[2] == 0)

var floatArray2 = Array<Float>(repeating: 0, count: 3)
precondition(floatArray2.count == 3)
precondition(floatArray2[0] == 0)
precondition(floatArray2[1] == 0)
precondition(floatArray2[2] == 0)

var occupations = [
  "Tom": "Captain",
  "Jerry": "Mechanic",
]
print(occupations) // ["Tom": "Captain", "Jerry": "Mechanic"]
occupations["Tom"] = "Teacher"
precondition(occupations["Dan"] == nil) // not exist, so return nil

let emptyArray: [String] = []
let emptyDict: [String: Float] = [:]
