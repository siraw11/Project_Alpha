//
// Created by andreatadde on 12/12/19.
//

#ifndef GAME_STATE_END_H
#define GAME_STATE_END_H

#include "State.h"
#include "../Game_Screens/EndScreen.h"

class State_End : public State {
public:
    explicit State_End(StateManager *stateManager);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    StateManager *_stateManager;
    EndScreen endScreen;
};


#endif //GAME_STATE_END_H
