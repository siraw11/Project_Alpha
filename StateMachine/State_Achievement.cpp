//
// Created by davide on 08/11/19.
//

#include "State_Achievement.h"

State_Achievement::State_Achievement(StateManager *stateManager) {
    _stateManager = stateManager;
}

void State_Achievement::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    achievementScreen.update(input, _stateManager);
    achievementScreen.drawAchievements(&logic->achievementNotifier, window);
}