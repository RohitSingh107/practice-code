# simple dev shell for simple haskell files 
# nix-shell -p "haskellPackages.ghcWithPackages ( p: [p.vector p.haskell-language-server])"
{ pkgs ? import <nixpkgs> {} }:

let
  myHaskell = pkgs.haskellPackages.ghcWithPackages myHaskellPackages;
  myHaskellPackages = p: with p; [
    vector
    haskell-language-server
    # Haskell Packages
  ];
in
pkgs.mkShell {
  buildInputs = [
    myHaskell
    # Other non haskell packages
  ];
}
