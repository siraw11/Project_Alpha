//
// Created by matteo on 07/10/19.
//

#include "Projectile.h"
Projectile::Projectile()  {
    auto projectileTexture = new sf::Texture;
    projectileTexture->loadFromFile("../Resources/Sprites/item/arrow.png");
    setTexture(*projectileTexture);
    //setTextureRect(sf::IntRect(0,64,50,50));
    setScale(sf::Vector2f(1.f,1.f));
}

void Projectile::update() {
    //right
    if(direction==2)
        move(attackSpeed,0);
    //down
    if(direction==0)
        move(0,attackSpeed);
    //left
    if(direction==1)
        move(-attackSpeed,0);
    //up
    if(direction==3)
        move(0,-attackSpeed);
}
