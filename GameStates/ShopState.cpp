//
// Created by Luca Graziotti on 18/11/2019.
//

#include "ShopState.h"
#include <Menu.h>
#include <Game.h>
#include "GameState.h"
#include "MenuHomeState.h"

ShopState::ShopState() {
    this->menu = new Menu(MenuType::Home, ShopState::loadLevelsOptions());
}

ShopState::~ShopState() {

}


std::vector<MenuOption *> ShopState::loadLevelsOptions() {
    std::vector<MenuOption *> options;
    MenuOption *option;

    int i = 0;
    bool unlockNext = false;
    for (auto it = Game::gameData->levels.begin(); it != Game::gameData->levels.end(); ++it, ++i) {
        if (unlockNext) {
            it->second->setIsUnlocked(unlockNext);
        }
        unlockNext = it->second->getIsCompleted();

        if (it->second->getIsUnlocked()) {
            option = new MenuOption(it->second->getName());
        } else {
            option = new MenuOption(it->second->getName() + " (locked)");
        }
        option->setValue(it->second->getId());
        options.push_back(option);
    }
    option = new MenuOption("Back");
    option->setValue("back");
    options.push_back(option);
    return options;
}


void ShopState::update() {
}

void ShopState::draw() {
    Game::gameData->window.clear(sf::Color(0, 0, 0));
    std::vector<MenuOption *>::iterator it;
    float width = Game::gameData->window.getView().getCenter().x;
    float height = Game::gameData->window.getView().getCenter().y;


    sf::Font font;
    if (!font.loadFromFile("./fonts/Arial.ttf")) {}
    sf::Text textHeader;
    textHeader.setPosition(width, height);
    textHeader.setFont(font);
    textHeader.setCharacterSize(80);
    textHeader.setPosition(width, height - 350);
    textHeader.setColor(sf::Color(50, 50, 100));
    textHeader.setString("Shop");
    Game::gameData->window.draw(textHeader);


    sf::Text textCoins;
    textCoins.setPosition(width, height);
    textCoins.setFont(font);
    textCoins.setCharacterSize(40);
    textCoins.setPosition(width, height - 250);
    textCoins.setColor(sf::Color(255, 255, 255));
    std::string stringTotalCoins = "You have:";
    textCoins.setString("You have: " + std::to_string(Game::gameData->player->getTotalCoin()) + " coins");
    std::cout << "You have:" << Game::gameData->player->getTotalCoin() << std::endl;
    Game::gameData->window.draw(textCoins);


    int i = 0;
    for (it = menu->options.begin(), i = 0; it != menu->options.end(); it++, i++) {
        (*it)->option.setPosition(sf::Vector2f(width, height + i * 100));
        (*it)->option.setColor(sf::Color::White);
        if (i < Game::gameData->levels.size()) {
            if (Game::gameData->levels.at((*it)->getValue())->getIsUnlocked()) {
                if (i == menu->getSelectedItemIndex()) {
                    (*it)->option.setColor(sf::Color::Red);
                }
            } else {
                if (i == menu->getSelectedItemIndex()) {
                    (*it)->option.setColor(sf::Color(100, 10, 100));
                } else {
                    (*it)->option.setColor(sf::Color(10, 10, 100));
                }
            }
        } else {
            if (i == menu->getSelectedItemIndex()) {
                (*it)->option.setColor(sf::Color::Red);
            }
        }


        Game::gameData->window.draw((*it)->option);
    }
}

void ShopState::handleInput(sf::Event event) {
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
                    std::string actionValue = menu->options.at(menu->getSelectedItemIndex())->getValue();
                    if (actionValue == "back") {
                        Game::gameData->machine.push_state(StateRef(new MenuHomeState()));
                    } else {
                        if (actionValue.find("lv") != std::string::npos) {//controllo sia un livello
                            auto level = Game::gameData->levels.at(actionValue);
                            if (level->getIsUnlocked()) {
                                std::cout << "Selected Level:" << level->getName() << std::endl;
                                Game::gameData->match->setMap(level);
                                Game::gameData->machine.push_state(StateRef(new GameState(true)));
                            } else {
                                std::cout << "Level " << level->getName() << " is locked!" << std::endl;
                            }
                        }
                    }
            }
            break;
        default:
            break;
    }
}
