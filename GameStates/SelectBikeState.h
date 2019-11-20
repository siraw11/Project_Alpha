//
// Created by Luca Graziotti on 20/11/2019.
//

#ifndef MOTOCROSS2D_SELECTBIKESTATE_H
#define MOTOCROSS2D_SELECTBIKESTATE_H


#include <Menu.h>
#include "State.h"

class SelectBikeState : public State {
private:


    void update() override;

    void draw() override;

    void handleInput(sf::Event event) override;

    std::vector<MenuOption *> loadOptions();

    Menu *menu;

public:
    SelectBikeState();

    virtual ~SelectBikeState();

};


#endif //MOTOCROSS2D_SELECTBIKESTATE_H
