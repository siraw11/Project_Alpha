//
// Created by matteo on 07/10/19.
//

#ifndef PROJECT_ALPHA_PROJECTILE_H
#define PROJECT_ALPHA_PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "PlayerType.h"


class Projectile : public sf::Sprite{

public:
    explicit Projectile(PlayerType type);
    int attackSpeed=20;
    int direction;//right=2,down=0,left=1,up=3
    int counterAttack=0;
    void update();
};

#endif //PROJECT_ALPHA_PROJECTILE_H
