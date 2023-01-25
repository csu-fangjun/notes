@main
public struct hello2 {
    public private(set) var text = "Hello, World!"

    public static func main() {
        print(hello2().text)
    }
}
