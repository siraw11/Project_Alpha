//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_MAGE_H
#define EXAM_PROJECT_MAGE_H

#include "GameCharacter.h"


class Mage{

public:
    Mage(int hp, int s, int sp);
    ~Mage();

    int getRange() const;

    void setRange(int range);

    int getMana() const;

    void setMana(int mana);

    //void fight(GameCharacter* enemy);

private:

    int range;
    int mana;
};

#endif //EXAM_PROJECT_MAGE_H
