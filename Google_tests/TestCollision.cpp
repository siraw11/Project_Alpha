//
// Created by davide on 09/10/19.
//
#include <gtest/gtest.h>
#include <SFML/System.hpp>
#include "../Hero.h"
#include "../GameCharacter.h"
#include "../RectangleShape.h"
#include "../Bullet.h"
#include "../Platform.h"
#include "../Collision.h"
#include <vector>
#include <iostream>

TEST(Bullet,TestBulletCollisionMap) {//Test per verificare se all'impatto con la mappa il priettile viene distrutto e se
    //la mappa rimane invariata
    int ceckcoll = -1;
    Bullet bullet(false, sf::Vector2f(1, 0));
    std::vector<Bullet> vectorBullet;
    std::vector<Platform> vectorPlat;

    bullet.init(100, 100, sf::Vector2f(10, 10));
    Platform objectr(1);
    objectr.init(130, 100, sf::Vector2f(30, 30));

    vectorPlat.push_back(objectr);
    vectorBullet.push_back(bullet);

    while(bullet.x<objectr.hitLeft-bullet.hitRight){
        bullet.fire();
        ceckcoll=Collision::checkCollision(&vectorBullet,&vectorPlat);
        ASSERT_EQ(ceckcoll,-1);
    }
    while(bullet.x<=objectr.hitLeft){
        ceckcoll=Collision::checkCollision(&vectorBullet,&vectorPlat);
        bullet.fire();
    }
    ASSERT_EQ(ceckcoll,0);
}

TEST(Bullet,TestBulletCollisionEnemy) {//Test per verificare se all'impatto con un nemico il priettile viene distrutto  se
    //insieme al nemico
    Bullet bullet(false, sf::Vector2f(1, 0));
    std::vector<Bullet> vectorBullet;
    std::vector<Enemy> vectorEnemy;
    sf::Vector2i checkColl;
    checkColl.x = -1;
    checkColl.y = -1;
    bullet.init(100, 100, sf::Vector2f(10, 10));

    Enemy enemy;
    enemy.init(130, 100, sf::Vector2f(30, 30));

    vectorEnemy.push_back(enemy);
    vectorBullet.push_back(bullet);

    while (bullet.x<enemy.hitRight-bullet.hitRight) {
        vectorBullet[0].fire();
        checkColl = Collision::checkCollision(&vectorBullet, &vectorEnemy);
        ASSERT_EQ(vectorBullet.size(), -1);
        ASSERT_EQ(vectorEnemy.size(), -1);

    }
    while (bullet.x<=enemy.hitLeft){
        checkColl = Collision::checkCollision(&vectorBullet, &vectorEnemy);
        bullet.fire();
    }
    ASSERT_EQ(checkColl.x, 0);
    ASSERT_EQ(checkColl.y, 0);
}

TEST(Hero,TestCollisionPlatform){
    Platform platform(0);
    platform.init(100,110,sf::Vector2f(10,10));
    std::vector<Platform> vectorPlat;
    Hero hero;
    hero.init(100,100,sf::Vector2f(10,10));
    while (hero.y<platform.hitTop-hero.hitBottom) {
        hero.update(false,false, false, false,&vectorPlat);
        ASSERT_TRUE(hero.y>hero.spawnY);
    }
    while (hero.y<=platform.hitBottom){
        hero.update(false,false, false, false,&vectorPlat);
    }
    ASSERT_EQ(hero.hitBottom,platform.hitTop);
}