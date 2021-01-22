//
// Created by matteo on 09/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_TILE_H
#define PROGETTO_PROVA_TILE_H


#include <SFML/Graphics.hpp>


class Tile: public sf::RectangleShape {
public:
//constructor, destructor
    explicit Tile(int type);
    ~Tile() override;

//function
    void init(float xPos,float yPos);
    void openGate();

//attributes
    int t;
    int width = 32;
    int height = 32;
    float posx{};
    float posy{};

    float hitTop{};
    float hitBottom{};
    float hitLeft{};
    float hitRight{};


};


#endif //PROGETTO_PROVA_TILE_H
