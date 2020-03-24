cmake_minimum_required(VERSION 3.12)
project(chtest)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(chtest
        Source.cpp)
