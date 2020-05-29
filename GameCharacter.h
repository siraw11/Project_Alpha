//
// Created by matteo on 19/03/20.
//

#ifndef PROGETTO_PROVA_GAMECHARACTER_H
#define PROGETTO_PROVA_GAMECHARACTER_H


#include <SFML/Graphics.hpp>
#include "Tile.h"


class map;


class GameCharacter:public sf::RectangleShape {

public:
    GameCharacter(int hp, int s, int sp);
    virtual ~GameCharacter();

    int getLife() const;

    void setLife(int life);

    int getStrength() const;

    void setStrength(int strength);

    int getSpeed() const;

    void setSpeed(int speed);

    bool collisionLinker(const std::vector<Tile>& tile_vector, int x, int y);

    void takeDamage(int damage);

protected:
    int strength;
    int speed;
    int life;
};



#endif //PROGETTO_PROVA_GAMECHARACTER_H
