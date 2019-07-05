//
// Created by matteo on 20/06/19.
//

#include "GameCharacter.h"
#include "Weapon.h"
#include <stdexcept>

using namespace std;

GameCharacter::GameCharacter(int hp, int s, int sp): posX(0), posY(0), weapon(nullptr){
    if(hp <= 0 || s <= 0 || sp <= 0){
        throw std::out_of_range("Negative Value");
    }else{
        life = hp;
        strength = s;
        speed = sp;
    }
};

Weapon* GameCharacter::getWeapon() const {
    return weapon;
}

void GameCharacter::setWeapon(Weapon *weapon) {
    this->weapon = weapon;
}

void GameCharacter::Attack(Enemy& enemy) {
    int point=strength;
    if(weapon!=nullptr)
        point+=weapon->getStrength();
    TakeDamage(point);
}

 void GameCharacter::TakeDamage(int point) {
    life-=point;
    return true;
}

