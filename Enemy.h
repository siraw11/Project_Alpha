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
    virtual void movement( const std::vector<Tile>& tile_vector, Hero &hero, const std::vector<Chest>& chest_vector);
    void walkingAnimation();
    void deathAnimation();
    sf::Vector2i walkingDirection();
    virtual void aggro(sf::Vector2f d);
    void update(std::unique_ptr<Hero> &hero, const std::vector<Tile>& tile_vector, const std::vector<Chest>& chest_vector);

    ///attributes
    sf::Vector2f spawnposition;
    bool hit=false;
    int counterDeath=0;
    bool heroHitted;
    bool dead=false;

protected:
    ///attributes
    int direction=0;// 1=up,2=left,3=down,4=right
    int walkingRate=0;
    int counterWalking=0;
    sf::Vector2f movementvect;
};


#endif //PROGETTO_PROVA_ENEMY_H
