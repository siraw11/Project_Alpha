#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "../GameManager/DEFINITIONS.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "../map.h"
#include "../Hero.h"
#include "../PlayerType.h"
#include "../CharacterFactory.h"
#include "../Weapon.h"
#include "../Boss.h"
#include <iostream>



namespace Alpha {
    GameState::GameState(GameDataRef data,PlayerType playertype) : _data(data) {
        playerType=playertype;

    }


    void GameState::Init() {
        gameState = STATE_PLAYING;
    }

    void GameState::HandleInput() {
        sf::Event event{};

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


    void GameState::Draw() {
        srand(time(nullptr));

        map level;

        CharacterFactory factory;

        std::unique_ptr<Hero> hero =factory.createCharacter(playerType);

        auto heroWeapon = new Weapon(1);
        hero->setWeapon(heroWeapon);

        std::unique_ptr<Boss> boss=std::unique_ptr<Boss>(new Boss(1, 1, 10));


        ///View variable
        sf::View view;
        this->_data->window.setFramerateLimit(60);
        view.reset(sf::FloatRect(0, 0, 1920.0, 1080.0));
        view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
        sf::Vector2f position(0, 0);

        //map sprite
        level.setTexture();

        while (this->_data->window.isOpen())
        {
            sf::Event event;
            while (this->_data->window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    this->_data->window.close();
                if (event.type == sf::Event::Resized) {
                    sf::View temp = this->_data->window.getView();
                    temp.setSize(this->_data->window.getSize().x,this->_data->window.getSize().y);
                    this->_data->window.setView(temp);
                }
            }
            ///hero movement
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){///up
                hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector );
                hero->walkingDirection=0;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){///left
                hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
                hero->walkingDirection=1;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){///down
                hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
                hero->walkingDirection=2;
            }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){///right
                hero->heroMovement( level.tile_vector, level.enemy_vector, level.chest_vector);
                hero->walkingDirection=3;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){///attack
                hero->counterAttack=1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){///open chest
                hero->openChest(&level.chest_vector, &level.tile_vector);
            }


            ///update level events
            level.update(hero, boss);

            ///camera settings
            position.x = hero->getPosition().x + 20 - (1920.0 / 2);
            position.y = hero->getPosition().y + 20 - (1080.0 / 2);

            if (position.x < 0)
                position.x = 0;
            if (position.y < 0)
                position.y = 0;

            view.reset(sf::FloatRect(position.x, position.y, 3840, 2160));

            this->_data->window.setView(view);
            this->_data->window.setFramerateLimit(60);

            //UI Elements
            this->_data->assets.LoadTexture("Heart", HEART_UI);
            this->_heart.setTexture(this->_data->assets.GetTexture("Heart"));
            this->_heart.setScale(3,3);
            _heart.setPosition(hero->getPosition().x,hero->getPosition().y-30 );

            if(playerType==PlayerType::ARCHER){
                this->_data->assets.LoadTexture("Arrow", ARROW_UI);
                this->_arrow_1.setTexture(this->_data->assets.GetTexture("Arrow"));
                this->_arrow_1.setScale(3,3);
                _arrow_1.setPosition(hero->getPosition().x+80,hero->getPosition().y-30 );

            }

            else if (playerType==PlayerType::MAGE){
                this->_data->assets.LoadTexture("Mana", MANA_UI);
                this->_mana.setTexture(this->_data->assets.GetTexture("Mana"));
                this->_mana.setScale(3,3);
                _mana.setPosition(hero->getPosition().x+80,hero->getPosition().y-30 );}

            else if (playerType==PlayerType::KNIGHT){
                this->_data->assets.LoadTexture("Armor", ARMOR_UI);
                this->_armor.setTexture(this->_data->assets.GetTexture("Armor"));
                this->_armor.setScale(2.7,2.7);
                _armor.setPosition(hero->getPosition().x+80,hero->getPosition().y-30 );}

            level.drawTile(_data);
            level.drawEnemy(_data);
            level.drawChest(_data);
            this->_data->window.draw(*hero);
            this->_data->window.draw(this->_heart);
            this->_data->window.draw(this->_arrow_1);
            this->_data->window.draw(this->_mana);
            this->_data->window.draw(this->_armor);
            this->_data->window.draw(*boss);
            level.drawProjectile(hero->projectile_vector,_data);
            level.drawProjectile(boss->projectile_vector,_data);

            this->_data->window.display();
        }
    }
}