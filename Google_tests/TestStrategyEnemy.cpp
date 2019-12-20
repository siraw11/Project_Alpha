//
// Created by andreatadde on 12/11/19.
//
#include <gtest/gtest.h>
#include <SFML/System.hpp>
#include "../Hero.h"
#include "../GameCharacter.h"
#include "../RectangleShape.h"
#include "../Bullet.h"
#include "../Platform.h"
#include "../Collision.h"
#include "../GameLogic.h"
#include <vector>
#include <iostream>
#include <cmath>

TEST(Enemy,testIdle){
    Enemy enemy;
    Hero hero;
    sf::Time time = sf::seconds(3);
    enemy.init(400,400,sf::Vector2f(10,10));
    hero.init(100,100,sf::Vector2f(10,10));
    enemy.aggroUpdate(&hero,time,NULL);
    ASSERT_EQ(enemy.x,400);
    ASSERT_EQ(enemy.y,400);
}

TEST(Enemy,testCatch){
    Enemy enemy;
    Hero hero;
    sf::Time time = sf::seconds(3);
    std::vector<Platform> platform;
    enemy.init(150,100,sf::Vector2f(10,10));
    hero.init(100,100,sf::Vector2f(10,10));
    enemy.aggroUpdate(&hero,time,&platform);
    ASSERT_TRUE(50 > fabs(hero.x - enemy.x));
}

TEST(Enemy,testReturnHome){
    Enemy enemy;
    Hero hero;
    sf::Time time = sf::seconds(3);
    std::vector<Platform> platform;
    enemy.init(150,100,sf::Vector2f(10,10));
    hero.init(100,100,sf::Vector2f(10,10));
    enemy.aggroUpdate(&hero,time,&platform);
    hero.x = 300;
    hero.y = 100;
    ASSERT_TRUE(150 < fabs(hero.x - enemy.x));
}

TEST(Enemy,testAttack){
    Enemy enemy;
    Hero hero;
    sf::Time time = sf::seconds(3);
    std::vector<Platform> platform;
    int initialHP = hero.HP;
    hero.init(100,100,sf::Vector2f(10,10));
    enemy.init(100,100,sf::Vector2f(10,10));
    enemy.aggroUpdate(&hero,time,&platform);
    ASSERT_EQ(hero.HP,initialHP-enemy.damage);
}