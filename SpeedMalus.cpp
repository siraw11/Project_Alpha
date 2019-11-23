//
// Created by Magna on 2019-11-23.
//

#include "SpeedMalus.h"
#include "Game.h"

SpeedMalus::SpeedMalus(double _speedDecrement, double _posX, double _posY, double _width, double _height,
                       std::string _texture, float _angle) : Item(_posX,
                                                                  _posY,
                                                                  _width,
                                                                  _height,
                                                                  _texture, _angle),
                                                             speedDecrement(_speedDecrement) {}

double SpeedMalus::getSpeedDecrement() const {
    return speedDecrement;
}

void SpeedMalus::setSpeedDecrement(double speedDecrement) {
    SpeedMalus::speedDecrement = speedDecrement;
}


void SpeedMalus::doSpecial() {
    std::cout << "OH NO! Removed:" << speedDecrement << " speed" << std::endl;
    Game::gameData->engine->speedChange(200);
}
