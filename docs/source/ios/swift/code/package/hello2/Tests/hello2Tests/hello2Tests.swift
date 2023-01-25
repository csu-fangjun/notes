import XCTest
@testable import hello2

final class hello2Tests: XCTestCase {
    func testExample() throws {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct
        // results.
        XCTAssertEqual(hello2().text, "Hello, World!")
    }
}
