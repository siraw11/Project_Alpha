#include <utility>



#include "MainMenuState.hpp"
#include "SelectClassState.h"
#include <iostream>


namespace Alpha
{
	MainMenuState::MainMenuState(GameDataRef data) : data(std::move(data))
	{

	}

	void MainMenuState::Init()
	{
	    this->_background.setTexture(this->data->assets.GetTexture("Background"));
        this->_selectClass.setTexture(this->data->assets.GetTexture("Select Class"));
		this->_title.setTexture(this->data->assets.GetTexture("Game Title"));
        this->_selectClass.setScale(0.5,0.5);

        this->_selectClass.setPosition((this->data->window.getSize().x/ 2.0) - (this->_selectClass.getGlobalBounds().width / 2), ((int)(this->data->window.getSize().y/ 2)) - (this->_selectClass.getGlobalBounds().height / 2));
        this->_title.setPosition((this->data->window.getSize().x/ 2.0) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.5);

        click.setBuffer(this->data->assets.GetSound("Click"));
	}


	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->data->window.close();
			}

		else if (this->data->input.IsSpriteClicked(this->_selectClass, sf::Mouse::Left, this->data->window))
            {
		        click.play();
                // Switch To Select Class State
                this->data->machine.AddState(StateRef(new SelectClassState(data)), true);


            }
		}

	}

	void MainMenuState::Update()
	{

	}

	void MainMenuState::Draw()
	{


		this->data->window.draw(this->_background);
        this->data->window.draw(this->_selectClass);
		this->data->window.draw(this->_title);

	}

    MainMenuState::~MainMenuState() = default;
}