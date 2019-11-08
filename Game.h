//
// Created by Luca Graziotti on 04/11/2019.
//

#ifndef MOTOCROSS2D_GAME_H
#define MOTOCROSS2D_GAME_H

#include <SFML/Graphics.hpp>
#include <GameStates/StateMachine.h>
#include "GameEngine.h"

struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
    std::shared_ptr<GameEngine> engine;
};
typedef std::shared_ptr<GameData> GameDataRef;


class Game {
public:
    static GameDataRef gameData;

    Game();

private:
    static void Run();
};


#endif //MOTOCROSS2D_GAME_H
