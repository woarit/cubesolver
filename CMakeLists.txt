cmake_minimum_required(VERSION 3.3)
project(cubesolver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
        include/cubesolver/axis.h
        include/cubesolver/corner.h
        include/cubesolver/edge.h
        include/cubesolver/piece.h
        include/cubesolver/sticker.h
        include/cubesolver/tile.h

        src/corner.cpp
        src/edge.cpp
        src/main.cpp
        src/piece.cpp
        src/tile.cpp
        )
add_executable(cubesolver ${SOURCE_FILES})