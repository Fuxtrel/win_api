cmake_minimum_required(VERSION 3.21)
project(win_api)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(win_api main.cpp win_shortcuts.cpp win_shortcuts.h)
