//
// Created by davide on 09/11/19.
//

#ifndef GAME_STATE_DEATH_H
#define GAME_STATE_DEATH_H


#include "State.h"
#include "../Game_Screens/DeathScreen.h"

class State_Death : public State {

public:
    explicit State_Death(StateManager *stateManager);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    StateManager *_stateManager;
    DeathScreen deathScreen;
};


#endif //GAME_STATE_DEATH_H
