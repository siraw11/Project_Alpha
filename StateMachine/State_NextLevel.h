//
// Created by davide on 09/11/19.
//

#ifndef GAME_STATE_NEXTLEVEL_H
#define GAME_STATE_NEXTLEVEL_H

#include "State.h"
#include "../Game_Screens/NextLevelScreen.h"

class State_NextLevel : public State {
public:
    explicit State_NextLevel(StateManager *stateManager);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    StateManager *_stateManager;
    NextLevelScreen nextLevelScreen;

};


#endif //GAME_STATE_NEXTLEVEL_H
