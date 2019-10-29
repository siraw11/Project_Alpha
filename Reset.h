//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_RESET_H
#define GAME_RESET_H


#include "Aggro.h"

class Reset : public Aggro {
public:
    void behaviour(Enemy* enemy, Hero* hero);

private:
    float spawnRange = 5.f; // spawnRange is used to reset the position of the enemy
};

#endif //GAME_RESET_H
