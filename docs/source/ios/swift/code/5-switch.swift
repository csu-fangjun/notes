let vegetable = "red pepper"
switch vegetable {
  case "celery":
    print("celery")
  case "cucumber", "watercress":
    print("cucumber or watercress")
  case let x where x.hasSuffix("pepper"):
    print("x")
  default:
    print("Everything tastes good in soup.")
}
// 1. no need to use break
// 2. default is mandatory so that it is exhaustive
