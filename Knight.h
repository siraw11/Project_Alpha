//
//
// Created by matteo on 31/03/20.
//

#ifndef PROGETTO_PROVA_KNIGHT_H
#define PROGETTO_PROVA_KNIGHT_H


#include "Hero.h"

class Knight : public Hero{
public:
    Knight(int hp, int s, int sp, int a);

    void Attack();

    int getArmor() const;
    void setArmor(int armor);
private:
    int armor;

};


#endif //PROGETTO_PROVA_KNIGHT_H
