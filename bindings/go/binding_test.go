package tree_sitter_rttm_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_rttm "github.com/mxpanf/tree-sitter-rttm/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_rttm.Language())
	if language == nil {
		t.Errorf("Error loading Rich Transcription Time Marked grammar")
	}
}
