//
// Created by andreatadde on 18/09/19.
//

#ifndef GAME_POWERUP_H
#define GAME_POWERUP_H

#include "RectangleShape.h"
#include "Hero.h"
#include "Bullet.h"

class PowerUp : public RectangleShape {
public:
    PowerUp(int t);

    static void setPower(Hero *hero, int t);

public:
    int type;
    //float bulletLifeIncr;
};


#endif //GAME_POWERUP_H
