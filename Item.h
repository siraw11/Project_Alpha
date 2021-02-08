//
// Created by waris on 20/06/19.
//
#pragma once


#ifndef EXAM_PROJECT_ITEM_H
#define EXAM_PROJECT_ITEM

#include "Object.h"

class Item : public Object{
public:

//constructor and destructor
    Item(bool S, bool E, bool G, bool HP, bool P, bool K);
    ~Item() override;

//functions
    void use(Hero* hero, std::vector<Tile>* tile_vector) override;

//getters
    bool isStrength() const;
    bool isGeneric() const;
    bool isLife() const;
    bool isKey() const;
    bool isExhaust() const;
    bool isPoison() const;

private:
//attributes
    bool strength;
    bool exhaust;
    bool generic;
    bool poison;
    bool life;
    bool key;
};

#endif //EXAM_PROJECT_ITEM_H
