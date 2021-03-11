//
// Created by matteo on 31/03/20.
//


#include "GameManager/DEFINITIONS.hpp"
#include "Knight.h"

//constructor
Knight::Knight(int hp, int s, int sp, int a, int ar, int m) : Hero(hp ,s , sp, a, ar, m){

    auto heroTexture = new sf::Texture;
    heroTexture->loadFromFile("./Resources/Sprites/Hero/knight.png");
    setTexture(heroTexture);
    setTextureRect(sf::IntRect(0, 128, 64, 64));

    setScale(sf::Vector2f(HERO_SCALE,HERO_SCALE));

    playerType = PlayerType::KNIGHT;
}

//destructor
Knight::~Knight() = default;

