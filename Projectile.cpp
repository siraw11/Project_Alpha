//
// Created by matteo on 07/10/19.
//

#include "Projectile.h"
Projectile::Projectile(PlayerType type)  {
    auto projectileTexture = new sf::Texture;
    switch (type){
        case PlayerType::ARCHER:
            projectileTexture->loadFromFile("../Resources/Sprites/item/arrow.png");
            setTexture(*projectileTexture);
            break;

        case PlayerType::MAGE:
            projectileTexture->loadFromFile("../Resources/Sprites/item/fireball.png");
            setTexture(*projectileTexture);
            break;
    }

    setScale(sf::Vector2f(1.f,1.f));
}

void Projectile::update() {
    //down
    if(direction==0) {
        move(0,attackSpeed);
    }
    //left
    if(direction==1) {
        move(-attackSpeed,0);
    }
    //right
    if(direction==2)
        move(attackSpeed,0);
    //up
    if(direction==3)
        move(0,-attackSpeed);
}

//Projectile:: ~Projectile() {}