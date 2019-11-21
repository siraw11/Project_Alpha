//
// Created by Magna on 2019-06-03.
//

#include "gtest/gtest.h"
#include "../Player.h"

TEST(Player, DefaultConstructor) {
    Player p;
    ASSERT_EQ(0, p.getTotalCoin());
    ASSERT_NE("", p.getUsername());
}
