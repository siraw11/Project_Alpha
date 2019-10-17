//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_SPEEDBONUS_H
#define MOTOCROSS2D_SPEEDBONUS_H


#include "Item.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class SpeedBonus: public Item {
public:
    SpeedBonus(double seconds=0,double speedIncrement=0,
            double posX = 0, double posY = 0, double width = 0,
            double height = 0,
               std::string texture = "../textures/rocket1.png");
    ~SpeedBonus();

    double getSeconds() const;

    void setSeconds(double seconds);

    double getSpeedIncrement() const;

    void setSpeedIncrement(double speedIncrement);

    void doSpecial() override final;

private:
    double seconds;
    double speedIncrement;




};


#endif //MOTOCROSS2D_SPEEDBONUS_H
