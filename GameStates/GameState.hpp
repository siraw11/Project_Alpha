#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"



namespace Alpha
{
	class GameState : public State
	{
	public:
		explicit GameState(GameDataRef data,PlayerType playerType);

		void Init() override;

		void HandleInput()override ;
		void Update() override;
		void Draw() override;

	private:
	    PlayerType playerType;

	    GameDataRef _data;

	    int gameState{};

		sf::Clock _clock;
	};
}