//
// Created by Magna on 2019-06-07.
//

#include "TimeBonus.h"

TimeBonus::TimeBonus(double _timeEarned):timeEarned(_timeEarned) {}
double TimeBonus::getTimeEarned() const {
    return timeEarned;
}

void TimeBonus::setTimeEarned(double timeEarned) {
    TimeBonus::timeEarned = timeEarned;
}
//todo doSpecial();