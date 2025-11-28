cmake_minimum_required(VERSION 3.10)
project(ActivatorLauncher)

set(CMAKE_CXX_STANDARD 11)

add_executable(activator_launcher launcher.cpp)

if(WIN32)
    target_compile_definitions(activator_launcher PRIVATE _WIN32)
endif()
