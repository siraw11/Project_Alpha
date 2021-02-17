#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"

namespace Alpha
{
	class SplashState : public State
	{
	public:
		explicit SplashState(GameDataRef data);

		void Init() override;

		void HandleInput() override;
		void Update() override;
		void Draw() override;

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::Sprite _background;
	};
}