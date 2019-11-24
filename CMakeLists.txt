cmake_minimum_required(VERSION 3.5)
project(Motocross2D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(.)

set(EXECUTABLE_NAME Motocross2D)

set(SOURCE_FILES
        Game.h Game.cpp Player.cpp Player.h Bike.cpp Bike.h GameEngine.h GameEngine.cpp Item.h Item.cpp Map.h Map.cpp Coin.cpp Coin.h SpeedBonus.cpp SpeedBonus.h Checkpoint.cpp Checkpoint.h TimeBonus.cpp TimeBonus.h Subject.cpp Subject.h Observer.cpp Observer.h Match.cpp Match.h Menu.cpp Menu.h MenuOption.h MenuOption.cpp Timer.cpp Timer.h SpeedMalus.cpp SpeedMalus.h
        ResourceManager/ResourceManager.cpp ResourceManager/ResourceManager.h ResourceManager/ResourceManagerException.h ResourceManager/ResourceManagerException.cpp ResourceManager/Resource.cpp ResourceManager/Resource.h ResourceManager/ResourceTexture.cpp ResourceManager/ResourceTexture.h ResourceManager/ResourceFont.h ResourceManager/ResourceFont.cpp
        GameStates/State.h GameStates/StateMachine.cpp GameStates/StateMachine.h GameStates/GameState.h GameStates/GameState.cpp GameStates/MenuHomeState.cpp GameStates/MenuHomeState.h GameStates/MenuPauseState.h GameStates/MenuPauseState.cpp GameStates/SelectLevelState.cpp GameStates/SelectLevelState.h GameStates/GameWinState.cpp GameStates/GameWinState.h GameStates/GameLostState.cpp GameStates/GameLostState.h GameStates/ShopState.cpp GameStates/ShopState.h GameStates/SelectBikeState.cpp GameStates/SelectBikeState.h)


add_library(core ${SOURCE_FILES})

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} core)

#Add Unit Testing
add_subdirectory(test)

#Add Box2D
target_link_libraries(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/Box2D/libBox2D.a)
#--------------------

#include SFML
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    include_directories(/usr/local/include)
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
endif ()
set(SFML_STATIC_LIBRARIES TRUE)
#-----------
