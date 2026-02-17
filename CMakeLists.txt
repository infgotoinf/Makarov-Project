cmake_minimum_required(VERSION 3.23)

project(MyProjectName)

add_executable(game)

target_sources(game
  PRIVATE
    main/main.c

  PUBLIC
    FILE_SET raylib_headers
    TYPE HEADERS
    BASE_DIRS
      external/raylib-5.5/src
    FILES
      external/raylib-5.5/src/raylib.h
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
