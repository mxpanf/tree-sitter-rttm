{
  description = "A Tree-sitter grammar for RTTM";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            nodejs_20
            nodePackages.tree-sitter-cli
            python3
            rustc
            cargo
            clang
            pkg-config
          ];

          shellHook = ''
            export TREE_SITTER_CLI=$(which tree-sitter)
            echo "Tree-sitter CLI: $TREE_SITTER_CLI"
          '';
        };
      });
}
