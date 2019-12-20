//
// Created by andreatadde on 12/12/19.
//

#ifndef GAME_ENDSCREEN_H
#define GAME_ENDSCREEN_H
#define SIZE_END 2

#include "../Input.h"
#include "../StateMachine/StateManager.h"
#include "SFML/Graphics.hpp"

class EndScreen {

public:
    EndScreen();

    void update(Input input, StateManager *state, sf::RenderWindow *window);
    void drawMenu(sf::RenderWindow *window);

    virtual ~EndScreen();

private:
    sf::Text title;
    sf::Text endVect[SIZE_END];
    sf::Font Font;
    int selected = 0;
    sf::Vector2i text1Pos;
    sf::Vector2i text2Pos;
    sf::Vector2i titlePos;
    unsigned int textSize = 30;
};


#endif //GAME_ENDSCREEN_H
