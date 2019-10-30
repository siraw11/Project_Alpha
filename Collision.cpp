
#include "Collision.h"
#include <math.h>
#include <iostream>

void Collision::checkCollision(std::vector<Platform> *platform, Hero *player) {

    int movementStopper = 0;
    int movementCheck = 0;

    // Checking the collision on the x axis
    player->x += player->velocity.x * player->getMoveSpeed();
    for (int i = 0; i < platform->size(); i++) {
        if (player->x + player->width > (*platform)[i].hitLeft && player->x < (*platform)[i].hitRight &&
            player->y<(*platform)[i].hitBottom
                      && player->y + player->height>(*platform)[i].hitTop) {

            if (player->velocity.x > movementCheck) {
                // Moving right so I'm hitting the left border of the platform
                player->x = (*platform)[i].hitLeft - player->width;
                player->velocity.x = movementStopper;
            }
            if (player->velocity.x < movementCheck) {
                // Moving left so I'm hitting the right border of the platform
                player->x = (*platform)[i].hitRight;
                player->velocity.x = movementStopper;
            }
        }
    }

    // Checking the collision on the y axis
    player->isOnGround = false;
    player->y += player->velocity.y * player->getMoveSpeed();

    for (int i = 0; i < platform->size(); i++) {
        if (player->x + player->width > (*platform)[i].hitLeft && player->x < (*platform)[i].hitRight &&
            player->y<(*platform)[i].hitBottom
                      && player->y + player->height>(*platform)[i].hitTop) {
            if (player->velocity.y > movementCheck) {
                // Falling so I'm hitting the top border of the platform, I'm grounded
                player->y = (*platform)[i].hitTop - player->height;
                player->velocity.y = movementStopper;
                player->isOnGround = true;
            }
            if (player->velocity.y < movementCheck) {
                // Jumping so I'm hitting the bottom border of the platform
                player->y = (*platform)[i].hitBottom;
                player->velocity.y = movementStopper;
            }
        }
    }

    player->rectShape.setPosition(player->x, player->y); // Updating the position of the player
}

int Collision::checkCollision(std::vector<PowerUp> *powerUp, Hero *player) {
    int collisioncheck = -1;
    for (int i = 0; i < powerUp->size(); i++) {
        if (player->x + player->width > (*powerUp)[i].hitLeft && player->x < (*powerUp)[i].hitRight &&
            player->y<(*powerUp)[i].hitBottom
                      && player->y + player->height>(*powerUp)[i].hitTop) {
            collisioncheck = i;
        }
    }
    return collisioncheck;
}

sf::Vector2i Collision::checkCollision(std::vector<Bullet> *bullet, std::vector<Enemy> *enemy) {
    sf::Vector2i collisioncheck;
    collisioncheck.x = -1;
    collisioncheck.y = -1;
    for (int i = 0; i < bullet->size(); i++) {
        (*bullet)[i].fire();
        if ((fabs((*bullet)[i].rectShape.getPosition().x - (*bullet)[i].spawnX)) <= (*bullet)[i].bulletLife &&
            (fabs((*bullet)[i].rectShape.getPosition().y - (*bullet)[i].spawnY)) <= (*bullet)[i].bulletLife) {
            for (int j = 0; j < enemy->size(); j++) {

                if ((*bullet)[i].rectShape.getGlobalBounds().intersects((*enemy)[j].rectShape.getGlobalBounds())) {
                    collisioncheck.x = i;
                    collisioncheck.y = j;
                }
            }
        }
    }
    return collisioncheck;
}

int Collision::checkCollision(std::vector<Bullet> *bullet, std::vector<Platform> *platform) {
    int collisioncheck = -1;
    for (int i = 0; i < bullet->size(); i++) {
        (*bullet)[i].fire();
            for (int j = 0; j < platform->size(); j++) {
                if ((*bullet)[i].rectShape.getGlobalBounds().intersects((*platform)[j].rectShape.getGlobalBounds())) {
                    collisioncheck = i;
                }
            }
    }
    return collisioncheck;
}

int Collision::checkCollision(Hero *hero, std::vector<Enemy> *enemy) {
    int collisioncheck = -1;
    for (int i = 0; i < enemy->size(); i++) {

        if ((*enemy)[i].rectShape.getGlobalBounds().intersects(hero->rectShape.getGlobalBounds())) {
            collisioncheck = i;
        }
    }
    return collisioncheck;
}
