
#include <utility>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "GameOverState.hpp"
#include <iostream>
#include "GameWinState.h"



namespace Alpha {
    GameState::GameState(GameDataRef data,Hero* hero) : data(std::move(data)), hero(hero) {

    }


    void GameState::Init() {
        gameStatus = GameStatus::isPlaying;
        //map sprite
        level.setTexture();
        level.initSound(data);
        hero->initSound(data);
        boss->initSound(data);
        background.setBuffer(this->data->assets.GetSound("Background"));

        //View variable
        this->data->window.setFramerateLimit(60);
        background.play();
        background.setLoop(true);

        killAchievement = new KillAchievement(hero, &badge);
        walkingAchievement = new WalkingAchievement(hero, &badge);

        badge.init(data);
    }

    void GameState::HandleInput() {

        sf::Event event{};

        while (this->data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->data->window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                this->data->machine.AddState(StateRef(new GameOverState(data)),true);
               ;
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

            level.update(*this->hero, this->boss);
            //Hud update
            hud->update(*hero);
            camera.update(*hero, data);
            badge.update(data, camera);


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
            this->data->machine.AddState(StateRef(new GameOverState(data)), true);
            camera.resetCamera(data);
            background.pause();
        }
        //Switch to GameWinState
        if(gameStatus == GameStatus::isWin){
            this->data->machine.AddState(StateRef(new GameWinState(data)), true);
            camera.resetCamera(data);
            background.pause();
        }

    }


    void GameState::Draw() {


        level.drawTile(data);
        level.drawEnemy(data);
        level.drawChest(data);
        this->data->window.draw(*hero);
        this->data->window.draw(*boss);
        hud->draw(data);
        badge.drawBadge(data);
        level.drawProjectile(hero->projectile_vector,data);
        level.drawProjectile(boss->projectile_vector,data);

    }

    GameState::~GameState() = default;


}