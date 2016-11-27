import XCTest
@testable import CTptpParsing

class CTptpParsingTests: XCTestCase {
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
        XCTAssertEqual(CTptpParsing().text, "Hello, World!")
    }


    static var allTests : [(String, (CTptpParsingTests) -> () throws -> Void)] {
        return [
            ("testExample", testExample),
        ]
    }
}
