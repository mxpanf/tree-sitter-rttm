# RTTM: A Detailed Specification

## 1. Introduction

RTTM stands for **Rich Transcription Time Marked**. It is an open, plain-text specification format originally developed by the **National Institute of Standards and Technology (NIST)**.

Its primary purpose is to store time-marked annotations of audio or video data, created either by humans or by automated systems. It is most famously used in NIST's "Rich Transcription" (RT) evaluations, particularly for scoring **speaker diarization** (the task of identifying "who spoke when").

As a format specified by a U.S. government agency for research, RTTM is in the **public domain**, is not encumbered by patents, and can be freely implemented in any tool.

## 2. Format Overview

At its core, RTTM is a simple, space-delimited text format.

* **File Encoding:** UTF-8.
* **Structure:** Each valid, non-comment line represents a single time-based event.
* **Fields:** Every event line **must** contain exactly **10 fields**, separated by one or more spaces or tabs. Multiple spaces between fields are fine.
* **Null Values:** Fields that are not applicable or have no value *must* use the literal string `<NA>`.
* **Token form:** Except for `<NA>`, all non-numeric fields are single whitespace-free tokens. UTF-8 text is allowed (e.g. accents, apostrophes, slashes), but semicolons mark the start of comments and therefore cannot appear in field contents.
* **Identifiers:** File IDs traditionally follow `[A-Za-z0-9._-]+`. Speaker IDs and other metadata use the same character set in the original NIST corpora, but the grammar also accepts any other non-whitespace token so modern toolchains can attach richer tags.

## 3. Field-by-Field Specification

This table details all 10 mandatory fields in the order they must appear.

| # | Field Name | Permitted Values | Notes |
| :--- | :--- | :--- | :--- |
| 1 | `Type` | One of `SPKR-INFO`, `TURN`, `SEGMENT`, `SPEAKER`, `FU`, `SU`, `LEXEME`, `NON-LEX`, `NON_SPEECH`, `NON-SPEECH` | Hyphenated and underscored `NON[-_]SPEECH` both appear in the wild. Each type changes the semantics of fields 6–10. |
| 2 | `File ID` | `<NA>` or a single token matching `[A-Za-z0-9._-]+` | Usually the basename of the recording. `<NA>` appears in synthetic examples. |
| 3 | `Channel` | `<NA>` or a non-negative integer | Channel numbers are 1-indexed in NIST corpora. Use `<NA>` for mono or unknown channels. |
| 4 | `Onset` | Floating-point number or `<NA>` | `<NA>` is legal for metadata records (`SPKR-INFO`, some `TURN` descriptions). Times are measured in seconds from the start of the file and must be non-negative. |
| 5 | `Duration` | Floating-point number or `<NA>` | `<NA>` is legal for metadata records. Duration is in seconds and must be non-negative. |
| 6 | `Orthography` | `<NA>` or any non-whitespace token (UTF-8) without semicolons | Contains transcribed words, event mnemonics, or other descriptors. |
| 7 | `Speaker Type / Subset` | `<NA>` or any non-whitespace token (UTF-8) without semicolons | Used for demographic tags (e.g., `adult`, `child`) or subset labels. |
| 8 | `Speaker ID` | `<NA>` or any non-whitespace token (UTF-8) without semicolons | Identifies the speaker, entity, or event label. |
| 9 | `Confidence` | Floating-point number or `<NA>` | Confidence is typically between 0 and 1, but the spec does not clamp the range. |
| 10 | `SLAT` | Floating-point number or `<NA>` | "Signal Lookahead Time"; legacy scoring field that is almost always `<NA>`. |

### 3.1. Event types in detail

The `Type` field drives how the remaining columns should be interpreted:

* **`SPKR-INFO`** — Speaker metadata (gender, dialect, etc.). Timing fields are `<NA>`.
* **`TURN`** — Turn boundaries for conversation analysis.
* **`SEGMENT`** — Generic segmentation boundaries (often used for manual annotations).
* **`SPEAKER`** — Diarization segments indicating who is speaking.
* **`FU`** — Minimal *functional units* used in some MDE corpora.
* **`SU`** — *Sentence units* (a higher-level grouping of `FU` records).
* **`LEXEME`** — Lexical items (typically ASR word outputs).
* **`NON-LEX`** — Non-lexical vocalizations (laughter, breath, cough, etc.).
* **`NON_SPEECH` / `NON-SPEECH`** — Environmental non-speech events (music, noise, silence).

#### Why you might see fewer than 10 tokens in the wild

Occasionally official corpora circulate with only 8 or 9 tokens per row. Those files are malformed: the author dropped one or more trailing `<NA>` placeholders. NIST tooling (and this grammar) expect all ten fields to be present, even when a column's value is `<NA>`. If you encounter such data, pad the missing columns with `<NA>` before attempting to parse it.

---

## 4. Common "Dialects" & Use Cases

The meaning of the fields (especially `Orthography` and `Speaker ID`) changes based on the `Type` (Field 1). This creates three common "dialects" for RTTM.

