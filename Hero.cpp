//
// Created by waris on 20/06/19.
//

#include "Hero.h"
#include "Item.h"

Hero::Hero(int a,int hp, int s, int sp):GameCharacter(hp,s,sp),Knight(a,hp,s,sp),Archer(hp,s,sp),Mage(hp,s,sp), item(nullptr){}

Item *Hero::getItem() const {
    return item;
}

void Hero::setItem(Item *item) {
    Hero::item = item;
}
//void Hero::isLegalTile(Map &map) {
    //if()
//}



