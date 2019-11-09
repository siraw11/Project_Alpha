//
// Created by Luca Graziotti on 2019-10-12.
//
#include "MenuOption.h"

MenuOption::MenuOption(const std::string &_text) {
    font.loadFromFile("../fonts/Arial.ttf");
    option.setString(_text);
    option.setColor(sf::Color::White);
    option.setCharacterSize(40);
    option.setFont(font);
}

MenuOption::~MenuOption() {

}


std::vector<MenuOption *> MenuOption::loadMainMenuOptions() {
    std::vector<MenuOption *> options;
    MenuOption *option;
    option = new MenuOption("Play");
    options.push_back(option);
    option = new MenuOption("Settings");
    options.push_back(option);
    option = new MenuOption("Exit Game");
    options.push_back(option);
    return options;
}

std::vector<MenuOption *> MenuOption::loadPauseMenuOptions() {
    std::vector<MenuOption *> options;
    MenuOption *option;
    option = new MenuOption("Resume");
    options.push_back(option);
    option = new MenuOption("Back Menu");
    options.push_back(option);
    option = new MenuOption("Exit Game");
    options.push_back(option);
    return options;
}