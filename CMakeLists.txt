cmake_minimum_required(VERSION 3.21)
project(win_api)

set(CMAKE_CXX_STANDARD 23)

set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(lib_win_api SHARED win_shortcuts.cpp win_shortcuts.h)

add_executable(win_api main.cpp win_shortcuts.cpp win_shortcuts.h)

target_link_libraries(win_api lib_win_api)
