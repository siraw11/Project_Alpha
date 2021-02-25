//
// Created by matteo on 19/03/20.
//
#pragma once

#ifndef PROGETTO_PROVA_GAMECHARACTER_H
#define PROGETTO_PROVA_GAMECHARACTER_H


#include <SFML/Graphics.hpp>
#include "GameManager/Game.hpp"





class GameCharacter:public sf::RectangleShape {

public:
//constructor, destructor
    GameCharacter(int hp, int s, int sp);
    ~GameCharacter() override;

//getters
    int getLife() const;
    int getStrength() const;
    int getSpeed() const;

//setters
    void setLife(int life);
    void setStrength(int strength);
    void setSpeed(int speed);

//funciton
    void takeDamage(int damage);



protected:
    int strength;
    int speed;
    int life;
};



#endif //PROGETTO_PROVA_GAMECHARACTER_H
