//
// Created by Luca Graziotti on 2019-10-30.
//
#include "GameState.h"
#include "Game.h"
#include "GameEngine.h"

void GameState::Init() {
    this->update();
}


void GameState::update() {
    if (this->init) {
        std::cout << "INIT" << std::endl;
        Game::gameData->engine = std::make_shared<GameEngine>();
        Game::gameData->engine->run();
        this->init = false;
    } else {
        Game::gameData->engine->setPause(false);
        Game::gameData->engine->run();
    }
}

void GameState::draw() {}

GameState::~GameState() = default;

void GameState::handleInput(sf::Event) {}

GameState::GameState(bool r) : init(r) {}
