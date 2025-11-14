;; Syntax highlighting queries for RTTM (NIST-compatible)

;; Comments
(comment) @comment

;; Event types (SPEAKER / LEXEME / NON-SPEECH / etc.)
(event_type) @keyword

;; Null literal
(null_literal) @constant.builtin

;; Base tokens (fallbacks)
(identifier) @constant
(channel_number) @number
(time_value) @number
(number) @number
(text_value) @string

;; File / channel
(file_id (identifier) @namespace)
(channel (channel_number) @number)

;; Timing fields
(start_time (time_value) @number)
(duration (time_value) @number)

;; Orthography / descriptors
(orthography (text_value) @string)

;; stype / speaker_type
(speaker_type (text_value) @type)

;; Speaker / object labels
(speaker_id (text_value) @constant)

;; Confidence & SLAT
(confidence (number) @number)
(signal_look_time (number) @number)

;; LEXEME: orthography = ASR word
((entry
   (event_type) @_t
   (file_id)
   (channel)
   (start_time)
   (duration)
   (orthography (text_value) @string.special)
   (speaker_type)
   (speaker_id (text_value) @constant)
   (confidence (number) @number)
   (signal_look_time))
 (#match? @_t "^LEXEME$"))

;; NON-SPEECH: fine-grained noise label in orthography, stype=noise|music|other
((entry
   (event_type) @_t
   (file_id)
   (channel)
   (start_time)
   (duration)
   (orthography (text_value) @string.special)
   (speaker_type (text_value) @type)
   (speaker_id)
   (confidence (number) @number)
   (signal_look_time))
 (#match? @_t "^NON-SPEECH$"))

;; NON-LEX: non-lexical vocalizations (laughter, cough, ...)
((entry
   (event_type) @_t
   (file_id)
   (channel)
   (start_time)
   (duration)
   (orthography (text_value) @string.special)
   (speaker_type)
   (speaker_id (text_value) @constant)
   (confidence (number) @number)
   (signal_look_time))
 (#match? @_t "^NON-LEX$"))

;; SPEAKER: speaker_id as main object
((entry
   (event_type) @_t
   (file_id)
   (channel)
   (start_time)
   (duration)
   (orthography)
   (speaker_type)
   (speaker_id (text_value) @constant)
   (confidence)
   (signal_look_time))
 (#match? @_t "^SPEAKER$"))

;; SPKR-INFO: speaker metadata
((entry
   (event_type) @_t
   (file_id)
   (channel)
   (start_time)
   (duration)
   (orthography (text_value) @constant)
   (speaker_type (text_value) @type)
   (speaker_id (text_value) @constant)
   (confidence)
   (signal_look_time))
 (#match? @_t "^SPKR-INFO$"))
