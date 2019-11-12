//
// Created by Luca Graziotti on 11/11/2019.
//

#ifndef MOTOCROSS2D_GAMEWINSTATE_H
#define MOTOCROSS2D_GAMEWINSTATE_H

#include "StateMachine.h"
#include "State.h"
#include <iostream>
#include <Menu.h>

class GameWinState : public State {
public:
    GameWinState();

    virtual ~GameWinState();

private:
    void update() override;

    void draw() override;

    void handleInput(sf::Event event) override;

    Menu *menu{};

    std::vector<MenuOption *> loadMenu();
};


#endif //MOTOCROSS2D_GAMEWINSTATE_H
