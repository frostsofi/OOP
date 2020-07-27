cmake_minimum_required(VERSION 3.8)
project(SeaBattle)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp game_process.h player.h model.h field.h player.cpp game_process.cpp model.cpp field.cpp view.h view.cpp)
add_executable(SeaBattle ${SOURCE_FILES} game_process.h player.h model.h field.h player.cpp game_process.cpp model.cpp field.cpp view.h view.cpp)