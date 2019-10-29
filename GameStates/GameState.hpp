#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"


namespace Alpha
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:

	    GameDataRef _data;

	    int gameState;

		sf::Clock _clock;
	};
}