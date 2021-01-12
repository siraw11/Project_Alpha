//
// Created by matteo on 19/03/20.
//

#pragma once

#ifndef PROGETTO_PROVA_HERO_H
#define PROGETTO_PROVA_HERO_H


#include "GameCharacter.h"
#include "Tile.h"
#include "Enemy.h"
#include "Chest.h"
#include "Projectile.h"
#include "Weapon.h"
#include "PlayerType.h"

class Hero: public GameCharacter {
public:
///constructor,desctructor
    Hero(int hp, int s,int sp, int a, int ar, int m);
    ~Hero() override;

///function
    void heroMovement( const std::vector<Tile>& tile_vector, const std::vector<Enemy>& enemy_vector, const std::vector<Chest>& chest_vector );
    void openChest( std::vector<Chest> *chest_vector, std::vector<Tile>* tile_vector );
    void attackAnimation();
    void attack( std::vector<Enemy>* enemy_vector );
    int damage();
    sf::Vector2i direction();
    void update( const std::vector<Tile>& tile_vector, std::vector<Enemy>& enemy_vector, std::vector<Chest>* chest_vector );

///attributi
    int walkingDirection=2;//0=up, 1=left, 2=down, 3=right
    int counterAttack=0;//attack rate
    std::vector<Projectile> projectile_vector;
    PlayerType playerType;
    bool hit;
///getters
    Weapon *getWeapon() const;
    int getArmor() const;
    int getArrow() const;
    int getMana() const;

///setters
    void setWeapon(Weapon* weapon);
    void setArmor(int armor);
    void setArrow(int arrow);
    void setMana(int mana);


protected:
///attributes
    Weapon* weapon;
    int armor;
    int arrow;
    int mana;



private:
///attributes
    int counterWalking=0;

///function
    void walkingAnimation();
};


#endif //PROGETTO_PROVA_HERO_H
