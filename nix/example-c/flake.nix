{
  description = "example c package";

  inputs = {
    nixpkgs = {
      url = github:nixos/nixpkgs?ref=nixos-22.11;
    };
  };

  # outputs = { self, nixpkgs }: {
  #
  #   packages.x86_64-linux.hello = nixpkgs.legacyPackages.x86_64-linux.hello;
  #
  #   packages.x86_64-linux = {
  #
  #     default = self.packages.x86_64-linux.hello;
  #     thing1 = {
  #       thing2 = nixpkgs.legacyPackages.x86_64-linux.neofetch;
  #     };
  #   };
  #
  # };
  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      packages.${system} = {
        myPackage = pkgs.screenfetch;
        default = self.packages.myPackage;
      };
    };
}
