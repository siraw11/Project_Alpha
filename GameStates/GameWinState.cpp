//
// Created by Luca Graziotti on 11/11/2019.
//

#include <Game.h>
#include "GameWinState.h"
#include "MenuHomeState.h"

GameWinState::GameWinState() {
    Game::gameData->engine->setPause(true);
    this->menu = new Menu(MenuType::Home, GameWinState::loadMenu());
}

std::vector<MenuOption *> GameWinState::loadMenu() {
    std::vector<MenuOption *> options;
    MenuOption *option;

    option = new MenuOption("Continue");
    options.push_back(option);

    return options;
}

void GameWinState::update() {
}

void GameWinState::draw() {
    Game::gameData->window.clear(sf::Color(0, 0, 0));
    std::vector<MenuOption *>::iterator it;
    float width = Game::gameData->window.getView().getCenter().x;
    float height = Game::gameData->window.getView().getCenter().y;
    int i = 0;
    for (it = menu->options.begin(); it != menu->options.end(); it++, i++) {
        (*it)->option.setPosition(
                sf::Vector2f(width, height + i * 100));
        if (i == menu->getSelectedItemIndex()) {
            (*it)->option.setColor(sf::Color::Red);
        }
        Game::gameData->window.draw((*it)->option);
    }
}

void GameWinState::handleInput(sf::Event event) {
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
                        case 0://Continue
                            Game::gameData->match->map->setIsCompleted(true);
                            Game::gameData->player->addTotalCoin(Game::gameData->match->getMoney());
                            Game::gameData->match = std::unique_ptr<Match>(new Match());
                            Game::gameData->machine.push_state(StateRef(new MenuHomeState()));
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

GameWinState::~GameWinState() {

}
