//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_ITEM_H
#define MOTOCROSS2D_ITEM_H

#include <iostream>

class Item {
public:
    explicit Item(double posX = 0, double posY = 0, double width = 0, double height = 0, float angle = 0,
                  std::string texture = "");

    const std::string &getTexture() const;

    void setTexture(const std::string &texture);

    ~Item();


    double getPosX() const;

    void setPosX(double posX);

    double getPosY() const;

    void setPosY(double posY);

    double getWidth() const;

    void setWidth(double width);

    double getHeight() const;

    void setHeight(double height);

    double getAngle() const;

    void setAngle(float angle);


    bool isTaken() const;

    void setTaken(bool taken);


    virtual void doSpecial();

private:
    float posX;
    float posY;
    float angle;
    float width;
    float height;
    bool taken = false;
    std::string texture;
};


#endif //MOTOCROSS2D_ITEM_H
