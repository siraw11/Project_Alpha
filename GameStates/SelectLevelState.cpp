//
// Created by Luca Graziotti on 09/11/2019.
//

#include <Menu.h>
#include <Game.h>
#include <ResourceManager/ResourceFont.h>
#include "SelectLevelState.h"
#include "GameState.h"
#include "MenuHomeState.h"
#include "SelectBikeState.h"

SelectLevelState::SelectLevelState() {
    this->menu = new Menu(MenuType::Home, SelectLevelState::loadLevelsOptions());
}

SelectLevelState::~SelectLevelState() {

}


std::vector<MenuOption *> SelectLevelState::loadLevelsOptions() {
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


void SelectLevelState::update() {
}

void SelectLevelState::draw() {
    Game::gameData->window.clear(sf::Color(0, 0, 0));
    std::vector<MenuOption *>::iterator it;
    float width = Game::gameData->window.getView().getCenter().x;
    float height = Game::gameData->window.getView().getCenter().y;


    sf::Text textHeader;
    textHeader.setPosition(width, height);
    textHeader.setFont(Game::gameData->resources.getResource<ResourceFont *>("arial.ttf")->getFont());
    textHeader.setCharacterSize(80);
    textHeader.setPosition(width, height - 250);
    textHeader.setFillColor(sf::Color(50, 50, 100));
    textHeader.setString("Select Level");
    Game::gameData->window.draw(textHeader);


    int i = 0;
    for (it = menu->options.begin(), i = 0; it != menu->options.end(); it++, i++) {
        (*it)->option.setPosition(sf::Vector2f(width, height + i * 100));
        (*it)->option.setFillColor(sf::Color::White);
        if (i < Game::gameData->levels.size()) {
            if (Game::gameData->levels.at((*it)->getValue())->getIsUnlocked()) {
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

void SelectLevelState::handleInput(sf::Event event) {
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
                                Game::gameData->match->getMap()->resetItems();
                                Game::gameData->match->setLifes(3);
                                Game::gameData->match->setFlips(0);
                                Game::gameData->machine.push_state(StateRef(new SelectBikeState()));
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
