//
// Created by andreatadde on 23/10/19.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "GameCharacter.h"

#include "Context.h"
#include "Hero.h"
#include "SFML/Graphics.hpp"


class Context;
class Enemy : public GameCharacter {
public:
    Enemy();
    Context* context;
    int HP = 2;
    int damage = 1;
    sf::Vector2f range;
    sf::Time lastAttackTime = sf::seconds(0);
    sf::Time attackReload = sf::seconds(2);
public:
    void aggroManager(Hero* player, sf::Clock* clock);
};


#endif //GAME_ENEMY_H
