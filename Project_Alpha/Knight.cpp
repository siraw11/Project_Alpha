//
// Created by waris on 20/06/19.
//

#include "Knight.h"

Knight::Knight(int a, int hp, int s, int sp): GameCharacter(hp, s, sp), armor(a) {

}

void Knight::fight(Enemy& enemy) {
    int damage=0;
    damage=strength+weapon->getStrength();
    if(damage>armor)
        damage-=armor;
    else
        damage =0;

    TakeDamage(damage);
}


