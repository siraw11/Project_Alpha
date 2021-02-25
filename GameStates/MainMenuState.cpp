#include <utility>



#include <sstream>
#include "MainMenuState.hpp"
#include "../GameManager/DEFINITIONS.hpp"
#include "GameState.hpp"
#include "SelectClassState.h"
#include "GameOverState.hpp"

#include <iostream>
#include <ieee754.h>

namespace Alpha
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(std::move(data))
	{
    std::cout<<"main menu"<<std::endl;
	}

	void MainMenuState::Init()
	{
	    this->_background.setTexture(this->_data->assets.GetTexture("Background"));
        this->_selectClass.setTexture(this->_data->assets.GetTexture("Select Class"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));
        this->_selectClass.setScale(0.5,0.5);

        this->_selectClass.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_selectClass.getGlobalBounds().width / 2), ((int)(this->_data->window.getSize().y/ 2)) - (this->_selectClass.getGlobalBounds().height / 2));
        this->_title.setPosition((this->_data->window.getSize().x/ 2.0) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.5);

        //this->_background.setScale(sf::Vector2f(GAME_BACKGROUND_SCALE,GAME_BACKGROUND_SCALE));
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

		else if (this->_data->input.IsSpriteClicked(this->_selectClass, sf::Mouse::Left, this->_data->window))
            {
                // Switch To Select Class State

                this->_data->machine.AddState(StateRef(new SelectClassState(_data)), true);
                std::cout<<"rimpiazza main menu"<<std::endl;

            }
		}

	}

	void MainMenuState::Update()
	{

	}

	void MainMenuState::Draw()
	{


		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_playButton);
        this->_data->window.draw(this->_selectClass);
		this->_data->window.draw(this->_title);

	}

    MainMenuState::~MainMenuState() = default;
}