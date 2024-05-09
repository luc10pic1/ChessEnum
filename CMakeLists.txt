cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp pieces.cpp pieces.h )

add_executable(Chess ${SOURCE_FILES})
