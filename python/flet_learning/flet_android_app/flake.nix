{
description = "Flutter 3.13.x";
inputs = {
  nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  flake-utils.url = "github:numtide/flake-utils";
};
outputs = { self, nixpkgs, flake-utils }:
  flake-utils.lib.eachDefaultSystem (system:
    let
      pkgs = import nixpkgs {
        inherit system;
        config = {
          android_sdk.accept_license = true;
          allowUnfree = true;
        };
      };
      # buildToolsVersion = "34.0.0";
      androidComposition = pkgs.androidenv.composeAndroidPackages {
        buildToolsVersions = [ "34.0.0" "28.0.3" "30.0.3" ];
        platformVersions = [ "34" "28" "33" ];
        abiVersions = [ "armeabi-v7a" "arm64-v8a" ];
      };
      androidSdk = androidComposition.androidsdk;
    in
    {
      devShell =
        with pkgs; mkShell rec {
          ANDROID_SDK_ROOT = "${androidSdk}/libexec/android-sdk";
          buildInputs = [
            flutter
            androidSdk
            jdk17

  
            python312Packages.flet
            python312Packages.flet-runtime
            flet-client-flutter
          ];
        };
    });
}
