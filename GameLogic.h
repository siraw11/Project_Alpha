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
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "GameStates.h"
#include "Input.h"
#include "Level.h"

//Classe per la gestione degli eventi fra oggetti + eventi in input, tasi premuti ecc..
class Level;

class GameLogic {
public:
    GameLogic();

    void Update(Level *level, GameStates *state, Input input, sf::RenderWindow *window);

private:
    int playerCollisionEnemy;
    sf::Vector2i enemyCollisionBullet;
    int playerCollisionPowerUp;
    int bulletCollisionMap;
};


#endif //GAME_GAMELOGIC_H
