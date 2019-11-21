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
            options[selectedItemIndex]->option.setFillColor(sf::Color::White);
            selectedItemIndex--;
            options[selectedItemIndex]->option.setFillColor(sf::Color::Red);
        }
    }
}

void Menu::MoveDown() {
    if (options.size() > 0) {
        if (selectedItemIndex + 1 < options.size()) {
            options[selectedItemIndex]->option.setFillColor(sf::Color::White);
            selectedItemIndex++;
            options[selectedItemIndex]->option.setFillColor(sf::Color::Red);
        }
    }
}

int Menu::getSelectedItemIndex() const {
    return selectedItemIndex;
}

void Menu::setSelectedItemIndex(int selectedItemIndex) {
    Menu::selectedItemIndex = selectedItemIndex;
}


