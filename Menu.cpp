//
// Created by Luca Graziotti on 2019-10-12.
//
#include <MacTypes.h>
#include "Menu.h"
#include "Game.h"

Menu::Menu(MenuType _type, std::vector<MenuOption *> _options) : type(_type), options(_options), selectedItemIndex(0) {}


Menu::~Menu() {
}

void Menu::MoveUp() {
    if (options.size() > 0) {
        if (selectedItemIndex - 1 >= 0) {
            options[selectedItemIndex]->option.setColor(sf::Color::White);
            selectedItemIndex--;
            options[selectedItemIndex]->option.setColor(sf::Color::Red);
        }
    }
}

void Menu::MoveDown() {
    if (options.size() > 0) {
        if (selectedItemIndex + 1 < options.size()) {
            options[selectedItemIndex]->option.setColor(sf::Color::White);
            selectedItemIndex++;
            options[selectedItemIndex]->option.setColor(sf::Color::Red);
        }
    }
}

int Menu::getSelectedItemIndex() const {
    return selectedItemIndex;
}

void Menu::setSelectedItemIndex(int selectedItemIndex) {
    Menu::selectedItemIndex = selectedItemIndex;
}


void Menu::open() {
    while (Game::gameData->window.isOpen()) {
        sf::Event event;
        while (Game::gameData->window.pollEvent(event)) {
            Game::gameData->window.display();
            if (event.type == sf::Event::KeyReleased) {

                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        this->MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        this->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (type) {
                            case Home:
                                switch (this->getSelectedItemIndex()) {
                                    case 0:
                                        std::cout << "Play button has been pressed" << std::endl;
                                        //engine->run();
                                        break;
                                    case 1:
                                        std::cout << "Option button has been pressed" << std::endl;
                                        break;
                                    case 2:
                                        Game::gameData->window.close();
                                        break;
                                }
                                break;
                            case Pause:
                                switch (this->getSelectedItemIndex()) {
                                    case 0:
                                        std::cout << "Resume button has been pressed" << std::endl;
                                        //engine->setPause(false);
                                        return;
                                    case 1:
                                        Game::gameData->window.close();
                                        break;
                                }
                                break;
                        }


                        break;
                }
            }
        }
    }

}
