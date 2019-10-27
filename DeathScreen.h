//
// Created by davide on 20/10/19.
//
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "GameStates.h"

#ifndef GAME_DEATHSCREEN_H
#define GAME_DEATHSCREEN_H
#define SIZE 3

class DeathScreen {

public:
    DeathScreen();

    void update(Input *input, GameStates *state, sf::RenderWindow *window);

    void drawMenu(sf::RenderWindow *window);

    int selected = 0;
private:
    sf::Text dead;
    sf::Text pause[SIZE];
    sf::Font Font;
    sf::Vector2i text1Pos;
    sf::Vector2i text2Pos;
    sf::Vector2i text3Pos;
    sf::Vector2i deadPos;
    unsigned int textSize = 30;
};


#endif //GAME_DEATHSCREEN_H
