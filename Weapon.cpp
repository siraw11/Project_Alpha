//
// Created by matteo on 18/04/20.
//

#include <stdexcept>
#include "Weapon.h"

Weapon::Weapon(int s) {
    if(s<=0)
        throw std::out_of_range("Negative value");
    else
        strenght=s;
}

int Weapon::getStrenght() const {
    return strenght;
}

Weapon::~Weapon() = default;
