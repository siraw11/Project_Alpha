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

class Badge : public sf::RectangleShape{
public:
    Badge();

    void init(const Alpha::GameDataRef& _data);
    void update(const Alpha::GameDataRef& _data, Camera& camera);
    void drawBadge(const Alpha::GameDataRef& _data);

    bool start = false;
    BadgeType type;
private:

    void setText();
    sf::Vector2f position;
    sf::Time duration = sf::seconds( 3);
    sf::Clock clock;
    sf::Text text;

};


#endif //PROJECT_ALPHA_BADGE_H
