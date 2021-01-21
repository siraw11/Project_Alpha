//
// Created by matteo on 10/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_MAP_H
#define PROGETTO_PROVA_MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameManager/Game.hpp"
#include "Tile.h"
#include "Enemy.h"
#include "Boss.h"
#include "Chest.h"
#include "Projectile.h"
#include "Hero.h"

class map {

public:
    ///constructor, destructor
    map();
    ~map();

    ///vettori di tile
    std::vector<Tile> tile_vector;
    ///vettore dei nemici
    std::vector<Enemy> enemy_vector;
    ///vettore delle chest
    std::vector<Chest> chest_vector;



    ///draw oggetti
    void drawTile(const Alpha::GameDataRef& _data);
    void setTexture();
    void drawEnemy(const Alpha::GameDataRef& _data);
    void drawProjectile(const std::vector<Projectile>& projectile_vector, const Alpha::GameDataRef& _data);
    void drawChest( const Alpha::GameDataRef& _data);
    void update( std::unique_ptr<Hero>& hero, std::unique_ptr<Boss>& boss);// update level events

private:
    ///attributes
    int raws=84;
    int column=120;
    int floor=0;
    int up_wall=1;
    int right_wall=2;
    int left_wall=3;
    int down_wall=4;
    int down_left_corner=5;
    int down_right_corner=6;
    int up_left_corner=7;
    int up_right_corner=8;
    int key_wall=9;
    int left_corridor=10;
    int torch_wall=11;
    int right_corridor=12;
    int bones=13;
    int web=14;
    int skull=15;
    int torch=16;
    int left_front_door=17;
    int right_front_door=18;
    int left_side_door=19;
    int right_side_door=20;
    int void_tile=21;

};


#endif //PROGETTO_PROVA_MAP_H
