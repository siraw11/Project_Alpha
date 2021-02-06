//
// Created by Luca Graziotti on 07/11/2019.
//

#ifndef MOTOCROSS2D_MENUPAUSESTATE_H
#define MOTOCROSS2D_MENUPAUSESTATE_H

#include <GameEngine.h>
#include <Menu.h>
#include "State.h"

class MenuPauseState : public State {
public:
    MenuPauseState();

    ~MenuPauseState();
private:
    Menu *menu;
    void update() override;

    void draw() override;

    void handleInput(sf::Event event) override;
};

#endif //MOTOCROSS2D_MENUPAUSESTATE_H
