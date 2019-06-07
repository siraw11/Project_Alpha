//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_COIN_H
#define MOTOCROSS2D_COIN_H

#include "Item.h"

class Coin : public Item {

public:
    Coin(int value = 0);
    ~Coin();


    int getValue() const;

    void setValue(int value);

    void doSpecial() override final;


private:
    int value;

};


#endif //MOTOCROSS2D_COIN_H
