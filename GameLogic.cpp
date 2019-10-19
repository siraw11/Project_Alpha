//
// Created by davide on 19/09/19.
//

#include "GameLogic.h"
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Time lastHitTime = sf::seconds(0);

GameLogic::GameLogic() = default;

void GameLogic::Update(std::vector<Enemy> *enemy, std::vector<Bullet> *bullet, std::vector<Platform> *platform,
                       Hero *player, std::vector<PowerUp> *powerUp, sf::Clock *clock, GameStates *state,
                       Input input, sf::RenderWindow *window) {

    const sf::Time invulnerabilityTime = sf::seconds(2);
    bool W, A, S, D;

    W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    player->update(W, A, S, D);

    Collision::checkCollision(platform, player);
    playerCollisionPowerUp = Collision::checkCollision(powerUp, player);
    bulletCollisionMap = Collision::checkCollision(bullet, platform);
    enemyCollisionBullet = Collision::checkCollision(bullet, enemy);
    playerCollisionEnemy = Collision::checkCollision(player, enemy);
    //-----Vari casi di esecuzione a seconda delle collisioni avvenute---//
    if (bulletCollisionMap >= 0) {
        (*bullet).erase((*bullet).begin() + bulletCollisionMap);
    }
    if (playerCollisionPowerUp >= 0) {
        PowerUp::setPower(player, (*powerUp)[playerCollisionPowerUp].type);
        powerUp->erase(powerUp->begin() + playerCollisionPowerUp);
    }
    if (enemyCollisionBullet.x >= 0 && enemyCollisionBullet.y >= 0) {
        (*bullet).erase((*bullet).begin() + enemyCollisionBullet.x);
        (*enemy)[enemyCollisionBullet.y].HP =
                (*enemy)[enemyCollisionBullet.y].HP - (*bullet)[enemyCollisionBullet.x].damage;
        std::cout << "Enemy HP: " << (*enemy)[enemyCollisionBullet.y].HP << std::endl;
        if ((*enemy)[enemyCollisionBullet.y].HP <= 0) {
            (*enemy).erase((*enemy).begin() + enemyCollisionBullet.y);
        }
    }
    if (playerCollisionEnemy >= 0 && clock->getElapsedTime() - lastHitTime >= invulnerabilityTime && player->HP > 0) {
        player->HP = player->HP - (*enemy)[playerCollisionEnemy].damage;
        std::cout << "Player HP: " << player->HP << std::endl;
        lastHitTime = clock->getElapsedTime();
    }

    if (player->HP <= 0) {
        player->HP = player->initialHP;
        (*state) = GameStates::Main_menu;
    }
    if (input == Input::Escape) {
        (*state) = GameStates::Pause;
    }
    //TODO sistemare tutti i distruttori
    //perchè sennò alla morte o al ritorno la menu principale in gioco non si resetta
}

