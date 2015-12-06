cmake_minimum_required(VERSION 3.3)
project(cubesolver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
        include/cubesolver/sticker.h

        src/main.cpp
        )
add_executable(cubesolver ${SOURCE_FILES})