//
// Created by matteo on 19/03/20.
//


#include "GameCharacter.h"

//constructor
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

//destructor
GameCharacter::~GameCharacter() = default;

//getters

int GameCharacter::getLife() const {
    return life;
}

int GameCharacter::getSpeed() const {
    return speed;
}

int GameCharacter::getStrength() const {
    return strength;
}

//setters
void GameCharacter::setLife(int life) {
    GameCharacter::life = life;
}

void GameCharacter::setSpeed(int speed) {
    GameCharacter::speed = speed;
}

void GameCharacter::setStrength(int strength) {
    GameCharacter::strength = strength;
}

//functions

void GameCharacter::takeDamage(int damage) {
    life -= damage;
}


