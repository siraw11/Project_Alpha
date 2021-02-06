//
// Created by Luca Graziotti on 18/11/2019.
//

#ifndef MOTOCROSS2D_SHOPSTATE_H
#define MOTOCROSS2D_SHOPSTATE_H


#include <Menu.h>
#include "State.h"

class ShopState : public State {
private:


    void update() override;

    void draw() override;

    void handleInput(sf::Event event) override;

    std::vector<MenuOption *> loadLevelsOptions();

    Menu *menu;

public:
    ShopState();

    virtual ~ShopState();

};

#endif //MOTOCROSS2D_SHOPSTATE_H
