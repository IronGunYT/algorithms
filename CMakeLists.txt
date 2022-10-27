cmake_minimum_required(VERSION 3.23)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

include_directories(search)
include_directories(data_structures)

add_executable(main main.cpp)

add_subdirectory(search)
add_subdirectory(data_structures)
