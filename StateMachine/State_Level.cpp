//
// Created by davide on 08/11/19.
//

#include "State_Level.h"
#include "StateManager.h"

State_Level::State_Level(StateManager *stateManager) {
    _stateManager = stateManager;
    music.setVolume(volume);
    music.openFromFile("Music/Megalovania8bit.ogg");

}

void State_Level::run(sf::RenderWindow *window, Input input, LevelManager *levelManager, GameLogic *logic) {
    Hud hud;
    if (!playing) {
        music.play();
        playing = true;
    }
    levelManager->currentLevel->Update(window);
    logic->Update(levelManager->currentLevel, _stateManager, input, window, &hud, levelManager->getLevelNumber(),
                  levelManager->getNumberOfLevels());

    if (_stateManager->current != this) {
        music.stop();
    }
}