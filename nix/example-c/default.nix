{
  stdenv,
  raylib,
  ...
}: stdenv.mkDerivation {
  name = "myPackage";
  version = "v0.0.1";

  src = ./src;

  buildInput = [raylib];
  buildPhase = ''
    ls
    exit 1
    '';
}
