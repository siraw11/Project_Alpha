//
// Created by Luca Graziotti on 2019-10-30.
//

#pragma once

#include <SFML/Graphics.hpp>

#ifndef MOTOCROSS2D_STATE_H
#define MOTOCROSS2D_STATE_H


class State {
public:
    virtual ~State() = default;

    virtual void update() = 0;

    virtual void draw() = 0;

    virtual void handleInput(sf::Event event) = 0;
};

#endif //MOTOCROSS2D_STATE_H
