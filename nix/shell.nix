{ pkgs }:

pkgs.clangStdenv.mkDerivation (rec {
  name = "shell";
  buildInputs = with pkgs; [
    boost185
    catch2_3
    clang
    cmake
    cmake-language-server
    entr
  ];
})
