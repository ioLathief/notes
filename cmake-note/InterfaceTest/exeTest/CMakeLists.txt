
project(exeTest)

file(GLOB SRC
        src/*.cpp
        src/*.h)

link_libraries(libTest libFack)



add_executable(${PROJECT_NAME} ${SRC})

