//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_AGGRO_H
#define GAME_AGGRO_H



#include "Hero.h"
#include "Enemy.h"

class Enemy;

class Aggro {
public:
    //virtual ~Aggro() = 0;
    virtual void behaviour(Enemy* enemy,Hero* hero) = 0;
};


#endif //GAME_AGGRO_H
