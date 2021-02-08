//
// Created by matteo on 18/04/20.
//
#pragma once

#ifndef PROGETTO_PROVA_WEAPON_H
#define PROGETTO_PROVA_WEAPON_H


#include "Object.h"

class Weapon : public Object {

public:
//constructor, destructor
    explicit Weapon(int s);
    ~Weapon() override;
    Weapon(Weapon &w);

//getter
    int getStrength() const;

//functions
    void use(Hero* hero, std::vector<Tile>* tile_vector) override;

private:
//attributes
    int strength;
};


#endif //PROGETTO_PROVA_WEAPON_H
