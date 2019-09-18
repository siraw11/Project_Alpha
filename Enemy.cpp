//
// Created by waris on 20/06/19.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int s, int sp, int a) :GameCharacter(hp,s,sp), Mage(hp,s,sp),Archer(hp,s,sp),Knight(a,hp,s,sp){}
