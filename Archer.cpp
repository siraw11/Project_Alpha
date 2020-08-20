//
// Created by matteo on 31/03/20.
//

#include "Archer.h"
#include "GameManager/DEFINITIONS.hpp"

Archer::Archer(int hp, int s, int sp, int ar):Hero(hp,s,sp),arrows(ar) {

    auto heroTexture= new sf::Texture;
    heroTexture->loadFromFile("../Resources/Sprites/Hero/archer.png");
    setTexture(heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));

    setScale(sf::Vector2f(HERO_SCALE,HERO_SCALE));


}

void Archer::Attack() {


}
