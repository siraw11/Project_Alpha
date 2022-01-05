#include <utility>



#include "GameOverState.hpp"
#include "SelectClassState.h"
#include <iostream>
#include "GameWinState.h"
#include <SFML/Window/Event.hpp>

namespace Alpha
{
    GameWinState::GameWinState(GameDataRef data) : data(std::move(data))
    {
        std::cout<<"GameOverState"<<std::endl;
    }

    void GameWinState::Init()
    {


        this->_background.setTexture(this->data->assets.GetTexture("GameWinBackground"));
        this->_retryButton.setTexture(this->data->assets.GetTexture("RetryButton"));
        this->_exitButton.setTexture(this->data->assets.GetTexture("ExitButton"));
        this->_winTitle.setTexture(this->data->assets.GetTexture("Win Title"));
        this->_exitButton.setScale(0.5,0.5);
        this->_retryButton.setScale(0.5,0.5);

        this->_retryButton.setPosition((this->data->window.getSize().x/ 2.0) - (this->_retryButton.getGlobalBounds().width / 2), (this->data->window.getSize().y/ 3) - (this->_retryButton.getGlobalBounds().height / 2));
        this->_exitButton.setPosition((this->data->window.getSize().x/ 2.0) - (this->_exitButton.getGlobalBounds().width / 2), (this->data->window.getSize().y/ 2) - (this->_exitButton.getGlobalBounds().height / 2));
        this->_winTitle.setPosition((this->data->window.getSize().x/ 2.0) - (this->_winTitle.getGlobalBounds().width / 2), this->_winTitle.getGlobalBounds().height * 0.5);

        click.setBuffer(this->data->assets.GetSound("Click"));
        youWin.setBuffer(this->data->assets.GetSound("Win"));
        youWin.play();
    }

    void GameWinState:: HandleInput()
    {
        sf::Event event{};

        while (this->data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->data->window.close();
            }

            if (this->data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->data->window))
            {
                click.play();
                // Switch To Main Menu State By Replacing The Game Over State
                this->data->machine.AddState(StateRef(new SelectClassState(data)), true);

            }

            if (this->data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->data->window))
            {
                click.play();
                // Switch To Main Menu State By Replacing The Game Over State
                this->data->window.close();

            }
        }
    }

    void GameWinState::Update()
    {

    }

    void GameWinState::Draw()
    {

        this->data->window.draw(this->_background);
        this->data->window.draw(this->_retryButton);
        this->data->window.draw(this->_exitButton);
        this->data->window.draw(this->_winTitle);



    }

    GameWinState::~GameWinState() = default;
}