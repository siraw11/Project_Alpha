#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"

namespace Alpha
{
    class SelectClassState : public State
    {
    public:
        SelectClassState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
       GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _archerButton;

        sf::Sprite _knightButton;

        sf::Sprite _mageButton;

        sf::Sprite _title;


    };
}