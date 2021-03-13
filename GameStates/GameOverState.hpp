#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
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
		GameDataRef data;

        sf::Sprite _background;
        sf::Sprite _lostTitle;
		sf::Sprite _retryButton;
		sf::Sprite _exitButton;

		sf::Sound click;
		sf::Sound youLose;

	};
}