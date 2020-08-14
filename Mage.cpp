//
// Created by matteo on 31/03/20.
//

#include "Mage.h"
#include "GameManager/DEFINITIONS.hpp"

Mage::Mage(int hp, int s, int sp, int m) : Hero(hp,s,sp){

    auto heroTexture= new sf::Texture ;
    heroTexture->loadFromFile("../Resources/Sprites/Hero/mage.png");
    setTexture(heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));

    setScale(sf::Vector2f(HERO_SCALE,HERO_SCALE));

    mana=m;
}

void Mage::Attack() {

}
