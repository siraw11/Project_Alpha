//
// Created by matteo on 23/03/20.
//

#include <iostream>
#include "Collision.h"
#include "GameManager/DEFINITIONS.hpp"

bool Collision::checkCollision( std::vector<Tile>& tile_vector,  GameCharacter *gameCharacter, int x, int y ) {
    bool collided=false;
    sf::Vector2f position(gameCharacter->getPosition());

    position.x += gameCharacter->getSpeed()*x;
    position.y += gameCharacter->getSpeed()*y;

    for(const auto& i: tile_vector)
    {
        if(i.t!=0 && position.x + TILE_WIDTH > i.hitLeft && position.x < i.hitRight &&
           position.y <i.hitBottom && position.y + TILE_HEIGHT > i.hitTop)
        {
            collided=true;


        }
    }

    return collided;
}
