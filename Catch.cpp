//
// Created by andreatadde on 23/10/19.
//

#include <iostream>
#include "Catch.h"
#include "Collision.h"

void Catch::behaviour(Enemy* enemy, Hero* hero, std::vector<Platform> *platform) {
    //std::cout<<"In Catch state"<<std::endl;
    if(hero->x < enemy->x){
        enemy->velocity.x = -1.f;
    }
    else{
        enemy->velocity.x = 1.f;
    }

    if(hero->y < enemy->y){
        enemy->velocity.y = -1.f;
    }
    else{
        enemy->velocity.y = 1.f;
    }

    // Checking for collision before setting the new position
    Collision::checkCollision(platform, enemy);
    enemy->rectShape.setPosition(enemy->x,enemy->y);
}
