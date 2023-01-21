let interestingNumbers = [
  "Prime": [2, 3, 5, 7, 11, 13],
  "Fibonacci": [1, 1, 2, 3, 5, 8],
  "Square": [1, 4, 9, 16, 25],
]
var largest = 0
for (_, numbers) in interestingNumbers {
  for number in numbers {
    if number > largest {
      largest = number
    }
  }
}
print(largest) // 25

var total = 0
for i in 0..<4 {
  total += i
}
print(total) // 6

total = 0
for i in 0...4 {
  total += i
}
print(total) // 10
