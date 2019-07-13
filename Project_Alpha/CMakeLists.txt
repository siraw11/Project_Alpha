cmake_minimum_required(VERSION 3.14)
project(Exam_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Exam_Project main.cpp ../Map.cpp ../Map.h ../Archer.cpp ../Archer.h ../Mage.cpp ../Mage.h ../Knight.cpp ../Knight.h ../Boss.cpp ../Boss.h ../Enemy.cpp ../Enemy.h ../Hero.cpp ../Hero.h ../Weapon.cpp ../Weapon.h ../Chest.cpp ../Chest.h ../Tile.cpp ../Tile.h ../Item.cpp ../Item.h)

set(SFML_ROOT /home/matteo/Documenti/libraries/SFML)
set(SFML_STATIC_LIBRARIES TRUE)