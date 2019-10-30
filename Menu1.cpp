//
// Created by waris on 11/10/19.
//

#include "Menu1.h"

Menu1::Menu1(float width, float height){
    if (!font.loadFromFile("../Resources/Menu/pacifico.ttf"))
    {
        // handle error
    }

    menu1[0].setFont(font);
    menu1[0].setFillColor(sf::Color::Red);
    menu1[0].setString("Archer");
    menu1[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu1[1].setFont(font);
    menu1[1].setFillColor(sf::Color::White);
    menu1[1].setString("Knight");
    menu1[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu1[2].setFont(font);
    menu1[2].setFillColor(sf::Color::White);
    menu1[2].setString("Mage");
    menu1[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Menu1::~Menu1()
= default;

void Menu1::draw(sf::RenderWindow &window)
{
    for (const auto & i : menu1)
    {
        window.draw(i);
    }
}

void Menu1::MoveUp1()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu1[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu1[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu1::MoveDown1()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu1[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu1[selectedItemIndex].setFillColor(sf::Color::Red);
    }

}

