//
//
// Created by matteo on 31/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_KNIGHT_H
#define PROGETTO_PROVA_KNIGHT_H

#include "Hero.h"


class Knight : public Hero{
public:
    //constructor and destructor
    Knight(int hp, int s, int sp, int a, int ar, int m);
    ~Knight() override;

};


#endif //PROGETTO_PROVA_KNIGHT_H
