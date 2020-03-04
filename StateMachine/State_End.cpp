//
// Created by andreatadde on 12/12/19.
//

#include "State_End.h"

State_End::State_End(StateManager *stateManager) {
    _stateManager = stateManager;
}

void State_End::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    levelManager->setLevelNumber(0);
    levelManager->resetLevel();
    levelManager->currentLevel->camera.setCenter(400, 300);
    window->setView(levelManager->currentLevel->camera);
    endScreen.update(input, _stateManager,window);
    endScreen.drawMenu(window);
}
