#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"

namespace Alpha
{
	class GameOverState : public State
	{
	public:
		explicit GameOverState(GameDataRef data);

		void Init() override;

		void HandleInput()override;
		void Update() override;
		void Draw() override;

	private:
		GameDataRef _data;

		sf::Sprite _retryButton;
		sf::Sprite _homeButton;

	};
}