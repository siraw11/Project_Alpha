//
// Created by waris on 20/06/19.
//

#include "Mage.h"
#include "GameCharacter.h"

Mage::Mage(int hp, int s, int sp): GameCharacter(hp, s, sp), range(3), mana(20) {}

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
