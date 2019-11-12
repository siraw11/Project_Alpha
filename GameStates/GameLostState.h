//
// Created by Luca Graziotti on 11/11/2019.
//

#ifndef MOTOCROSS2D_GAMELOSTSTATE_H
#define MOTOCROSS2D_GAMELOSTSTATE_H


#include "State.h"
#include "Menu.h"

class GameLostState : public State {
public:
    GameLostState();

private:
    void update() override;

    void draw() override;

    void handleInput(sf::Event) override;

    Menu *menu{};

    bool canRetry = true;

    std::vector<MenuOption *> loadMenu();

};

#endif //MOTOCROSS2D_GAMELOSTSTATE_H
