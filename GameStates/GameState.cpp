#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "../GameManager/DEFINITIONS.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "../Map.h"
#include "../Projectile.h"
#include "../Hero.h"
#include "../Enemy.h"
#include "../Random.h"
#include "../PlayerType.h"

#include <iostream>
#include <fstream>

namespace Alpha {
    GameState::GameState(GameDataRef data) : _data(data) {

    }

    void GameState::Init() {
        gameState = STATE_PLAYING;
    }

    void GameState::HandleInput() {
        sf::Event event;

        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                // Switch To Pause State
                this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
            }

        }
    }

    void GameState::Update() {
        if (STATE_LOSE == gameState || STATE_WON == gameState) {
            if (this->_clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOWING_GAME_OVER) {

                // Switch To Game Over State

                this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
            }
        }
    }

    PlayerType playerType;

    void GameState::Draw() {

        int SCALE = 3;

        // Create matrix
        int level[10080] = {};//TODO: Dynamic allocation

        //Load map from Resources
        std::fstream fin("../Resources/Map/map.txt", std::fstream::in);
        char c;
        std::string tmp;
        int k = 0;
        while (fin >> std::noskipws >> c) {
            if (c != ',') {
                tmp += c;
            } else {
                level[k] = std::stoi(tmp);
                k++;
                tmp = "";
            }
        }
        fin.close();

        // Create the Map
        Map map;
        if (!map.load("../Resources/Map/map.png", sf::Vector2u(32, 32), level, 120, 84));
        map.setScale(sf::Vector2f(1.f * SCALE, 1.f * SCALE));

        //View variable
        sf::View view;
        view.reset(sf::FloatRect(0, 0, 3840.0, 2160.0));
        view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
        sf::Vector2f position(0, 0);


        //set hero
        Hero hero( 5, 2, 16, playerType);
        int counterWalking = 0;

        //vector of enemy
        std::vector<Enemy> enemyArray;

        //set enemy
        Enemy enemy(3, 1, 4, 0);

        //set projectile
        std::vector<Projectile> projectileArray;
        Projectile projectile(playerType);

        if(enemyArray.empty()){
            for (int i = 0; i <200 ; ++i) {
                enemy.spawnPosition=generateRandomPos(level);
                enemy.setPosition(enemy.spawnPosition);
                enemyArray.push_back(enemy);
            }
        }

        //animation variable
        int attackAnimation = 0;

        while (this->_data->window.isOpen()) {

            sf::Event event2{};
            while (this->_data->window.pollEvent(event2)) {
                if (event2.type == sf::Event::Closed)
                    this->_data->window.close();
                if (event2.type == sf::Event::Resized) {
                    sf::View temp = this->_data->window.getView();
                    temp.setSize(this->_data->window.getSize().x,this->_data->window.getSize().y);
                    this->_data->window.setView(temp);

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        // Switch To Pause State
                        this->_data->machine.AddState(StateRef(new PauseState(_data)), false);}
                }
            }

            //hero movement and collision
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                hero.direction = 1;
                if (projectile.counterAttack == 0)
                    hero.heroMovement(level);
                hero.setTextureRect(sf::IntRect(64 * counterWalking, 0, 64, 64));


            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                hero.direction = 2;
                //down movement
                if (projectile.counterAttack == 0)
                    hero.heroMovement(level);

                hero.setTextureRect(sf::IntRect(64 * counterWalking, 128, 64, 64));

            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                hero.direction = 3;
                //left movement
                if (projectile.counterAttack == 0)
                    hero.heroMovement(level);

                hero.setTextureRect(sf::IntRect(64 * counterWalking, 64, 64, 64));


            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                hero.direction = 4;
                // right movement
                if (projectile.counterAttack == 0)
                    hero.heroMovement(level);

                hero.setTextureRect(sf::IntRect(64 * counterWalking, 192, 64, 64));
            }

            //attack animation

            //right attack
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                attackAnimation = 7;
                projectile.direction = 2;
                projectile.counterAttack = 1;
            }//down attack
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                attackAnimation = 6;
                projectile.direction = 0;
                projectile.counterAttack = 1;
            }// left attack
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                attackAnimation = 5;
                projectile.direction = 1;
                projectile.counterAttack = 1;
            }// up attack
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                attackAnimation = 4;
                projectile.direction = 3;
                projectile.counterAttack = 1;
            }

            //camera settings
            position.x = hero.getPosition().x + 20 - (3840.0 / 2);
            position.y = hero.getPosition().y + 20 - (2160.0 / 2);

            if (position.x < 0)
                position.x = 0;
            if (position.y < 0)
                position.y = 0;

            view.reset(sf::FloatRect(position.x, position.y, 3840, 2160));

            projectile.counterAttack = hero.animation(projectile.counterAttack, attackAnimation);

            //fire projectile
            if ((projectile.counterAttack == 11) && (playerType != PlayerType::KNIGHT)) {
                projectile.projectileStart=hero.getPosition();
                projectile.setPosition(projectile.projectileStart);
                projectile.setTextureRect(sf::IntRect(0, 64 * projectile.direction, 64, 64));
                projectileArray.push_back(projectile);
                projectile.counterAttack = 0;
            } else if (projectile.counterAttack == 11) {
                projectile.counterAttack = 0;
            }

            //reset walking animation
            if (counterWalking == 8) {
                counterWalking = 0;
            } else {

                counterWalking++;
            }

            //projectile collision
            for(auto i=projectileArray.begin(); i!= projectileArray.end(); ++i){
                for(auto j=enemyArray.begin(); j!= enemyArray.end(); ++j){

                    if(i->controlCollision(level)){
                        projectileArray.erase(i);
                        i--;

                    }else if (std::abs(i->getPosition().x-i->projectileStart.x)>=640 || std::abs(i->getPosition().y-i->projectileStart.y)>=640){
                        projectileArray.erase(i);
                        i--;
                    }else if(i->getGlobalBounds().intersects(j->getGlobalBounds())){
                        hero.Attack(*j);
                        projectileArray.erase(i);
                        i--;
                    }
                }
            }
            //Draw on window

            this->_data->window.setView(view);

            this->_data->window.setFramerateLimit(30);

            this->_data->window.clear();


            this->_data->window.draw(map);

            this->_data->window.draw(hero);


            //pojectile draw
            for (auto & i : projectileArray) {
                i.update();
                this->_data->window.draw(i);
            }
            //draw enemy and movement
            for( auto i=enemyArray.begin(); i!=enemyArray.end(); ++i){
                i->movement(level);
                this->_data->window.draw(*i);

                if(i->getLife()<=0){
                    i->setTextureRect(sf::IntRect(64*i->counterDeath,64*8,64,64));
                    i->counterDeath++;
                    if(i->counterDeath==11){
                        enemyArray.erase(i);
                        i--;
                        i->counterDeath=0;
                    }
                }


            }
            this->_data->window.display();
        }
    }
}
