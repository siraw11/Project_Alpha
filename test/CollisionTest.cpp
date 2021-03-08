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

    Tile tile1(1);
    tile1.init(350,300);
    tile_vector.push_back(tile1);
    ASSERT_TRUE(Collision::checkCollision(tile_vector, hero, 1, 0));
}

TEST(Enemy, wallCollision){
    Enemy *enemy = new Enemy (1,1,10);
    enemy->setPosition(300,300);
    Tile tile(0);
    sf::Vector2f position(412, 300);
    tile.setPosition(position);
    std::vector<Tile> tile_vector;
    tile_vector.push_back(tile);
    ASSERT_FALSE(Collision::checkCollision(tile_vector, enemy, 1, 0));

    Tile tile1(1);
    tile1.init(350,300);
    tile_vector.push_back(tile1);
    ASSERT_TRUE(Collision::checkCollision(tile_vector, enemy, 1, 0));

}

TEST(Hero,enemyCollision){
    Hero *hero = new Archer (1,1,30,1,1,1);
    Enemy *enemy = new Enemy (1,1,10);
    enemy->setPosition(350,300);
    std::vector<Enemy> enemy_vector;
    enemy_vector.push_back(*enemy);
    ASSERT_TRUE(Collision::enemyCollision(hero,enemy_vector,1,0));
}

TEST(Projectile,enemyCollision){
    Projectile projectile(PlayerType::ARCHER);
    projectile.setPosition(300,300);
    Enemy *enemy = new Enemy (1,1,10);
    enemy->setPosition(350,300);
    ASSERT_TRUE(Collision::projectileCollisionEnemy(&projectile,*enemy,1,0));

}

TEST(Projectile, wallCollision){
    Projectile projectile(PlayerType::ARCHER);
    projectile.setPosition(300,300);
    Tile tile(0);
    sf::Vector2f position(412, 300);
    tile.setPosition(position);
    std::vector<Tile> tile_vector;
    tile_vector.push_back(tile);

    ASSERT_FALSE(Collision::projectileCollision(&projectile,tile_vector,1,0));

    Tile tile1(1);
    tile1.init(350,300);
    tile_vector.push_back(tile1);
    ASSERT_TRUE(Collision::projectileCollision(&projectile,tile_vector,1,0));

}
