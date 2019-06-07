//
// Created by Magna on 2019-06-07.
//

#include "Coin.h"
#include "Item.h"

Coin::Coin(int _value):value(_value) {}

int Coin::getValue() const {
    return value;
}

void Coin::setValue(int value) {
    Coin::value = value;
}
//todo doSpecial();