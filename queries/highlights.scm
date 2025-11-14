;; Syntax highlighting queries for RTTM

;; Comments
(comment) @comment

;; Event types (SPEAKER / etc.)
(event_type) @keyword

;; File/channel IDs
(file_id (identifier) @constant)
(file_id (null_literal) @comment)

(channel (channel_number) @number)
(channel (null_literal) @comment)

;; Timing fields
(start_time (time_value) @time_value)
(duration (time_value) @time_value)

;; Orthography / textual metadata
(orthography (text_value) @string)
(orthography (null_literal) @comment)

(speaker_type (text_value) @type)
(speaker_type (null_literal) @comment)

(signal_look_time (number) @number)
(signal_look_time (null_literal) @comment)

;; Speaker identifiers: treat "real" IDs as constants, <NA> as comments.
(speaker_id (text_value) @constant)
(speaker_id (null_literal) @comment)

;; Confidence scores (number or <NA>)
(confidence (number) @number)
(confidence (null_literal) @comment)
