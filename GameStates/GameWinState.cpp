#include <utility>


#include <sstream>
#include "GameOverState.hpp"
#include "../GameManager/DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "SelectClassState.h"

#include <iostream>
#include "GameWinState.h"

#include <iostream>
#include <SFML/Window/Event.hpp>

namespace Alpha
{
    GameWinState::GameWinState(GameDataRef data) : _data(std::move(data))
    {
        std::cout<<"GameOverState"<<std::endl;
    }

    void GameWinState::Init()
    {


        this->_background.setTexture(this->_data->assets.GetTexture("GameWinBackground"));
        this->_retryButton.setTexture(this->_data->assets.GetTexture("RetryButton"));
        this->_exitButton.setTexture(this->_data->assets.GetTexture("ExitButton"));


        this->_retryButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_retryButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 3) - (this->_retryButton.getGlobalBounds().height / 2));
        this->_exitButton.setPosition((this->_data->window.getSize().x / 2.0) - (this->_exitButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 3.0 * 2.0) - (this->_exitButton.getLocalBounds().height / 2.0));

        this->_background.setScale(sf::Vector2f(GAME_ENDING_BACKGROUND_SCALE,GAME_ENDING_BACKGROUND_SCALE));
    }

    void GameWinState:: HandleInput()
    {
        sf::Event event{};

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }

            if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
            {
                // Switch To Main Menu State By Replacing The Game Over State
                this->_data->machine.AddState(StateRef(new SelectClassState(_data)), true);

            }

            if (this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
            {
                // Switch To Main Menu State By Replacing The Game Over State
                this->_data->window.close();

            }
        }
    }

    void GameWinState::Update()
    {

    }

    void GameWinState::Draw()
    {

        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_retryButton);
        this->_data->window.draw(this->_exitButton);


    }

    GameWinState::~GameWinState() = default;
}