//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_KNIGHT_H
#define EXAM_PROJECT_KNIGHT_H

#include "GameCharacter.h"

class Knight : public GameCharacter{
public:
    Knight(int a , int hp, int s , int sp);

    void fight(Enemy& enemy);
    void TakeDamage(int damage)override;

protected:
    int armor;
};

#endif //EXAM_PROJECT_KNIGHT_H
