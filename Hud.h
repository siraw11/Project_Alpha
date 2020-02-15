//
// Created by davide on 02/11/19.
//

#ifndef GAME_HUD_H
#define GAME_HUD_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "Level.h"

class Hud {
public:
    Hud();

    void update(sf::RenderWindow *window, Level *level);

private:
    std::vector<sf::RectangleShape> vector_of_hearts;
    std::vector<sf::RectangleShape> vector_of_enemyHp;
    sf::Texture playerHpTex;
    sf::Texture enemyHpTex;
    sf::Vector2f offset;
    sf::Vector2f sizeHeart;
    sf::Text hp;
    sf::Font font;
    sf::Text invulnerabilityTime;
    unsigned int textSize = 30;
};


#endif //GAME_HUD_H
