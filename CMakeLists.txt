cmake_minimum_required(VERSION 3.11)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2 COMPONENTS audio graphics window system network REQUIRED)

add_executable(game main.cpp Game_Screens/Menu.cpp Game_Screens/Menu.h RectangleShape.cpp RectangleShape.h
        Collision.cpp Collision.h Bullet.cpp Bullet.h Level.cpp Level.h Platform.cpp Platform.h
        GameCharacter.cpp GameCharacter.h Hero.cpp Hero.h PowerUp.cpp PowerUp.h
        GameLogic.cpp GameLogic.h Enemy.cpp Enemy.h Animation.cpp Animation.h Input.cpp Input.h Game_Screens/Pause.cpp Game_Screens/Pause.h
        Game_Screens/DeathScreen.cpp Game_Screens/DeathScreen.h AchievementNotifier.cpp AchievementNotifier.h
        Achievements/Achievement.cpp Achievements/Achievement.h Achievements/FirstBlood.cpp Achievements/FirstBlood.h
        Achievements/FirstDeath.cpp Achievements/FirstDeath.h
        Achievements/PotionAchievement.cpp Achievements/PotionAchievement.h Aggro.cpp Aggro.h Idle.cpp Idle.h
        Catch.cpp Catch.h Attack.cpp Attack.h ReturnHome.cpp ReturnHome.h Game_Screens/NextLevelScreen.cpp Game_Screens/NextLevelScreen.h
        LevelManager.cpp LevelManager.h Hud.cpp Hud.h StateMachine/State_Level.cpp StateMachine/State.h StateMachine/State.cpp
        StateMachine/State_Main.cpp StateMachine/State_Main.h StateMachine/StateManager.h StateMachine/StateManager.cpp
        StateMachine/State_Achievement.cpp StateMachine/State_Achievement.h StateMachine/State_Death.cpp
        StateMachine/State_Death.h StateMachine/State_Pause.cpp StateMachine/State_Pause.h
        StateMachine/State_NextLevel.cpp StateMachine/State_NextLevel.h Game_Screens/AchievementScreen.cpp Game_Screens/AchievementScreen.h)
target_include_directories(game PUBLIC "${SFML_INCLUDE_DIRS}")

if (SFML_FOUND)
    target_link_libraries(game sfml-graphics sfml-window sfml-audio sfml-system)
endif ()

add_subdirectory(Google_tests)

add_library(core Game_Screens/Menu.cpp Game_Screens/Menu.h RectangleShape.cpp RectangleShape.h
        Collision.cpp Collision.h Bullet.cpp Bullet.h Level.cpp Level.h Platform.cpp Platform.h
        GameCharacter.cpp GameCharacter.h Hero.cpp Hero.h PowerUp.cpp PowerUp.h
        GameLogic.cpp GameLogic.h Enemy.cpp Enemy.h Animation.cpp Animation.h Input.cpp Input.h Game_Screens/Pause.cpp Game_Screens/Pause.h
        Game_Screens/DeathScreen.cpp Game_Screens/DeathScreen.h AchievementNotifier.cpp AchievementNotifier.h
        Achievements/Achievement.cpp Achievements/Achievement.h Achievements/FirstBlood.cpp Achievements/FirstBlood.h
        Achievements/FirstDeath.cpp Achievements/FirstDeath.h
        Achievements/PotionAchievement.cpp Achievements/PotionAchievement.h Aggro.cpp Aggro.h Idle.cpp Idle.h
        Catch.cpp Catch.h Attack.cpp Attack.h ReturnHome.cpp ReturnHome.h Game_Screens/NextLevelScreen.cpp Game_Screens/NextLevelScreen.h
        LevelManager.cpp LevelManager.h Hud.cpp Hud.h StateMachine/State_Level.cpp StateMachine/State.h StateMachine/State.cpp
        StateMachine/State_Main.cpp StateMachine/State_Main.h StateMachine/StateManager.h StateMachine/StateManager.cpp
        StateMachine/State_Achievement.cpp StateMachine/State_Achievement.h StateMachine/State_Death.cpp
        StateMachine/State_Death.h StateMachine/State_Pause.cpp StateMachine/State_Pause.h
        StateMachine/State_NextLevel.cpp StateMachine/State_NextLevel.h Game_Screens/AchievementScreen.cpp Game_Screens/AchievementScreen.h)
target_link_libraries(game core)