//
// Created by davide on 07/11/19.
//

#include "StateManager.h"
#include "State_Main.h"

StateManager::StateManager() {
    current = new State_Main(this);
}

void StateManager::setState(State *state) {
    current = state;
}

void StateManager::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    current->run(window, input, levelManager, logic);
}