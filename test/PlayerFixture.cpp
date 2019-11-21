//
// Created by Magna on 2019-06-03.
//
#include "gtest/gtest.h"
#include "../Player.h"

class PlayerSuite : public ::testing::Test {
protected:
    Player p;

    virtual void SetUp() {
        p.setUsername("Player");
        p.addTotalCoin(500);
    }
};

TEST_F(PlayerSuite, TestCoin) {
    p.removeTotalCoin(100);
    p.addTotalCoin((100));
    ASSERT_EQ(p.getTotalCoin(), 500);
}