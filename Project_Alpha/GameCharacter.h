//
// Created by matteo on 20/06/19.
//

#ifndef EXAM_PROJECT_GAMECHARACTER_H
#define EXAM_PROJECT_GAMECHARACTER_H

#include "Weapon.h"

class GameCharacter{

private:

int life;
int strength;
int speed;


public:
    GameCharacter(int hp, int s, int sp);
    void addWeapon(Weapon& w);

int posX;

    int getLife() const {
        return life;
    }

    int getStrength() const {
        return strength;
    }

    int getSpeed() const {
        return speed;
    }

    int posY;
Weapon* weapon;

void Attack();
bool TakeDamage();

};

#endif //EXAM_PROJECT_GAMECHARACTER_H
