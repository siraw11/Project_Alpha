#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"

namespace Alpha
{
	class MainMenuState : public State
	{
	public:
		explicit MainMenuState(GameDataRef data);
        ~MainMenuState();

		void Init() override;

		void HandleInput() override;
		void Update() override;
		void Draw() override;

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _playButton;


		sf::Sprite _selectClass;

		sf::Sprite _title;
	};
}