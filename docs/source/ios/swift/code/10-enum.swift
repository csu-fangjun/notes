enum Rank: Int {
  case ace = 1
  case two, three, four, five, six, seven, eight, nine, ten
  case jack, queen, king

  func simpleDescription() -> String {
    switch self {
      case .ace:
        return "ace"
      case .jack:
        return "jack"
      case .queen:
        return "queen"
      case .king:
        return "king"
      default:
        return String(self.rawValue)
    }
  }
}
let ace = Rank.ace
let aceRawValue = ace.rawValue
print(ace) // ace
print(aceRawValue) // 1

let two = Rank(rawValue: 2)
print(two ?? "zwei") // two
