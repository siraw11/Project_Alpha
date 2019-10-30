#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"

namespace Alpha
{
	class PauseState : public State
	{
	public:
		explicit PauseState(GameDataRef data);

		void Init() override;

		void HandleInput() override;
		void Update() override;
		void Draw() override;

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

	};
}