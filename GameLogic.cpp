//
// Created by davide on 19/09/19.
//

#include "GameLogic.h"
#include <iostream>
#include <SFML/Graphics.hpp>

GameLogic::GameLogic() = default;

void GameLogic::Update(Level *level, GameStates *state, Input *input, sf::RenderWindow *window) {
    playerCollisionEnemy = -1;
    playerCollisionPowerUp = -1;
    bulletCollisionMap = -1;
    enemyCollisionBullet.x = -1;
    enemyCollisionBullet.y = -1;
    const sf::Time invulnerabilityTime = sf::seconds(2);
    bool W, A, S, D;

    W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    level->player.update(W, A, S, D);

    Collision::checkCollision(&level->vector_of_platform, &level->player);
    playerCollisionPowerUp = Collision::checkCollision(&level->vector_of_powerUp, &level->player);
    bulletCollisionMap = Collision::checkCollision(&level->vector_of_bullet, &level->vector_of_platform);
    enemyCollisionBullet = Collision::checkCollision(&level->vector_of_bullet, &level->vector_of_enemy);
    playerCollisionEnemy = Collision::checkCollision(&level->player, &level->vector_of_enemy);
    //-----Vari casi di esecuzione a seconda delle collisioni avvenute---//
    if (bulletCollisionMap >= 0) {
        level->vector_of_bullet.erase(level->vector_of_bullet.begin() + bulletCollisionMap);
    }
    if (playerCollisionPowerUp >= 0) {
        PowerUp::setPower(&level->player, level->vector_of_powerUp[playerCollisionPowerUp].type);
        level->vector_of_powerUp.erase(level->vector_of_powerUp.begin() + playerCollisionPowerUp);
        potionUsed++;
    }
    if (enemyCollisionBullet.x >= 0 && enemyCollisionBullet.y >= 0) {
        level->vector_of_bullet.erase(level->vector_of_bullet.begin() + enemyCollisionBullet.x);
        level->vector_of_enemy[enemyCollisionBullet.y].HP =
                level->vector_of_enemy[enemyCollisionBullet.y].HP -
                level->vector_of_bullet[enemyCollisionBullet.x].damage;
        std::cout << "Enemy HP: " << level->vector_of_enemy[enemyCollisionBullet.y].HP << std::endl;
        if (level->vector_of_enemy[enemyCollisionBullet.y].HP <= 0) {
            level->vector_of_enemy.erase(level->vector_of_enemy.begin() + enemyCollisionBullet.y);
            enemyKilled++;
        }
    }

    if (playerCollisionEnemy >= 0 && level->clock.getElapsedTime() - lastHitTime >= invulnerabilityTime &&
        level->player.HP > 0) {
        level->player.HP = level->player.HP - level->vector_of_enemy[playerCollisionEnemy].damage;
        std::cout << "Player HP: " << level->player.HP << std::endl;
        lastHitTime = level->clock.getElapsedTime();
    }

    if (level->player.HP <= 0) {
        level->reset = true;
        deathcounter++;
    }
    if (*input == Input::Escape) {
        (*state) = GameStates::Pause;
    }
    *input = Input::Null;
    achievementNotifier.update(&level->clock, window, enemyKilled, potionUsed, deathcounter);
}


