//
// Created by Luca Graziotti on 04/11/2019.
//

#ifndef MOTOCROSS2D_GAME_H
#define MOTOCROSS2D_GAME_H

#include <SFML/Graphics.hpp>
#include <GameStates/StateMachine.h>
#include "ResourceManager/ResourceManager.h"
#include "GameEngine.h"
#include "Match.h"

struct GameData {
    StateMachine machine;
    sf::RenderWindow window;
    std::shared_ptr<GameEngine> engine;
    ResourceManager resources;


    std::unique_ptr<Match> match;
    std::unique_ptr<Player> player;
    std::map<std::string, std::shared_ptr<Map>> levels;
    std::map<std::string, std::shared_ptr<Bike>> bikes;
};
typedef std::shared_ptr<GameData> GameDataRef;


class Game {
public:
    static GameDataRef gameData;

    static void Run();
    Game();
};


#endif //MOTOCROSS2D_GAME_H
