cmake_minimum_required(VERSION 3.12)
project(Project1)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)

file(GLOB SOURCES "*.cpp")


add_library(Project1 SHARED ${SOURCES})
install(TARGETS Project1 DESTINATION Debug/)