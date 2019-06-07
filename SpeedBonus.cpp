//
// Created by Magna on 2019-06-07.
//

#include "SpeedBonus.h"

SpeedBonus::SpeedBonus(double seconds, double speedIncrement) {}

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

//todo doSpecial();