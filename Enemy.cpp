//
// Created by andreatadde on 23/10/19.
//


#include "Enemy.h"
#include <cmath>

#include "Idle.h"
#include "Catch.h"
#include "Attack.h"
#include "Reset.h"

Enemy::Enemy() : aggro(new Idle()){
    range.x = 130.f;
    range.y = 50.f;
    moveSpeed = 0.2f;
}

void Enemy::aggroUpdate(Hero *player, sf::Time time, std::vector<Platform> *platform){

    if(this->velocity.x == 0 && this->velocity.y == 0 && this->rectShape.getPosition().x == spawnX && this->rectShape.getPosition().y == spawnY)
    {
        aggro = (new Idle());
    }

    if(fabs(player->x-this->spawnX) < range.x && fabs(player->y-this->spawnY) < range.y){
        aggro = (new Catch());
    }
    else if(this->rectShape.getPosition().x != spawnX && this->rectShape.getPosition().y != spawnY)
    {
        aggro = (new Reset());
    }

    if(this->rectShape.getGlobalBounds().intersects(player->rectShape.getGlobalBounds()) && time - lastAttackTime >= attackReload){
        aggro = (new Attack());
        lastAttackTime = time;
    }

    aggro->behaviour(this, player, platform);
}
