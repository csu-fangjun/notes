let individualScores = [75, 43, 103, 87, 12]
var teamScore = 0
for score in individualScores {
  if score > 50 {
    teamScore += 3
  } else {
    teamScore += 1
  }
}
print(teamScore) // 11

var optionalString: String? = "Hello"
print(optionalString == nil) // false

var optionalName: String? = "Tom"
var greeting = "Hello!"
if let name = optionalName {
  greeting = "Hello,\(name)"
}
print(greeting) // Hello,Tom

let nickname: String? = nil
let fullName: String = "Tom Green"
let informalGreeting = "Hi, \(nickname ?? fullName)" // Hi, Tom Green
print(informalGreeting)

if let nickname {
  print("Hey, \(nickname)")
}
