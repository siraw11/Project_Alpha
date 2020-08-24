//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_ITEM_H
#define EXAM_PROJECT_ITEM_H

#include "Hero.h"

class Item{
public:
    //void use(Item &item, Hero* hero);

    Item(bool S, bool M, bool arm, bool arw, bool HP, bool K);

    bool isStrenght() const;

    void setStrenght(bool strenght);

    bool isMana() const;

    void setMana(bool mana);

    bool isArmor() const;

    void setArmor(bool armor);

    bool isArrow() const;

    void setArrow(bool arrow);

    bool isLife() const;

    void setLife(bool life);

    bool isKey() const;

    void setKey(bool key);

private:
    bool Strenght;
    bool Mana;
    bool Armor;
    bool Arrow;
    bool Life;
    bool Key;






};

#endif //EXAM_PROJECT_ITEM_H
