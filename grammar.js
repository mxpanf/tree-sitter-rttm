/**
 * @file A Tree-sitter grammar for RTTM files
 * @author Maksim Panfilov <maks@panf.me>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const IDENTIFIER = /[A-Za-z0-9._-]+/;
const NUMBER = /\d+(\.\d+)?/;

module.exports = grammar({
  name: "rttm",

  // Whitespace (spaces, tabs, newlines) is ignored between tokens.
  extras: ($) => [/\s+/],

  rules: {
    // A file is zero or more lines
    source_file: ($) => repeat($._line),

    // A line is either a comment or a data entry
    _line: ($) => choice($.comment, $.entry),

    // RTTM standard: a 10-field, space-delimited entry
    entry: ($) =>
      seq(
        $.event_type, // 1. Type
        $.file_id, // 2. File ID
        $.channel, // 3. Channel
        $.start_time, // 4. Onset
        $.duration, // 5. Duration
        $.orthography, // 6. Orthography
        $.speaker_type, // 7. Speaker Type
        $.speaker_id, // 8. Speaker ID
        $.confidence, // 9. Confidence
        $.signal_look_time, // 10. SLAT
      ),

    // --- Field Definitions ---

    event_type: ($) => choice("SPEAKER", "NON_SPEECH", "LEXEME"),
    file_id: ($) => token(choice("<NA>", IDENTIFIER)),
    channel: ($) => token(choice("<NA>", IDENTIFIER)), // Allows numeric or <NA>
    start_time: ($) => token(NUMBER),
    duration: ($) => token(NUMBER),
    orthography: ($) => seq(alias($.field_value, $._field)),
    speaker_type: ($) => seq(alias($.field_value, $._field)),
    speaker_id: ($) => seq(alias($.field_value, $._field)),
    confidence: ($) => seq(alias($.number_or_na_value, $._number_or_na)),
    signal_look_time: ($) => seq(alias($.field_value, $._field)), // Almost always <NA>

    // --- Base Tokens ---

    // A comment starts with ;; and goes to the end of the line
    comment: ($) => /;;.*/,

    number: () => token(NUMBER),
    identifier: () => token(IDENTIFIER),
    null_literal: () => "<NA>",

    field_value: ($) =>
      seq(
        choice(
          alias($.null_literal, $._null),
          alias($.identifier, $._identifier),
        ),
      ),

    number_or_na_value: ($) =>
      seq(choice(alias($.null_literal, $._null), alias($.number, $._number))),
  },
});
