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
        ~GameOverState();

		void Init() override;

		void HandleInput()override;
		void Update() override;
		void Draw() override;

	private:
		GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _LostTitle;
		sf::Sprite _retryButton;
		sf::Sprite _exitButton;

	};
}