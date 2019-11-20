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
    for (auto it = Game::gameData->bikes.begin(); it != Game::gameData->bikes.end(); ++it, ++i) {
        std::string bikeInfo = it->second->getName();
        if (it->second->getIsUnlocked()) {
            bikeInfo += " (already bought)";
        } else {
            bikeInfo +=
                    std::to_string((int) it->second->getSpeed()) + " [buy for" +
                    std::to_string(it->second->getPrice()) + "]";
        }
        option = new MenuOption(bikeInfo);
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


    sf::Text textHeader;
    textHeader.setPosition(width, height);
    textHeader.setFont(Game::gameData->resources.getFont("arial.ttf"));
    textHeader.setCharacterSize(80);
    textHeader.setPosition(width, height - 350);
    textHeader.setFillColor(sf::Color(50, 50, 100));
    textHeader.setString("Shop");
    Game::gameData->window.draw(textHeader);


    sf::Text textCoins;
    textCoins.setPosition(width, height);
    textCoins.setFont(Game::gameData->resources.getFont("arial.ttf"));
    textCoins.setCharacterSize(40);
    textCoins.setPosition(width, height - 250);
    textCoins.setFillColor(sf::Color(255, 255, 255));
    std::string stringTotalCoins = "You have:";
    textCoins.setString("You have: " + std::to_string(Game::gameData->player->getTotalCoin()) + " coins");
    Game::gameData->window.draw(textCoins);


    int i = 0;
    for (it = menu->options.begin(), i = 0; it != menu->options.end(); it++, i++) {
        (*it)->option.setPosition(sf::Vector2f(width, height + i * 100));
        (*it)->option.setFillColor(sf::Color::White);
        if (i < Game::gameData->bikes.size()) {
            if (Game::gameData->bikes.at((*it)->getValue())->getIsUnlocked()) {
                if (i == menu->getSelectedItemIndex()) {
                    (*it)->option.setFillColor(sf::Color(200, 100, 0));
                }
            } else {
                if (i == menu->getSelectedItemIndex()) {
                    (*it)->option.setFillColor(sf::Color(100, 10, 100));
                } else {
                    (*it)->option.setFillColor(sf::Color(10, 10, 100));
                }
            }
        } else {
            if (i == menu->getSelectedItemIndex()) {
                (*it)->option.setFillColor(sf::Color(200, 100, 0));
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
                        if (actionValue.find("b") != std::string::npos) {//controllo sia una moto
                            auto bike = Game::gameData->bikes.at(actionValue);
                            if (!bike->getIsUnlocked()) {
                                std::cout << "Selected Bike to buy:" << bike->getName() << std::endl;
                                if (Game::gameData->player->getTotalCoin() >= bike->getPrice()) {
                                    Game::gameData->player->removeTotalCoin(bike->getPrice());
                                    Game::gameData->bikes.at(bike->getId())->setIsUnlocked(true);
                                    std::cout << bike->getName() << " bought!" << std::endl;
                                } else {
                                    std::cout << "Sorry, you are poor D:" << std::endl;
                                }
                            } else {
                                std::cout << "Bike " << bike->getName() << " already bought!" << std::endl;
                            }
                        }
                    }
            }
            break;
        default:
            break;
    }
}
