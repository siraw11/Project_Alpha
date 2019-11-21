//
// Created by Luca Graziotti on 21/11/2019.
//

#include <Game.h>
#include "gtest/gtest.h"
#include "GameEngine.h"

class GameEngineFixture : public ::testing::Test {
protected:
    std::shared_ptr<GameEngine> e;

    virtual void SetUp() {
        Game();//inizializzo e carico le risorse necessarie per le mappe e i livelli
        Game::gameData->match->setMap(Game::gameData->levels.at("lv1"));
        Game::gameData->match->setBike(Game::gameData->bikes.at("b1"));
        Game::gameData->engine = std::make_shared<GameEngine>();
        e = Game::gameData->engine;
    }
};


TEST_F(GameEngineFixture, TestPause) {
    //testo condizione di pre-pausa
    e->setPause(false);
    ASSERT_GT(e->getGravity().y, 0.1);
    ASSERT_GT(e->getFramerate(), 20);
    ASSERT_EQ(e->getTimeStep(), 1.0f / 60.0f);
    ASSERT_EQ(e->getVelocityIterations(), 3);
    ASSERT_EQ(e->getPositionIterations(), 6);
    float prePausePosX = e->getBikePosition().posX;
    float prePausePosY = e->getBikePosition().posY;

    //testo condizione di pausa
    e->setPause(true);
    ASSERT_GT(e->getGravity().y, 0.1);
    ASSERT_GT(e->getFramerate(), 20);
    ASSERT_EQ(e->getTimeStep(), 0);
    ASSERT_EQ(e->getVelocityIterations(), 0);
    ASSERT_EQ(e->getPositionIterations(), 0);

    //testo condizione post-pausa
    e->setPause(false);
    ASSERT_GT(e->getGravity().y, 0.1);
    ASSERT_GT(e->getFramerate(), 20);
    ASSERT_EQ(e->getTimeStep(), 1.0f / 60.0f);
    ASSERT_EQ(e->getVelocityIterations(), 3);
    ASSERT_EQ(e->getPositionIterations(), 6);
    float postPausePosX = e->getBikePosition().posX;
    float postPausePosY = e->getBikePosition().posY;


    ASSERT_EQ(prePausePosX, postPausePosX);
    ASSERT_EQ(prePausePosY, postPausePosY);
}


TEST_F(GameEngineFixture, TestMovement) {
    float prePosX = e->getBikePosition().posX;

    int i = 60;
    while (i > 1) {
        e->move();
        i--;
    }

    float postPosX = e->getBikePosition().posX;

    ASSERT_GT(postPosX, prePosX);
}
