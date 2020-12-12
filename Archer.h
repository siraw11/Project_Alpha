//
// Created by matteo on 31/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_ARCHER_H
#define PROGETTO_PROVA_ARCHER_H


#include "Hero.h"

class Archer: public Hero {
public:
    ///constructor and destructor
    Archer(int hp, int s, int sp, int a, int ar, int m);
    ~Archer() override;

};


#endif //PROGETTO_PROVA_ARCHER_H
