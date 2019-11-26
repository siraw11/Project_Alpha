//
// Created by Luca Graziotti on 18/11/2019.
//

#ifndef MOTOCROSS2D_TIMER_H
#define MOTOCROSS2D_TIMER_H

#include <list>
#include <iostream>
#include "Subject.h"
#include "Observer.h"


class Timer : public Subject {
public:
    void start();

    void stop();

    void update();

    static std::string elapsedString(long t);

    double elapsedSeconds();

    double elapsedMilliseconds();

    void decrementTimer(float dt);

    time_t getTime();

    virtual void registerObserver(Observer *o) override;

    virtual void removeObserver(Observer *o) override;

    virtual void notifyObservers() override;

    std::list<Observer *> observers;
private:
    std::time_t time;
    std::time_t elapsed;


    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
    bool running = false;

    static std::string chronoFormat(float t);
};


#endif //MOTOCROSS2D_TIMER_H
