//
// Created by matteo on 31/03/20.
//

#include "Archer.h"

Archer::Archer(int hp, int s, int sp, int ar):Hero(hp,s,sp),arrows(ar) {

    auto heroTexture= new sf::Texture;
    heroTexture->loadFromFile("../Resources/Sprites/Hero/archer.png");
    setTexture(heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));

    setScale(sf::Vector2f(3.5,3.5));


}

void Archer::Attack() {


}
