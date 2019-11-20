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


struct Position {
    float posX;
    float posY;
};

class Player : public Subject {
public:
    explicit Player(std::string username = "Player1", int totalCoin = 0, Bike *bike = nullptr);

    virtual ~Player();

    const std::string &getUsername() const;

    void setUsername(const std::string &username);

    int getTotalCoin() const;

    void addTotalCoin(int incrementCoin);

    void removeTotalCoin(int decrementCoin);

    Bike *getBike() const;

    void setBike(Bike *bike);

    virtual void registerObserver(Observer *o) override ;

    virtual void removeObserver(Observer *o) override ;

    virtual void notifyObservers() override ;

    void move(float x, float y, float a);

private:
    std::string username;
    int totalCoin;
    Bike *bike;

    std::list<Observer*> observers;
};


#endif //MOTOCROSS2D_PLAYER_H