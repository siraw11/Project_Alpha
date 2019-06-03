//
// Created by Magna on 2019-06-03.
//

#include "gtest/gtest.h"
#include "../Player.h"

TEST(Player, DefaultConstructor) {
    Player p;
    ASSERT_EQ(0, p.getPosX()); //check initial x position
    ASSERT_EQ(0, p.getPosY());  //check initial y position
    ASSERT_EQ(0, p.getAngle()); //check initial angle
    ASSERT_GE(p.getTotalCoin(), 0); //check initial amount of money
    ASSERT_GT(p.getUsername().length(), 3); //check the length of the username > 3
}