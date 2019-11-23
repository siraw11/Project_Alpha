//
// Created by Magna on 2019-06-07.
//

#include "TimeBonus.h"
#include "Game.h"

TimeBonus::TimeBonus(double _timeEarned, double _posX, double _posY, double _width, double _height,
                     std::string _texture, float _angle) : Item(_posX,
                                                                _posY,
                                                                _width,
                                                                _height,
                                                                _texture, _angle), timeEarned(_timeEarned) {}
double TimeBonus::getTimeEarned() const {
    return timeEarned;
}

void TimeBonus::setTimeEarned(double timeEarned) {
    TimeBonus::timeEarned = timeEarned;
}

void TimeBonus::doSpecial() {
    std::cout << "Special! " << this->timeEarned << " seconds earned" << std::endl;
    Game::gameData->match->getTimer()->decrementTimer(this->timeEarned);
    setTaken(true);

}