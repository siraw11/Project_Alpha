//
// Created by davide on 16/09/19.
//

#ifndef GAME_MENU_H
#define GAME_MENU_H
#define SIZE 3

#include "../Input.h"
#include "../StateMachine/StateManager.h"
#include "SFML/Graphics.hpp"

class Menu {

public:
    Menu();

    void update(Input input, StateManager *state, sf::RenderWindow *window);
    void drawMenu(sf::RenderWindow *window);

    virtual ~Menu();

private:
    sf::Text title;
    sf::Text menu[SIZE];
    sf::Font Font;
    int selected = 0;
    sf::Vector2i text1Pos;
    sf::Vector2i text2Pos;
    sf::Vector2i text3Pos;
    sf::Vector2i titlePos;
    unsigned int textSize = 30;
};


#endif //GAME_MENU_H
