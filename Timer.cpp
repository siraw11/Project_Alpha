//
// Created by Luca Graziotti on 18/11/2019.
//

#include "Timer.h"

void Timer::start() {
    startTime = std::chrono::system_clock::now();
    running = true;
}

void Timer::stop() {
    endTime = std::chrono::system_clock::now();
    elapsed = time;
    running = false;
}

void Timer::update() {
    time = elapsedMilliseconds();
}


double Timer::elapsedMilliseconds() {
    std::chrono::time_point<std::chrono::system_clock> endTimeNow;
    if (running) {
        endTimeNow = std::chrono::system_clock::now();
    } else {
        endTimeNow = this->endTime;
    }
    double diffTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeNow - startTime).count();
    return diffTime;
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

time_t Timer::getTime() {
    update();
    if (running) {
        time += elapsed;
    } else {
        time = elapsed;
    }
    return time;
}
