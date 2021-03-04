//
// Created by matteo on 03/03/21.
//

#include "gtest/gtest.h"
#include "../Hero.h"
#include "../Collision.h"
#include "../Archer.h"


TEST(Hero, wallCollision){
    Hero *hero = new Archer (1,1,30,1,1,1);
    Tile tile(0);
    sf::Vector2f position(412, 300);
    tile.setPosition(position);
    std::vector<Tile> tile_vector;
    tile_vector.push_back(tile);
    ASSERT_FALSE(Collision::checkCollision(tile_vector, hero, 1, 0));
}