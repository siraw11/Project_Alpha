//
// Created by davide on 19/10/19.
//
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "GameStates.h"

#ifndef GAME_PAUSE_H
#define GAME_PAUSE_H
#define SIZE 3

class Pause {
public:
    Pause();

    void update(Input *input, GameStates *state, sf::RenderWindow *window);

    void drawMenu(sf::RenderWindow *window);

    int selected = 0;
private:
    sf::Text text;
    sf::Text pause[SIZE];
    sf::Font Font;
    sf::Vector2i text1Pos;
    sf::Vector2i text2Pos;
    sf::Vector2i text3Pos;
    sf::Vector2i textPos;
    unsigned int textSize = 30;
};


#endif //GAME_PAUSE_H
