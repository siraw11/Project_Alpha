#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"

namespace Alpha
{
    class SelectClassState : public State
    {
    public:
        explicit SelectClassState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update() override;
        void Draw() override;

    private:
       GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _archerButton;

        sf::Sprite _knightButton;

        sf::Sprite _mageButton;

        sf::Sprite _title;


    };
}