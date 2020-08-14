//
// Created by matteo on 23/03/20.
//

#ifndef PROGETTO_PROVA_COLLISION_H
#define PROGETTO_PROVA_COLLISION_H


#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Hero.h"


class Collision {
public:
    static bool checkCollision( std::vector<Tile>& tile_vector,  Hero *hero, int x, int y);
    static bool checkCollision( std::vector<Tile>& tile_vector,  Enemy *enemy, int x, int y );
    static bool enemyCollision(Hero *hero,const std::vector<Enemy>& enemy_vector, int x, int y);
    static bool projectileCollisionEnemy(Projectile *projectile, const Enemy &enemy, int x, int y);//projectile collision with enemies
    static bool projectileCollision(Projectile *projectile,const std::vector<Tile>& tile_vector, int x, int y);//projectile collision with walls





};


#endif //PROGETTO_PROVA_COLLISION_H