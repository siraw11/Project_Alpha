//
// Created by andreatadde on 23/10/19.
//

#include "Attack.h"
#include "Enemy.h"

void Attack::behaviour(Enemy* enemy, Hero* hero, std::vector<Platform> *platform) {
    if(hero->HP > 0){
        hero->HP -= enemy->damage;
    }
}
