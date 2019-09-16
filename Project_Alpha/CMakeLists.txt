cmake_minimum_required(VERSION 3.12)
project(Exam_Project)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_NAME Project_Alpha)

add_executable(${EXECUTABLE_NAME} main.cpp ../Map.cpp ../Map.h ../Archer.cpp ../Archer.h ../Mage.cpp ../Mage.h ../Knight.cpp ../Knight.h ../Boss.cpp ../Boss.h ../Enemy.cpp ../Enemy.h ../Hero.cpp ../Hero.h ../Weapon.cpp ../Weapon.h ../Chest.cpp ../Chest.h ../Tile.cpp ../Tile.h ../Item.cpp ../Item.h)

add_subdirectory(test)

add_library(core ${EXECUTABLE_NAME})
target_link_libraries(${EXECUTABLE_NAME} core)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif()

