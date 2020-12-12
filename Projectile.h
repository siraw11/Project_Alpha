//
// Created by matteo on 22/04/20.
//
#pragma once

#ifndef PROGETTO_PROVA_PROJECTILE_H
#define PROGETTO_PROVA_PROJECTILE_H


#include <SFML/Graphics/RectangleShape.hpp>

#include "PlayerType.h"
#include "Tile.h"
class Enemy;


class Projectile: public sf::RectangleShape {
public:
    ///constructor, destructor
    explicit Projectile(PlayerType playerType);
    ~Projectile() override;

    ///functions
    void init();
    bool checkCollision(std::vector<Enemy> *enemy_vector, const std::vector<Tile> &tile_vector);
    void updateProjectile();

    ///attributes
    int direction{};//0=down,1=left,2=right,3=up



    int projectile_speed=20;

    sf::Vector2f projectile_start;
};


#endif //PROGETTO_PROVA_PROJECTILE_H
