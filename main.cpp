#include <SFML/Graphics.hpp>
#include <GameStates.h>
#include <Level.h>
#include <iostream>
#include <Menu.h>
#include <Input.h>
#include "Pause.h"
#include "DeathScreen.h"
#include "AchievementScreen.h"

#define arrayRow 10
#define arrayColumn 50

int main() {
    //TODO Fare il fullscreen del gioco
    GameStates stateChecker = GameStates::Main_menu;
    AchievementScreen achievementScreen;
    GameLogic logic;
    int resetcheckMenu = 1;
    int resetcheckRestart = 0;
    Menu menu;
    Pause pauseMenu;
    DeathScreen deathScreen;
    sf::Event event{};
    Input KeyBoardInput;
    sf::Vector2u sizeMenu;
    sizeMenu.x = 1600;
    sizeMenu.y = 320;

    //-----Livello 1-------//
    int levelArray[arrayColumn * arrayRow] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 11, 11,
            12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 7, 3, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1, 1, 1, 12, 0, 0, 0, 0,
            0, 0, 0, 10, 1, 1, 1, 12, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 9, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 6, 0, 1, 2, 2, 2, 0, 0, 0, 0, 7, 0, 0, 0, 7, 0, 3, 0,
            1, 1, 1, 1, 0, 0, 7, 0, 0, 7, 0, 0, 0, 0,
            1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    };

    Level *level = new Level(levelArray, arrayColumn, arrayRow, &logic);

    //---------Loop di gioco------------//

    sf::RenderWindow window(sf::VideoMode(sizeMenu.x, sizeMenu.y), "Game");

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //----Gestione input----//
            if (event.type == sf::Event::KeyPressed) {
                KeyBoardInput = Input::Null;
                if (event.key.code == sf::Keyboard::Down) {
                    KeyBoardInput = Input::Down;
                }
                if (event.key.code == sf::Keyboard::Up) {
                    KeyBoardInput = Input::Up;
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    KeyBoardInput = Input::Enter;
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    KeyBoardInput = Input::Escape;
                }


                //----Update dei menù solo in caso di input avvenuto----//
                if (stateChecker == GameStates::AchievementScreen) {
                    achievementScreen.update(&KeyBoardInput, &stateChecker);
                }
                if (stateChecker == GameStates::Main_menu) {
                    menu.update(&KeyBoardInput, &stateChecker, &window);
                }

                if (stateChecker == GameStates::Pause) {
                    pauseMenu.update(&KeyBoardInput, &stateChecker, &window);
                    if ((pauseMenu.selected == resetcheckMenu) && KeyBoardInput == Input::Enter) {
                        Level *levelR = new Level(levelArray, arrayColumn, arrayRow, &logic);
                        logic.lastHitTime = sf::seconds(0);
                        level = levelR;
                    }
                }
                if (stateChecker == GameStates::Dead) {
                    deathScreen.update(&KeyBoardInput, &stateChecker, &window);
                    if ((deathScreen.selected == resetcheckMenu || deathScreen.selected == resetcheckRestart)
                        && KeyBoardInput == Input::Enter) {
                        Level *levelR = new Level(levelArray, arrayColumn, arrayRow, &logic);
                        logic.lastHitTime = sf::seconds(0);
                        level = levelR;
                    }
                }
            }

        }

        if (stateChecker == GameStates::Level) {
            level->Update(&window, &KeyBoardInput, &stateChecker);
            if (level->reset) {
                delete level;
                stateChecker = GameStates::Dead;
                level->reset = false;
            }
        }
        if (stateChecker == GameStates::Main_menu) {
            menu.drawMenu(&window);
        }
        if (stateChecker == GameStates::Pause) {
            pauseMenu.drawMenu(&window);
        }
        if (stateChecker == GameStates::Dead) {
            deathScreen.drawMenu(&window);
        }
        if (stateChecker == GameStates::AchievementScreen) {
            achievementScreen.drawAchievements(&logic.achievementNotifier, &window);
        }
        window.display();
        window.clear(sf::Color(10, 108, 180));
    }
}