//
// Created by matteo on 09/03/20.
//

#ifndef PROGETTO_PROVA_TILE_H
#define PROGETTO_PROVA_TILE_H


#include <SFML/Graphics.hpp>


class Tile: public sf::RectangleShape {
public:
    explicit Tile(int type);
    void init(float xPos,float yPos);
    int t;
    int width=32;
    int height=32;
    float posx{};
    float posy{};

    float hitTop{};
    float hitBottom{};
    float hitLeft{};
    float hitRight{};


};


#endif //PROGETTO_PROVA_TILE_H
