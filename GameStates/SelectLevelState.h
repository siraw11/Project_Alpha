//
// Created by Luca Graziotti on 09/11/2019.
//

#ifndef MOTOCROSS2D_SELECTLEVELSTATE_H
#define MOTOCROSS2D_SELECTLEVELSTATE_H


#include "State.h"

class SelectLevelState : public State {
private:


    void update() override;

    void draw() override;

    void handleInput(sf::Event event) override;

    std::list<int> lockedLevelsIndexes;

    std::vector<MenuOption *> loadLevelsOptions();

    Menu *menu;

public:
    SelectLevelState();

    virtual ~SelectLevelState();

};


#endif //MOTOCROSS2D_SELECTLEVELSTATE_H
