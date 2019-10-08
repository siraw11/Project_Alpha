//
// Created by andreatadde on 29/09/19.
//

#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H


#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation() = default;

    void setAnimation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);

    ~Animation();

    void Update(int row, float deltaTime, bool facingRight);

    sf::IntRect uvRect; // Rectangle that resize the texture

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;
};


#endif //GAME_ANIMATION_H
