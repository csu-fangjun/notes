var fruits = ["strawberries", "limes", "apples"]
fruits[1] = "grapes"

print(fruits) // ["strawberries", "grapes", "apples"]

// resized automatically
fruits.append("blueberries")

// assign by copy!
var fruits2 = fruits
fruits2.append("banana")

print(fruits) // ["strawberries", "grapes", "apples", "blueberries"]
print(fruits2) // ["strawberries", "grapes", "apples", "blueberries", "banana"]

var occupations = [
  "Tom": "Captain",
  "Jerry": "Mechanic",
]
print(occupations) // ["Tom": "Captain", "Jerry": "Mechanic"]
occupations["Tom"] = "Teacher"

let emptyArray: [String] = []
let emptyDict: [String: Float] = [:]
