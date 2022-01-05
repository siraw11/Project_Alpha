//
// Created by matteo on 09/03/21.
//

#ifndef PROJECT_ALPHA_BADGE_H
#define PROJECT_ALPHA_BADGE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include "GameManager/DEFINITIONS.hpp"
#include "GameManager/Game.hpp"
#include "Hero.h"
#include "Camera.h"

class Badge {
public:
    Badge();

    void init(const Alpha::GameDataRef& data);
    void update(const Alpha::GameDataRef& data, Camera& camera);
    void drawBadge(const Alpha::GameDataRef& data);

    bool start = false;
    BadgeType type;
private:

    void setText();
    sf::Sprite trophy;
    sf::Vector2f position;
    sf::Time duration = sf::seconds(4);
    sf::Clock clock;
    sf::Text text;

};


#endif //PROJECT_ALPHA_BADGE_H
