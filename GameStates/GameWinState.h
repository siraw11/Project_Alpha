#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"

namespace Alpha
{
    class GameWinState : public State
    {
    public:
        explicit GameWinState(GameDataRef data);
        ~GameWinState();

        void Init() override;

        void HandleInput()override;
        void Update() override;
        void Draw() override;

    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _retryButton;
        sf::Sprite _exitButton;
        sf::Sprite _WinTitle;

    };
}