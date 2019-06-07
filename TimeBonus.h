//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_TIMEBONUS_H
#define MOTOCROSS2D_TIMEBONUS_H


#include "Item.h"

class TimeBonus: public Item{
public:
    TimeBonus(double timeEarned=0);

    ~TimeBonus();

    double getTimeEarned() const;

    void setTimeEarned(double timeEarned);

    void doSpecial() override final;

private:
    double timeEarned;
};


#endif //MOTOCROSS2D_TIMEBONUS_H
