//
// Created by Luca Graziotti on 11/11/2019.
//

#include <iostream>
#include <Game.h>
#include "GameLostState.h"
#include "MenuHomeState.h"

GameLostState::GameLostState() {
    Game::gameData->engine->setPause(true);
    this->menu = new Menu(MenuType::Home, GameLostState::loadMenu());
}

std::vector<MenuOption *> GameLostState::loadMenu() {
    std::vector<MenuOption *> options;
    MenuOption *option;

    Game::gameData->match->removeLife();

    if (Game::gameData->match->getLifes() > 0) {
        this->canRetry = true;
        option = new MenuOption("Retry");
        options.push_back(option);
    } else {
        this->canRetry = false;
        option = new MenuOption("Return to Menu");
        options.push_back(option);
    }


    return options;
}

void GameLostState::update() {
}

void GameLostState::draw() {
    Game::gameData->window.clear(sf::Color(0, 0, 0));
    std::vector<MenuOption *>::iterator it;
    float width = Game::gameData->window.getView().getCenter().x;
    float height = Game::gameData->window.getView().getCenter().y;
    int i = 0;
    for (it = menu->options.begin(); it != menu->options.end(); it++, i++) {
        (*it)->option.setPosition(
                sf::Vector2f(width, height + i * 100));
        if (i == menu->getSelectedItemIndex()) {
            (*it)->option.setColor(sf::Color(200, 100, 0));
        }
        Game::gameData->window.draw((*it)->option);
    }
}

void GameLostState::handleInput(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
                case sf::Keyboard::Down:
                    menu->MoveDown();
                    break;
                case sf::Keyboard::Up:
                    menu->MoveUp();
                    break;
                case sf::Keyboard::Enter:
                    if (this->canRetry) {
                        switch (menu->getSelectedItemIndex()) {
                            case 0://Retry
                                std::cout << "retry from last checkpoint:" << std::endl;
                                Game::gameData->engine->respawn();
                                Game::gameData->machine.pop_state();
                                break;
                        }
                    } else {
                        switch (menu->getSelectedItemIndex()) {
                            case 0://Continue
                                Game::gameData->machine.push_state(StateRef(new MenuHomeState()));
                                break;
                        }
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

