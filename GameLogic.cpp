//
// Created by davide on 19/09/19.
//

#include "GameLogic.h"

GameLogic::GameLogic(std::vector<Enemy> *enemy, std::vector<Bullet> *bullet, std::vector<Platform> *platform,
                     Hero *player, std::vector<PowerUp> *powerUp) {
    bool W, A, S, D;
    W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    player->update(W, A, S, D);
    Collision::checkCollision(platform, player);
    Collision::checkCollision(powerUp, player);
    Collision::checkCollision(bullet, platform);
    Collision::checkCollision(bullet, enemy);
}

