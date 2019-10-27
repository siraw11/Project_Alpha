cmake_minimum_required(VERSION 3.11)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2 COMPONENTS audio graphics window system network REQUIRED)

add_executable(game main.cpp GameStates.cpp GameStates.h Menu.cpp Menu.h RectangleShape.cpp RectangleShape.h
        Collision.cpp Collision.h Bullet.cpp Bullet.h Level.cpp Level.h Platform.cpp Platform.h
        GameCharacter.cpp GameCharacter.h Hero.cpp Hero.h PowerUp.cpp PowerUp.h
        GameLogic.cpp GameLogic.h Enemy.cpp Enemy.h Animation.cpp Animation.h Input.cpp Input.h Pause.cpp Pause.h
        DeathScreen.cpp DeathScreen.h AchievementNotifier.cpp AchievementNotifier.h
        Achievements/Achievement.cpp Achievements/Achievement.h Achievements/FirstBlood.cpp Achievements/FirstBlood.h AchievementScreen.cpp AchievementScreen.h Achievements/FirstDeath.cpp Achievements/FirstDeath.h Achievements/PotionAchievement.cpp Achievements/PotionAchievement.h)

target_include_directories(game PUBLIC "${SFML_INCLUDE_DIRS}")

if (SFML_FOUND)
    target_link_libraries(game sfml-graphics sfml-window sfml-system)
endif ()

add_subdirectory(Google_tests)

add_library(core GameStates.cpp GameStates.h Menu.cpp Menu.h RectangleShape.cpp RectangleShape.h Collision.cpp Collision.h
        Bullet.cpp Bullet.h Level.cpp Level.h Platform.cpp Platform.h GameCharacter.cpp GameCharacter.h
        Hero.cpp Hero.h PowerUp.cpp PowerUp.h GameLogic.cpp GameLogic.h Enemy.cpp Enemy.h Animation.cpp Animation.h)
target_link_libraries(game core)