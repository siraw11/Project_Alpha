//
// Created by matteo on 18/08/20.
//
#pragma once

#ifndef PROJECT_ALPHA_BOSS_H
#define PROJECT_ALPHA_BOSS_H


#include "Enemy.h"

class Boss : public Enemy {

public:
    Boss(int hp, int s, int sp);
    ~Boss() override;

private:
    int posx;
    int posy;

};


#endif //PROJECT_ALPHA_BOSS_H
