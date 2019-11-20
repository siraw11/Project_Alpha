//
// Created by Luca Graziotti on 20/11/2019.
//

#include "SelectBikeState.h"

#include <Menu.h>
#include <Game.h>
#include "GameState.h"
#include "MenuHomeState.h"

SelectBikeState::SelectBikeState() {
    this->menu = new Menu(MenuType::Home, SelectBikeState::loadOptions());
}

SelectBikeState::~SelectBikeState() {

}


std::vector<MenuOption *> SelectBikeState::loadOptions() {
    std::vector<MenuOption *> options;
    MenuOption *option;

    int i = 0;
    for (auto it = Game::gameData->bikes.begin(); it != Game::gameData->bikes.end(); ++it, ++i) {
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


void SelectBikeState::update() {
}

void SelectBikeState::draw() {
    Game::gameData->window.clear(sf::Color(0, 0, 0));
    std::vector<MenuOption *>::iterator it;
    float width = Game::gameData->window.getView().getCenter().x;
    float height = Game::gameData->window.getView().getCenter().y;


    sf::Text textHeader;
    textHeader.setPosition(width, height);
    sf::Font font;
    if (!font.loadFromFile("./resources/fonts/Arial.ttf")) {}
    textHeader.setFont(font);
    textHeader.setCharacterSize(80);
    textHeader.setPosition(width, height - 250);
    textHeader.setFillColor(sf::Color(50, 50, 100));
    textHeader.setString("Select Bike");
    Game::gameData->window.draw(textHeader);


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
                    (*it)->option.setFillColor(sf::Color(200, 100, 100));
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

void SelectBikeState::handleInput(sf::Event event) {
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
                        if (actionValue.find("b") != std::string::npos) {
                            auto bike = Game::gameData->bikes.at(actionValue);
                            if (bike->getIsUnlocked()) {
                                std::cout << "Selected bike:" << bike->getName() << std::endl;
                                Game::gameData->match->setBike(bike);
                                Game::gameData->machine.push_state(StateRef(new GameState(true)));
                            } else {
                                std::cout << "Map " << bike->getName() << " is locked!" << std::endl;
                            }
                        }
                    }
            }
            break;
        default:
            break;
    }
}
