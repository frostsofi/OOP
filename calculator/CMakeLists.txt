cmake_minimum_required(VERSION 3.8)
project(calculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Factory.cpp Factory.h base.h execution.h calculator.cpp calculator.h define.cpp comment.cpp dev.cpp mult.cpp plus.cpp pop.cpp print.cpp push.cpp sqrt.cpp sub.cpp execution.cpp)
add_executable(calculator ${SOURCE_FILES} Factory.cpp base.h execution.h calculator.cpp calculator.h define.cpp comment.cpp dev.cpp mult.cpp pop.cpp print.cpp push.cpp sqrt.cpp sub.cpp execution.cpp)