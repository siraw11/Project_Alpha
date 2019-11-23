//
// Created by Magna on 2019-06-07.
//

#include "Coin.h"
#include "Item.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Game.h"


Coin::Coin(double _posX, double _posY, double _width, double _height, int _value, std::string _texture, float _angle)
        : Item(_posX,
               _posY,
               _width,
               _height,
               _texture, _angle),
          value(_value) {}

int Coin::getValue() const {
    return value;
}

void Coin::setValue(int value) {
    Coin::value = value;
}

void Coin::doSpecial(){
    if (!isTaken()) {
        setTaken(true);
        Game::gameData->match->addMoney(value);

        std::cout << "Special! Addedd:" << value << "\ttotal:" << Game::gameData->match->getMoney() << " coins"
                  << std::endl;
    }
}
