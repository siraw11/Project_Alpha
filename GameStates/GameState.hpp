#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"
#include "../PlayerType.h"


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

        sf::Sprite _heart;

        sf::Sprite _mana;

        sf::Sprite _armor;

        sf::Sprite _arrow_1;

        GameDataRef _data;

        int gameState{};

        sf::Clock _clock;
    };
}