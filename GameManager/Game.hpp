#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "../GameStates/StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "DEFINITIONS.hpp"

namespace Alpha
{
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        explicit Game( const std::string& title);

    private:
        

        GameDataRef _data = std::make_shared<GameData>();//si usa nei vari state per accedere ai vari pezzi di game data

        void Run();//fa iniziare il gioco
        void Load();
    };
}