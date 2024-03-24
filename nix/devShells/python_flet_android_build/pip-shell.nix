{ pkgs ? import <nixpkgs> {} }:
(pkgs.buildFHSUserEnv {
  name = "pipzone";
  targetPkgs = pkgs: (with pkgs; [
    python312Packages.pip
    python312Packages.virtualenv
    python312Packages.flet
    python312Packages.flet-runtime
  ]);
}).env
