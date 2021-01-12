//
// Created by matteo on 23/03/20.
//

#include <iostream>
#include "GameManager/DEFINITIONS.hpp"
#include "Collision.h"


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

bool Collision::checkCollision(std::vector<Tile> &tile_vector, Boss *boss, int x, int y) {
    bool collided=false;
    sf::Vector2f position(boss->getPosition());

    position.x += boss->getSpeed()*x;//next position right or left
    position.y += boss->getSpeed()*y;//next position up or down

    for(const auto& i: tile_vector){

        if(i.t!=0 && position.x + BOSS_SIZE*BOSS_SCALE - boss->getGlobalBounds().width/6 > i.hitLeft && position.x + boss->getGlobalBounds().width/6  < i.hitRight &&
           position.y + boss->getGlobalBounds().height/2 < i.hitBottom && position.y + BOSS_SIZE*BOSS_SCALE + boss->getGlobalBounds().height/6 > i.hitTop){
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

bool Collision::heroCollision(Enemy *enemy, const Hero &hero, int x, int y) {
    bool collided=false;
    sf::Vector2f position(enemy->getPosition());


    position.x+= enemy->getSpeed()*x;//next position right or left
    position.y+= enemy->getSpeed()*y;//next position up or down

    if(position.x+ENEMY_WIDTH*ENEMY_SCALE - enemy->getGlobalBounds().width/2 > hero.getPosition().x && position.x + enemy->getGlobalBounds().width/3 < hero.getPosition().x + HERO_WIDTH*HERO_SCALE &&
       position.y + enemy->getGlobalBounds().height/2 < hero.getPosition().y + HERO_HEIGHT*HERO_SCALE && position.y + ENEMY_HEIGHT*ENEMY_SCALE - enemy->getGlobalBounds().height/2 > hero.getPosition().y ){
        //control on the enemy, I left side, II right side, III bottom  side, IV top side
        collided=true;
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

bool Collision::projectileCollisionBoss(Projectile *projectile, const Boss &boss, int x, int y) {
    bool collided=false;
    sf::Vector2f position(projectile->getPosition());

    position.x+= projectile->projectile_speed*x;//next position right or left
    position.y+= projectile->projectile_speed*y;//next position up or down

    if(position.x + PROJECTILE_SIZE > boss.getPosition().x && position.x < boss.getPosition().x + BOSS_SIZE*BOSS_SCALE &&
       position.y < boss.getPosition().y + BOSS_SIZE*BOSS_SCALE && position.y + PROJECTILE_SIZE > boss.getPosition().y){

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

bool Collision::chestCollision(const Chest& chest, Enemy *enemy, int x, int y) {
    bool collided=false;
    sf::Vector2f position(enemy->getPosition());

    position.x+= enemy->getSpeed()*x;//next position right or left
    position.y+= enemy->getSpeed()*y;//next position up or down

    if(position.x + ENEMY_WIDTH*ENEMY_SCALE  > chest.getPosition().x && position.x < chest.getPosition().x + CHEST_SIZE*CHEST_SCALE &&
           position.y < chest.getPosition().y + CHEST_SIZE*CHEST_SCALE && position.y  > chest.getPosition().y){
            //control on the tile, I left side, II right side, III bottom side, IV top side
            collided=true;

            return collided;
    }
}

bool Collision::chestCollision( const Chest& chest, Hero *hero, int x, int y) {
    bool collided=false;
    sf::Vector2f position(hero->getPosition());

    position.x+= hero->getSpeed()*x;//next position right or left
    position.y+= hero->getSpeed()*y;//next position up or down


    if(position.x + HERO_WIDTH*HERO_SCALE> chest.getPosition().x && position.x < chest.getPosition().x + CHEST_SIZE*CHEST_SCALE &&
       position.y < chest.getPosition().y + CHEST_SIZE*CHEST_SCALE && position.y > chest.getPosition().y){

        collided=true;
    }

    return collided;
}


