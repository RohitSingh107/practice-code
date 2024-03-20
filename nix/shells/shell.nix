

{ pkgs ? import <nixpkgs> {} }: pkgs.mkShell 
{

  nativeBuildInputs = with pkgs; [
    python312Packages.ipython
    tldr
  ];

  shellHook = ''

    echo "Welcome to my custom shell"

    echo "I can also do this" | ${pkgs.lolcat}/bin/lolcat

  '';

  MY_ENV_VAR = "This is custom defined env variable";

  PASSWORD = import ./password.nix;

}

