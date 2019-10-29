//
// Created by waris on 20/06/19.
//

#include "Item.h"
#include "Hero.h"

Item::Item(bool S,bool M,bool arm,bool arw,bool HP,bool K):Strenght(S), Mana(M), Armor(arm), Arrow(arw), Life(HP),Key(K){}

bool Item::isStrenght() const {
    return Strenght;
}

void Item::setStrenght(bool strenght) {
    Strenght = strenght;
}

bool Item::isMana() const {
    return Mana;
}

void Item::setMana(bool mana) {
    Mana = mana;
}

bool Item::isArmor() const {
    return Armor;
}

void Item::setArmor(bool armor) {
    Armor = armor;
}

bool Item::isArrow() const {
    return Arrow;
}

void Item::setArrow(bool arrow) {
    Arrow = arrow;
}

bool Item::isLife() const {
    return Life;
}

void Item::setLife(bool life) {
    Life = life;
}

bool Item::isKey() const {
    return Key;
}

void Item::setKey(bool key) {
    Key = key;
}

void Item::use(Item &item, GameCharacter* hero) {
    Hero *ptr = dynamic_cast<Hero *>(hero);
    if (ptr != nullptr) {
        if (item.isStrenght())
            ptr->setStrength(ptr->getStrength() + 2);
        if (item.isArmor())
            ptr->setArmor(ptr->getArmor() + 2);
        if (item.isMana())
            ptr->setMana(ptr->getMana() + 10);
        if (item.isArrow())
            ptr->setArrows(ptr->getArrows() + 10);
        if (item.isLife())
            ptr->setLife(ptr->getLife() + 2);
        if (item.isKey()){}
        //Todo:open the gate
    }
}
