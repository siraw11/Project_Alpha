//
// Created by Magna on 2019-06-06.
//

#include "gtest/gtest.h"
#include "../Map.h"

TEST(Map, DefaultConstraction){
    Map m;
    ASSERT_EQ(false,m.getIsUnlocked()); //check if the Map is unlocked
}
