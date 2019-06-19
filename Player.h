//
// Created by Magna on 2019-06-03.
//

#ifndef MOTOCROSS2D_PLAYER_H
#define MOTOCROSS2D_PLAYER_H

#include <iostream>
#include <list>
#include "Bike.h"
#include "Observer.h"
#include "Subject.h"
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

class Player : public Subject {
public:
    Player(std::string username = "Player1", int totalCoin = 0, float posX = 0, float posY = 0, float angle = 0,
           Bike *bike = nullptr);

    virtual ~Player();

    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    int getTotalCoin() const;

    void setTotalCoin(int totalCoin);

    float getPosX() const;

    void setPosX(float posX);

    float getPosY() const;

    void setPosY(float posY);

    float getAngle() const;

    void setAngle(float angle);

    Bike *getBike() const;

    void setBike(Bike *bike);

private:
    std::string username;
    int totalCoin;
    float posX;
    float posY;
    float angle;
    Bike* bike;

};


#endif //MOTOCROSS2D_PLAYER_H
