//
// Created by matteo on 22/04/20.
//

#include <SFML/Graphics/Texture.hpp>
#include "Projectile.h"

Projectile::Projectile(PlayerType playerType) {
    sf::Texture *projectileTexture = nullptr;
    switch(playerType){
        case PlayerType ::ARCHER:
            projectileTexture->loadFromFile("../Resources/Sprites/item/arrow.png");
            setTexture(projectileTexture);
            break;
        case PlayerType ::MAGE:
            projectileTexture->loadFromFile("../Resources/Sprites/item/fireball.png");
            setTexture(projectileTexture);
            break;
    }


}

Projectile::~Projectile() = default;

void Projectile::updateProjectile() {
    if(direction==0)//down
        move(0,projectile_speed);
    else if(direction==1)//left
        move(-projectile_speed,0);
    else if(direction==2)//right
        move(projectile_speed,0);
    else if(direction==3)//up
        move(0,-projectile_speed);
}
