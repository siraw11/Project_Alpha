#include "Collision.h"
#include <math.h>

void Collision::checkCollision(std::vector<Platform> *platform, GameCharacter* gameCharacter) {

    float movementStopper = 0.f;
    float movementCheck = 0.f;

    // Checking the collision on the x axis
    gameCharacter->x += gameCharacter->velocity.x * gameCharacter->getMoveSpeed();
    for (int i = 0; i < platform->size(); i++) {
        if (gameCharacter->x + gameCharacter->width > (*platform)[i].hitLeft && gameCharacter->x < (*platform)[i].hitRight &&
            gameCharacter->y<(*platform)[i].hitBottom
                      && gameCharacter->y + gameCharacter->height>(*platform)[i].hitTop) {

            if (gameCharacter->velocity.x > movementCheck) {
                // Moving right so I'm hitting the left border of the platform
                gameCharacter->x = (*platform)[i].hitLeft - gameCharacter->width;
                gameCharacter->velocity.x = movementStopper;
            }
            if (gameCharacter->velocity.x < movementCheck) {
                // Moving left so I'm hitting the right border of the platform
                gameCharacter->x = (*platform)[i].hitRight;
                gameCharacter->velocity.x = movementStopper;
            }
        }
    }

    // Checking the collision on the y axis
    gameCharacter->isOnGround = false;
    gameCharacter->y += gameCharacter->velocity.y * gameCharacter->getMoveSpeed();

    for (int i = 0; i < platform->size(); i++) {
        if (gameCharacter->x + gameCharacter->width > (*platform)[i].hitLeft &&
            gameCharacter->x < (*platform)[i].hitRight &&
            gameCharacter->y<(*platform)[i].hitBottom
                             && gameCharacter->y + gameCharacter->height>(*platform)[i].hitTop) {
            if (gameCharacter->velocity.y > movementCheck) {
                // Falling so I'm hitting the top border of the platform, I'm grounded
                gameCharacter->y = (*platform)[i].hitTop - gameCharacter->height;
                gameCharacter->velocity.y = movementStopper;
                gameCharacter->isOnGround = true;
            }
            if (gameCharacter->velocity.y < movementCheck) {
                // Jumping so I'm hitting the bottom border of the platform
                gameCharacter->y = (*platform)[i].hitBottom;
                gameCharacter->velocity.y = movementStopper;
            }
        }
    }
}

int Collision::checkCollision(std::vector<PowerUp> *powerUp, Hero *player) {
    int collisionCheck = -1;
    for (int i = 0; i < powerUp->size(); i++) {
        if (player->rectShape.getGlobalBounds().intersects((*powerUp)[i].rectShape.getGlobalBounds())) {
            collisionCheck = i;
        }
    }
    return collisionCheck;
}

sf::Vector2i Collision::checkCollision(std::vector<Bullet> *bullet, std::vector<Enemy> *enemy) {
    sf::Vector2i collisionCheck;
    collisionCheck.x = -1;
    collisionCheck.y = -1;
    for (int i = 0; i < bullet->size(); i++) {
        (*bullet)[i].fire();
        if ((fabs((*bullet)[i].rectShape.getPosition().x - (*bullet)[i].spawnX)) <= (*bullet)[i].bulletLife &&
            (fabs((*bullet)[i].rectShape.getPosition().y - (*bullet)[i].spawnY)) <= (*bullet)[i].bulletLife) {
            for (int j = 0; j < enemy->size(); j++) {

                if ((*bullet)[i].rectShape.getGlobalBounds().intersects((*enemy)[j].rectShape.getGlobalBounds())) {
                    collisionCheck.x = i;
                    collisionCheck.y = j;
                }
            }
        }
    }
    return collisionCheck;
}

int Collision::checkCollision(std::vector<Bullet> *bullet, std::vector<Platform> *platform) {
    int collisionCheck = -1;
    for (int i = 0; i < bullet->size(); i++) {
        (*bullet)[i].fire();
            for (int j = 0; j < platform->size(); j++) {
                if ((*bullet)[i].rectShape.getGlobalBounds().intersects((*platform)[j].rectShape.getGlobalBounds())) {
                    collisionCheck = i;
                }
            }
    }
    return collisionCheck;
}