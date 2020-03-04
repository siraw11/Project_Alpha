//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_IDLE_H
#define GAME_IDLE_H

#include "Aggro.h"
#include "Enemy.h"

class Idle : public Aggro{
public:
    void behaviour(Enemy* enemy, Hero* hero, std::vector<Platform> *platform);
};


#endif //GAME_IDLE_H
