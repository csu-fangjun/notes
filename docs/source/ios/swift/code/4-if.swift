let individualScores = [75, 43, 103, 87, 12]
var teamScore = 0
for score in individualScores {
  if score > 50 {
    teamScore += 3
  } else {
    teamScore += 1
  }
}
// 11
print(teamScore)

var optionalString: String? = "Hello"
// false
print(optionalString == nil)

var optionalName: String? = "Tom"
var greeting = "Hello!"

// if optionalName is nil, then the condition is false
// if optionalName is not nil, then the condition is true and optionalName is unwrapped and assigned to name
if let name = optionalName {
  greeting = "Hello,\(name)"
}
// Hello,Tom
print(greeting)

let nickname: String? = nil
let fullName: String = "Tom Green"
// Hi, Tom Green
let informalGreeting = "Hi, \(nickname ?? fullName)"
// if nickname is not nil, then nickname is used
// if nickname is nil, then fullName is used

print(informalGreeting)

if let nickname {
  print("Hey, \(nickname)")
}

// if can be used as an expression!
let i = 3
let b = if i >= 0 {
    1
} else {
    -1
}

// 1
print(b)

var s: String?  // initialized to nil by default
print(s == nil) // true
