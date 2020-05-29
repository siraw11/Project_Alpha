#include "Projectile.h"
#include "GameManager/DEFINITIONS.hpp"

Projectile::Projectile(PlayerType playerType)  {
    auto projectileTexture = new sf::Texture;
    switch (playerType){
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
    if(direction==2) {
        move(attackSpeed,0);
    }
    //up
    if(direction==3)
        move(0,-attackSpeed);
}

bool Projectile::controlCollision( const int level[10080]) {

    int x,y, SCALE=3;

    switch(direction){
        case 0:
            x = (int) (getPosition().x) / 32 / SCALE;
            y = (int) ((getPosition().y) / 32 / SCALE )+1;
            return level[120 * y + x] != 0;
           break;
        case 1:
            x = (int) (getPosition().x-1) / 32 / SCALE;
            y = (int) (getPosition().y) / 32 / SCALE;
            return level[120 * y + x] != 0;
            break;
        case 2:
            x = (int) ((getPosition().x) / 32 / SCALE+1);
            y = (int) (getPosition().y) / 32 / SCALE;
            return level[120 * y + x] != 0;
            break;
        case 3:
            x = (int) (getPosition().x) / 32 / SCALE;
            y = (int) (getPosition().y-1) / 32 / SCALE;
            return level[120 * y + x] != 0;
            break;
    }

    return false;

}

Projectile:: ~Projectile() = default;
