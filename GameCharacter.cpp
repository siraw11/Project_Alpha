//
// Created by matteo on 19/03/20.
//

#include "GameCharacter.h"
#include "Collision.h"
#include "map.h"

GameCharacter::GameCharacter(int hp, int s, int sp){
    if(hp <= 0 || s <= 0 || sp <= 0){
        throw std::out_of_range("Negative Value");
    }else{
        life = hp;
        strength = s;
        speed = sp;
    }

    setSize(sf::Vector2f(64,64));

}

int GameCharacter::getLife() const {
    return life;
}

void GameCharacter::setLife(int life) {
    GameCharacter::life = life;
}

int GameCharacter::getSpeed() const {
    return speed;
}

void GameCharacter::setSpeed(int speed) {
    GameCharacter::speed = speed;
}

int GameCharacter::getStrength() const {
    return strength;
}

void GameCharacter::setStrength(int strength) {
    GameCharacter::strength = strength;
}

GameCharacter::~GameCharacter() = default;

void GameCharacter::takeDamage(int damage) {
    life-=damage;
}


