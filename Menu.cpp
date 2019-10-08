//
// Created by davide on 16/09/19.
//

#include "Menu.h"
#include <iostream>

Menu::Menu() {
    menu = (sf::Text *) malloc(2 * sizeof(sf::Text));
    menu[0].setString("PLAY");
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setPosition(100, 100);
    menu[1].setString("Exit");
    menu[1].setFillColor(sf::Color::White);
    menu[1].setPosition(100, 75);
}

void Menu::drawMenu(sf::RenderWindow *window) {

    for (int i = 0; i < 1; i++) {
        std::cout << "Scrivo" << std::endl;
        window->draw(menu[0]);
    }
}