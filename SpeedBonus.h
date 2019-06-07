//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_SPEEDBONUS_H
#define MOTOCROSS2D_SPEEDBONUS_H


#include "Item.h"

class SpeedBonus: public Item {
public:
    SpeedBonus(double seconds=0,double speedIncrement=0);
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
