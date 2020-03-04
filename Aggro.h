//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_AGGRO_H
#define GAME_AGGRO_H

#include "Hero.h"
#include "Enemy.h"
#include "Platform.h"

class Enemy;

class Aggro {
public:
    virtual void behaviour(Enemy* enemy,Hero* hero, std::vector<Platform> *platform) = 0;
};


#endif //GAME_AGGRO_H
