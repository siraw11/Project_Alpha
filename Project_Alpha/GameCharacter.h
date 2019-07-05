//
// Created by matteo on 20/06/19.
//

#ifndef EXAM_PROJECT_GAMECHARACTER_H
#define EXAM_PROJECT_GAMECHARACTER_H

#include "Weapon.h"

class GameCharacter{
public:
    GameCharacter(int hp, int s, int sp);



    Weapon *getWeapon() const;
    void setWeapon(Weapon* weapon);

    int getLife() const {
        return life;
    }

    int getStrength() const {
        return strength;
    }

    int getSpeed() const {
        return speed;
    }

    void Attack(Enemy& enemy);
    virtual void TakeDamage(int point);

protected:

    int life;
    int strength;
    int speed;
    int posX;
    int posY;

    Weapon* weapon;

};

#endif //EXAM_PROJECT_GAMECHARACTER_H
