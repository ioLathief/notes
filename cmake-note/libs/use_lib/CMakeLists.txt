cmake_minimum_required(VERSION 2.8.9)
project(use_lib)

set(CMAKE_CXX_STANDARD 17)

#set library file name to project_link_libs variable
set(PROJECT_LINK_LIBS testStudent.lib)


#include additional directorys that contain lib file
link_directories(lib)

include_directories(include)


add_executable(use_lib main.cpp)
target_link_libraries(use_lib ${PROJECT_LINK_LIBS})