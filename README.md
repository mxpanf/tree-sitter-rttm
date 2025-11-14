# Tree Sitter RTTM

[![LICENSE](https://img.shields.io/gitlab/license/mxp-studying/mirea/artificial-intelligence-methods?logo=opensourceinitiative&logoColor=white)](./LICENSE)
![Tree-sitter ABI](https://img.shields.io/badge/tree--sitter--ABI-15-blue)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.1-ff69b4.svg)](./CODE_OF_CONDUCT.md)
![CI](https://github.com/mxpanf/tree-sitter-rttm/actions/workflows/ci.yml/badge.svg)

A [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar for the **RTTM (Rich Transcription Time Marked)** format.

This parser provides a complete and robust grammar for the standard 10-column RTTM specification, used widely in audio processing, ASR, and speaker diarization tasks.

### Features

* **Robust Grammar:** (`grammar.js`) Parses all standard RTTM 10-column entries.
* **Highlighting:** (`queries/highlights.scm`) Provides highlighting queries for editors like Neovim and Helix.
* **Test Corpus:** (`corpus/`) Includes a rich test suite to ensure correctness.

![DEMO](./examples/neovim.webp)

-----

### RTTM Format Guide

This parser adheres to the 10-field RTTM specification. For a complete, human-readable breakdown of the format, its fields, and common "dialects" (like `SPEAKER` vs `LEXEME`), please see [the guide](./RTTM_GUIDE.md).
