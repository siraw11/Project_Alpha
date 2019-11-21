//
// Created by Luca Graziotti on 18/11/2019.
//

#ifndef MOTOCROSS2D_TIMER_H
#define MOTOCROSS2D_TIMER_H

#include <iostream>

class Timer {
public:
    void start();

    void stop();

    void update();

    static std::string elapsedString(long t);

    double elapsedSeconds();

    double elapsedMilliseconds();

    void decrementTimer(float dt);

    time_t getTime();

private:
    std::time_t time;
    std::time_t elapsed;

    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
    bool running = false;

    static std::string chronoFormat(float t);
};


#endif //MOTOCROSS2D_TIMER_H
