
project(libTest
        LANGUAGES CXX
        VERSION 1.0.0)


add_library(libTest INTERFACE)

target_include_directories(libTest INTERFACE include/)
