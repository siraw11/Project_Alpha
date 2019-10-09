#include <gtest/gtest.h>
#include <SFML/System.hpp>
#include "../Hero.h"
#include "../GameCharacter.h"
#include "../RectangleShape.h"
#include "../Bullet.h"
//
// Created by davide on 28/09/19.

TEST(Bullet, checkInitObject) {
    RectangleShape o1;
    o1.init(90,100,sf::Vector2f(10,20));
    ASSERT_EQ(90,o1.x);
    ASSERT_EQ(100,o1.y);
    ASSERT_EQ(10,o1.width);
    ASSERT_EQ(20,o1.height);
    ASSERT_EQ(90,o1.spawnX);
    ASSERT_EQ(100,o1.spawnY);
    ASSERT_EQ(o1.hitTop,o1.y);
    ASSERT_EQ(o1.hitBottom,o1.y+o1.height);
    ASSERT_EQ(o1.hitLeft,o1.x);
    ASSERT_EQ(o1.hitRight,o1.x+o1.width);

}

TEST(GameCharacter,checkCharacterInit){
    GameCharacter g1;
    ASSERT_EQ(g1.velocity.x,0);
    ASSERT_EQ(g1.velocity.y,0);
}

TEST(Hero,checkHeroUpdate){
    Hero h1;
    h1.init(10,10,sf::Vector2f(32,32));
    h1.setMoveSpeed(30);
    h1.isOnGround= true;
    h1.update(false, false, false, true);
    ASSERT_EQ(h1.velocity.x,1);
    h1.update(false, true, false, false);
    ASSERT_EQ(h1.velocity.x,-1);
    h1.update(true, false, false, false);
    ASSERT_EQ(h1.velocity.y,-8);
}

TEST(Bullet,checkBullet){
    Bullet b1(false,sf::Vector2f(1,0));
    b1.init(10,20,sf::Vector2f(30,30));
    b1.fire();
    ASSERT_EQ(b1.spawnX,b1.x-2);
    Bullet b2(false,sf::Vector2f(-1,0));
    b2.init(10,20,sf::Vector2f(30,30));
    b2.fire();
    ASSERT_EQ(b2.spawnX,b2.x+2);
    Bullet b3(false,sf::Vector2f(0,1));
    b3.init(10,20,sf::Vector2f(30,30));
    b3.fire();
    ASSERT_EQ(b3.spawnY,b3.y-2);
    Bullet b4(false,sf::Vector2f(0,-1));
    b4.init(10,20,sf::Vector2f(30,30));
    b4.fire();
    ASSERT_EQ(b4.spawnY,b4.y+2);
    Bullet b5(true,sf::Vector2f(0,0));
    ASSERT_EQ(b5.bulletLife,b1.bulletLife*3);
}
