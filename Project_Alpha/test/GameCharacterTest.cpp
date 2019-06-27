//
// Created by matteo on 27/06/19.
//

#include "gtest/gtest.h"
#include "../GameCharacter.h"

TEST(GameCharacter, GameCharacterConstructo){
    GameCharacter g(1, 2, 3);
    ASSERT_EQ(g.getLife(), 1);
    ASSERT_EQ(g.getStrength(), 2);
    ASSERT_EQ(g.getSpeed(), 3);
}