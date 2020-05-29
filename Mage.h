//
// Created by matteo on 31/03/20.
//

#ifndef PROGETTO_PROVA_MAGE_H
#define PROGETTO_PROVA_MAGE_H


#include "Hero.h"

class Mage: public Hero {
public:
    Mage(int hp, int s,int sp, int m);

    void Attack();

private:
    int mana;

};


#endif //PROGETTO_PROVA_MAGE_H
