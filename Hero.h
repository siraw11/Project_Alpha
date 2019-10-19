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

    int HP = 5;
    int initialHP = HP;
private:
    bool isPowerBullet;
    //---Animation variables--//
    float delta_time = 1.0f / 60.0f;
    unsigned int frame_x = 3;
    unsigned int frame_y = 9;
public:
    bool getIsPowerBullet() const;

    void setIsPowerBullet(bool isPowerBullet);

    virtual ~Hero();
};


#endif //GAME_HERO_H
