//
// Created by Magna on 2019-06-07.
//

#include "Coin.h"
#include "Item.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

Coin::Coin(int _value):value(_value) {}

int Coin::getValue() const {
    return value;
}

void Coin::setValue(int value) {
    Coin::value = value;
}

void Coin::doSpecial(){

}