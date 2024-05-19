cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES pieces.cpp pieces.h )
add_executable(Chess main.cpp)
add_library(pieces ${SOURCE_FILES})
target_link_libraries(Chess pieces)
