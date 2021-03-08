//
// Created by waris on 07/03/21.
//
#include "gtest/gtest.h"
#include "../Enemy.h"
#include "../Collision.h"


TEST(Enemy,takeDamage){
Enemy *enemy = new Enemy (10,1,10);
enemy->takeDamage(5);
ASSERT_EQ(enemy->getLife(),5);

}