//
// Created by matteo on 18/04/20.
//

#include "Weapon.h"

Weapon::Weapon(int s, int l):strenght(s), level(l) {
}

int Weapon::getStrenght() const {
    return strenght;
}

Weapon::~Weapon() = default;
