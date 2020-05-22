#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include "SFML/Graphics.hpp"

namespace Alpha
{
    class InputManager
    {
    public:
        InputManager() = default;
        ~InputManager() = default;

        bool IsSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window);

        //sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}