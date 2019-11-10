//
// Created by Luca Graziotti on 09/11/2019.
//

#include <Menu.h>
#include <Game.h>
#include "SelectLevelState.h"
#include "GameState.h"
#include "MenuHomeState.h"

SelectLevelState::SelectLevelState() {
    this->menu = new Menu(MenuType::Home, SelectLevelState::loadLevelsOptions());
}

SelectLevelState::~SelectLevelState() {

}


std::vector<MenuOption *> SelectLevelState::loadLevelsOptions() {
    std::vector<MenuOption *> options;
    MenuOption *option;


    option = new MenuOption("Level 1");
    options.push_back(option);

    //TODO: aggiungere riconoscimento se mappa bloccata
    option = new MenuOption("Level 2");
    options.push_back(option);
    option = new MenuOption("Level 3 (locked)");
    options.push_back(option);
    lockedLevelsIndexes.push_front(2);

    option = new MenuOption("Back");
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
    int i = 0;

    for (it = menu->options.begin(); it != menu->options.end(); it++, i++) {
        (*it)->option.setPosition(sf::Vector2f(width, height + i * 100));
        bool isLockedLevel =
                std::find(lockedLevelsIndexes.begin(), lockedLevelsIndexes.end(), i) != lockedLevelsIndexes.end();
        if (i == menu->getSelectedItemIndex()) {
            if (!isLockedLevel) {
                (*it)->option.setColor(sf::Color::Red);
            } else {
                (*it)->option.setColor(sf::Color(100, 10, 100));
            }
        } else {
            if (isLockedLevel) {
                (*it)->option.setColor(sf::Color(10, 10, 100));
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
                    switch (menu->getSelectedItemIndex()) {
                        case 0://Level 1
                            std::cout << "Level 1 selected" << std::endl;
                            Game::gameData->match->map->loadLevel1();
                            Game::gameData->machine.push_state(StateRef(new GameState(true)));
                            break;
                        case 1://Level 2
                            std::cout << "Level 2 selected" << std::endl;
                            Game::gameData->match->map->loadLevel2();
                            Game::gameData->machine.push_state(StateRef(new GameState(true)));
                            break;
                        case 2://Level 3
                            std::cout << "Level 3 selected" << std::endl;
                            break;
                        case 3://Back to home menu
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
