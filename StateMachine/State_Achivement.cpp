//
// Created by davide on 08/11/19.
//

#include "State_Achivement.h"

State_Achivement::State_Achivement(StateManager *stateManager) {
    _stateManager = stateManager;
}

void State_Achivement::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    achievementScreen.update(input, _stateManager);
    achievementScreen.drawAchievements(&logic->achievementNotifier, window);
}