{ pkgs ? import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/nixos-unstable.tar.gz") { } } : 
pkgs.mkShell {

  nativeBuildInputs = with pkgs; [
    python312Packages.flet
    flet-client-flutter
    tldr
  ];
    
  shellHook = ''
    echo "Welcome to nix shell"

  '';
}
