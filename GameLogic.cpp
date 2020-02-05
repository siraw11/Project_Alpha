//
// Created by davide on 19/09/19.
//

#include "GameLogic.h"
#include <iostream>
#include "cmath"
#include "Collision.h"
#include "StateMachine/State_Main.h"
#include "StateMachine/State_Death.h"
#include "StateMachine/State_NextLevel.h"
#include "StateMachine/State_Pause.h"
#include "StateMachine/State_End.h"

GameLogic::GameLogic() {
    heroDeathBuffer.loadFromFile("Music/heroDeath.wav");
    enemyDeathBuffer.loadFromFile("Music/enemyDeath.wav");
    heroDeathSound.setBuffer(heroDeathBuffer);
    enemyDeathSound.setBuffer(enemyDeathBuffer);
}

void GameLogic::Update(Level *level, StateManager *state, Input input, sf::RenderWindow *window, Hud *hud, int nLevel, int maxLevel) {
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
        powerUpEffect(&level->player,&level->vector_of_powerUp);
        level->setTextures();
    }
    if (enemyCollisionBullet.x >= 0 && enemyCollisionBullet.y >= 0) {
        enemyDamageCalculator(&level->vector_of_enemy,&level->vector_of_bullet);
        level->setTextures();
    }
    for(int i = 0; i < level->vector_of_enemy.size();i++){
        level->vector_of_enemy[i].aggroUpdate(&level->player, level->clock.getElapsedTime(), &level->vector_of_platform);
    }
    if(level->player.y >= level->vector_of_platform[level->vector_of_platform.size()-1].y) level->player.HP = 0;
    if (level->player.HP <= 0) {
        heroDeathSound.play();
        state->setState(new State_Death(state));
        deathCounter++;
    }
    if (input == Input::Escape) {
        state->setState(new State_Pause(state));
    }
    if((*level).vector_of_enemy.empty()){
        if (nLevel >= maxLevel - 1) {
            state->setState(new State_End(state));
        }
        else {
            state->setState(new State_NextLevel(state));
        }
    }
    level->camera.setCenter(level->player.x, 0);
    achievementNotifier.update(&level->clock, window, enemyKilled, potionUsed, deathCounter, &level->camera);
    hud->update(window, level);

}

void GameLogic::enemyDamageCalculator(std::vector<Enemy> *enemy, std::vector<Bullet> *bullet) {
    bullet->erase(bullet->begin() + enemyCollisionBullet.x);
    (*enemy)[enemyCollisionBullet.y].HP = (*enemy)[enemyCollisionBullet.y].HP - (*bullet)[enemyCollisionBullet.x].damage;

    if ((*enemy)[enemyCollisionBullet.y].HP <= 0) {
        enemy->erase(enemy->begin() + enemyCollisionBullet.y);
        enemyKilled++;
        enemyDeathSound.play();
    }
}

void GameLogic::powerUpEffect(Hero *hero, std::vector<PowerUp> *powerUp) {
    if((*powerUp)[playerCollisionPowerUp].type == powerUpBullet) hero->setIsPowerBullet(true);
    if((*powerUp)[playerCollisionPowerUp].type == powerUpSpeed) hero->setMoveSpeed(hero->getMoveSpeed() * moveSpeedMux);
    powerUp->erase(powerUp->begin() + playerCollisionPowerUp);
    potionUsed++;
}