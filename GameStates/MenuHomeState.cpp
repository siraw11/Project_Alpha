//
// Created by Luca Graziotti on 03/11/2019.
//

#include <iostream>
#include <Game.h>
#include <ResourceManager/ResourceFont.h>
#include "MenuHomeState.h"
#include "GameState.h"
#include "StateMachine.h"
#include "Menu.h"
#include "SelectLevelState.h"
#include "ShopState.h"


MenuHomeState::MenuHomeState() {
    this->menu = new Menu(MenuType::Home, MenuOption::loadMainMenuOptions());
}

void MenuHomeState::draw() {
    Game::gameData->window.clear(sf::Color(0, 0, 0));
    std::vector<MenuOption *>::iterator it;
    float width = Game::gameData->window.getView().getCenter().x;
    float height = Game::gameData->window.getView().getCenter().y;


    sf::Text textWelcome;
    textWelcome.setPosition(width, height);
    textWelcome.setFont(Game::gameData->resources.getResource<ResourceFont *>("arial.ttf")->getFont());
    textWelcome.setCharacterSize(80);
    textWelcome.setPosition(width, height - 450);
    textWelcome.setFillColor(sf::Color(50, 50, 100));
    textWelcome.setString("Welcome back,");


    sf::Text textWelcomeUsername;
    textWelcomeUsername.setPosition(width, height);
    textWelcomeUsername.setFont(Game::gameData->resources.getResource<ResourceFont *>("arial.ttf")->getFont());
    textWelcomeUsername.setCharacterSize(50);
    textWelcomeUsername.setPosition(width, height - 350);
    textWelcomeUsername.setFillColor(sf::Color::White);
    textWelcomeUsername.setString(Game::gameData->player->getUsername());

    Game::gameData->window.draw(textWelcome);
    Game::gameData->window.draw(textWelcomeUsername);


    int i = 0;
    for (it = menu->options.begin(); it != menu->options.end(); it++, i++) {
        (*it)->option.setPosition(
                sf::Vector2f(width, height + i * 100));
        if (i == menu->getSelectedItemIndex()) {
            (*it)->option.setFillColor(sf::Color(200, 100, 0));
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
                    menu->MoveDown();
                    break;
                case sf::Keyboard::Up:
                    menu->MoveUp();
                    break;
                case sf::Keyboard::Enter:
                    switch (menu->getSelectedItemIndex()) {
                        case 0:
                            std::cout << "Play" << std::endl;
                            Game::gameData->machine.push_state(StateRef(new SelectLevelState()));
                            break;
                        case 1:
                            std::cout << "Shop" << std::endl;
                            Game::gameData->machine.push_state(StateRef(new ShopState()));
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
