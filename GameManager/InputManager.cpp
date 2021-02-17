
#include "InputManager.hpp"

namespace Alpha
{
    bool InputManager::IsSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

            if (playButtonRect.contains(sf::Mouse::getPosition(window)))
            {
                return true;
            }
        }

        return false;
    }


}