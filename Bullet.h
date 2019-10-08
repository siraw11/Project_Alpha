//
// Created by andreatadde on 17/09/19.
//

#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include "Object.h"

//Classe proiettile
class Bullet : public Object {
public:
    explicit Bullet(bool isPoweredUp, sf::Vector2f shootingDirectionInput);

    void fire();//Metodo per muovere il proiettile
public:

    float bulletLife = 100.f;//distanza massima proiettile

private:
    float bulletSpeed = 2.f;//velocità del proiettile
private:
    sf::Vector2f shootingDirection;//direzione
    int spriteDirectionLeft = 180;
    int spriteDirectionUp = -90;
    int spriteDirectionDown = 90;
    float bulletLifeMultiplier = 3.f;
};


#endif //GAME_BULLET_H
