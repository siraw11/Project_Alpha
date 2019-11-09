//
// Created by davide on 09/11/19.
//

#include "State_NextLevel.h"

State_NextLevel::State_NextLevel(StateManager *stateManager) {
    _stateManager = stateManager;

}

void State_NextLevel::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    levelManager->nextLevel();
    levelManager->currentLevel->camera.setCenter(400, 300);
    window->setView(levelManager->currentLevel->camera);
    nextLevelScreen.update(input, _stateManager, window);
    nextLevelScreen.drawMenu(window);

}