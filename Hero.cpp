//
// Created by waris on 20/06/19.
//

#include "Hero.h"
#include "Item.h"

Hero::Hero(int a,int hp, int s, float sp):GameCharacter(hp,s,sp),Knight(a,hp,s,sp),Archer(hp,s,sp),Mage(hp,s,sp), item(nullptr){}

Item *Hero::getItem() const {
    return item;
}

void Hero::setItem(Item *item) {
    Hero::item = item;
}

void Hero::animationControl(int typeAnimation){
   setTextureRect(sf::IntRect(0,64*typeAnimation,64,64));

}

int Hero::animation(int n, int direction) {

    if(n>0 ){
        int k=n-1;
        setTextureRect((sf::IntRect(64*k,64*direction,64,64)));
        n++;
    }
     

return n;

}

