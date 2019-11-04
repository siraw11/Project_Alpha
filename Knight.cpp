//
// Created by waris on 20/06/19.
//

#include <stdexcept>
#include "Knight.h"

Knight::Knight(int a, int hp, int s, int sp) {
    if (a<0){
        throw std::out_of_range("negative values");
    }else{
        armor=a;
    }
}

Knight::~Knight() {}

/*void Knight::fight(GameCharacter* enemy) {
    int damage=0;
    damage=strength+weapon->getStrength();

    TakeDamage(damage);
}*/

/*void Knight::TakeDamage(int damage) {
if(armor>=0)
    damage-=armor;
life-=damage;
}*/

int Knight::getArmor() const {
    return armor;
}

void Knight::setArmor(int armor) {
    Knight::armor = armor;
}
