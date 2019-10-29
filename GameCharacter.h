//
// Created by matteo on 20/06/19.
//

#ifndef EXAM_PROJECT_GAMECHARACTER_H
#define EXAM_PROJECT_GAMECHARACTER_H

#include "Weapon.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
class GameCharacter:public sf::Sprite {
public:
    GameCharacter(int hp, int s, int sp);
    virtual ~GameCharacter();


    Weapon *getWeapon() const;
    void setWeapon(Weapon* weapon);

    int getLife() const {
        return life;
    }
    void setLife(int life);

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength);
    int getSpeed() const {
        return speed;
    }

    void Attack(GameCharacter &enemy);
    virtual void TakeDamage(int point);

    int animation(int n, int direction);



protected:

    int life;
    int strength;
    int speed;


    Weapon* weapon;

};

#endif //EXAM_PROJECT_GAMECHARACTER_H
