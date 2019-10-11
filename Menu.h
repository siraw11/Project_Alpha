//
// Created by waris on 09/10/19.
//
#pragma once

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3
#define D  1.5 //distanza da bordo dx.


class Menu {
public:
    Menu(float width, float height);

    ~Menu();

    void draw(sf::RenderWindow &window);

    void MoveUp();

    void MoveDown();

    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
