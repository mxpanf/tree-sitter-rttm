#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 29
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 26
#define ALIAS_COUNT 0
#define TOKEN_COUNT 9
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 10
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_SPEAKER = 1,
  anon_sym_NON_SPEECH = 2,
  anon_sym_LEXEME = 3,
  aux_sym_file_id_token1 = 4,
  aux_sym_start_time_token1 = 5,
  sym_comment = 6,
  sym_identifier = 7,
  sym_null_literal = 8,
  sym_source_file = 9,
  sym__line = 10,
  sym_entry = 11,
  sym_event_type = 12,
  sym_file_id = 13,
  sym_channel = 14,
  sym_start_time = 15,
  sym_duration = 16,
  sym_orthography = 17,
  sym_speaker_type = 18,
  sym_speaker_id = 19,
  sym_confidence = 20,
  sym_signal_look_time = 21,
  sym_number = 22,
  sym_field_value = 23,
  sym_number_or_na_value = 24,
  aux_sym_source_file_repeat1 = 25,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SPEAKER] = "SPEAKER",
  [anon_sym_NON_SPEECH] = "NON_SPEECH",
  [anon_sym_LEXEME] = "LEXEME",
  [aux_sym_file_id_token1] = "file_id_token1",
  [aux_sym_start_time_token1] = "start_time_token1",
  [sym_comment] = "comment",
  [sym_identifier] = "_identifier",
  [sym_null_literal] = "_null",
  [sym_source_file] = "source_file",
  [sym__line] = "_line",
  [sym_entry] = "entry",
  [sym_event_type] = "event_type",
  [sym_file_id] = "file_id",
  [sym_channel] = "channel",
  [sym_start_time] = "start_time",
  [sym_duration] = "duration",
  [sym_orthography] = "orthography",
  [sym_speaker_type] = "speaker_type",
  [sym_speaker_id] = "speaker_id",
  [sym_confidence] = "confidence",
  [sym_signal_look_time] = "signal_look_time",
  [sym_number] = "_number",
  [sym_field_value] = "_field",
  [sym_number_or_na_value] = "_number_or_na",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SPEAKER] = anon_sym_SPEAKER,
  [anon_sym_NON_SPEECH] = anon_sym_NON_SPEECH,
  [anon_sym_LEXEME] = anon_sym_LEXEME,
  [aux_sym_file_id_token1] = aux_sym_file_id_token1,
  [aux_sym_start_time_token1] = aux_sym_start_time_token1,
  [sym_comment] = sym_comment,
  [sym_identifier] = sym_identifier,
  [sym_null_literal] = sym_null_literal,
  [sym_source_file] = sym_source_file,
  [sym__line] = sym__line,
  [sym_entry] = sym_entry,
  [sym_event_type] = sym_event_type,
  [sym_file_id] = sym_file_id,
  [sym_channel] = sym_channel,
  [sym_start_time] = sym_start_time,
  [sym_duration] = sym_duration,
  [sym_orthography] = sym_orthography,
  [sym_speaker_type] = sym_speaker_type,
  [sym_speaker_id] = sym_speaker_id,
  [sym_confidence] = sym_confidence,
  [sym_signal_look_time] = sym_signal_look_time,
  [sym_number] = sym_number,
  [sym_field_value] = sym_field_value,
  [sym_number_or_na_value] = sym_number_or_na_value,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SPEAKER] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NON_SPEECH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LEXEME] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_file_id_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_start_time_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_null_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__line] = {
    .visible = false,
    .named = true,
  },
  [sym_entry] = {
    .visible = true,
    .named = true,
  },
  [sym_event_type] = {
    .visible = true,
    .named = true,
  },
  [sym_file_id] = {
    .visible = true,
    .named = true,
  },
  [sym_channel] = {
    .visible = true,
    .named = true,
  },
  [sym_start_time] = {
    .visible = true,
    .named = true,
  },
  [sym_duration] = {
    .visible = true,
    .named = true,
  },
  [sym_orthography] = {
    .visible = true,
    .named = true,
  },
  [sym_speaker_type] = {
    .visible = true,
    .named = true,
  },
  [sym_speaker_id] = {
    .visible = true,
    .named = true,
  },
  [sym_confidence] = {
    .visible = true,
    .named = true,
  },
  [sym_signal_look_time] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_field_value] = {
    .visible = true,
    .named = true,
  },
  [sym_number_or_na_value] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 4,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(31);
      if (lookahead == ';') ADVANCE(1);
      if (lookahead == '<') ADVANCE(20);
      if (lookahead == 'L') ADVANCE(10);
      if (lookahead == 'N') ADVANCE(23);
      if (lookahead == 'S') ADVANCE(24);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 1:
      if (lookahead == ';') ADVANCE(39);
      END_STATE();
    case 2:
      if (lookahead == '<') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 3:
      if (lookahead == '<') ADVANCE(22);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 4:
      if (lookahead == '>') ADVANCE(41);
      END_STATE();
    case 5:
      if (lookahead == '>') ADVANCE(35);
      END_STATE();
    case 6:
      if (lookahead == 'A') ADVANCE(4);
      END_STATE();
    case 7:
      if (lookahead == 'A') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 'A') ADVANCE(5);
      END_STATE();
    case 9:
      if (lookahead == 'C') ADVANCE(17);
      END_STATE();
    case 10:
      if (lookahead == 'E') ADVANCE(28);
      END_STATE();
    case 11:
      if (lookahead == 'E') ADVANCE(19);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(34);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(26);
      END_STATE();
    case 14:
      if (lookahead == 'E') ADVANCE(9);
      END_STATE();
    case 15:
      if (lookahead == 'E') ADVANCE(7);
      END_STATE();
    case 16:
      if (lookahead == 'E') ADVANCE(14);
      END_STATE();
    case 17:
      if (lookahead == 'H') ADVANCE(33);
      END_STATE();
    case 18:
      if (lookahead == 'K') ADVANCE(13);
      END_STATE();
    case 19:
      if (lookahead == 'M') ADVANCE(12);
      END_STATE();
    case 20:
      if (lookahead == 'N') ADVANCE(6);
      END_STATE();
    case 21:
      if (lookahead == 'N') ADVANCE(29);
      END_STATE();
    case 22:
      if (lookahead == 'N') ADVANCE(8);
      END_STATE();
    case 23:
      if (lookahead == 'O') ADVANCE(21);
      END_STATE();
    case 24:
      if (lookahead == 'P') ADVANCE(15);
      END_STATE();
    case 25:
      if (lookahead == 'P') ADVANCE(16);
      END_STATE();
    case 26:
      if (lookahead == 'R') ADVANCE(32);
      END_STATE();
    case 27:
      if (lookahead == 'S') ADVANCE(25);
      END_STATE();
    case 28:
      if (lookahead == 'X') ADVANCE(11);
      END_STATE();
    case 29:
      if (lookahead == '_') ADVANCE(27);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SPEAKER);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_NON_SPEECH);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_LEXEME);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_file_id_token1);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_file_id_token1);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym_start_time_token1);
      if (lookahead == '.') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_start_time_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_null_literal);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SPEAKER] = ACTIONS(1),
    [anon_sym_NON_SPEECH] = ACTIONS(1),
    [anon_sym_LEXEME] = ACTIONS(1),
    [aux_sym_start_time_token1] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_null_literal] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(27),
    [sym__line] = STATE(2),
    [sym_entry] = STATE(2),
    [sym_event_type] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_SPEAKER] = ACTIONS(5),
    [anon_sym_NON_SPEECH] = ACTIONS(5),
    [anon_sym_LEXEME] = ACTIONS(5),
    [sym_comment] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    ACTIONS(11), 1,
      sym_comment,
    STATE(12), 1,
      sym_event_type,
    ACTIONS(5), 3,
      anon_sym_SPEAKER,
      anon_sym_NON_SPEECH,
      anon_sym_LEXEME,
    STATE(3), 3,
      sym__line,
      sym_entry,
      aux_sym_source_file_repeat1,
  [20] = 5,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(18), 1,
      sym_comment,
    STATE(12), 1,
      sym_event_type,
    ACTIONS(15), 3,
      anon_sym_SPEAKER,
      anon_sym_NON_SPEECH,
      anon_sym_LEXEME,
    STATE(3), 3,
      sym__line,
      sym_entry,
      aux_sym_source_file_repeat1,
  [40] = 1,
    ACTIONS(21), 7,
      ts_builtin_sym_end,
      anon_sym_SPEAKER,
      anon_sym_NON_SPEECH,
      anon_sym_LEXEME,
      aux_sym_start_time_token1,
      sym_comment,
      sym_null_literal,
  [50] = 1,
    ACTIONS(23), 5,
      ts_builtin_sym_end,
      anon_sym_SPEAKER,
      anon_sym_NON_SPEECH,
      anon_sym_LEXEME,
      sym_comment,
  [58] = 5,
    ACTIONS(25), 1,
      aux_sym_start_time_token1,
    ACTIONS(27), 1,
      sym_null_literal,
    STATE(9), 1,
      sym_confidence,
    STATE(20), 1,
      sym_number,
    STATE(23), 1,
      sym_number_or_na_value,
  [74] = 1,
    ACTIONS(29), 5,
      ts_builtin_sym_end,
      anon_sym_SPEAKER,
      anon_sym_NON_SPEECH,
      anon_sym_LEXEME,
      sym_comment,
  [82] = 3,
    STATE(10), 1,
      sym_speaker_type,
    STATE(18), 1,
      sym_field_value,
    ACTIONS(31), 2,
      sym_identifier,
      sym_null_literal,
  [93] = 3,
    STATE(5), 1,
      sym_signal_look_time,
    STATE(7), 1,
      sym_field_value,
    ACTIONS(33), 2,
      sym_identifier,
      sym_null_literal,
  [104] = 3,
    STATE(6), 1,
      sym_speaker_id,
    STATE(19), 1,
      sym_field_value,
    ACTIONS(33), 2,
      sym_identifier,
      sym_null_literal,
  [115] = 3,
    STATE(8), 1,
      sym_orthography,
    STATE(17), 1,
      sym_field_value,
    ACTIONS(31), 2,
      sym_identifier,
      sym_null_literal,
  [126] = 2,
    ACTIONS(35), 1,
      aux_sym_file_id_token1,
    STATE(13), 1,
      sym_file_id,
  [133] = 2,
    ACTIONS(37), 1,
      aux_sym_file_id_token1,
    STATE(15), 1,
      sym_channel,
  [140] = 2,
    ACTIONS(39), 1,
      aux_sym_start_time_token1,
    STATE(11), 1,
      sym_duration,
  [147] = 2,
    ACTIONS(41), 1,
      aux_sym_start_time_token1,
    STATE(14), 1,
      sym_start_time,
  [154] = 1,
    ACTIONS(43), 2,
      sym_identifier,
      sym_null_literal,
  [159] = 1,
    ACTIONS(45), 2,
      sym_identifier,
      sym_null_literal,
  [164] = 1,
    ACTIONS(47), 2,
      sym_identifier,
      sym_null_literal,
  [169] = 1,
    ACTIONS(49), 2,
      aux_sym_start_time_token1,
      sym_null_literal,
  [174] = 1,
    ACTIONS(51), 2,
      sym_identifier,
      sym_null_literal,
  [179] = 1,
    ACTIONS(21), 2,
      sym_identifier,
      sym_null_literal,
  [184] = 1,
    ACTIONS(53), 2,
      sym_identifier,
      sym_null_literal,
  [189] = 1,
    ACTIONS(55), 2,
      sym_identifier,
      sym_null_literal,
  [194] = 1,
    ACTIONS(57), 1,
      aux_sym_file_id_token1,
  [198] = 1,
    ACTIONS(59), 1,
      aux_sym_start_time_token1,
  [202] = 1,
    ACTIONS(61), 1,
      aux_sym_file_id_token1,
  [206] = 1,
    ACTIONS(63), 1,
      ts_builtin_sym_end,
  [210] = 1,
    ACTIONS(65), 1,
      aux_sym_start_time_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 20,
  [SMALL_STATE(4)] = 40,
  [SMALL_STATE(5)] = 50,
  [SMALL_STATE(6)] = 58,
  [SMALL_STATE(7)] = 74,
  [SMALL_STATE(8)] = 82,
  [SMALL_STATE(9)] = 93,
  [SMALL_STATE(10)] = 104,
  [SMALL_STATE(11)] = 115,
  [SMALL_STATE(12)] = 126,
  [SMALL_STATE(13)] = 133,
  [SMALL_STATE(14)] = 140,
  [SMALL_STATE(15)] = 147,
  [SMALL_STATE(16)] = 154,
  [SMALL_STATE(17)] = 159,
  [SMALL_STATE(18)] = 164,
  [SMALL_STATE(19)] = 169,
  [SMALL_STATE(20)] = 174,
  [SMALL_STATE(21)] = 179,
  [SMALL_STATE(22)] = 184,
  [SMALL_STATE(23)] = 189,
  [SMALL_STATE(24)] = 194,
  [SMALL_STATE(25)] = 198,
  [SMALL_STATE(26)] = 202,
  [SMALL_STATE(27)] = 206,
  [SMALL_STATE(28)] = 210,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(24),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field_value, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entry, 10),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signal_look_time, 1),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_duration, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_orthography, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_speaker_type, 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_speaker_id, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_or_na_value, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_confidence, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_event_type, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_channel, 1),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_id, 1),
  [63] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_start_time, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_rttm(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
