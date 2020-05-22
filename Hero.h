//
// Created by matteo on 19/03/20.
//

#ifndef PROGETTO_PROVA_HERO_H
#define PROGETTO_PROVA_HERO_H


#include "GameCharacter.h"
#include "PlayerType.h"
#include "Enemy.h"


class Hero: public GameCharacter {
public:
    Hero(int hp, int s,int sp);
    ~Hero() override;

    void heroMovement(int x, int y, const map& level);

    int walkingDirection=2;//0=up, 1=left, 2=down, 3=right

    // PlayerType playerType;

    void fight(Enemy &enemy);

protected:


private:
    int counterWalking=0;
    void walkingAnimation();
};


#endif //PROGETTO_PROVA_HERO_H
