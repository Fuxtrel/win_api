cmake_minimum_required(VERSION 3.21)
project(win_api)

set(CMAKE_CXX_STANDARD 23)

set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#add_library(win_api SHARED tmp.cpp)
add_executable(win_api main.cpp win_shortcuts.cpp win_shortcuts.h)
