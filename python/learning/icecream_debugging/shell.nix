{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell
{
  nativeBuildInputs = with pkgs; [
    python312Packages.ipython
    python312Packages.black
    python312Packages.black

    (python312.withPackages (
      ps:
        with ps; [
          black
          icecream
        ]
    ))
  ];

  shellHook = ''

    echo "Welcome to my custom shell"

  '';
}
