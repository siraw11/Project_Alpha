//
// Created by davide on 08/11/19.
//

#ifndef GAME_STATE_ACHIEVEMENT_H
#define GAME_STATE_ACHIEVEMENT_H

#include "State.h"
#include "../Game_Screens/AchievementScreen.h"

class State_Achievement : public State {
public:
    explicit State_Achievement(StateManager *stateManager);

    void run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic);

    StateManager *_stateManager;
    AchievementScreen achievementScreen;

};


#endif //GAME_STATE_ACHIEVEMENT_H
