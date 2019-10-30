//
// Created by andreatadde on 23/10/19.
//

#include <iostream>
#include "Catch.h"

void Catch::behaviour(Enemy* enemy, Hero* hero) {
    //std::cout<<"In Catch state"<<std::endl;
    if(hero->x < enemy->x){
        enemy->velocity.x = -1.f;
    }
    else{
        enemy->velocity.x = 1.f;
    }
    enemy->x += enemy->velocity.x * enemy->getMoveSpeed();
    if(hero->y < enemy->y){
        enemy->velocity.y = -1.f;
    }
    else{
        enemy->velocity.y = 1.f;
    }
    enemy->y += enemy->velocity.y * enemy->getMoveSpeed();
    enemy->rectShape.setPosition(enemy->x,enemy->y);
}
