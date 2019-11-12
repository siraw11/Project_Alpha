//
// Created by Luca Graziotti on 11/11/2019.
//

#ifndef MOTOCROSS2D_GAMELOSTSTATE_H
#define MOTOCROSS2D_GAMELOSTSTATE_H


#include "State.h"

class GameLostState : public State {
    void update() override;

    void draw() override;

    void handleInput(sf::Event) override;


};

#endif //MOTOCROSS2D_GAMELOSTSTATE_H
