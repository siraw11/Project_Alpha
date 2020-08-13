//
// Created by matteo on 23/03/20.
//

#include <iostream>
#include "Collision.h"
#include "GameManager/DEFINITIONS.hpp"

bool Collision::checkCollision( std::vector<Tile>& tile_vector,  GameCharacter *gameCharacter, int x, int y ) {
    bool collided=false;
    sf::Vector2f position(gameCharacter->getPosition());

    position.x += gameCharacter->getSpeed()*x;
    position.y += gameCharacter->getSpeed()*y;

    for(const auto& i: tile_vector){

        if(i.t!=0 && position.x + TILE_WIDTH > i.hitLeft && position.x < i.hitRight &&
           position.y <i.hitBottom && position.y + TILE_HEIGHT > i.hitTop){

            collided=true;
            break;
        }
    }

    return collided;
}

bool Collision::enemyCollision(Hero *hero, const std::vector<Enemy>& enemy_vector, int x, int y) {
    bool collided=false;
    sf::Vector2f position(hero->getPosition());


    position.x+= hero->getSpeed()*x;
    position.y+= hero->getSpeed()*y;

    for( const auto& i: enemy_vector){

        if(position.x+ENEMY_WIDTH> i.getPosition().x && position.x-i.getGlobalBounds().width/2 < i.getPosition().x+ENEMY_WIDTH &&
           position.y< i.getPosition().y+ENEMY_HEIGHT && position.y+ENEMY_HEIGHT> i.getPosition().y){

            collided=true;
            break;
        }
    }

    return collided;
}

bool Collision::projectileCollisionEnemy(Projectile *projectile,const Enemy &enemy, int x, int y) {
    bool collided=false;
    sf::Vector2f position(projectile->getPosition());

    position.x+= projectile->projectile_speed*x;
    position.y+= projectile->projectile_speed*y;

    if(position.x+ENEMY_WIDTH> enemy.getPosition().x && position.x-enemy.getGlobalBounds().width/2 < enemy.getPosition().x+ENEMY_WIDTH &&
       position.y< enemy.getPosition().y+ENEMY_HEIGHT && position.y+ENEMY_HEIGHT> enemy.getPosition().y){


        collided=true;
    }
    return collided;
}

bool Collision::projectileCollision(Projectile *projectile, const std::vector<Tile> &tile_vector, int x, int y) {
    bool collided=false;
    sf::Vector2f position(projectile->getPosition());

    position.x+= projectile->projectile_speed*x;
    position.y+= projectile->projectile_speed*y;

    for(const auto& i: tile_vector){

        if(i.t!=0 && position.x + TILE_WIDTH > i.hitLeft && position.x < i.hitRight &&
           position.y <i.hitBottom && position.y + TILE_HEIGHT > i.hitTop){

            collided=true;
            break;
        }
    }

    return collided;
}

