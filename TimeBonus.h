//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_TIMEBONUS_H
#define MOTOCROSS2D_TIMEBONUS_H


#include "Item.h"

class TimeBonus : public Item {
public:
    TimeBonus(double posX = 0, double posY = 0, double width = 0,
              double height = 0, float angle = 0, double timeEarned = 0,
              std::string texture = "timer.png");

    ~TimeBonus();

    double getTimeEarned() const;

    void setTimeEarned(double timeEarned);

    void doSpecial() override final;

private:
    double timeEarned;
};


#endif //MOTOCROSS2D_TIMEBONUS_H
