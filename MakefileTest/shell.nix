# Tip: direnv to keep dependencies for a specific project in Nix
# Run: nix-shell

# { pkgs ? import (builtins.fetchTarball { # https://nixos.wiki/wiki/FAQ/Pinning_Nixpkgs :
#   # Descriptive name to make the store path easier to identify
#   name = "nixos-unstable-2020-09-03";
#   # Commit hash for nixos-unstable as of the date above
#   url = "https://github.com/NixOS/nixpkgs/archive/702d1834218e483ab630a3414a47f3a537f94182.tar.gz";
#   # Hash obtained using `nix-prefetch-url --unpack <url>`
#   sha256 = "1vs08avqidij5mznb475k5qb74dkjvnsd745aix27qcw55rm0pwb";
# }) { }}:
# with pkgs;

{ pkgs ? import (builtins.fetchTarball { # https://nixos.wiki/wiki/FAQ/Pinning_Nixpkgs :
  # Descriptive name to make the store path easier to identify
  name = "nixos-unstable-2022-06-02";
  # Commit hash for nixos-unstable as of the date above
  url = "https://github.com/NixOS/nixpkgs/archive/d2a0531a0d7c434bd8bb790f41625e44d12300a4.tar.gz";
  # Hash obtained using `nix-prefetch-url --unpack <url>`
  sha256 = "13nwivn77w705ii86x1s4zpjld6r2l197pw66cr1nhyyhi5x9f7d";
}) { }}:
with pkgs;

let
  # VADL2022 "library" #
  python37m = (python37.overrideAttrs (oldAttrs: rec {
    configureFlags = oldAttrs.configureFlags ++ [ "--with-pymalloc" ]; # Enable Pymalloc
  })).override {
    #enableOptimizations = true; # If enabled: longer build time but 10% faster performance.. but the build is no longer reproducible 100% apparently (source: "15.21.2.2. Optimizations" of https://nixos.org/manual/nixpkgs/stable/ )
  };
  # #
in
mkShell {
  buildInputs = [
    # VADL2022 "library" #
    coreutils
    (python37m.withPackages (p: with p; ([
      pyserial
      
      # For Python interop #
      pybind11
      # #
      
    ])))

    ] ++ (lib.optionals (stdenv.hostPlatform.isLinux) [ (callPackage ./nix/pigpio.nix {}) ]) ++ [
    
    llvmPackages.libstdcxxClang
  ]; # Note: for macos need this: write this into the path indicated:
  # b) For `nix-env`, `nix-build`, `nix-shell` or any other Nix command you can add
  #   { allowUnsupportedSystem = true; }
  # to ~/.config/nixpkgs/config.nix.
  # ^^^^^^^^^^^^^^^^^^ This doesn't work, use `brew install cartr/qt4/pyqt` instead.
  
}
