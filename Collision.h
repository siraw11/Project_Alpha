//
// Created by matteo on 23/03/20.
//

#ifndef PROGETTO_PROVA_COLLISION_H
#define PROGETTO_PROVA_COLLISION_H


#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "GameCharacter.h"


class Collision {
public:
    static bool checkCollision(  std::vector<Tile>& tile_vector,  GameCharacter *gameCharacter, int x, int y);

private:




};


#endif //PROGETTO_PROVA_COLLISION_H