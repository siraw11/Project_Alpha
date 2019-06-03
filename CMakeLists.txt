cmake_minimum_required(VERSION 3.5)
project(Motocross2D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES Player.cpp Player.h Bike.cpp Bike.h)
add_executable(Motocross2D main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(Motocross2D core)
