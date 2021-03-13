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
//constructor and destructor
    Boss(int hp, int s, int sp);
    ~Boss() override;

//functions
    void movement(const std::vector<Tile>& tile_vector, Hero &hero, const std::vector<Chest>& chest_vector)override;
    void update(Hero& hero, const std::vector<Tile>& tile_vector, const std::vector<Chest>& chest_vector, std::vector<Enemy>& enemy_vector);
    void attack(const Hero& hero);
    void aggro(sf::Vector2f d)override;
    sf::Vector2f distance(const Hero& hero);
    void deathAnimation()override;
    void initSound(const Alpha::GameDataRef &data) override;

//attributes
    std::vector<Projectile> projectile_vector;

private:
    int attackRate = 30;
    int counterAttack = 0;
    int posx;
    int posy;

    sf::Sound bone;
};


#endif //PROJECT_ALPHA_BOSS_H
