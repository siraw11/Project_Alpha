//
// Created by davide on 19/10/19.
//


#ifndef GAME_PAUSE_H
#define GAME_PAUSE_H

#include <SFML/Graphics.hpp>
#include "../Input.h"

#define SIZE 3

class StateManager;
class Pause {
public:
    Pause();

    void update(Input input, StateManager *state, sf::RenderWindow *window);
    void drawPause(sf::RenderWindow *window);

    int selected = 0;
private:
    sf::Text text;
    sf::Text pause[SIZE];
    sf::Font Font;
    sf::Vector2i text1Pos;
    sf::Vector2i text2Pos;
    sf::Vector2i text3Pos;
    sf::Vector2i titlePos;
    unsigned int textSize = 30;
};


#endif //GAME_PAUSE_H
