//
// Created by Luca Graziotti on 03/11/2019.
//

#ifndef MOTOCROSS2D_MENUHOMESTATE_H
#define MOTOCROSS2D_MENUHOMESTATE_H

#include <Menu.h>
#include "State.h"

class MenuHomeState : public State {
private:
    void update() override;

    void draw() override;

    void handleInput(sf::Event) override;
};


#endif //MOTOCROSS2D_MENUHOMESTATE_H
