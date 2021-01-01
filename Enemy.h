//
// Created by matteo on 10/04/20.
//
#pragma once

#ifndef PROGETTO_PROVA_ENEMY_H
#define PROGETTO_PROVA_ENEMY_H


#include "GameCharacter.h"
#include "Tile.h"
#include "Chest.h"

class Hero;

class Enemy : public GameCharacter{
public:

    ///constructor and destructor
    Enemy(int hp, int s, int sp);
    ~Enemy() override;

    ///functions
    void movement( const std::vector<Tile>& tile_vector, Hero &hero, const std::vector<Chest>& chest_vector);
    void walkingAnimation();
    void deathAnimation();
    int damage();

    ///attributes
    sf::Vector2f spawnposition;
    bool hit=false;
    int counterDeath=0;
    bool heroHitted;

private:
    ///attributes
    int direction=0;// 1=up,2=down,3=left,4=right
    int walkingRate=0;
    int counterWalking=0;
};


#endif //PROGETTO_PROVA_ENEMY_H
