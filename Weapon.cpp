//
// Created by matteo on 18/04/20.
//

#include <stdexcept>
#include <iostream>
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

void Weapon::use(Hero *hero, std::vector<Tile>* tile_vector) {
    std::cout<<"weapon"<<std::endl;

    hero->setWeapon(this);
    std::cout<<"forza arma subito dopo il set"<<std::endl;
    std::cout<<hero->getWeapon()->strength<<std::endl;
}

Weapon::Weapon(Weapon &w) {

    strength= w.getStrength();

}




