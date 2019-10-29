//
// Created by andreatadde on 23/10/19.
//

#include <iostream>
#include "Reset.h"
#include <math.h>

void Reset::behaviour(Enemy* enemy, Hero* hero) {
    //std::cout<<"In Reset state"<<std::endl;
    if(enemy->spawnX < enemy->x){
        enemy->velocity.x = -1.f;
    }
    else{
        enemy->velocity.x = 1.f;
    }
    enemy->x += enemy->velocity.x * enemy->getMoveSpeed();
    if(enemy->spawnY < enemy->y){
        enemy->velocity.y = -1.f;
    }
    else{
        enemy->velocity.y = 1.f;
    }
    enemy->y += enemy->velocity.y * enemy->getMoveSpeed();
    if(fabs(enemy->y - enemy->spawnY) < spawnRange && fabs(enemy->x - enemy->spawnX) < spawnRange){
        enemy->x = enemy->spawnX;
        enemy->y = enemy->spawnY;
        enemy->velocity.x = 0.f;
        enemy->velocity.y = 0.f;
    }
    enemy->rectShape.setPosition(enemy->x,enemy->y);
}
