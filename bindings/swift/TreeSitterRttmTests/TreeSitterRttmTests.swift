import XCTest
import SwiftTreeSitter
import TreeSitterRttm

final class TreeSitterRttmTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_rttm())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Rich Transcription Time Marked grammar")
    }
}
