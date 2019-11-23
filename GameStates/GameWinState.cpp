//
// Created by Luca Graziotti on 11/11/2019.
//

#include <Game.h>
#include "GameWinState.h"
#include "MenuHomeState.h"

GameWinState::GameWinState() {
    Game::gameData->engine->setPause(true);
    Game::gameData->match->getTimer()->stop();
    float bestRecord = Game::gameData->match->getMap()->getRecord();
    float newRecord = Game::gameData->match->getTimer()->getTime();

    if (newRecord < bestRecord || bestRecord == 0) {
        Game::gameData->match->getMap()->setRecord(newRecord);
        this->isRecord = true;
    }

    std::cout << "Actual map record:" << bestRecord << std::endl;
    std::cout << "new record:" << newRecord << std::endl;

    Game::gameData->match->getMap()->resetItems();
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


    if (this->isRecord) {
        sf::Text textRecord;
        textRecord.setPosition(width, height);
        textRecord.setFont(Game::gameData->resources.getFont("arial.ttf"));
        textRecord.setCharacterSize(80);
        textRecord.setPosition(width - 150, height - 400);
        textRecord.setFillColor(sf::Color(50, 255, 100));
        textRecord.setString("New Record !\n" + Game::gameData->match->getMap()->getRecordString());
        Game::gameData->window.draw(textRecord);
    }


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
                            if (!Game::gameData->match->getMap()->getIsCompleted()) {
                                Game::gameData->match->getMap()->setIsCompleted(true);
                            }
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
