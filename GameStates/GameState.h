//
// Created by Luca Graziotti on 2019-10-30.
//

#ifndef MOTOCROSS2D_GAMESTATE_H
#define MOTOCROSS2D_GAMESTATE_H

#include <GameEngine.h>
#include "State.h"

class GameState : public State {
public:
    explicit GameState(bool init = false);

    void Init();

    void draw() override;

    void update() override;

    void handleInput(sf::Event event) override;

    virtual ~GameState();

private:
    bool init;
};

#endif //MOTOCROSS2D_GAMESTATE_H
