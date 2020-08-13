//
// Created by matteo on 31/03/20.
//

#include "Knight.h"

Knight::Knight(int hp, int s, int sp, int a) :Hero(hp,s,sp){

    auto heroTexture= new sf::Texture;
    heroTexture->loadFromFile("../Resources/Sprites/Hero/knight.png");
    setTexture(heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));

    setScale(sf::Vector2f(3.5f,3.5f));

    armor=a;
}

int Knight::getArmor() const {
    return armor;
}

void Knight::setArmor(int armor) {
    Knight::armor = armor;
}

void Knight::Attack() {

}
