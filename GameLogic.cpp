//
// Created by davide on 19/09/19.
//

#include "GameLogic.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "cmath"

GameLogic::GameLogic() {
    deathBuffer.loadFromFile("Music/death-sound.wav");
    deathSound.setBuffer(deathBuffer);
}

void GameLogic::Update(Level *level, GameStates *state, Input *input, sf::RenderWindow *window, Hud *hud) {
    playerCollisionEnemy = -1;
    playerCollisionPowerUp = -1;
    bulletCollisionMap = -1;
    enemyCollisionBullet.x = -1;
    enemyCollisionBullet.y = -1;
    bool W, A, S, D;

    W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    level->player.update(W, A, S, D, &level->vector_of_platform);

    playerCollisionPowerUp = Collision::checkCollision(&level->vector_of_powerUp, &level->player);
    bulletCollisionMap = Collision::checkCollision(&level->vector_of_bullet, &level->vector_of_platform);
    enemyCollisionBullet = Collision::checkCollision(&level->vector_of_bullet, &level->vector_of_enemy);
    playerCollisionEnemy = Collision::checkCollision(&level->player, &level->vector_of_enemy);

    for(int i=0;i<level->vector_of_bullet.size();i++) {
        if (fabs(level->vector_of_bullet[i].spawnX-level->vector_of_bullet[i].x)>=level->vector_of_bullet[i].bulletLife||
                fabs(level->vector_of_bullet[i].spawnY-level->vector_of_bullet[i].y)>=level->vector_of_bullet[i].bulletLife){
            level->vector_of_bullet.erase(level->vector_of_bullet.begin()+i);
            level->setTextures();
        }
    }
    //-----Vari casi di esecuzione a seconda delle collisioni avvenute---//
    if (bulletCollisionMap >= 0) {
        level->vector_of_bullet.erase(level->vector_of_bullet.begin() + bulletCollisionMap);
        level->setTextures();
    }
    if (playerCollisionPowerUp >= 0) {
        if(level->vector_of_powerUp[playerCollisionPowerUp].type == powerUpBullet) level->player.setIsPowerBullet(true);
        if(level->vector_of_powerUp[playerCollisionPowerUp].type == powerUpSpeed) level->player.setMoveSpeed(level->player.getMoveSpeed() * moveSpeedMux);
        level->vector_of_powerUp.erase(level->vector_of_powerUp.begin() + playerCollisionPowerUp);
        potionUsed++;
        level->setTextures();
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
            deathSound.play();
        }
        level->setTextures();
    }
    for(int i = 0; i < level->vector_of_enemy.size();i++){
        level->vector_of_enemy[i].aggroUpdate(&(level->player), &(level->clock), &(level->vector_of_platform));
    }
    if(level->player.y >= level->vector_of_platform[level->vector_of_platform.size()-1].y) level->player.HP = 0;
    if (level->player.HP <= 0) {
        level->reset = true;
        deathcounter++;
    }
    if (*input == Input::Escape) {
        (*state) = GameStates::Pause;
    }
    if((*level).vector_of_enemy.empty()){
        (*state) = GameStates ::Level_next;
    }
    *input = Input::Null;
    if((*state)==GameStates::Level) {
        level->camera.setCenter(level->player.x,-25);
    }
    achievementNotifier.update(&level->clock, window, enemyKilled, potionUsed, deathcounter,&level->camera);
    hud->update(window, level);
}