### 4.1. Speaker Diarization (The most common use)

This is the classic RTTM use case: marking speech segments for different speakers.

* `Type` is **`SPEAKER`**.
* `Orthography` (Field 6) is almost always **`<NA>`**, as the content of the speech is not the focus.
* `Speaker ID` (Field 8) is the **key information**, identifying the speaker.

**Example:**
```rttm
SPEAKER file_01 1 10.34 2.15 <NA> <NA> spk_0 <NA> <NA>
SPEAKER file_01 1 12.80 0.90 <NA> <NA> spk_1 <NA> <NA>
```

### 4.2. Non-Speech and Non-Lexical Events

Use these records to describe sounds that are not lexical speech.

* `Type` is **`NON_SPEECH`** (or the hyphenated form `NON-SPEECH`) for environmental audio such as `music`, `applause`, or `noise`.
* `Type` is **`NON-LEX`** for vocalizations like laughter or breath that you wish to separate from spoken words.
* `Orthography` (Field 6) contains a short mnemonic (`music`, `laughter`, `cough`).
* `Speaker ID` (Field 8) often captures the noise source or repeats the speaker label.

**Example:**
```rttm
NON_SPEECH file_01 1 14.00 5.0 music <NA> stage <NA> <NA>
NON-LEX file_01 1 19.00 0.5 laughter <NA> spk_1 <NA> <NA>
```

### 4.3. Lexical Transcription (ASR Output)

This dialect is used to mark the time of individual words, as generated by an Automatic Speech Recognition (ASR) system.

* `Type` is **`LEXEME`**.
* `Orthography` (Field 6) is the **key information**, containing the transcribed word.
* `Speaker ID` (Field 8) identifies the speaker of that word.
* `Confidence` (Field 9) is often used here.

**Example:**
```rttm
LEXEME file_01 1 10.34 0.25 hello <NA> spk_0 0.98 <NA>
LEXEME file_01 1 10.60 0.30 world <NA> spk_0 0.95 <NA>
```

### 4.4. Metadata rows (`SPKR-INFO`, `TURN`, `SEGMENT`)

These records carry contextual information rather than time-aligned speech content.

* Timing columns are `<NA>` for `SPKR-INFO` and often `<NA>` when the boundary is unknown.
* `Orthography` (field 6) stores the speaker identifier or turn label.
* `Speaker Type` (field 7) captures attributes such as gender, dialect, or channel class.
* `Speaker ID` (field 8) can repeat the speaker tag (for convenience) or encode higher-level grouping.

Because the structure is still ten columns wide, downstream tooling can safely skip unneeded metadata by filtering on `Type`.

### 4.5. Functional and Sentence Units (`FU`, `SU`)

Functional (`FU`) and sentence (`SU`) units are primarily used by the Multiple Discourse Evaluation (MDE) corpora. They mark discourse-level segments on top of diarization records.

* `Orthography` (field 6) stores a mnemonic (e.g., `backchannel`, `statement`).
* `Speaker Type` is usually `<NA>`.
* `Speaker ID` carries the diarization label that the unit belongs to.

---

## 5. Validation Checklist

When producing or reviewing RTTM files, verify the following:

1. **Exactly 10 tokens** (separated by whitespace) appear on every non-comment, non-blank line. If you see fewer than ten, one of the `<NA>` placeholders was omitted and the line is invalid.
2. **Numeric fields** (`Onset`, `Duration`, `Confidence`, `SLAT`) use a dot (`.`) as the decimal separator and can omit the fractional part (`15` is valid for `15.0`). Scientific notation (e.g., `3e-1`) is legal.
3. **Timing non-negativity:** When numeric, `Onset` and `Duration` are measured from the start of the recording and therefore must be greater than or equal to zero.
4. **Metadata timing**: For `SPKR-INFO`, and in rare cases for `TURN`/`SEGMENT`, both `Onset` and `Duration` legitimately contain `<NA>`. Do not drop the columns.
5. **Identifiers contain no spaces**. If a tooling pipeline needs richer tags, it must still encode them as a single token (for example, replace whitespace with underscores or use slashes).
6. **`<NA>` is uppercase** and never quoted. Any other representation (`NA`, `None`, `null`) is invalid.
7. **Comments** always begin with `;;`. If you need to annotate an entry inline, append `;; note...` after the tenth field or at the previous line.

Following this checklist keeps the files compatible with both the original NIST scoring tools and modern parsers such as this Tree-sitter grammar.

## 6. Comments

RTTM files can contain comments.

* Any line beginning with two semicolons (`;;`) is considered a comment and must be ignored by parsers.
* Inline comments are permitted: a comment that follows a valid event on the same line is treated as a separate comment line. This is common when annotators tack on notes at the end of an entry.
* Comments may be indented, may appear between blank lines, and can contain arbitrary text.

**Example:**
```rttm
;; This is a file-level comment.
SPEAKER file_01 1 10.34 2.15 <NA> <NA> spk_0 <NA> <NA> ;; raw diarization output
    ;; Processed by NIST-Tool v5 on 2025-11-13
```
