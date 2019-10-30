//
// Created by davide on 29/10/19.
//

#ifndef GAME_NEXTLEVELSCREEN_H
#define GAME_NEXTLEVELSCREEN_H
#define SIZE 3

#include "Input.h"
#include "SFML/Graphics.hpp"
#include "GameStates.h"

class NextLevelScreen {
public:
    NextLevelScreen();

    void update(Input *input, GameStates *state, sf::RenderWindow *window);
    void drawMenu(sf::RenderWindow *window);

    int selected = 0;
private:
    sf::Text title;
    sf::Text menu[SIZE];
    sf::Font Font;
    sf::Vector2i text1Pos;
    sf::Vector2i text2Pos;
    sf::Vector2i text3Pos;
    sf::Vector2i titlePos;
    unsigned int textSize = 30;

};


#endif //GAME_NEXTLEVELSCREEN_H
