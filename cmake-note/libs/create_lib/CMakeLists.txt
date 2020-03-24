cmake_minimum_required(VERSION 2.8.9)
project(create_lib)
set(CMAKE_BUILD_TYPE Release)
#Bring the headers, such as create_lib.h into the project
include_directories(include)

#message that you want to print to the console
message(STATUS "project source directory is ${PROJECT_SOURCE_DIR}")

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/create_lib.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

#this is making static library if you want to make a shared or dynamic
#just replace STATIC with SHARED  then compile you should get the .a and .dll(windows)
add_library(create_lib_ STATIC ${SOURCES})

#install is copy the builded dll to this directory(right side of the DESTINATION) 
#its not automatically done when you build the project its done when you install the project 
#install means other project can use this dll so copy this dll to other projects path
install(TARGETS create_lib_ DESTINATION ${PROJECT_SOURCE_DIR}/build/lib)

