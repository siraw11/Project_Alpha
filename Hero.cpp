//
// Created by matteo on 19/03/20.
//

#include <iostream>
#include "Hero.h"

#include "GameManager/DEFINITIONS.hpp"


Hero::Hero(int hp, int s,int sp):GameCharacter(hp,s,sp){

    setOrigin(getPosition().x +getGlobalBounds().width/10 ,getPosition().y +getGlobalBounds().height / 6);

    setPosition(sf::Vector2f(300,300));


}

void Hero::heroMovement(int x, int y, const map& level) {

    sf::Vector2f movement(x*speed,y*speed);

    if(this->collisionLinker(level,x,y)) {
        movement.x=0;
        movement.y=0;
    }else{
        walkingAnimation();
    }

    move(movement);

}

void Hero::walkingAnimation() {
    if(counterWalking!=8){
        setTextureRect(sf::IntRect(64*counterWalking,64*walkingDirection,64,64));
        counterWalking++;
    }else{
        counterWalking=0;
    }

}

void Hero::fight(Enemy &enemy) {
    enemy.takeDamage(1);
}

Hero::~Hero() = default;
