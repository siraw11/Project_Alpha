//
// Created by davide on 07/11/19.
//

#ifndef GAME_STATE_MAIN_H
#define GAME_STATE_MAIN_H

#include "State.h"
#include "../Game_Screens/Menu.h"

class State_Main : public State {
public:
    explicit State_Main(StateManager *stateManager);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    StateManager *_stateManager;
    bool playing = false;
    sf::Music music;
    Menu menu;
    float volume = 40.f;
    bool reset = false;
};


#endif //GAME_STATE_MAIN_H
