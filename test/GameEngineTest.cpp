//
// Created by Luca Graziotti on 21/11/2019.
//

#include <Game.h>
#include "gtest/gtest.h"
#include "../GameEngine.h"

TEST(GameEngine, DefaultConstructor) {
    std::shared_ptr<GameEngine> e = std::make_shared<GameEngine>();
    ASSERT_GT(e->getGravity().y, 0.1);
    ASSERT_GT(e->getFramerate(), 20);
    ASSERT_EQ(e->getTimeStep(), 1.0f / 60.0f);
    ASSERT_EQ(e->getVelocityIterations(), 3);
    ASSERT_EQ(e->getPositionIterations(), 6);
}