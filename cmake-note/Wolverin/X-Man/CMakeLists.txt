
project(X-Man)

file(GLOB SOURCES
        src/*.cpp)

include_directories(include)

add_library(${PROJECT_NAME} ${SOURCES})
