//
// Created by matteo on 09/03/20.
//

#include <iostream>
#include "GameManager/DEFINITIONS.hpp"
#include "Tile.h"

///constructor
Tile::Tile(int type) {
    t=type;
}

///destructor
Tile::~Tile() =default;

///functions
void Tile::init(float xPos, float yPos) {

    posx=xPos;
    posy=yPos;

    setPosition(posx,posy);
    setSize(sf::Vector2f(width, height));
    setScale(sf::Vector2f(3.f,3.f));


    hitTop=posy-(height);
    hitBottom=posy+(height*SCALE);
    hitLeft=posx-(width);
    hitRight=posx+(width*SCALE);
}

void Tile::openGate() {
    this->t=0;
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));





















}
