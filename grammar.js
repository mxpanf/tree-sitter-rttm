/**
 * @file A Tree-sitter grammar for RTTM files
 * @author Maksim Panfilov <maks@panf.me>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const IDENTIFIER = /[A-Za-z0-9._-]+/;
const INTEGER = /\d+/;
const UNSIGNED_NUMBER = /\d+(?:\.\d+)?(?:[eE][-+]?\d+)?/;
const NUMBER = /-?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?/;
const TEXT = /[^\s;]+/;

module.exports = grammar({
  name: "rttm",

  // Whitespace (spaces, tabs, newlines) is ignored between tokens.
  extras: ($) => [/\s+/],

  rules: {
    // A file is zero or more lines
    source_file: ($) => repeat($._line),

    // A line is either a comment or an entry (optionally followed by an inline comment)
    _line: ($) =>
      choice(seq($.entry, optional(seq(/[ \t]+/, $.comment))), $.comment),

    // RTTM standard: a 10-field, space-delimited entry
    entry: ($) =>
      seq(
        field("event_type", $.event_type), // 1. Type
        field("file_id", $.file_id), // 2. File ID
        field("channel", $.channel), // 3. Channel
        field("start_time", $.start_time), // 4. Onset
        field("duration", $.duration), // 5. Duration
        field("orthography", $.orthography), // 6. Orthography
        field("speaker_type", $.speaker_type), // 7. Speaker Type
        field("speaker_id", $.speaker_id), // 8. Speaker ID
        field("confidence", $.confidence), // 9. Confidence
        field("signal_look_time", $.signal_look_time), // 10. SLAT
      ),

    // --- Field Definitions ---
    //
    // NIST / KWS15 object types.
    // NOTE:
    //  - "NON-SPEECH" is the canonical form per KWS15.
    //  - TURN/FU/SU are kept for RT / MDE-style corpora.
    event_type: ($) =>
      choice(
        "SPKR-INFO",
        "TURN",
        "SEGMENT",
        "SPEAKER",
        "FU",
        "SU",
        "LEXEME",
        "NON-LEX",
        "NON-SPEECH",
        "NOSCORE",
      ),
    file_id: ($) => choice($.null_literal, $.identifier),
    channel: ($) => choice($.null_literal, $.channel_number),
    // tbeg, tdur (seconds, >= 0; scientific notation allowed)
    start_time: ($) => choice($.time_value, $.null_literal),
    duration: ($) => choice($.time_value, $.null_literal),
    // Field 6: ortho
    //
    // KWS15: general "orthography" / descriptor.
    // Convention:
    //   - for LEXEME / NON-LEX: word / non-lexical token
    //   - for NON-SPEECH: fine-grained noise label (keyboard, door_slam, music_intro, ...)
    orthography: ($) => choice($.null_literal, $.text_value),
    // Field 7: stype
    //
    // KWS15: subtype; semantics depend on Type.
    // Convention:
    //   - for NON-SPEECH: coarse category in {noise, music, other}
    //   - for other types: free-form subset / demographic tag / classifier.
    speaker_type: ($) => choice($.null_literal, $.text_value),
    // Field 8: name
    //
    // Used as speaker / object label.
    speaker_id: ($) => choice($.null_literal, $.text_value),
    // Field 9: conf
    confidence: ($) => choice($.null_literal, $.number),
    // Field 10: Slat (signal lookahead time / legacy scoring field)
    signal_look_time: ($) => choice($.null_literal, $.number),

    // --- Base Tokens ---

    // A comment starts with ;; and goes to the end of the line
    comment: () => token(seq(";;", /.*/)),

    channel_number: () => token(INTEGER),
    time_value: () => token(UNSIGNED_NUMBER),
    number: () => token(NUMBER),
    identifier: () => token(IDENTIFIER),
    text_value: () => token(TEXT),
    null_literal: () => "<NA>",
  },
});
