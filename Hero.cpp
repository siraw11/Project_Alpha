//
// Created by matteo on 19/03/20.
//

#include <iostream>
#include "Hero.h"
#include "GameManager/DEFINITIONS.hpp"
#include "Projectile.h"
#include "Collision.h"


Hero::Hero(int hp, int s,int sp):GameCharacter(hp,s,sp){

    weapon= nullptr;

    //setOrigin(getPosition().x +getGlobalBounds().width/10 ,getPosition().y +getGlobalBounds().height / 2);

    setPosition(sf::Vector2f(300,300));


}

void Hero::heroMovement(int x, int y, const std::vector<Tile>& tile_vector, const std::vector<Enemy>& enemy_vector) {

    sf::Vector2f movement(x*speed,y*speed);

    if(Collision::checkCollision(const_cast<std::vector<Tile> &>(tile_vector), this, x, y) || counterAttack != 0) {
        movement.x=0;
        movement.y=0;
    }else if(Collision::enemyCollision(this, enemy_vector, x, y )){
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

void Hero::attackAnimation() {
    int k = counterAttack - 1;
    setTextureRect(sf::IntRect(64 * k, 64 *(walkingDirection+4), 64, 64));
}

void Hero::attack( std::vector<Enemy>* enemy_vector) {
    if(playerType!=PlayerType::KNIGHT) {
        Projectile newProjectile(playerType);
        newProjectile.projectile_start.x = getPosition().x;
        newProjectile.projectile_start.y = getPosition().y+ getGlobalBounds().height/4;
        newProjectile.direction=walkingDirection;
        newProjectile.init();
        projectile_vector.push_back(newProjectile);

    }else {
        int x=0;
        int y=0;
        switch(walkingDirection){
            case 0: {
                x=0;
                y=-1;
                break;
            }
            case 1: {
                x=-1;
                y=0;
                break;
            }
            case 2: {
                x=0;
                y=-1;
                break;
            }
            case 3: {
                x=1;
                y=0;
                break;
            }
        }

        for(auto &i: *enemy_vector)
            if (Collision::meleeHeroAttak(this, i, x, y)){
                i.hit=true;
                break;
            }
    }
}

Weapon *Hero::getWeapon() const {
    return weapon;
}

void Hero::setWeapon(Weapon *weapon) {
    Hero::weapon = weapon;
}

int Hero::damage() {
    int damage=strength;
    if(weapon!= nullptr)
        damage+=weapon->getStrenght();
    return damage;
}

Hero::~Hero(){

    delete weapon;
}
