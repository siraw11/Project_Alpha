//
// Created by andreatadde on 23/10/19.
//


#include "Enemy.h"
#include <cmath>

#include "Idle.h"
#include "Catch.h"
#include "Attack.h"
#include "Reset.h"

Enemy::Enemy() : context(new Context(new Idle())){
    range.x = 130.f;
    range.y = 50.f;
    moveSpeed = 0.2f;
}

void Enemy::aggroManager(Hero* player, sf::Clock* clock, std::vector<Platform> *platform) {
    if(this->velocity.x == 0 && this->velocity.y == 0 && this->rectShape.getPosition().x == spawnX && this->rectShape.getPosition().y == spawnY)
    {
        context = new Context(new Idle());
    }

    if(fabs(player->x-this->spawnX) < range.x && fabs(player->y-this->spawnY) < range.y){
        context = new Context(new Catch());
    }
    else if(this->rectShape.getPosition().x != spawnX && this->rectShape.getPosition().y != spawnY)
    {
        context = new Context(new Reset());
    }

    if(this->rectShape.getGlobalBounds().intersects(player->rectShape.getGlobalBounds()) && clock->getElapsedTime() - lastAttackTime >= attackReload){
        context = new Context(new Attack());
        lastAttackTime = clock->getElapsedTime();
    }

    context->executeAggro(this, player, platform);
}
