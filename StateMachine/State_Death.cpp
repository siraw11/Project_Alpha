//
// Created by davide on 09/11/19.
//

#include "State_Death.h"

State_Death::State_Death(StateManager *stateManager) {
    _stateManager = stateManager;

}

void State_Death::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    levelManager->resetLevel();
    levelManager->currentLevel->camera.setCenter(400, 300);
    window->setView(levelManager->currentLevel->camera);
    deathScreen.update(input, _stateManager, window);
    deathScreen.drawMenu(window);
}