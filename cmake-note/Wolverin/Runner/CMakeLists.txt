project(Runner)

include_directories(${X-Man_SOURCE_DIR}/include)

link_libraries(X-Man)

add_executable(Runner Runner.cpp)
