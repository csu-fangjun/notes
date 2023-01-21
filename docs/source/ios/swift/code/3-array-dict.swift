var fruits = ["strawberries", "limes", "apples"]
fruits[1] = "grapes"

print(fruits) // ["strawberries", "grapes", "apples"]

fruits.append("blueberries")

var occupations = [
  "Tom": "Captain",
  "Jerry": "Mechanic",
]
print(occupations) // ["Tom": "Captain", "Jerry": "Mechanic"]
occupations["Tom"] = "Teacher"

let emptyArray: [String] = []
let emptyDict: [String: Float] = [:]
