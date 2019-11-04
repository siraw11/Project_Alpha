cmake_minimum_required(VERSION 3.12)
project(Project_Alpha)

set(CMAKE_CXX_STANDARD 11)

include_directories(Project_Alpha)
set(SOURCE_FILE GameManager/AssetManager.cpp GameManager/AssetManager.hpp GameManager/DEFINITIONS.hpp GameManager/Game.cpp GameManager/Game.hpp GameStates/GameOverState.cpp GameStates/GameOverState.hpp GameStates/GameState.cpp GameStates/GameState.hpp GameManager/InputManager.cpp GameManager/InputManager.hpp main.cpp GameStates/MainMenuState.cpp GameStates/MainMenuState.hpp GameStates/PauseState.cpp GameStates/PauseState.hpp GameStates/SplashState.cpp GameStates/SplashState.hpp GameStates/State.hpp GameStates/StateMachine.cpp GameStates/StateMachine.hpp GameStates/SelectClassState.cpp GameStates/SelectClassState.h Map.cpp Map.h Hero.cpp Hero.h GameCharacter.cpp GameCharacter.h Item.cpp Item.h Weapon.cpp Weapon.h Archer.h Archer.cpp Knight.h Knight.cpp Mage.h Mage.cpp Projectile.cpp Projectile.h PlayerType.h Enemy.h Enemy.cpp Random.h Random.cpp Classes.cpp Classes.h)
add_executable(Project_Alpha_ROOT ${SOURCE_FILE})
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if (SFML_FOUND)
    target_link_libraries(Project_Alpha_ROOT sfml-graphics sfml-window sfml-system)

endif ()