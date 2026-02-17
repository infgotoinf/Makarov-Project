{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    raylib
    
    libGL

    # X11 dependencies
    libX11
    libX11.dev
    libXcursor
    libXi
    libXinerama
    libXrandr

    # Web support (uncomment to enable)
    # pkgs.emscripten

    cmake
    ninja
  ];

  shellHook = ''
    export CMAKE_GENERATOR=Ninja
    export CMAKE_BUILD_TYPE=Debug
  '';

  # Audio dependencies
  LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [pkgs.alsa-lib];
}
