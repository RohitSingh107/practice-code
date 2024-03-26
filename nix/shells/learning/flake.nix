{
  description = "Flake for learning";

  inputs = {
    nixpkgs = {
      url = github:NixOS/nixpkgs/nixos-unstable;
    };
  };

  outputs = {
    self,
    nixpkgs,
    ...
  } @ inputs: let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in {
    devShells.${system} = rec {
      shellA = pkgs.mkShell {
        shellHook = ''

          echo "Welcome to Shell A" | ${pkgs.lolcat}/bin/lolcat

        '';

        buildInputs = with pkgs; [
          tldr
        ];
      };

      shellB = pkgs.mkShell {
        shellHook = ''

          echo "Welcome to Shell B" | ${pkgs.lolcat}/bin/lolcat


        '';

        buildInputs = with pkgs; [
          alejandra
        ];
        ENVB = "Some environment varianle";
      };

      default = shellB;
    };
  };
}
