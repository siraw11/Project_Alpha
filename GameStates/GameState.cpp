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
    GameState::GameState(GameDataRef data,Hero* hero) : _data(data), hero(hero) {


    }


    void GameState::Init() {
        gameState = STATE_PLAYING;

        //map sprite
        level.setTexture();
        //View variable
        this->_data->window.setFramerateLimit(60);
        view.reset(sf::FloatRect(0, 0, 1920.0, 1080.0));
        view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    }

    void GameState::HandleInput() {

        sf::Event event{};

        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }




        }
    }

    void GameState::Update() {


        //hero movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){//up
            hero->walkingDirection = 0;
            hero->isMoving = true;
            //hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector );
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){//left
            hero->walkingDirection = 1;
            hero->isMoving = true;
            // hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){//down
            hero->walkingDirection = 2;
            hero->isMoving = true;
            //hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){//right
            hero->walkingDirection = 3;
            hero->isMoving = true;
            //hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){//attack
            hero->counterAttack = 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){//open chest
            hero->openChest(&level.chest_vector, &level.tile_vector);
        }




            srand(time(nullptr));
            //update level events
            level.update(this->hero, this->boss);
            //Hud update
            hud->update(*hero);



            //camera settings
            positionView.x = hero->getPosition().x + 20 - (1920.0 / 2);
            positionView.y = hero->getPosition().y + 20 - (1080.0 / 2);

            if (positionView.x < 0)
                positionView.x = 0;
            if (positionView.y < 0)
                positionView.y = 0;

            view.reset(sf::FloatRect(positionView.x, positionView.y, 3840, 2160));

            this->_data->window.setView(view);
         //Game Over

        if (hero->dead){
            // Switch To GameOverState
            this->_data->machine.RemoveState();
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

        }
        if (boss->dead){
            // Switch To WinState

            this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
        }
    }


    void GameState::Draw() {
        //this->_data->window.setFramerateLimit(20);

        level.drawTile(_data);
        level.drawEnemy(_data);
        level.drawChest(_data);
        this->_data->window.draw(*hero);
        this->_data->window.draw(*boss);
        hud->draw(_data);
        level.drawProjectile(hero->projectile_vector,_data);
        level.drawProjectile(boss->projectile_vector,_data);
        this->_data->window.display();

    }



}