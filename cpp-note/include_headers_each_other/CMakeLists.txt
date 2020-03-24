cmake_minimum_required(VERSION 3.12)
project(testcpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES
        src/*.h
        src/*.cpp
        )

add_executable(testcpp ${SOURCES})