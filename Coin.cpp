//
// Created by Magna on 2019-06-07.
//

#include "Coin.h"
#include "Item.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"


Coin::Coin(double _posX, double _posY, double _width, double _height, int _value, std::string _texture) : Item(_posX,
                                                                                                               _posY,
                                                                                                               _width,
                                                                                                               _height,
                                                                                                               _texture),
                                                                                                          value(_value) {}

int Coin::getValue() const {
    return value;
}

void Coin::setValue(int value) {
    Coin::value = value;
}

void Coin::doSpecial(){
    std::cout << "Special! Addedd:" << value << " coins" << std::endl;
}