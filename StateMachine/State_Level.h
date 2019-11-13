//
// Created by davide on 08/11/19.
//

#ifndef GAME_STATE_LEVEL_H
#define GAME_STATE_LEVEL_H

#include "State.h"

class State_Level : public State {

public:
    explicit State_Level(StateManager *stateManager);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    StateManager *_stateManager;
    bool playing = false;
    sf::Music music;
    float volume = 30.f;
};


#endif //GAME_STATE_LEVEL_H
