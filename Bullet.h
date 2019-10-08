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

    float bulletLife;//distanza massima proiettile

private:
    float bulletSpeed;//velocità del proiettile
    sf::Vector2f shootingDirection;//direzione
};


#endif //GAME_BULLET_H
