PROJECT(Value)

file(GLOB SOURCES
        src/*.cpp
        src/*.h)

add_executable(${PROJECT_NAME} ${SOURCES})