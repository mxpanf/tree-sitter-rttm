// swift-tools-version:5.3

import Foundation
import PackageDescription

var sources = ["src/parser.c"]
if FileManager.default.fileExists(atPath: "src/scanner.c") {
    sources.append("src/scanner.c")
}

let package = Package(
    name: "TreeSitterRttm",
    products: [
        .library(name: "TreeSitterRttm", targets: ["TreeSitterRttm"]),
    ],
    dependencies: [
        .package(name: "SwiftTreeSitter", url: "https://github.com/tree-sitter/swift-tree-sitter", from: "0.9.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterRttm",
            dependencies: [],
            path: ".",
            sources: sources,
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterRttmTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterRttm",
            ],
            path: "bindings/swift/TreeSitterRttmTests"
        )
    ],
    cLanguageStandard: .c11
)
