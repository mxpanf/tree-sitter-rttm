# Changelog

All notable changes to this project will be documented in this file.

The format roughly follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and the project adheres to [Semantic Versioning](https://semver.org/).

## [Unreleased]

- Nothing yet.

## [0.1.0] - 2025-11-14

### Added

- Initial release of the Tree-sitter RTTM grammar, queries, examples, and editor support.
- Implemented basic support for the NIST RTTM format.
- Enforced non-negative validation for `start_time` and `duration`, plus a dedicated
  `invalid_numbers` corpus fixture guarding the behavior.
- Highlighted the new timing constraint in `RTTM_GUIDE.md` to keep the docs in sync
  with the grammar.
- Guarded against malformed input with missing trailing numeric tokens so that parser
  errors surface in predictable positions.
