/**
 * @file A Tree-sitter grammar for RTTM files
 * @author Maksim Panfilov <maks@panf.me>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "rttm",

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ => "hello"
  }
});
