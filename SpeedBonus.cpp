//
// Created by Magna on 2019-06-07.
//

#include "SpeedBonus.h"
#include "Item.h"
#include "Game.h"

SpeedBonus::SpeedBonus(double _posX, double _posY, double _width,
                       double _height, float _angle, double _speedIncrement, double _seconds, std::string _texture)
        : Item(_posX,
                                                                                  _posY,
                                                                                  _width,
                                                                                  _height,
                                                                                  _angle,
                                                                                  _texture),
          speedIncrement(_speedIncrement),
          seconds(_seconds) {
}

double SpeedBonus::getSeconds() const {
    return seconds;
}

void SpeedBonus::setSeconds(double seconds) {
    SpeedBonus::seconds = seconds;
}

double SpeedBonus::getSpeedIncrement() const {
    return speedIncrement;
}

void SpeedBonus::setSpeedIncrement(double speedIncrement) {
    SpeedBonus::speedIncrement = speedIncrement;
}

void SpeedBonus::doSpecial() {
    this->attach();
    setTaken(true);
    setTakenTime(Game::gameData->match->getTimer()->getTime());
    std::cout << "Taken at :" << getTakenTime() << std::endl;
    std::cout << "Special! Addedd:" << speedIncrement << " speed" << std::endl;
    Game::gameData->engine->speedChange(speedIncrement);
}


void SpeedBonus::update(float dt) {
    if (dt - getTakenTime() > seconds * 1000) {
        detach();
    }
    Game::gameData->engine->speedChange(speedIncrement);
}

void SpeedBonus::attach() {
    Game::gameData->match->getTimer()->registerObserver(this);
    std::cout << "attached observer!" << std::endl;
}

void SpeedBonus::detach() {
    Game::gameData->match->getTimer()->removeObserver(this);
    std::cout << "Detached observer" << std::endl;
}


float SpeedBonus::getTakenTime() const {
    return takenTime;
}

void SpeedBonus::setTakenTime(float takenTime) {
    SpeedBonus::takenTime = takenTime;
}

SpeedBonus::~SpeedBonus() {
    detach();
}

