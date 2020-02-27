//
// Created by Magna on 2019-06-03.
//

#include "gtest/gtest.h"
#include "../Bike.h"

TEST(Bike, DefaultConstructor) {
    Bike b;
    ASSERT_EQ(0, b.getSpeed());
    ASSERT_EQ(0, b.getPrice());
    ASSERT_EQ(false, b.getIsUnlocked());
    ASSERT_NE("", b.getId());
    ASSERT_NE("", b.getTexture());
}
