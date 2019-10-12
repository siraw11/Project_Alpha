//
// Created by davide on 16/09/19.
//

#include "Menu.h"
#include <iostream>

Menu::Menu() {
    this->Font.loadFromFile("../textures/arial_narrow_7.ttf");
    this->Font2.loadFromFile("../textures/arial_narrow_7.ttf");
    menu[0].setFont(this->Font);
    menu[0].setCharacterSize(30);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setPosition(100, 100);
    menu[0].setString("START");

    menu[1].setFont(this->Font2);
    menu[1].setCharacterSize(30);
    menu[1].setFillColor(sf::Color::Red);
    menu[1].setPosition(300, 100);
    menu[1].setString("EXIT");
}

void Menu::drawMenu(sf::RenderWindow *window) {

    for (int i = 0; i < SIZE; i++) {
        std::cout << "Scrivo" << std::endl;
        window->draw(this->menu[i]);
    }
}