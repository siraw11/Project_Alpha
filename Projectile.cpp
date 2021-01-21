//
// Created by matteo on 22/04/20.
//

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "Projectile.h"
#include "Collision.h"


///constructor
Projectile::Projectile(PlayerType playerType) {
    auto projectileTexture= new sf::Texture;
    switch(playerType){
        case PlayerType ::ARCHER:
            projectileTexture->loadFromFile("../Resources/Sprites/item/arrow.png");
            setTexture(projectileTexture);
            type = PlayerType::ARCHER;
            break;
        case PlayerType ::MAGE:
            projectileTexture->loadFromFile("../Resources/Sprites/item/fireball.png");
            setTexture(projectileTexture);
            type = PlayerType::MAGE;
            break;
        case PlayerType ::BOSS:
            projectileTexture->loadFromFile("../Resources/Sprites/item/ice.png");
            setTexture(projectileTexture);
            type = PlayerType::BOSS;
            break;
        case PlayerType ::KNIGHT:
            break;

    }

    setSize(sf::Vector2f(64,64));
}

///destructor
Projectile::~Projectile() = default;

///functions
void Projectile::updatePosition() {
    switch(direction){
        case 0:{//up
            move(0,-projectile_speed);
            break;
        }
   case 1:{//left
        move(-projectile_speed,0);
        break;
   }
   case 2:{//down
        move(0,projectile_speed);
        break;
   }
   case 3:{//right
       move(projectile_speed,0);
       break;
   }
   case 4:{
       move(projectile_speed*directionVector.x,projectile_speed*directionVector.y);
       break;

   }
    }
}

void Projectile::init() {
    setPosition(projectile_start);
    if(direction==4){
        setTextureRect(sf::IntRect(0,0,BOSS_PROJECTILE_WIDTH,BOSS_PROJECTILE_HEIGTH));
        setScale(sf::Vector2f(BOSS_PROJECTILE_SCALE,BOSS_PROJECTILE_SCALE));
    }else{
        setTextureRect(sf::IntRect(0,64*direction,64,64));

    }
}

bool Projectile::checkCollision(std::vector<Enemy> *enemy_vector, const std::vector<Tile> &tile_vector, Boss& boss, std::unique_ptr<Hero>& hero) {
    int x = 0;
    int y = 0;
    switch (direction) {
        case 0: {
            x = 0;
            y = -1;
            break;
        }
        case 1: {
            x = -1;
            y = 0;
            break;
        }
        case 2: {
            x = 0;
            y = -1;
            break;
        }
        case 3: {
            x = 1;
            y = 0;
            break;
        }
    }

    bool collided = false;
    if (Collision::projectileCollision(this, tile_vector, x, y)) {
        collided = true;

    } else if (Collision::projectileCollisionBoss(this, boss, x, y) && this->type != PlayerType::BOSS) {
        boss.hit = true;
        collided = true;

    } else if (Collision::projectileCollisionHero(this,*hero,x,y) && this->type == PlayerType::BOSS){
        hero->hit = true;
        collided = true;
        boss.heroHitted=true;

    }else{
        for (auto &i : *enemy_vector)
            if (Collision::projectileCollisionEnemy(this, i, x, y)) {
                collided = true;
                i.hit = true;
                break;
            }
    }




return collided;
}


