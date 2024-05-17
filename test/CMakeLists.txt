cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(FILES PiecesFixture.cpp PiecesTests.cpp runAllTests.cpp)
add_executable(runAllTests ${FILES})
target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} pieces)
