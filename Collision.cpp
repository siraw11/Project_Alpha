//
// Created by andreatadde on 17/09/19.
//
#include "Collision.h"
#include <math.h>

void Collision::checkCollision(std::vector<Platform> *platform, Hero *player) {

    // Checking the collision on the x axis
    player->x += player->velocity.x * player->getMoveSpeed();

    for (int i = 0; i < platform->size(); i++) {
        if (player->x + player->width > (*platform)[i].hitLeft && player->x < (*platform)[i].hitRight &&
            player->y<(*platform)[i].hitBottom
                      && player->y + player->height>(*platform)[i].hitTop) {

            if (player->velocity.x > 0) {
                // Moving right so I'm hitting the left border of the platform
                player->x = (*platform)[i].hitLeft - player->width;
                player->velocity.x = 0;
            }
            if (player->velocity.x < 0) {
                // Moving left so I'm hitting the right border of the platform
                player->x = (*platform)[i].hitRight;
                player->velocity.x = 0;
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
            if (player->velocity.y > 0) {
                // Falling so I'm hitting the top border of the platform, I'm grounded
                player->y = (*platform)[i].hitTop - player->height;
                player->velocity.y = 0;
                player->isOnGround = true;
            }
            if (player->velocity.y < 0) {
                // Jumping so I'm hitting the bottom border of the platform
                player->y = (*platform)[i].hitBottom;
                player->velocity.y = 0;
            }
        }
    }

    player->rectShape.setPosition(player->x, player->y); // Updating the position of the player
}

void Collision::checkCollision(std::vector<PowerUp> *powerUp, Hero *player) {
    for (int i = 0; i < powerUp->size(); i++) {
        if (player->x + player->width > (*powerUp)[i].hitLeft && player->x < (*powerUp)[i].hitRight &&
            player->y<(*powerUp)[i].hitBottom
                      && player->y + player->height>(*powerUp)[i].hitTop) {
            PowerUp::setPower(player, (*powerUp)[i].type);
            powerUp->erase(powerUp->begin() + i);
        }
    }
}

void Collision::checkCollision(std::vector<Bullet> *bullet, std::vector<Enemy> *enemy) {
    for (int i = 0; i < bullet->size(); i++) {
        (*bullet)[i].fire();
        if ((fabs((*bullet)[i].rectShape.getPosition().x - (*bullet)[i].spawnX)) <= (*bullet)[i].bulletLife &&
            (fabs((*bullet)[i].rectShape.getPosition().y - (*bullet)[i].spawnY)) <= (*bullet)[i].bulletLife) {
            for (int j = 0; j < enemy->size(); j++) {

                if ((*bullet)[i].rectShape.getGlobalBounds().intersects((*enemy)[j].rectShape.getGlobalBounds())) {
                    (*bullet).erase((*bullet).begin() + i);
                    (*enemy).erase((*enemy).begin() + j);
                }
            }
        } else (*bullet).erase((*bullet).begin() + i);
    }
}

void Collision::checkCollision(std::vector<Bullet> *bullet, std::vector<Platform> *platform) {
    for (int i = 0; i < bullet->size(); i++) {
        (*bullet)[i].fire();
        if ((fabs((*bullet)[i].rectShape.getPosition().x - (*bullet)[i].spawnX)) <= (*bullet)[i].bulletLife &&
            (fabs((*bullet)[i].rectShape.getPosition().y - (*bullet)[i].spawnY)) <= (*bullet)[i].bulletLife) {
            for (int j = 0; j < platform->size(); j++) {
                if ((*bullet)[i].rectShape.getGlobalBounds().intersects((*platform)[j].rectShape.getGlobalBounds())) {
                    (*bullet).erase((*bullet).begin() + i);
                }
            }
        } else (*bullet).erase((*bullet).begin() + i);
    }
}