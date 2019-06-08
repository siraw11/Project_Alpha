cmake_minimum_required(VERSION 3.5)
project(Motocross2D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(.)


set(SOURCE_FILES Player.cpp Player.h Bike.cpp Bike.h Map.cpp Map.h Item.cpp Item.h Coin.cpp Coin.h SpeedBonus.cpp SpeedBonus.h TimeBonus.cpp TimeBonus.h Checkpoint.cpp Checkpoint.h)
add_executable(Motocross2D main.cpp )
add_library(core ${SOURCE_FILES})
target_link_libraries(Motocross2D core)


#Add Unit Testing
add_subdirectory(test)
#--------------------

#Add Box2D
target_link_libraries(Motocross2D ${CMAKE_SOURCE_DIR}/Box2D/libBox2D.a)
#--------------------
