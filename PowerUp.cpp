//
// Created by andreatadde on 18/09/19.
//

#include "PowerUp.h"

PowerUp::PowerUp(int t) {

    type = t;
    //bulletLifeIncr = 3.0f;
}

void PowerUp::setPower(Hero *hero, int type) {
    int typeBulletLife = 5;
    int typeSpeed = 6;
    float movementSpeedMultiplier = 1.2f;
    if (type == typeBulletLife) hero->setMoveSpeed(hero->getMoveSpeed() * movementSpeedMultiplier);
    if (type == typeSpeed) hero->setIsPowerBullet(true);
}

