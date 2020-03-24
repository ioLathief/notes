
project(GRun)

#variables
file(GLOB SOURCES
        src/*.cpp
        src/*.h)
option(PROJETO_BUILD_DLL "Build Dll" OFF)


#preprocessing and linker defines
if(PROJETO_BUILD_DLL)
    add_definitions(-DPROJETO_BUILD_DLL)
    message("projeto-io build dll")
else()
    message("projeto-io build static lib")
endif(PROJETO_BUILD_DLL)


#including directories
include_directories(include)

#linking files
add_library(${PROJECT_NAME} SHARED ${SOURCES})

#copy files to directories
#[[install(TARGETS ${PROJECT_NAME} DESTINATION ./../listener/lib)
install(TARGETS ${PROJECT_NAME} DESTINATION ./../sender/lib)]]

