# RTTM: Rich Transcription Time Marked

### Full Specification (NIST-Compatible + Extended NON-SPEECH Convention)

## 1. Introduction

RTTM (**Rich Transcription Time Marked**) is a space-delimited, UTF-8 text format created by the **National Institute of Standards and Technology (NIST)**.
It is used to describe time-aligned events in audio (and occasionally video) recordings — including speech turns, lexical items, non-speech events, and metadata.

RTTM is employed in NIST evaluations such as **Rich Transcription (RT)**, **OpenKWS**, and **OpenSAT**.
The format is public domain and can be implemented freely.

This document describes:

1. The **canonical NIST RTTM format** (10 mandatory fields)
2. All **standard RTTM object types** from RT/MDE and KWS15
3. A **strict interpretation** appropriate for validation and tooling
4. A **clean extension** for NON-SPEECH events:

   * Field 6 (`orthography`) → fine-grained noise label (e.g. `keyboard`, `door_slam`)
   * Field 7 (`stype`) → coarse category: `noise`, `music`, `other`

The extension is backward-compatible with NIST’s structure.

---

## 2. Line Structure

Every non-comment, non-blank line represents a **single RTTM record**.

* Exactly **10 whitespace-separated fields**
* Fields that are unknown or not applicable MUST use `<NA>` (uppercase)
* Comments begin with `;;` and extend to the end of the line
* Inline comments are allowed
* Tokens cannot contain spaces; semicolons cannot appear inside tokens

Blank lines are ignored.

---

## 3. Required Fields (1–10)

This is the authoritative RTTM column order (from NIST KWS15 and RT/MDE):

| #  | Field Name (NIST) | Grammar field      | Description                             |
| -- | ----------------- | ------------------ | --------------------------------------- |
| 1  | `Type`            | `event_type`       | RTTM object type (see Section 4)        |
| 2  | `file`            | `file_id`          | Recording identifier                    |
| 3  | `chnl`            | `channel`          | Channel number (1-indexed) or `<NA>`    |
| 4  | `tbeg`            | `start_time`       | Onset time in seconds                   |
| 5  | `tdur`            | `duration`         | Duration in seconds                     |
| 6  | `ortho`           | `orthography`      | Word / noise descriptor / unit mnemonic |
| 7  | `stype`           | `speaker_type`     | Type-dependent subtype                  |
| 8  | `name`            | `speaker_id`       | Speaker or object label                 |
| 9  | `conf`            | `confidence`       | Confidence score (float)                |
| 10 | `Slat`            | `signal_look_time` | Legacy “signal lookahead time”          |

### Notes

* Numeric fields accept floats and scientific notation (`3e-1`)
* Leading/trailing whitespace is ignored
* All ten fields **must** be present even if `<NA>`

---

## 4. Standard RTTM Object Types

This guide supports the **union** of object types from:

* NIST KWS15 / OpenKWS
* NIST RT / MDE evaluations

Non-standard / deprecated object types are intentionally omitted.

### 4.1 Canonical Types (strict)

```
SPKR-INFO
TURN
SEGMENT
SPEAKER
FU
SU
LEXEME
NON-LEX
NON-SPEECH
NOSCORE
```

### 4.2 Description of each type

#### `SPKR-INFO`

Speaker metadata record.
`tbeg`, `tdur` are `<NA>`.
`stype` and `name` contain demographic attributes and speaker IDs.

#### `TURN`

Conversation-level turn boundaries (RT evaluations).

#### `SEGMENT`

Manual or automatic segmentation boundaries.

#### `SPEAKER`

Diarization units (“who spoke when”).
Typically:

```
SPEAKER file 1 12.34 1.25 <NA> <NA> spk1 <NA> <NA>
```

#### `FU` — Functional Units

Used in MDE corpora: minimal discourse units.

#### `SU` — Sentence Units

Higher-level discourse grouping.

#### `LEXEME`

Lexical items (ASR outputs).
`ortho` = the actual word.
`confidence` is heavily used.

#### `NON-LEX`

Non-lexical vocalizations (e.g. `laughter`, `breath`, `cough`).

#### `NON-SPEECH`

