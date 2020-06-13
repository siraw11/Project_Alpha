cmake_minimum_required(VERSION 3.12)
project(Project_Alpha)

set(CMAKE_CXX_STANDARD 11)

include_directories(Project_Alpha)
set(SOURCE_FILE main.cpp  GameManager/AssetManager.hpp GameManager/AssetManager.cpp GameManager/DEFINITIONS.hpp GameManager/Game.hpp GameManager/Game.cpp GameManager/InputManager.cpp GameManager/InputManager.hpp
        GameStates/GameOverState.cpp GameStates/GameOverState.hpp GameStates/GameState.cpp GameStates/GameState.hpp GameStates/MainMenuState.hpp GameStates/MainMenuState.cpp GameStates/PauseState.cpp
        GameStates/PauseState.hpp GameStates/SelectClassState.cpp GameStates/SelectClassState.h GameStates/SplashState.cpp GameStates/SplashState.hpp GameStates/State.hpp GameStates/StateMachine.cpp
        GameStates/StateMachine.hpp Tile.cpp Tile.h map.cpp map.h GameCharacter.cpp GameCharacter.h Hero.cpp Hero.h PlayerType.h  Collision.cpp Archer.cpp Archer.h Knight.cpp Knight.h CharacterFactory.cpp CharacterFactory.h Mage.cpp Mage.h
        Collision.h Enemy.cpp Enemy.h Random.cpp Random.h Weapon.cpp Weapon.h Item.cpp Item.h Projectile.cpp Projectile.h )
add_executable(Project_Alpha_ROOT ${SOURCE_FILE})
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    target_link_libraries(Project_Alpha_ROOT sfml-graphics sfml-window sfml-system)

endif ()