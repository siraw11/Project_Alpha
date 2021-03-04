
#include <utility>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"
#include <iostream>
#include "GameWinState.h"


namespace Alpha {
    GameState::GameState(GameDataRef data,Hero* hero) : _data(std::move(data)), hero(hero) {


    }


    void GameState::Init() {
        gameStatus = GameStatus::isPlaying;
        //map sprite
        level.setTexture();
        level.initSound(_data);
        hero->initSound(_data);
        boss->initSound(_data);
        background.setBuffer(this->_data->assets.GetSound("Background"));

        //View variable
        this->_data->window.setFramerateLimit(60);
        background.play();
        background.setLoop(true);
    }

    void GameState::HandleInput() {

        sf::Event event{};

        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                this->_data->machine.AddState(StateRef(new GameOverState(_data)),true);
                std::cout << "rimpiazza game state" << std::endl;
            }
        }
    }

    void GameState::Update() {

        if (gameStatus == GameStatus::isPlaying) {
            //hero movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {//up
                hero->walkingDirection = 0;
                hero->isMoving = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//left
                hero->walkingDirection = 1;
                hero->isMoving = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//down
                hero->walkingDirection = 2;
                hero->isMoving = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//right
                hero->walkingDirection = 3;
                hero->isMoving = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {//attack
                hero->counterAttack = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {//open chest
                hero->openChest(&level.chest_vector, &level.tile_vector);
            }


            srand(time(nullptr));
            //update level events
            level.update(this->hero, this->boss);
            //Hud update
            hud->update(*hero);
            camera.update(*hero, _data);

            //Game Over
            if (hero->dead) {
            gameStatus = GameStatus::isGameOver;

            }
            //Win
            if (boss->dead) {
                gameStatus = GameStatus::isWin;
            }
        }
        //Switch to GameOverState
        if (gameStatus == GameStatus::isGameOver){
            this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
            camera.resetCamera(_data);
            background.pause();
        }
        //Switch to GameWinState
        if(gameStatus == GameStatus::isWin){
            this->_data->machine.AddState(StateRef(new GameWinState(_data)), true);
            camera.resetCamera(_data);
            background.pause();
        }

    }


    void GameState::Draw() {


        level.drawTile(_data);
        level.drawEnemy(_data);
        level.drawChest(_data);
        this->_data->window.draw(*hero);
        this->_data->window.draw(*boss);
        hud->draw(_data);
        level.drawProjectile(hero->projectile_vector,_data);
        level.drawProjectile(boss->projectile_vector,_data);

    }

    GameState::~GameState() = default;


}