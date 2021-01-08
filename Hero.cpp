//
// Created by matteo on 19/03/20.
//

#include <iostream>

#include "GameManager/DEFINITIONS.hpp"
#include "Hero.h"
#include "Collision.h"


///constructor
Hero::Hero(int hp, int s, int sp, int a, int ar, int m):GameCharacter(hp,s,sp){

    arrow=a;
    armor=ar;
    mana=m;
    weapon= nullptr;
    hit=false;
    setPosition(sf::Vector2f(300,300));


}

///destructor
Hero::~Hero(){
}

///functions
void Hero::heroMovement( const std::vector<Tile>& tile_vector, const std::vector<Enemy>& enemy_vector, const std::vector<Chest>& chest_vector ) {

    sf::Vector2f movement(direction().x*speed,direction().y*speed);
    bool collided=false;

    if(Collision::checkCollision(const_cast<std::vector<Tile> &>(tile_vector), this, direction().x, direction().y) || counterAttack != 0) {
        movement.x=0;
        movement.y=0;
        collided=true;
    }else if(Collision::enemyCollision(this, enemy_vector, direction().x, direction().y )){
        movement.x=0;
        movement.y=0;
        this->hit=true;
        collided=true;
    }else {
        for( const Chest& i : chest_vector)
            if(Collision::chestCollision( i, this, direction().x, direction().y )){
                movement.x=0;
                movement.y=0;
                collided=true;
                break;
            }

    }
    if(!collided){
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
        for(auto &i: *enemy_vector)
            if (Collision::meleeHeroAttak(this, i, direction().x, direction().y)){
                i.hit=true;
                break;
            }
    }
}

void Hero::openChest( std::vector<Chest> *chest_vector, std::vector<Tile>* tile_vector) {

    for(auto &i: *chest_vector) {
        if (Collision::chestCollision(i, this, direction().x, direction().y)) {

            if(i.close){
                i.open(this, tile_vector);
                std::cout<<"forza arma dopo open"<<std::endl;
                std::cout<<this->getWeapon()->getStrength()<<std::endl;
            }


            break;
        }
    }

}


sf::Vector2i Hero::direction() {
    sf::Vector2i direction;
    switch(walkingDirection){
        case 0: {
            direction.x=0;
            direction.y=-1;
            break;
        }
        case 1: {
            direction.x=-1;
            direction.y=0;
            break;
        }
        case 2: {
            direction.x=0;
            direction.y=1;
            break;
        }
        case 3: {
            direction.x=1;
            direction.y=0;
            break;
        }
    }

    return direction;
}

int Hero::damage() {
    int damage=strength;
    if(weapon!= nullptr)
        damage+=weapon->getStrength();
    return damage;
}

///getters
Weapon *Hero::getWeapon() const {
    return weapon;
}

int Hero::getArmor() const {
    return armor;
}

int Hero::getArrow() const {
    return arrow;
}

int Hero::getMana() const {
    return mana;
}

///setters
void Hero::setWeapon(Weapon* weapon) {
    this->weapon=weapon;
    std::cout<<"forza arma nel set"<<std::endl;
    std::cout<<this->weapon->getStrength()<<std::endl;
}

void Hero::setArmor(int armor) {
    Hero::armor = armor;
}

void Hero::setMana(int mana) {
    Hero::mana = mana;
}

void Hero::setArrow(int arrow) {
    Hero::arrow = arrow;
}


