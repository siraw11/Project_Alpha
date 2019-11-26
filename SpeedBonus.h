//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_SPEEDBONUS_H
#define MOTOCROSS2D_SPEEDBONUS_H


#include "Item.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Observer.h"
#include "Timer.h"

class SpeedBonus : public Item, public Observer {
public:
    SpeedBonus(double seconds = 0, double speedIncrement = 0,
               double posX = 0, double posY = 0, double width = 0,
               double height = 0, float angle = 0,
               std::string texture = "rocket1.png");

    ~SpeedBonus();

    double getSeconds() const;

    void setSeconds(double seconds);

    double getSpeedIncrement() const;

    void setSpeedIncrement(double speedIncrement);

    void doSpecial() override final;

    virtual void update(float dt);

    virtual void attach();

    virtual void detach();

    float getTakenTime() const;

    void setTakenTime(float takenTime);

private:
    double seconds;
    double speedIncrement;
    float takenTime;
};


#endif //MOTOCROSS2D_SPEEDBONUS_H
