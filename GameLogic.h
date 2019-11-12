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

    void enemyDamageCalculator(std::vector<Enemy>* enemy,std::vector<Bullet>* bullet);

    void powerUpEffect(Hero* hero,std::vector<PowerUp>* powerUp);
    AchievementNotifier achievementNotifier;
private:

    int enemyKilled = 0;
    int deathcounter = 0;
    int potionUsed = 0;
    int powerUpBullet = 6;
    int powerUpSpeed = 5;

    sf::SoundBuffer heroDeathBuffer;
    sf::SoundBuffer enemyDeathBuffer;
    sf::Sound heroDeathSound;
    sf::Sound enemyDeathSound;
public:
    float moveSpeedMux = 1.2f;
    int playerCollisionEnemy;
    sf::Vector2i enemyCollisionBullet;
    int playerCollisionPowerUp;
    int bulletCollisionMap;
};


#endif //GAME_GAMELOGIC_H
