cmake_minimum_required(VERSION 3.14)
project(Project_Alpha)
set(CMAKE_CXX_STANDARD 14)
add_subdirectory(Project_Alpha/test)
include_directories(Project_Alpha)
set(SOURCE_FILES Project_Alpha/Archer.cpp
        Project_Alpha/Archer.h
        Project_Alpha/Boss.cpp
        Project_Alpha/Boss.h
        Project_Alpha/Chest.cpp
        Project_Alpha/Chest.h
        Project_Alpha/Enemy.cpp
        Project_Alpha/Enemy.h
        Project_Alpha/GameCharacter.cpp
        Project_Alpha/GameCharacter.h
        Project_Alpha/Hero.cpp
        Project_Alpha/Hero.h
        Project_Alpha/Item.cpp
        Project_Alpha/Item.h
        Project_Alpha/Knight.cpp
        Project_Alpha/Knight.h
        Project_Alpha/Mage.cpp
        Project_Alpha/Mage.h
        Project_Alpha/Map.cpp
        Project_Alpha/Map.h
        Project_Alpha/Tile.cpp
        Project_Alpha/Tile.h
        Project_Alpha/Weapon.cpp
        Project_Alpha/Weapon.h)
add_executable(Project_Alpha Project_Alpha/main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Project_Alpha core)
