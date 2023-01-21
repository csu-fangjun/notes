func greet(person: String, day: String) -> String {
  return "Hello \(person), today is \(day)"
}

print(greet(person: "Bob", day: "Tuesday"))
// print(greet("Bob", day: "Tuesday")) // error: missing argument label 'person:' in call

func greet2(_ person: String, on day: String) -> String {
  return "Hello \(person), today is \(day)"
}
// print(greet2(person: "Bob", day: "Tuesday")) // error: incorrect argument labels in call (have 'person:day:', expected '_:on:')
print(greet2("Bob", on: "Tuesday"))

func calculateStatistics(scores: [Int]) -> (min: Int, max: Int, sum: Int) {
  var min = scores[0]
  var max = scores[1]
  var sum = 0

  for score in scores {
    if score > max {
      max = score
    } else if score < min {
      min = score
    }

    sum += score
  }

  return (min, max, sum)
}
let statistics = calculateStatistics(scores: [5, 3, 100, 3, 9])
print(statistics.sum) // 120
print(statistics.2) // 120

func returnFifteen() -> Int {
  var y = 10
  func add() {
    y += 5
  }
  add()
  return y
}
print(returnFifteen()) // 15

func makeIncrementer() -> ((Int) -> Int) {
  func addOne(number: Int) -> Int {
    return number + 1
  }

  return addOne
}

var increment = makeIncrementer()
print(increment(7)) // 8

func hasAnyElement(list: [Int], condition: (Int) -> Bool) -> Bool {
  for item in list {
    if condition(item) {
      return true
    }
  }
  return false
}
func lessThanTen(number: Int) -> Bool {
  return number < 10
}

var numbers = [20, 19, 7, 12]
print(hasAnyElement(list: numbers, condition: lessThanTen)) // true

// the closure has to be put in {}
print(hasAnyElement(list: numbers, condition: {(number: Int) -> Bool in number < 1})) // false

// we can omit the input argument type and return type
print(hasAnyElement(list: numbers, condition: {number in number < 1})) // false

print(numbers.map({ (number: Int) -> Int in
  let result = 3 * number
  return result
})) // [60, 57, 21, 36]

let mappedNumber = numbers.map({number in 3 * number})
print(mappedNumber) // [60, 57, 21, 36]

var sortedNumbers = numbers.sorted {$0 > $1}
print(sortedNumbers) // [20, 19, 12, 7]

sortedNumbers = numbers.sorted {$0 < $1} // also ok
print(sortedNumbers) // [7, 12, 19, 20]
