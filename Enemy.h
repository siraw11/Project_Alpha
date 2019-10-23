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
    ~Enemy() override;
    //void TakeDamage(int point) override;

    int direction;
    sf::Vector2f spawnPosition;



};

#endif //EXAM_PROJECT_ENEMY_H
