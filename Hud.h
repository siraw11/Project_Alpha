//
// Created by davide on 02/11/19.
//

#ifndef GAME_HUD_H
#define GAME_HUD_H

#include "SFML/Graphics.hpp"
#include "vector"

class Level;

class Hud {
public:
    Hud();

    void update(sf::RenderWindow *window, Level *level);

private:
    std::vector<sf::RectangleShape> vector_of_hearts;
    std::vector<sf::RectangleShape> vector_of_enemyhp;
    sf::Texture texture;
    sf::Texture texture2;
    sf::Vector2f offset;
    sf::Vector2f sizeHeart;
    sf::Text hp;
    sf::Font font;
    unsigned int textSize = 30;
    sf::Text invulnerabilityTime;
};


#endif //GAME_HUD_H
