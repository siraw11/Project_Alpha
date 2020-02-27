//
// Created by Magna on 2019-11-23.
//

#ifndef MOTOCROSS2D_SPEEDMALUS_H
#define MOTOCROSS2D_SPEEDMALUS_H

#include "Item.h"

class SpeedMalus : public Item {
public:
    SpeedMalus(double posX = 0, double posY = 0, double width = 0,
               double height = 0, float angle = 0, double speedDecrement = 0,
               std::string texture = "mud.png");

    ~SpeedMalus();

    double getSpeedDecrement() const;

    void setSpeedDecrement(double speedDecrement);

    void doSpecial() override final;


private:
    double speedDecrement;
};


#endif //MOTOCROSS2D_SPEEDMALUS_H
