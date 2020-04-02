cmake_minimum_required(VERSION 3.8)
project(parceptron_nef)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Parser.cpp Parser.h Label.cpp Label.h Data.h Neuron.cpp Neuron.h Layer.cpp Layer.h Neural_net.cpp Neural_net.h Normalizer.cpp Normalizer.h)
add_executable(parceptron_nef ${SOURCE_FILES} Parser.cpp Parser.h Label.cpp Label.h Data.h Neuron.cpp Neuron.h Layer.cpp Layer.h Neural_net.cpp Neural_net.h Normalizer.cpp Normalizer.h)