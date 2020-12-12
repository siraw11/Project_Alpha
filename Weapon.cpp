//
// Created by matteo on 18/04/20.
//

#include <stdexcept>
#include "Weapon.h"
#include "Hero.h"


///constructor
Weapon::Weapon(int s) {
    if(s<=0)
        throw std::out_of_range("Negative value");
    else
        strength=s;
}

///destructor
Weapon::~Weapon() = default;

///getters
int Weapon::getStrength() const {
    return strength;
}

void Weapon::use(Hero *hero) {
    Weapon weapon(*this);
    hero->setWeapon(&weapon);
   // delete(this);
}

Weapon::Weapon(Weapon &w) {

    strength= w.getStrength();

}




