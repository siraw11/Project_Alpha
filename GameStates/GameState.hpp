#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "../GameManager/Game.hpp"
#include "../PlayerType.h"
#include "../map.h"
#include "../Hud.h"
#include "../Camera.h"
#include "../Hero.h"
#include "../Weapon.h"
#include "../Boss.h"
#include "../GameManager/DEFINITIONS.hpp"
#include "../WalkingAchievement.h"
#include "../Badge.h"
#include "../KillAchievement.h"


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

        map level;
        Hero* hero = nullptr;
        std::unique_ptr<Boss> boss = std::unique_ptr<Boss>(new Boss(20, 3, 10));

        //Hud
        Hud* hud= new Hud(hero, this->_data);
        Camera camera;

        sf::Sound background;

        WalkingAchievement* walkingAchievement = nullptr;
        KillAchievement* killAchievement = nullptr;
        Badge badge;

    };
}