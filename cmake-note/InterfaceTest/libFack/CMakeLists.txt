
project(libFack)

file(GLOB SRC
        src/*.cpp)

include_directories(include)

add_library(libFack ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
