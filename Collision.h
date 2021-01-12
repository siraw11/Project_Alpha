//
// Created by matteo on 23/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_COLLISION_H
#define PROGETTO_PROVA_COLLISION_H


#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Hero.h"


class Collision {
public:
    static bool checkCollision( std::vector<Tile>& tile_vector,  Hero *hero, int x, int y);//hero collision with walls
    static bool checkCollision( std::vector<Tile>& tile_vector,  Enemy *enemy, int x, int y );//enemy collision with walls
    static bool checkCollision( std::vector<Tile>& tile_vector,  Boss *boss, int x, int y );
    static bool enemyCollision( Hero *hero, const std::vector<Enemy>& enemy_vector, int x, int y);//hero collision with enemy
    static bool heroCollision( Enemy *enemy, const Hero &hero, int x, int y);//enemy collision with hero
    static bool projectileCollisionEnemy( Projectile *projectile, const Enemy &enemy, int x, int y);//projectile collision with enemies
    static bool projectileCollisionBoss( Projectile *projectile, const Boss &boss, int x, int y);//projectile collision with boss
    static bool projectileCollision( Projectile *projectile,const std::vector<Tile>& tile_vector, int x, int y);//projectile collision with walls
    static bool meleeHeroAttak( Hero *hero, const Enemy &enemy, int x, int y);
    static bool chestCollision(const Chest& chest, Enemy *enemy, int x, int y );//enemy collision with chests
    static bool chestCollision(const Chest& chest, Hero *hero, int x, int y );//hero collision with item chests



};


#endif //PROGETTO_PROVA_COLLISION_H