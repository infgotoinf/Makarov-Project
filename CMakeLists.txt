cmake_minimum_required(VERSION 3.23)

project(MakarovProject)

add_executable(game)

target_sources(game
  PRIVATE
    main/main.c
    main/menus.c

  PUBLIC
    FILE_SET raylib_headers
    TYPE HEADERS
    BASE_DIRS
      external/raylib-5.5/src
      external/raygui-4.0/src
      main/include
    FILES
      external/raylib-5.5/src/raylib.h
      external/raygui-4.0/src/raygui.h

      main/include/window_codes.h
      main/include/menus.h
)

target_link_libraries(game
  PRIVATE
    raylib
    GL
    m
    pthread
    dl
    rt
    X11
)
