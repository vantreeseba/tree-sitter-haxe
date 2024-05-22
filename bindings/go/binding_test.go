package tree_sitter_haxe_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-haxe"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_haxe.Language())
	if language == nil {
		t.Errorf("Error loading Haxe grammar")
	}
}
