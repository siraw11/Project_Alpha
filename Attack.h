//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_ATTACK_H
#define GAME_ATTACK_H

#include "Aggro.h"
#include "Enemy.h"

class Attack : public Aggro{
public:
    void behaviour(Enemy* enemy, Hero* hero, std::vector<Platform> *platform);
};


#endif //GAME_ATTACK_H
