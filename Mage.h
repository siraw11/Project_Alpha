//
// Created by matteo on 31/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_MAGE_H
#define PROGETTO_PROVA_MAGE_H

#include "Hero.h"


class Mage: public Hero {

public:

///constructor, destructor
    Mage(int hp, int s,int sp,int a, int ar, int m);
    ~Mage() override;

};


#endif //PROGETTO_PROVA_MAGE_H
