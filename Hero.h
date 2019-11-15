//
// Created by waris on 20/06/19.
//

#ifndef EXAM_PROJECT_HERO_H
#define EXAM_PROJECT_HERO_H

//#include "Item.h"
//#include "PlayerType.h"



#include "GameCharacter.h"

class Hero : public GameCharacter{
public:
    Hero(int hp,int s, int sp);

    //Item* getItem() const;
    //void setItem(Item *item);
    void heroMovement(int *level);
    int direction=0; //1=up

private:
   // Item* item;


};

#endif //EXAM_PROJECT_HERO_H
