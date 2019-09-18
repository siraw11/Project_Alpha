//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_KNIGHT_H
#define EXAM_PROJECT_KNIGHT_H

#include "GameCharacter.h"

class Knight : virtual public GameCharacter {
public:
    Knight(int a , int hp, int s , int sp);

    void fight(GameCharacter* enemy);
    void TakeDamage(int damage) override;

    int getArmor() const;

    void setArmor(int armor);
protected:
    int armor;


};

#endif //EXAM_PROJECT_KNIGHT_H
