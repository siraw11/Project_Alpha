cmake_minimum_required(VERSION 3.5)
project(Motocross2D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(.)


set(EXECUTABLE_NAME Motocross2D)
set(SOURCE_FILES Player.cpp Player.h Bike.cpp Bike.h Map.cpp Map.h Item.cpp Item.h Coin.cpp Coin.h SpeedBonus.cpp SpeedBonus.h TimeBonus.cpp TimeBonus.h Checkpoint.cpp Checkpoint.h)
add_executable(${EXECUTABLE_NAME} main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} core)


#Add Unit Testing
add_subdirectory(test)
#--------------------

#Add Box2D
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/Box2D/libBox2D.a)
#--------------------


#include SFML
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif ()
#-----------

