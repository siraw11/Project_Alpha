//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_ENEMY_H
#define EXAM_PROJECT_ENEMY_H

#include "Knight.h"
#include "Mage.h"
#include "Archer.h"

class Enemy: public GameCharacter{
public:
    Enemy(int hp,int s, int sp);
    // ~Enemy() override;
    //void TakeDamage(int point) override;

    int direction;
    int counterWalking=0;
    int walkingRate;
    int counterDeath=0;
    sf::Vector2f spawnPosition;

    void movement(const int *level);



};

#endif //EXAM_PROJECT_ENEMY_H
