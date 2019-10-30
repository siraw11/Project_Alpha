

#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "../GameManager/DEFINITIONS.hpp"

#include <iostream>

namespace Alpha
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update()
	{
		if (this->_clock.getElapsedTime().asSeconds() >=SPLASH_STATE_SHOW_TIME)
		{
			// Switch To Main Menu
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw()

	{
        sf::View view;
        view.reset(sf::FloatRect(0, 0, 1920.0, 1080.0));
		this->_data->window.clear();

		this->_data->window.setView(view);

		this->_data->window.draw( this->_background );

		this->_data->window.display();
	}
}