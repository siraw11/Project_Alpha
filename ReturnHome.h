//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_RETURNHOME_H
#define GAME_RETURNHOME_H


#include "Aggro.h"

class ReturnHome : public Aggro {
public:
    void behaviour(Enemy* enemy, Hero* hero, std::vector<Platform> *platform);

private:
    float spawnRange = 1.f; // spawnRange is used to reset the position of the enemy
};

#endif //GAME_RETURNHOME_H
