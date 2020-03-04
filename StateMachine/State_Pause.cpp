//
// Created by davide on 09/11/19.
//

#include "State_Pause.h"

State_Pause::State_Pause(StateManager *stateManager) {
    _stateManager = stateManager;

}

void State_Pause::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    levelManager->currentLevel->camera.setCenter(400, 300);
    window->setView(levelManager->currentLevel->camera);
    pause.update(input, _stateManager, window);
    pause.drawPause(window);

}