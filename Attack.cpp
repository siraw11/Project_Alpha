//
// Created by andreatadde on 23/10/19.
//

#include <iostream>
#include "Attack.h"
#include "Enemy.h"

void Attack::behaviour(Enemy* enemy, Hero* hero, std::vector<Platform> *platform) {
    //std::cout<<"In Attack state"<<std::endl;
    if(hero->HP > 0){
        hero->HP -= enemy->damage;
        std::cout << "Player HP: " << hero->HP << std::endl;
    }
}
