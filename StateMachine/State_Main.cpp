//
// Created by davide on 07/11/19.
//

#include "State_Main.h"
#include "StateManager.h"
State_Main::State_Main(StateManager *stateManager) {
    _stateManager = stateManager;
    music.setVolume(volume);
    music.openFromFile("Music/buttercup .ogg");
}

void State_Main::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    if (!playing) {
        music.play();
        playing = true;
    }
    if (!reset) {
        levelManager->resetLevel();
        reset = true;
    }
    levelManager->currentLevel->camera.setCenter(400, 300);
    window->setView(levelManager->currentLevel->camera);
    menu.update(input, _stateManager, window);
    menu.drawMenu(window);
    if (_stateManager->current != this) {
        music.stop();
    }

}