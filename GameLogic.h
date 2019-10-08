//
// Created by davide on 19/09/19.
//

#ifndef GAME_GAMELOGIC_H
#define GAME_GAMELOGIC_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"
#include "Platform.h"
#include "PowerUp.h"
#include "Hero.h"
#include "Collision.h"
#include "Level.h"

//Classe per la gestione degli eventi fra oggetti

class GameLogic {
public:
    GameLogic(std::vector<Enemy> *enemy, std::vector<Bullet> *bullet, std::vector<Platform> *platform,
              Hero *player, std::vector<PowerUp> *powerUp);
};


#endif //GAME_GAMELOGIC_H
