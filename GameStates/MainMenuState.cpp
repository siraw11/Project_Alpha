

#include <sstream>
#include "MainMenuState.hpp"
#include "../GameManager/DEFINITIONS.hpp"
#include "GameState.hpp"
#include "SelectClassState.h"

#include <iostream>
#include <ieee754.h>

namespace Alpha
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play_Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Select Class", SELECT_CLASS);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play_Button"));
        this->_selectClass.setTexture(this->_data->assets.GetTexture("Select Class"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

		this->_playButton.setPosition((SCREEN_WIDTH/ 2.0) - (this->_playButton.getGlobalBounds().width / 2), ((int)(SCREEN_HEIGHT / 3)) - (this->_playButton.getGlobalBounds().height / 3));
		this->_selectClass.setPosition((SCREEN_WIDTH/ 2.0) - (this->_selectClass.getGlobalBounds().width / 2), ((int)(SCREEN_HEIGHT / 2)) - (this->_selectClass.getGlobalBounds().height / 2));
		this->_title.setPosition((SCREEN_WIDTH/ 2.0) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.5);
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Game State
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		else if (this->_data->input.IsSpriteClicked(this->_selectClass, sf::Mouse::Left, this->_data->window))
            {
                // Switch To Select Class State
                this->_data->machine.AddState(StateRef(new SelectClassState(_data)), true);
            }
		}

	}

	void MainMenuState::Update()
	{

	}

	void MainMenuState::Draw()
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
        this->_data->window.draw(this->_selectClass);
		this->_data->window.draw(this->_title);
		this->_data->window.display();
	}
}