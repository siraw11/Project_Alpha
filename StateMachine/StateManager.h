//
// Created by davide on 07/11/19.
//

#ifndef GAME_STATEMANAGER_H
#define GAME_STATEMANAGER_H

#include "SFML/Graphics.hpp"
#include "../Input.h"
#include "../LevelManager.h"
#include "../GameLogic.h"
#include "../StateMachine/State.h"

class StateManager {
public:
    StateManager();
    
    void setState(State *state);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    State *current;
};


#endif //GAME_STATEMANAGER_H
