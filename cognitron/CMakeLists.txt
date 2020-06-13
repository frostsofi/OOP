cmake_minimum_required(VERSION 3.8)
project(cognitron)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp C_plane.cpp C_plane.h S_plane.cpp S_plane.h V_plane.cpp V_plane.h Stage.cpp Stage.h Neocognitron.cpp Neocognitron.h Parser.cpp Parser.h Label.cpp Label.h)
add_executable(cognitron ${SOURCE_FILES} main.cpp C_plane.cpp C_plane.h S_plane.cpp S_plane.h V_plane.cpp V_plane.h Stage.cpp Stage.h Neocognitron.cpp Neocognitron.h Parser.cpp Parser.h)