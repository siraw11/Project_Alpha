//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_COIN_H
#define MOTOCROSS2D_COIN_H

#include "Item.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"


class Coin : public Item {

public:
    explicit Coin(double posX = 0, double posY = 0, double width = 0,
                  double height = 0, int value = 0,
                  std::string texture = "./resources/textures/coin.png");

    ~Coin();


    int getValue() const;

    void setValue(int value);

    void doSpecial() final;


private:
    int value;
};


#endif //MOTOCROSS2D_COIN_H
