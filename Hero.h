//
// Created by andreatadde on 18/09/19.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H

#include "GameCharacter.h"

//Classe addebita alla gestione del giocatore
class Hero : public GameCharacter {
public:
    Hero();

    void update(bool W, bool A, bool S, bool D);//Gestisce il movimento da input da tastiera

private:
    bool isPowerBullet;
public:
    bool getIsPowerBullet() const;

    void setIsPowerBullet(bool isPowerBullet);
};


#endif //GAME_HERO_H
