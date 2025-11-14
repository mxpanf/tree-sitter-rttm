# Tree Sitter RTTM

[![LICENSE](https://img.shields.io/gitlab/license/mxp-studying/mirea/artificial-intelligence-methods?logo=opensourceinitiative&logoColor=white)](./LICENSE)
![Tree-sitter ABI](https://img.shields.io/badge/tree--sitter--ABI-15-blue)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.1-ff69b4.svg)](./CODE_OF_CONDUCT.md)


![CI](https://github.com/mxpanf/tree-sitter-rttm/actions/workflows/ci.yml/badge.svg)
![Deploy](https://github.com/mxpanf/tree-sitter-rttm/actions/workflows/publish.yml/badge.svg)
[![Crates.io - Version](https://img.shields.io/crates/v/tree-sitter-rttm?logo=rust&logoColor=white)](https://crates.io/crates/tree-sitter-rttm)
[![PyPI - Version](https://img.shields.io/pypi/v/tree-sitter-rttm?logo=pypi&logoColor=white)](https://pypi.org/project/tree-sitter-rttm/)


A [Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar for the **RTTM (Rich Transcription Time Marked)** format.

This parser provides a complete and robust grammar for the standard 10-column RTTM specification, used widely in audio processing, ASR, and speaker diarization tasks.

### Features

* **Robust Grammar:** (`grammar.js`) Parses all standard RTTM 10-column entries.
* **Highlighting:** (`queries/highlights.scm`) Provides highlighting queries for editors like Neovim and Helix.
* **Test Corpus:** (`corpus/`) Includes a rich test suite to ensure correctness.

![DEMO](https://github.com/mxpanf/tree-sitter-rttm/blob/main/examples/neovim.webp?raw=true)

-----

### RTTM Format Guide

This parser adheres to the 10-field RTTM specification. For more details please see [the guide](https://github.com/mxpanf/tree-sitter-rttm/blob/main/RTTM_GUIDE.md).
