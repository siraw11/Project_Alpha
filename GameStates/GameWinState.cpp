#include <utility>



#include "GameOverState.hpp"
#include "SelectClassState.h"
#include <iostream>
#include "GameWinState.h"
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
        this->_winTitle.setTexture(this->_data->assets.GetTexture("Win Title"));
        this->_exitButton.setScale(0.5,0.5);
        this->_retryButton.setScale(0.5,0.5);

        this->_retryButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_retryButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 3) - (this->_retryButton.getGlobalBounds().height / 2));
        this->_exitButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_exitButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 2) - (this->_exitButton.getGlobalBounds().height / 2));
        this->_winTitle.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_winTitle.getGlobalBounds().width / 2), this->_winTitle.getGlobalBounds().height * 0.5);

        click.setBuffer(this->_data->assets.GetSound("Click"));
        youWin.setBuffer(this->_data->assets.GetSound("Win"));
        youWin.play();
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
                click.play();
                // Switch To Main Menu State By Replacing The Game Over State
                this->_data->machine.AddState(StateRef(new SelectClassState(_data)), true);

            }

            if (this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
            {
                click.play();
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
        this->_data->window.draw(this->_winTitle);



    }

    GameWinState::~GameWinState() = default;
}