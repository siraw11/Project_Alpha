//
// Created by andreatadde on 18/09/19.
//

#include "PowerUp.h"

PowerUp::PowerUp(int t) {
    type = t;
    //bulletLifeIncr = 3.0f;
}

void PowerUp::setPower(Hero *hero, int type) {
    if (type == 5) hero->setMoveSpeed(hero->getMoveSpeed() * 1.2f);
    if (type == 6) hero->setIsPowerBullet(true);
}

