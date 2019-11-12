//
// Created by Magna on 2019-06-07.
//

#include <GameStates/GameWinState.h>
#include "GameStates/StateMachine.h"
#include "Checkpoint.h"
#include "Game.h"

Checkpoint::Checkpoint(double _posX, double _posY, double _width, double _height, bool _isEnd, std::string _texture)
        : Item(_posX,
               _posY,
               _width,
               _height,
               _texture), isEnd(_isEnd) {}


void Checkpoint::doSpecial() {
    if (isEnd) {
        Game::gameData->machine.push_state(StateRef(new GameWinState()));
    } else {
        //TODO:da implementare salvataggio ultima posizione
        std::cout << "checkpoint Save";
    }
}