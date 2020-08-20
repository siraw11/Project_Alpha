//
// Created by matteo on 23/03/20.
//

#include <iostream>
#include "Collision.h"
#include "GameManager/DEFINITIONS.hpp"

bool Collision::checkCollision( std::vector<Tile>& tile_vector,  Hero *hero, int x, int y ) {
    bool collided=false;
    sf::Vector2f position(hero->getPosition());

    position.x += hero->getSpeed()*x;//next position right or left
    position.y += hero->getSpeed()*y;//next position up or down

    for(const auto& i: tile_vector){

        if(i.t!=0 && position.x + HERO_WIDTH - hero->getGlobalBounds().width/6 > i.hitLeft && position.x + hero->getGlobalBounds().width/6  < i.hitRight &&
           position.y + hero->getGlobalBounds().height/2 < i.hitBottom && position.y + HERO_HEIGHT + hero->getGlobalBounds().height/6 > i.hitTop){
            //control on the tile, I left side, II right side, III bottom side, IV top side

            collided=true;
            break;
        }
    }

    return collided;
}

bool Collision::enemyCollision(Hero *hero, const std::vector<Enemy>& enemy_vector, int x, int y) {
    bool collided=false;
    sf::Vector2f position(hero->getPosition());


    position.x+= hero->getSpeed()*x;//next position right or left
    position.y+= hero->getSpeed()*y;//next position up or down

    for( const auto& i: enemy_vector){

        if(position.x+HERO_WIDTH*HERO_SCALE - hero->getGlobalBounds().width/2 > i.getPosition().x && position.x + hero->getGlobalBounds().width/3 < i.getPosition().x + ENEMY_WIDTH*ENEMY_SCALE &&
           position.y + hero->getGlobalBounds().height/2 < i.getPosition().y + ENEMY_HEIGHT*ENEMY_SCALE && position.y + HERO_HEIGHT*HERO_SCALE - hero->getGlobalBounds().height/2 > i.getPosition().y ){
            //control on the enemy, I left side, II right side, III bottom  side, IV top side

            collided=true;
            break;
        }
    }

    return collided;
}

bool Collision::projectileCollisionEnemy(Projectile *projectile,const Enemy &enemy, int x, int y) {
    bool collided=false;
    sf::Vector2f position(projectile->getPosition());

    position.x+= projectile->projectile_speed*x;//next position right or left
    position.y+= projectile->projectile_speed*y;//next position up or down

    if(position.x + PROJECTILE_SIZE > enemy.getPosition().x && position.x < enemy.getPosition().x + ENEMY_WIDTH*ENEMY_SCALE &&
       position.y < enemy.getPosition().y + ENEMY_HEIGHT*ENEMY_SCALE && position.y + PROJECTILE_SIZE > enemy.getPosition().y){


        collided=true;
    }
    return collided;
}

bool Collision::projectileCollision(Projectile *projectile, const std::vector<Tile> &tile_vector, int x, int y) {
    bool collided=false;
    sf::Vector2f position(projectile->getPosition());

    position.x+= projectile->projectile_speed*x;//next position right or left
    position.y+= projectile->projectile_speed*y;//next position up or down

    for(const auto& i: tile_vector){

        if(i.t!=0 && position.x + TILE_WIDTH > i.hitLeft && position.x < i.hitRight &&
           position.y <i.hitBottom && position.y + TILE_HEIGHT > i.hitTop){

            collided=true;
            break;
        }
    }

    return collided;
}

bool Collision::checkCollision(std::vector<Tile> &tile_vector, Enemy *enemy, int x, int y) {
    bool collided=false;
    sf::Vector2f position(enemy->getPosition());

    position.x += enemy->getSpeed()*x;//next position right or left
    position.y += enemy->getSpeed()*y;//next position up or down

    for(const auto& i: tile_vector){

        if(i.t!=0 && position.x + ENEMY_WIDTH*ENEMY_SCALE - enemy->getGlobalBounds().width/6 > i.hitLeft && position.x + enemy->getGlobalBounds().width/6  < i.hitRight &&
           position.y + enemy->getGlobalBounds().height/2 < i.hitBottom && position.y + ENEMY_HEIGHT*ENEMY_SCALE + enemy->getGlobalBounds().height/6 > i.hitTop){
            //control on the tile, I left side, II right side, III bottom side, IV top side

            collided=true;
            break;
        }
    }

    return collided;
}

bool Collision::meleeHeroAttak(Hero *hero, const Enemy &enemy, int x, int y) {
    bool collided=false;
    sf::Vector2f position(hero->getPosition());

    position.x+= hero->getSpeed()*x+10;//next position right or left but +10 to avoid the collision with the enemy
    position.y+= hero->getSpeed()*y+10;//next position up or down

    if(position.x + HERO_WIDTH*HERO_SCALE > enemy.getPosition().x && position.x < enemy.getPosition().x + ENEMY_WIDTH*ENEMY_SCALE &&
       position.y < enemy.getPosition().y + ENEMY_HEIGHT*ENEMY_SCALE && position.y + HERO_HEIGHT*HERO_SCALE > enemy.getPosition().y){


        collided=true;
    }
    return collided;
}

