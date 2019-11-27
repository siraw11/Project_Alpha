//
// Created by davide on 07/11/19.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SFML/Graphics.hpp"
#include "../Input.h"
#include "../LevelManager.h"
#include "../GameLogic.h"

class State {
public:
    virtual void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) = 0;
};


#endif //GAME_STATE_H
