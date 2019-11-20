//
// Created by Magna on 2019-06-03.
//

#ifndef MOTOCROSS2D_BIKE_H
#define MOTOCROSS2D_BIKE_H


#include <iostream>

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Bike {
public:
    b2Body *wheelL;
    b2Body *wheelR;
    b2Body *cart;

    Bike(std::string id, std::string name = "n/d", std::string color = "red", float speed = 0., int price = 0,
         bool isUnlocked = false, b2Body *wheelL = nullptr, b2Body *wheelR = nullptr, b2Body *cart = nullptr);

    virtual ~Bike();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    float getSpeed() const;

    void setSpeed(float speed);


    int getPrice() const;

    void setPrice(int price);

    bool getIsUnlocked() const;

    void setIsUnlocked(bool isUnlocked);

private:
    std::string id;
public:
    const std::string &getId() const;

    void setId(const std::string &id);

private:
    std::string name;
    std::string color;
    float speed;
    int price;
    bool isUnlocked;


};


#endif //MOTOCROSS2D_BIKE_H