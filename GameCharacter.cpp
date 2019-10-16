//
// Created by matteo on 20/06/19.
//

#include "GameCharacter.h"
#include <stdexcept>

using namespace std;

GameCharacter::GameCharacter(int hp, int s, int sp): weapon(nullptr){
    if(hp <= 0 || s <= 0 || sp <= 0){
        throw std::out_of_range("Negative Value");
    }else{
        life = hp;
        strength = s;
        speed = sp;
    }
};


void GameCharacter::setStrength(int strength) {
    GameCharacter::strength = strength;
}


Weapon* GameCharacter::getWeapon() const {
    return weapon;
}

void GameCharacter::setWeapon(Weapon *weapon) {
    this->weapon = weapon;
}

void GameCharacter::Attack(GameCharacter* enemy) {
    int point=strength;
    if(weapon!=nullptr)
        point+=weapon->getStrength();
    TakeDamage(point);
}


void GameCharacter::TakeDamage(int point) {
    life-=point;
}

void GameCharacter::setLife(int life) {
    GameCharacter::life = life;
}

GameCharacter::~GameCharacter() {
    if(weapon!= nullptr)
        delete weapon;
}

int GameCharacter::animation(int n, int direction) {

    if (n > 0) {
        int k = n - 1;
        setTextureRect((sf::IntRect(64 * k, 64 * direction, 64, 64)));
        n++;
    }

    return n;

}
