//
// Created by davide on 16/09/19.
//

#ifndef GAME_MENU_H
#define GAME_MENU_H
#define SIZE 2

#include <SFML/Graphics.hpp>

class Menu {

public:
    Menu();//TODO Implmetare menu

    void drawMenu(sf::RenderWindow *window);

public:
    sf::Text menu[SIZE];
    sf::Font Font, Font2;
};


#endif //GAME_MENU_H
