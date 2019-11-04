//
// Created by waris on 20/06/19.
//

#include "Mage.h"

Mage::Mage(int hp, int s, int sp){}
Mage::~Mage() {}

int Mage::getRange() const {
    return range;
}

void Mage::setRange(int range) {
    Mage::range = range;
}

int Mage::getMana() const {
    return mana;
}

void Mage::setMana(int mana) {
    Mage::mana = mana;
}

/*void Mage::fight(GameCharacter* enemy){
    if(mana>0){
        Attack(*enemy);
        mana--;
    }
}*/
