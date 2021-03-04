#include <utility>



#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "SelectClassState.h"

#include <iostream>

namespace Alpha
{
	GameOverState::GameOverState(GameDataRef data) : _data(std::move(data))
	{

	}

	void GameOverState::Init()
	{


        this->_background.setTexture(this->_data->assets.GetTexture("GameOverBackground"));
		this->_retryButton.setTexture(this->_data->assets.GetTexture("RetryButton"));
		this->_exitButton.setTexture(this->_data->assets.GetTexture("ExitButton"));
        this->_lostTitle.setTexture(this->_data->assets.GetTexture("Lost Title"));
		this->_exitButton.setScale(0.5,0.5);
        this->_retryButton.setScale(0.5,0.5);

        this->_retryButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_retryButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 3) - (this->_retryButton.getGlobalBounds().height / 2));
        this->_exitButton.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_exitButton.getGlobalBounds().width / 2), (this->_data->window.getSize().y/ 2) - (this->_exitButton.getGlobalBounds().height / 2));
        this->_lostTitle.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_lostTitle.getGlobalBounds().width / 2), this->_lostTitle.getGlobalBounds().height * 0.5);

        click.setBuffer(this->_data->assets.GetSound("Click"));
        youLose.setBuffer(this->_data->assets.GetSound("Lose"));
        youLose.play();
	}

	void GameOverState::HandleInput()
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
			    this->_data->window.close();
			}
		}
	}

	void GameOverState::Update()
	{

	}

	void GameOverState::Draw()
	{
	    this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_retryButton);
		this->_data->window.draw(this->_exitButton);
        this->_data->window.draw(this->_lostTitle);
	}

    GameOverState::~GameOverState() = default;
}