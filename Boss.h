//
// Created by matteo on 18/08/20.
//
#pragma once

#ifndef PROJECT_ALPHA_BOSS_H
#define PROJECT_ALPHA_BOSS_H


#include "Enemy.h"

class Projectile;

class Boss : public Enemy {

public:
///constructor and destructor
    Boss(int hp, int s, int sp);
    ~Boss() override;

///functions
    void movement(const std::vector<Tile>& tile_vector, Hero &hero, const std::vector<Chest>& chest_vector)override;
    void update(Hero hero, const std::vector<Tile>& tile_vector, const std::vector<Chest>& chest_vector)override;
    void attack(const Hero& hero);
    std::vector<Projectile> projectile_vector;

private:
    int posx;
    int posy;


};


#endif //PROJECT_ALPHA_BOSS_H
