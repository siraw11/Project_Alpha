#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"
#include "../PlayerType.h"
#include "../map.h"
#include "../CharacterFactory.h"
#include "../Hud.h"
#include "../Camera.h"


namespace Alpha
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data,Hero *hero);
        ~GameState();

        void Init() override;

        void HandleInput()override ;
        void Update() override;
        void Draw() override;


    private:
        GameStatus gameStatus;

        PlayerType playerType;

        GameDataRef _data;

        sf::Clock _clock;

        map level;
        std::unique_ptr<Hero> hero = nullptr;
        std::unique_ptr<Boss> boss = std::unique_ptr<Boss>(new Boss(1, 1, 10));

        //Hud
        Hud* hud= new Hud(this->hero, this->_data);
        Camera camera;
        sf::Vector2f positionView;

    };
}