//
// Created by matteo on 31/03/20.
//

#ifndef PROGETTO_PROVA_ARCHER_H
#define PROGETTO_PROVA_ARCHER_H


#include "Hero.h"

class Archer: public Hero {
public:
    Archer(int hp, int s, int sp, int ar);

    void Attack();

private:
    int arrows;
    int range=4;

};


#endif //PROGETTO_PROVA_ARCHER_H
