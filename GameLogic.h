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
#include <SFML/Audio.hpp>
#include "GameStates.h"
#include "Input.h"
#include "Level.h"
#include "AchievementNotifier.h"
#include "AchievementScreen.h"
#include "Hud.h"

//Classe per la gestione degli eventi fra oggetti + eventi in input, tasi premuti ecc..
class Level;

class Hud;
class GameLogic {
public:
    GameLogic();

    void Update(Level *level, GameStates *state, Input *input, sf::RenderWindow *window, Hud *hud);

    AchievementNotifier achievementNotifier;

private:
    int playerCollisionEnemy;
    sf::Vector2i enemyCollisionBullet;
    int playerCollisionPowerUp;
    int bulletCollisionMap;
    int enemyKilled = 0;
    int deathcounter = 0;
    int potionUsed = 0;
    int powerUpBullet = 6;
    int powerUpSpeed = 5;
    float moveSpeedMux = 1.2f;
    sf::SoundBuffer deathBuffer;
    sf::Sound deathSound;
};


#endif //GAME_GAMELOGIC_H
