//
// Created by andreatadde on 18/09/19.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter() {
    velocity.x = 0;
    velocity.y = 0;
}

float GameCharacter::getMoveSpeed() const {
    return moveSpeed;
}

void GameCharacter::setMoveSpeed(float moveSpeed) {
    GameCharacter::moveSpeed = moveSpeed;
}

void GameCharacter::setAnimation(const std::string &textureDir, unsigned int xFrames, unsigned int yFrames) {
    RectangleShape::setTexture(textureDir);
    // SetAnimation need a texture, number of frames and an update frequency
    animation.setAnimation(&rectTexture, sf::Vector2u(xFrames, yFrames), switch_time);
}

GameCharacter::~GameCharacter() = default;
