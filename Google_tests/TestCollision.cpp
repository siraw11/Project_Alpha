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

TEST(Bullet,
     TestBulletCollisionMap) {//Test per verificare se all'impatto con la mappa il priettile viene distrutto e se
    //la mappa rimane invariata

    Bullet bullet(false, sf::Vector2f(1, 0));
    std::vector<Bullet> vectorBullet;
    std::vector<Platform> vectorPlat;

    bullet.init(100, 100, sf::Vector2f(10, 10));

    Platform objectr(0);
    objectr.init(130, 100, sf::Vector2f(30, 30));

    vectorPlat.push_back(objectr);
    vectorBullet.push_back(bullet);

    for (int i = 0; i < 6; i++) {
        vectorBullet[0].fire();
        ASSERT_EQ(vectorBullet.size(), 1);
        Collision::checkCollision(&vectorBullet, &vectorPlat);

    }

    ASSERT_EQ(vectorBullet.size(), 0);
    ASSERT_EQ(vectorPlat.size(), 1);
}

TEST(Bullet,
     TestBulletCollisionEnemy) {//Test per verificare se all'impatto con un nemico il priettile viene distrutto  se
    //insieme al nemico
    Bullet bullet(false, sf::Vector2f(1, 0));
    std::vector<Bullet> vectorBullet;
    std::vector<Enemy> vectorEnemy;

    bullet.init(100, 100, sf::Vector2f(10, 10));

    Enemy enemy;
    enemy.init(130, 100, sf::Vector2f(30, 30));

    vectorEnemy.push_back(enemy);
    vectorBullet.push_back(bullet);

    for (int i = 0; i < 6; i++) {
        vectorBullet[0].fire();
        ASSERT_EQ(vectorBullet.size(), 1);
        ASSERT_EQ(vectorEnemy.size(), 1);
        Collision::checkCollision(&vectorBullet, &vectorEnemy);
    }
    ASSERT_EQ(vectorBullet.size(), 0);
    ASSERT_EQ(vectorEnemy.size(), 0);
}