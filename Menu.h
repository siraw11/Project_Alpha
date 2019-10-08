//
// Created by davide on 16/09/19.
//

#ifndef GAME_MENU_H
#define GAME_MENU_H

#include <SFML/Graphics.hpp>

class Menu { //TODO risolvere bug memoria

public:
    Menu();

    void drawMenu(sf::RenderWindow *window);

public:
    sf::Text *menu;
};


#endif //GAME_MENU_H
