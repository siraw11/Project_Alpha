//
// Created by Magna on 2019-11-23.
//

#include "SpeedMalus.h"
#include "Game.h"

SpeedMalus::SpeedMalus(double _posX, double _posY, double _width, double _height, float _angle, double _speedDecrement,
                       std::string _texture) : Item(_posX,
                                                    _posY,
                                                    _width,
                                                    _height,
                                                    _angle,
                                                    _texture),
                                                             speedDecrement(_speedDecrement) {}

double SpeedMalus::getSpeedDecrement() const {
    return speedDecrement;
}

void SpeedMalus::setSpeedDecrement(double speedDecrement) {
    SpeedMalus::speedDecrement = speedDecrement;
}


void SpeedMalus::doSpecial() {
    Game::gameData->engine->speedChange(speedDecrement);
}
