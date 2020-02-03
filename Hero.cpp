//
// Created by andreatadde on 18/09/19.
//

#include "Hero.h"
#include "Collision.h"

Hero::Hero() { //Setting dei parametri iniziali e texture
    setAnimation("textures/tux_from_linux.png", frame_x, frame_y);

    isPowerBullet = false;
    moveSpeed = 0.6f;
    jumpPower = 6.8f;
    gravityAcc = 0.15f;
    gravityMax = 1.8f;//ricaduta
    facingRight = true;
    row = 0;
}

void Hero::update(bool W, bool A, bool S, bool D, std::vector<Platform> *platform) {
    x = this->rectShape.getPosition().x;
    y = this->rectShape.getPosition().y;

    // Y movements
    if (W && isOnGround) {
        velocity.y = jumpPower * -1.f;
        row = 2;
    }
    if (!isOnGround) {
        velocity.y += gravityAcc;
        if (velocity.y > gravityMax) velocity.y = gravityMax;
    }

    // X movements
    if (A) {
        velocity.x = -1.f;
        facingRight = false;
        row = 1;
    }
    if (D) {
        velocity.x = 1.f;
        facingRight = true;
        row = 1;

    }
    if (!(A || D)) {
        velocity.x = 0.f;
        row = 0;
    }
    Collision::checkCollision(platform, this); // Managing the collisions with the map
    this->rectShape.setPosition(this->x, this->y); // Updating the position of the player
    // Updating the texture based on the animation
    animation.Update(row, delta_time, facingRight);
    rectShape.setTextureRect(animation.uvRect);
}

bool Hero::getIsPowerBullet() const {
    return isPowerBullet;
}

void Hero::setIsPowerBullet(bool isPowerBullet) {
    Hero::isPowerBullet = isPowerBullet;
}

Hero::~Hero() = default;


