#include <utility>

#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "SelectClassState.h"
#include "../GameManager/DEFINITIONS.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "../Hero.h"
#include "../PlayerType.h"
#include "../Weapon.h"
#include "../Boss.h"
#include <iostream>
#include "sstream"
#include "../Hud.h"


namespace Alpha {
    GameState::GameState(GameDataRef data,Hero* hero) : _data(std::move(data)), hero(hero) {

        std::cout<<"game state"<<std::endl;
    }


    void GameState::Init() {
        gameStatus = GameStatus::isPlaying;
        //map sprite
        level.setTexture();
        //View variable
        this->_data->window.setFramerateLimit(60);
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
                //hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector );
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {//left
                hero->walkingDirection = 1;
                hero->isMoving = true;
                // hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {//down
                hero->walkingDirection = 2;
                hero->isMoving = true;
                //hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {//right
                hero->walkingDirection = 3;
                hero->isMoving = true;
                //hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
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
            if (boss->dead) {
                gameStatus = GameStatus::isWin;
            }
        }
        if (gameStatus == GameStatus::isGameOver){
            this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
            camera.resetCamera(_data);
            std::cout << "rimpiazza game state" << std::endl;
        }

        if(gameStatus == GameStatus::isWin){
            this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
            camera.resetCamera(_data);
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