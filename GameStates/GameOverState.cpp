#include <utility>



#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "SelectClassState.h"

#include <iostream>

namespace Alpha
{
	GameOverState::GameOverState(GameDataRef data) : data(std::move(data))
	{

	}

	void GameOverState::Init()
	{


        this->_background.setTexture(this->data->assets.GetTexture("GameOverBackground"));
		this->_retryButton.setTexture(this->data->assets.GetTexture("RetryButton"));
		this->_exitButton.setTexture(this->data->assets.GetTexture("ExitButton"));
        this->_lostTitle.setTexture(this->data->assets.GetTexture("Lost Title"));
		this->_exitButton.setScale(0.5,0.5);
        this->_retryButton.setScale(0.5,0.5);

        this->_retryButton.setPosition((this->data->window.getSize().x/ 2.0) - (this->_retryButton.getGlobalBounds().width / 2), (this->data->window.getSize().y/ 3) - (this->_retryButton.getGlobalBounds().height / 2));
        this->_exitButton.setPosition((this->data->window.getSize().x/ 2.0) - (this->_exitButton.getGlobalBounds().width / 2), (this->data->window.getSize().y/ 2) - (this->_exitButton.getGlobalBounds().height / 2));
        this->_lostTitle.setPosition((this->data->window.getSize().x/ 2.0) - (this->_lostTitle.getGlobalBounds().width / 2), this->_lostTitle.getGlobalBounds().height * 0.5);

        click.setBuffer(this->data->assets.GetSound("Click"));
        youLose.setBuffer(this->data->assets.GetSound("Lose"));
        youLose.play();
	}

	void GameOverState::HandleInput()
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
			    this->data->window.close();
			}
		}
	}

	void GameOverState::Update()
	{

	}

	void GameOverState::Draw()
	{
	    this->data->window.draw(this->_background);
		this->data->window.draw(this->_retryButton);
		this->data->window.draw(this->_exitButton);
        this->data->window.draw(this->_lostTitle);
	}

    GameOverState::~GameOverState() = default;
}