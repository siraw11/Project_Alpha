//
// Created by Magna on 2019-06-07.
//

#include "SpeedBonus.h"
#include "Item.h"

SpeedBonus::SpeedBonus(double _seconds, double _speedIncrement, double _posX, double _posY, double _width, double _height, std::string _texture): Item(_posX,
                                                                                                                                 _posY,
                                                                                                                                 _width,
                                                                                                                                 _height,
                                                                                                                                 _texture),
                                                                                                                            seconds(_seconds),
                                                                                                                            speedIncrement(_speedIncrement){}

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
    setTaken(true);
    std::cout << "Special! Addedd:" << speedIncrement << " speed" << std::endl;
    std::cout << "Special! Addedd:" << seconds << " seconds" << std::endl;


}
