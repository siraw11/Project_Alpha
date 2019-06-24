//
// Created by matteo on 20/06/19.
//

#include "GameCharacter.h"
#include "Weapon.h"

using namespace std;

GameCharacter::GameCharacter(int hp, int s, int sp): life(hp), strenght(s), speed(sp), posX(0), posY(0), weapon(nullptr){};
