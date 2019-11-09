//
// Created by davide on 19/09/19.
//

#ifndef GAME_GAMELOGIC_H
#define GAME_GAMELOGIC_H

#include "Level.h"
#include "Input.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "AchievementNotifier.h"
#include "Hud.h"

//Classe per la gestione degli eventi fra oggetti + eventi in input, tasi premuti ecc..
class StateManager;
class GameLogic {
public:
    GameLogic();

    void Update(Level *level, StateManager *state, Input input, sf::RenderWindow *window, Hud *hud);

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
