//
// Created by matteo on 22/04/20.
//
#pragma once

#ifndef PROGETTO_PROVA_PROJECTILE_H
#define PROGETTO_PROVA_PROJECTILE_H


#include <SFML/Graphics/RectangleShape.hpp>

#include "PlayerType.h"
#include "Tile.h"
#include "Boss.h"

class Enemy;


class Projectile: public sf::RectangleShape {
public:
//constructor, destructor
    explicit Projectile(PlayerType playerType);
    ~Projectile() override;

//functions
    void init();
    bool checkCollision(std::vector<Enemy> *enemy_vector, const std::vector<Tile> &tile_vector, Boss& boss, Hero& hero);
    void updatePosition();

//attributes
    int direction{};//0=up,1=left,2=down,3=right,4=other
    sf::Vector2f directionVector;

    int projectile_speed = 40;
    sf::Vector2f projectile_start;

private:
    PlayerType type;
};


#endif //PROGETTO_PROVA_PROJECTILE_H
