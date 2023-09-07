cmake_minimum_required(VERSION 3.23)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(Cube main.cpp)
target_link_libraries(Cube RubiksCubeLib)
