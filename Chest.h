//
// Created by matteo on 21/08/20.
//
#pragma once

#ifndef PROJECT_ALPHA_CHEST_H
#define PROJECT_ALPHA_CHEST_H



#include <SFML/Graphics.hpp>
#include "GameManager/DEFINITIONS.hpp"
#include "Object.h"


class Hero;

class Chest : public sf::RectangleShape{
public:
///constructor, destructor
    explicit Chest();
    ~Chest() override;

///function
    void init(int counter);
    void open(Hero* hero);
    void openingAnimation();
    void setClose(bool close);

///attributes
    bool close;
    int counterOpening=0;


private:
///attributes
    std::vector<Object*> elements;

    int posX{};
    int posY{};

};











#endif //PROJECT_ALPHA_CHEST_H
