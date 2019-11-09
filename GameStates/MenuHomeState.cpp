//
// Created by Luca Graziotti on 03/11/2019.
//

#include <iostream>
#include <Game.h>
#include "MenuHomeState.h"
#include "GameState.h"
#include "StateMachine.h"
#include "Menu.h"
#include "SelectLevelState.h"

static Menu menu(MenuType::Home, MenuOption::loadMainMenuOptions());

void MenuHomeState::draw() {
    Game::gameData->window.clear(sf::Color(0, 0, 0));
    std::vector<MenuOption *>::iterator it;
    float width = Game::gameData->window.getView().getCenter().x;
    float height = Game::gameData->window.getView().getCenter().y;
    int i = 0;
    for (it = menu.options.begin(); it != menu.options.end(); it++, i++) {
        (*it)->option.setPosition(
                sf::Vector2f(width, height + i * 100));
        if (i == menu.getSelectedItemIndex()) {
            (*it)->option.setColor(sf::Color::Red);
        }
        Game::gameData->window.draw((*it)->option);
    }
}

void MenuHomeState::update() {}

void MenuHomeState::handleInput(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Enter:
                    switch (menu.getSelectedItemIndex()) {
                        case 0:
                            std::cout << "Play" << std::endl;
                            //Game::gameData->machine.push_state(StateRef(new GameState(true)));
                            Game::gameData->machine.push_state(StateRef(new SelectLevelState()));
                            break;
                        case 1:
                            std::cout << "Settings" << std::endl;
                            break;
                        case 2:
                            Game::gameData->window.close();
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}