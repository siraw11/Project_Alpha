//
// Created by Luca Graziotti on 21/11/2019.
//

#include <Game.h>
#include <ResourceManager/LevelFactory.h>
#include <ResourceManager/BikeFactory.h>
#include <Coin.h>
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
    e->step();//calcolo il nuovo step

    //testo condizione post-pausa
    e->setPause(false);
    ASSERT_GT(e->getGravity().y, 0.1);
    ASSERT_GT(e->getFramerate(), 20);
    ASSERT_EQ(e->getTimeStep(), 1.0f / 60.0f);
    ASSERT_EQ(e->getVelocityIterations(), 3);
    ASSERT_EQ(e->getPositionIterations(), 6);
    float postPausePosX = e->getBikePosition().posX;
    float postPausePosY = e->getBikePosition().posY;

    //anche se effettuato lo step, essendo in stop la moto non si deve muovere
    ASSERT_EQ(prePausePosX, postPausePosX);
    ASSERT_EQ(prePausePosY, postPausePosY);
}


TEST_F(GameEngineFixture, TestMovement) {
    //controllo che si muova la moto
    float prePosX = e->getBikePosition().posX;

    int i = 60;
    while (i > 1) {
        e->step();
        i--;
    }

    float postPosX = e->getBikePosition().posX;

    ASSERT_GT(postPosX, prePosX);
}


TEST_F(GameEngineFixture, TestRespawn) {
    //controllo che il punto di respawn funzioni
    float respawnX = 10;
    Game::gameData->match->setLastCheckpoint({respawnX, 0});
    e->respawn();

    float postPosX = e->getBikePosition().posX;
    float postPosY = e->getBikePosition().posY;
    ASSERT_EQ(postPosX, respawnX);

    respawnX = 50;
    Game::gameData->match->setLastCheckpoint({respawnX, 0});
    e->respawn();

    postPosX = e->getBikePosition().posX;
    ASSERT_EQ(postPosX, respawnX);
}


TEST_F(GameEngineFixture, TestDeathAndCollision) {
    Game::gameData->levels.insert(std::make_pair("TestDeath", LevelFactory::getLevel("TestDeath")));
    Game::gameData->match->setMap(Game::gameData->levels.at("TestDeath"));

    ASSERT_EQ(Game::gameData->match->getLifes(), 3);

    bool isDead;
    do {
        Game::gameData->engine->bikeAccellerate();
        Game::gameData->engine->step();
        Game::gameData->engine->draw();

        isDead = Game::gameData->engine->checkDeath();
        Game::gameData->engine->checkCollisions();
        if (isDead) {
            break;
        }
    } while (Game::gameData->engine->getBikePosition().posX < 200);//200 la x massima nel qua
    auto firstCoin = dynamic_cast<Coin *>(Game::gameData->match->getMap()->getMapItems().front());


    ASSERT_EQ(isDead, true);
    ASSERT_EQ(Game::gameData->match->getLifes(), 2);
    ASSERT_EQ(firstCoin->isTaken(), true);
    ASSERT_EQ(Game::gameData->match->getMoney(), firstCoin->getValue());
    Game::gameData->levels.erase("TestDeath");
}
