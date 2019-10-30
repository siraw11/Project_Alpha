//
// Created by waris on 11/10/19.
//

#pragma once
#include "SFML/Graphics.hpp"


#define MAX_NUMBER_OF_ITEMS 3

class Menu1
{
public:
    Menu1(float width, float height);
    ~Menu1();

    void draw(sf::RenderWindow &window);
    void MoveUp1();
    void MoveDown1();
    int GetPressedItem1() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu1[MAX_NUMBER_OF_ITEMS];

};
