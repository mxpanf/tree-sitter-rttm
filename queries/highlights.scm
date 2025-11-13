;; Syntax highlighting queries for RTTM

;; Comments
(comment) @comment

;; Event types (SPEAKER / etc.)
(event_type) @keyword

;; File/channel IDs
(file_id) @constant
(
  (file_id) @comment
  (#match? @comment "^<NA>$")
)

(channel) @property
(
  (channel) @comment
  (#match? @comment "^<NA>$")
)

;; Timing fields
(start_time) @number
(duration) @number

;; Orthography / textual metadata
(orthography
  (_field
    (_identifier) @string))
(orthography
  (_field
    (_null) @comment))

(speaker_type
  (_field
    (_identifier) @string))
(speaker_type
  (_field
    (_null) @comment))

(signal_look_time
  (_field
    (_identifier) @string))
(signal_look_time
  (_field
    (_null) @comment))

;; Speaker identifiers: treat "real" IDs as constants, <NA> as comments.
(speaker_id
  (_field
    (_identifier) @constant))
(speaker_id
  (_field
    (_null) @comment))

;; Confidence scores (number or <NA>)
(confidence
  (_number_or_na
    (_number) @number))
(confidence
  (_number_or_na
    (_null) @comment))
