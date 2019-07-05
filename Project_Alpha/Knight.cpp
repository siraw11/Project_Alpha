//
// Created by waris on 20/06/19.
//

#include "Knight.h"

Knight::Knight(int a, int hp, int s, int sp): GameCharacter(hp, s, sp), armor(a) {

}

void Knight::fight(Enemy& enemy) {
    int damage=0;
    damage=strength+weapon->getStrength();

    TakeDamage(damage);
}

void Knight::TakeDamage(int damage) {

    if(armor>=0)
        damage-=armor;

    life-=damage;



}
