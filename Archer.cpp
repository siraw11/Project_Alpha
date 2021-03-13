//
// Created by matteo on 31/03/20.
//


#include "GameManager/DEFINITIONS.hpp"
#include "Archer.h"

//constructor
Archer::Archer(int hp, int s, int sp, int a, int ar, int m):Hero( hp, s, sp, a, ar, m) {

    auto heroTexture= new sf::Texture;
    heroTexture->loadFromFile("./Resources/Sprites/Hero/archer.png");
    setTexture(heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));
    setScale(sf::Vector2f(HERO_SCALE,HERO_SCALE));

    range = 700;

    playerType = PlayerType::ARCHER;

}

//destructor
Archer::~Archer() = default;





