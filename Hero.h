//
// Created by matteo on 19/03/20.
//

#pragma once

#ifndef PROGETTO_PROVA_HERO_H
#define PROGETTO_PROVA_HERO_H


#include <list>
#include "GameCharacter.h"
#include "Tile.h"
#include "Enemy.h"
#include "Chest.h"
#include "Projectile.h"
#include "Weapon.h"
#include "PlayerType.h"
#include "Subject.h"

class Hero: public GameCharacter , public Subject{
public:
//constructor,desctructor
    Hero(int hp, int s,int sp, int a, int ar, int m);
    ~Hero() override;

//function
    void heroMovement( const std::vector<Tile>& tile_vector, const std::vector<Enemy>& enemy_vector, const std::vector<Chest>& chest_vector );
    void openChest( std::vector<Chest> *chest_vector, std::vector<Tile>* tile_vector );
    void attackAnimation();
    void deathAnimation();
    void attack( std::vector<Enemy>* enemy_vector, std::unique_ptr<Boss>& boss );
    int damage();
    sf::Vector2i direction() const;
    void update( const std::vector<Tile>& tile_vector, std::vector<Enemy>& enemy_vector, std::vector<Chest>* chest_vector, std::unique_ptr<Boss>& boss );
    void bounce(const Enemy& enemy);
    void initSound(const Alpha::GameDataRef &data);

//attributi
    int walkingDirection = 2;//0=up, 1=left, 2=down, 3=right
    int counterAttack = 0;//attack rate
    int counterDeath = 0;
    std::vector<Projectile> projectile_vector;
    PlayerType playerType;
    bool hit;
    int range = 0;
    bool dead = false;
    bool isMoving = false;
    int counterStep = 0;
    int counterKill = 0;
    sf::Vector2f movement;

//getters
    Weapon *getWeapon() const;
    int getArmor() const;
    int getArrow() const;
    int getMana() const;

//setters
    void setWeapon(Weapon* weapon);
    void setArmor(int armor);
    void setArrow(int arrow);
    void setMana(int mana);

//Subject functions
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void notify() override;



protected:
//attributes
    Weapon* weapon;
    int armor;
    int arrow;
    int mana;
    sf::Sound arrowSound;
    sf::Sound swordSound;
    sf::Sound fireSound;
    sf::Sound femaleHitSound;
    sf::Sound maleHitSound;
    sf::Sound owSound;
    sf::Sound scream;


private:
//attributes
    int counterWalking = 0;
    std::list<Observer*> observers;

//function
    void walkingAnimation();


};


#endif //PROGETTO_PROVA_HERO_H
