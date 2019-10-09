//
// Created by andreatadde on 16/09/19.
//

#include "RectangleShape.h"

void RectangleShape::init(float xInit, float yInit, sf::Vector2f size) {

    x = xInit;
    y = yInit;
    width = size.x;
    height = size.y;
    spawnX = xInit;
    spawnY = yInit;

    hitTop = y;
    hitBottom = y + height;
    hitLeft = x;
    hitRight = x + width;

    rectShape.setPosition(x, y);
    rectShape.setSize(sf::Vector2f(width, height));
}

void RectangleShape::setTexture(const std::string &textureDir) {

    rectTexture.loadFromFile(textureDir);
    rectShape.setTexture(&rectTexture);
}
