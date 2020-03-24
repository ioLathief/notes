cmake_minimum_required(VERSION 3.12)
project(win_native)

set(CMAKE_CXX_STANDARD 14)

add_executable(win_native volume.cpp win_eventloop.cpp)