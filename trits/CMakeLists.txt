cmake_minimum_required(VERSION 3.8)
project(trits)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(SOURCE_FILES main.cpp TritSet.h TritSet.cpp Tests/Test.cpp)
add_executable(trits ${SOURCE_FILES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(lib ${SOURCE_FILES} Tests/Test.cpp)

target_link_libraries(trits gtest gtest_main)
target_link_libraries(trits gmock gmock_main)