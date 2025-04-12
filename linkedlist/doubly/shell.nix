{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    graphviz
    gnumake
    # Add other dependencies your project needs
    # For example:
    # gcc
    # gdb
    # valgrind
  ];

  shellHook = ''
    echo "Graphviz development environment loaded"
    echo "You can now use commands like dot, neato, fdp, etc."
  '';
}
