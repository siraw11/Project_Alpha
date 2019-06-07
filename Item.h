//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_ITEM_H
#define MOTOCROSS2D_ITEM_H

#include <iostream>

class Item {
public:
    Item(double posX = 0, double posY = 0, double width = 0, double height = 0);

    ~Item();


    double getPosX() const;

    void setPosX(double posX);

    double getPosY() const;

    void setPosY(double posY);

    double getWidth() const;

    void setWidth(double width);

    double getHeight() const;

    void setHeight(double height);

    virtual void doSpecial();

private:
    double posX;
    double posY;
    double width;
    double height;
};


#endif //MOTOCROSS2D_ITEM_H
