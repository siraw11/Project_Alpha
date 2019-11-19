//
// Created by Luca Graziotti on 18/11/2019.
//

#include "Timer.h"
#include <iomanip>

void Timer::start() {
    startTime = std::chrono::system_clock::now();
    running = true;
}

void Timer::stop() {
    endTime = std::chrono::system_clock::now();
    time = elapsedMilliseconds();
    running = false;
}


double Timer::elapsedMilliseconds() {
    std::chrono::time_point<std::chrono::system_clock> endTime;

    if (running) {
        endTime = std::chrono::system_clock::now();
    } else {
        endTime = this->endTime;
    }

    return time + std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
}

double Timer::elapsedSeconds() {
    return elapsedMilliseconds() / 1000.0;
}


std::string Timer::elapsedString(long milli) {
    long hr = milli / 3600000;
    milli = milli - 3600000 * hr;
    long min = milli / 60000;
    milli = milli - 60000 * min;
    long sec = milli / 1000;
    milli = milli - 1000 * sec;

    return chronoFormat(min) + ":" + chronoFormat(sec) + ":" + chronoFormat(milli);
}

std::string Timer::chronoFormat(float t) {
    std::string s = "00";
    if (t < 10) {
        s = "0" + std::to_string(t).substr(0, 1);
    } else {
        s = std::to_string(t).substr(0, 2);
    }
    return s;
}