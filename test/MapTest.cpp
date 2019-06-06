//
// Created by Magna on 2019-06-06.
//

#include "gtest/gtest.h"
#include "../Map.h"

TEST(Map, DefaultConstraction){
    Map m;
    ASSERT_EQ(1,m.isUnlocked1()); //check if the Map is unlocked
}