Environmental noise (music, background noise, doors, keyboard, traffic).
NIST constrains `stype ∈ {noise, music, other}`.
We extend the format as follows (Section 5).

#### `NOSCORE`

Regions excluded from scoring (KWS/OpenKWS evaluations).

---

## 5. Extended NON-SPEECH Convention (This Repository)

To preserve strict NIST compatibility while supporting detailed acoustic annotation, this repository adopts the following **structured extension**:

### For `NON-SPEECH` records:

| Field             | Meaning                                                                                     |
| ----------------- | ------------------------------------------------------------------------------------------- |
| 6 (`orthography`) | **fine-grained noise label** (e.g. `keyboard`, `door_slam`, `music_intro`, `traffic_heavy`) |
| 7 (`stype`)       | **coarse category** — MUST be one of: `noise`, `music`, `other`                             |
| 8 (`name`)        | Optional source label (e.g. `roomA`, `stage`) or `<NA>`                                     |

This preserves:

* the official KWS15 column semantics
* the canonical subtype set
* the strict 10-column format

but provides richer real-world annotation.

### Example:

```rttm
NON-SPEECH file_01 1 14.00 5.0 music_intro music <NA> 0.60 <NA>
NON-SPEECH file_01 1 19.50 0.8 keyboard_clicks noise <NA> 0.40 <NA>
NON-SPEECH file_01 1 21.00 1.2 door_slam noise <NA> 0.55 <NA>
```

Compatible with both NIST tools and extended tooling (e.g., LSP, visualizers).

---

## 6. Comments

* A comment line begins with **`;;`**
* Inline comments are permitted after the 10th field
* Example:

```rttm
;; File-level comment
SPEAKER rec1 1 10.34 2.15 <NA> <NA> spk1 <NA> <NA> ;; diarization
```

---

## 7. Validation Rules

A line is valid RTTM if and only if:

1. It contains **exactly 10 fields**
2. All mandatory fields follow NIST semantics
3. Numeric fields (if not `<NA>`) are valid numbers
4. `tbeg ≥ 0`, `tdur ≥ 0`
5. `<NA>` is uppercase and unquoted
6. No field contains spaces or semicolons

This grammar is strict:
If a line contains 8 or 9 tokens, it is **invalid** and must be padded with `<NA>`.

---

## 8. Examples

### 8.1 Minimal diarization

```rttm
SPEAKER rec1 1 10.34 1.25 <NA> <NA> spk1 <NA> <NA>
SPEAKER rec1 1 11.70 2.00 <NA> <NA> spk2 <NA> <NA>
```

### 8.2 Lexical (ASR)

```rttm
LEXEME rec1 1 10.34 0.22 hello <NA> spk1 0.98 <NA>
LEXEME rec1 1 10.56 0.31 world <NA> spk1 0.96 <NA>
```

### 8.3 Non-lexical

```rttm
NON-LEX rec1 1 14.50 0.50 laughter <NA> spk2 0.80 <NA>
```

### 8.4 NON-SPEECH (extended noise labels)

```rttm
NON-SPEECH rec1 1 5.00 1.20 keyboard noise <NA> 0.60 <NA>
NON-SPEECH rec1 1 7.00 3.00 music_intro music <NA> 0.70 <NA>
```

### 8.5 Metadata

```rttm
SPKR-INFO rec1 <NA> <NA> <NA> spk1 male adult <NA> <NA>
SEGMENT rec1 1 0.00 30.00 sceneA <NA> global <NA> <NA>
NOSCORE rec1 1 12.00 4.00 <NA> <NA> <NA> <NA> <NA>
```

---

## 9. Summary

This guide specifies:

* A **strict, NIST-compliant RTTM format**
* A unified set of RTTM object types from RT, MDE, and KWS15
* A clean, minimal, and safe **extension** for NON-SPEECH that:

  * preserves NIST subtype semantics
  * supports fine-grained real-world noise labels
  * remains compatible with legacy tools

This ensures the RTTM files you produce:

* validate cleanly
* interoperate with NIST toolchains
* support richer downstream analysis
* align fully with this repository’s grammar and editor tooling
