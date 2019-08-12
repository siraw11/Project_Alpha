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

void Item::use(Item &item, Hero &hero){
    switch(item){
        case item.isStrenght():{
            hero.setStrength(hero.getStrength()+2);
        }
        case item.isMana():{
            hero.setMana(hero.getMana()+10);
        }
        case item.isArmor():{
            hero.setArmor(hero.getArmor()+2);
        }
        case item.isArrow():{
            hero.setArrows(hero.getArrows()+10);

        }
        case item.isLife():{
            hero.setLife(hero.getLife()+2);
        }
        case item.isKey():{
            //TODO:open the gate
        }
    }
}
