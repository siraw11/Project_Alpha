//
// Created by davide on 09/11/19.
//

#ifndef GAME_STATE_PAUSE_H
#define GAME_STATE_PAUSE_H

#include "State.h"
#include "../Game_Screens/Pause.h"

class State_Pause : public State {
public:
    explicit State_Pause(StateManager *stateManager);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    StateManager *_stateManager;
    Pause pause;
};


#endif //GAME_STATE_PAUSE_H
