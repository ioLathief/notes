cmake_minimum_required(VERSION 3.1)
project(GTestRun)
set(CMAKE_CXX_STANDARD 14)

#vars
set(SOURCES main.cpp)
add_definitions(-DPLATFORM_WINDOWS)

#linking dirs
include_directories(GRun)

#sub dirs
add_subdirectory(GRun)
add_subdirectory(GRunTests)

#linking files
add_executable(GTestRun_RUN ${SOURCES})
target_link_libraries(GTestRun_RUN GRun)

#additional commands
#include_directories(lib/googletest-master/googletest/include lib/googletest-master/googlemock/include)
