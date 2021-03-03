//
// Created by matteo on 21/08/20.
//
#pragma once

#ifndef PROJECT_ALPHA_CHEST_H
#define PROJECT_ALPHA_CHEST_H



#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include "GameManager/DEFINITIONS.hpp"
#include "GameManager/Game.hpp"
#include "Object.h"


class Hero;

class Chest : public sf::RectangleShape{
public:
//constructor, destructor
    explicit Chest();
    ~Chest() override;

//function
    void init(int counter);
    void open(Hero* hero, std::vector<Tile>* tile_vector);
    void openingAnimation();
    void setClose(bool close);
    void initSound(const Alpha::GameDataRef &_data);

//attributes
    bool close;
    int counterOpening = 0;


private:
//attributes
    std::vector<Object*> elements;

    sf::Sound openingSound;

    int posX{};
    int posY{};

};











#endif //PROJECT_ALPHA_CHEST_H
