cmake_minimum_required(VERSION 3.12)
project(Project_Alpha)

set(CMAKE_CXX_STANDARD 11)

include_directories(Project_Alpha)
set(SOURCE_FILE  Archer.cpp Boss.cpp Chest.cpp Enemy.cpp GameCharacter.cpp Hero.cpp Item.cpp Knight.cpp Mage.cpp main.cpp Map.cpp Weapon.cpp Projectile.cpp Menu.cpp Menu1.cpp PlayerType.h Random.cpp)
add_executable(Project_Alpha_ROOT ${SOURCE_FILE})
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    target_link_libraries(Project_Alpha_ROOT sfml-graphics sfml-window sfml-system)

endif ()