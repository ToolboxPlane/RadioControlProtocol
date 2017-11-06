cmake_minimum_required(VERSION 3.8)
project(LoRaLib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES examples/main.cpp
        rcLib.hpp
        rcLib.cpp)
add_executable(LoRaLib ${SOURCE_FILES})