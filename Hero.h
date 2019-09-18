//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_HERO_H
#define EXAM_PROJECT_HERO_H
#include "Knight.h"
#include "Mage.h"
#include "Archer.h"
#include "Item.h"


class Hero: public Knight, public Archer, public Mage{
public:
    Hero(int a,int hp,int s, int sp);

    void Move(int x, int y);

    Item* getItem() const;

    void setItem(Item *item);

private:
    Item* item;


};

#endif //EXAM_PROJECT_HERO_H
