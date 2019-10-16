//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_ENEMY_H
#define EXAM_PROJECT_ENEMY_H

#include "Knight.h"
#include "Mage.h"
#include "Archer.h"

class Enemy: public Knight, public Archer, public Mage{
public:
    Enemy(int hp,int s, int sp, int a);

    int direction;





};

#endif //EXAM_PROJECT_ENEMY_H
