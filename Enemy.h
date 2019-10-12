//
// Created by davide on 19/09/19.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "GameCharacter.h"

class Enemy : public GameCharacter {
public:
    Enemy();
    //TODO implementare aggro
    int HP = 2;
public:
    int damage = 1;
};


#endif //GAME_ENEMY_H
