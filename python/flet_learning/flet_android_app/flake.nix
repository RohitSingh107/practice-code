{
  description = "moxplatform";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    # nixpkgs.url = "github:NixOS/nixpkgs/23.05";
    flake-utils.url = "github:numtide/flake-utils";
    android-nixpkgs.url = "github:tadfisher/android-nixpkgs";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
    android-nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {
      inherit system;
      config = {
        android_sdk.accept_license = true;
        allowUnfree = true;
      };
    };
    # Everything to make Flutter happy
    sdk = android-nixpkgs.sdk.${system} (sdkPkgs:
      with sdkPkgs; [
        cmdline-tools-latest
        build-tools-30-0-3
        build-tools-33-0-2
        build-tools-34-0-0
        platform-tools
        emulator
        # patcher-v4
        platforms-android-30
        platforms-android-31
        platforms-android-33
        platforms-android-34

        ndk-23-1-7779620
        cmake-3-18-1
      ]);
    pinnedJDK = pkgs.jdk17;
  in {
    devShells.${system} = {
      default = pkgs.mkShell rec {
        buildInputs = with pkgs; [
          # Android
          pinnedJDK
          sdk

          # Flutter
          flutter
          dart

          # Code hygiene
          gitlint

          # Flutter dependencies for linux desktop
          atk
          cairo
          clang
          cmake
          epoxy
          gdk-pixbuf
          glib
          gtk3
          harfbuzz
          ninja
          pango
          pcre
          pcre2
          pkg-config
          xorg.libX11
          xorg.xorgproto
          clutter-gst
          mount
          libunwind

          python312Packages.flet
          python312Packages.flet-runtime
          flet-client-flutter

          libdwg
          elfutils
          zstd
          orc
          util-linux
          libselinux
          libsepol
          libthai
          libdatrie
          python312Packages.datrie
          xorg.libXdmcp
          xorg.libXtst
        ];

        # Make Flutter build on desktop
        CPATH = "${pkgs.xorg.libX11.dev}/include:${pkgs.xorg.xorgproto}/include";
        LD_LIBRARY_PATH = with pkgs; lib.makeLibraryPath [atk cairo epoxy gdk-pixbuf glib gtk3 harfbuzz pango];

        ANDROID_HOME = "${sdk}/share/android-sdk";
        ANDROID_SDK_ROOT = "${sdk}/share/android-sdk";
        JAVA_HOME = pinnedJDK;

        FLUTTER_ROOT = "${pkgs.flutter}";
        ANDROID_NDK_HOME = "${ANDROID_SDK_ROOT}/ndk/23.1.7779620/";

        # Fix an issue with Flutter using an older version of aapt2, which does not know
        # an used parameter.
        GRADLE_OPTS = "-Dorg.gradle.project.android.aapt2FromMavenOverride=${sdk}/share/android-sdk/build-tools/34.0.0/aapt2";

        # shellHook = ''
        #
        #   unset LD_LIBRARY_PATH
        #   unset GIO_EXTRA_MODULES
        #
        #   echo "Welcome to nix shell"
        #
        # '';
      };

      pipzone =
        (pkgs.buildFHSUserEnv {
          name = "pipzone";
          targetPkgs = pkgs: (with pkgs; [
            poetry
            python311Packages.pip
            python311Packages.virtualenv

            gtk3
            pango
            harfbuzz
            atk
            gst_all_1.gstreamer
            gst_all_1.gst-plugins-base

            mpv-unwrapped
            mpv

            # Android
            pinnedJDK
            sdk

            # Flutter
            flutter
            dart

            # Flutter dependencies for linux desktop
            cairo
            clang
            cmake
            epoxy
            gdk-pixbuf
            glib
            gtk3
            harfbuzz
            ninja
            pcre
            pcre2
            pkg-config
            xorg.libX11
            xorg.xorgproto
            clutter-gst
            mount
            libunwind

            libdwg
            elfutils
            zstd
            orc
            util-linux
            libselinux
            libsepol
            libthai
            libdatrie
            python312Packages.datrie
            xorg.libXdmcp
            xorg.libXtst
          ]);

          runScript = ''
            poetry shell
            
          '';

          profile = ''
            unset LD_LIBRARY_PATH
            unset GIO_EXTRA_MODULES
            export CHROME_EXECUTABLE=chromium

            export ANDROID_HOME=${sdk}/share/android-sdk
            export ANDROID_SDK_ROOT=${sdk}/share/android-sdk
            export JAVA_HOME=${pinnedJDK}
            export FLUTTER_ROOT=${pkgs.flutter}
            export ANDROID_NDK_HOME=$ANDROID_SDK_ROOT/ndk/23.1.7779620/

            export GRADLE_OPTS=-Dorg.gradle.project.android.aapt2FromMavenOverride=${sdk}/share/android-sdk/build-tools/34.0.0/aapt2
          '';
        })
        .env;
    };
  };
}
