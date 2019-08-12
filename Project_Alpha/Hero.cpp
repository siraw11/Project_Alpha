//
// Created by waris on 20/06/19.
//

#include "Hero.h"
#include "Item.h"

Hero::Hero(int hp, int s, int sp):GameCharacter(hp,s,sp), item(nullptr){}

Item *Hero::getItem() const {
    return item;
}

void Hero::setItem(Item *item) {
    Hero::item = item;
}

void Hero::Move(int x, int y) {
    posX += x;
    posY += y;

}
