//
// Created by matteo on 10/03/20.
//

#ifndef PROGETTO_PROVA_MAP_H
#define PROGETTO_PROVA_MAP_H

#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameManager/Game.hpp"
#include "Enemy.h"


class map {

public:
    map();

    //vettori di tile
    std::vector<Tile> tile_vector;
    //vettore dei nemici
    std::vector<Enemy> enemy_vector;

    //draw oggetti
    void drawTile(const Alpha::GameDataRef& _data);
    void setTexture();
    void drawEnemy(const Alpha::GameDataRef& _data);

    void update();// update level events

private:
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
