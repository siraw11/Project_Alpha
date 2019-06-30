//
// Created by waris on 20/06/19.
//

#include <stdexcept>
#include "Weapon.h"

Weapon::Weapon(int s, int l) {
    if(strength<=0||level<=0){
        throw std::out_of_range("Negative value");
    }else{
        strength=s;
        level=l;
    }

}



int Weapon::getStrength() const {
    return strength;
}

void Weapon::setStrength(int strength) {
    Weapon::strength = strength;
}
