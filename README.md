# Tree Sitter RTTM

<a href="./LICENSE">
    <img alt="License" src="https://img.shields.io/gitlab/license/mxp-studying/mirea/artificial-intelligence-methods?style=flat-square&logo=opensourceinitiative&logoColor=white">
</a>
<a href="https://github.com/mxpanf/tree-sitter-rttm">
    <img alt="Last Commit" src="https://img.shields.io/github/last-commit/mxpanf/tree-sitter-rttm?style=flat-square&logo=github">
</a>


A [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar for the **RTTM (Rich Transcription Time Marked)** format.

This parser provides a complete and robust grammar for the standard 10-column RTTM specification, used widely in audio processing, ASR, and speaker diarization tasks.

### Features

* **Robust Grammar:** (`grammar.js`) Parses all standard RTTM 10-column entries.
* **Highlighting:** (`queries/highlights.scm`) Provides highlighting queries for editors like Neovim and Helix.
* **Test Corpus:** (`corpus/`) Includes a rich test suite to ensure correctness.

-----

### RTTM Format Guide

This parser adheres to the 10-field RTTM specification. For a complete, human-readable breakdown of the format, its fields, and common "dialects" (like `SPEAKER` vs `LEXEME`), please see the guide.
