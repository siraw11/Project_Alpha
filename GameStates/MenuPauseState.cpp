//
// Created by Luca Graziotti on 07/11/2019.
//

#include <iostream>
#include <Game.h>
#include "MenuPauseState.h"
#include "StateMachine.h"
#include "Menu.h"
#include "MenuHomeState.h"


static Menu menu(MenuType::Home, MenuOption::loadPauseMenuOptions());

MenuPauseState::~MenuPauseState() {

}

MenuPauseState::MenuPauseState() {
    Game::gameData->match->timer->stop();
}

void MenuPauseState::draw() {
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

void MenuPauseState::update() {

}

void MenuPauseState::handleInput(sf::Event event) {
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
                        case 0://Resume Case
                            Game::gameData->machine.pop_state();
                            break;
                        case 1://Back Menu case
                            Game::gameData->match = std::unique_ptr<Match>(new Match());
                            Game::gameData->machine.push_state(StateRef(new MenuHomeState()));
                            break;
                        case 2://Exit case
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