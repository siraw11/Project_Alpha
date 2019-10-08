//
// Created by andreatadde on 17/09/19.
//

#include "Bullet.h"

Bullet::Bullet(bool isPoweredUp, sf::Vector2f shootingDirectionInput) {

    if (isPoweredUp) { // if isPoweredUp true => Triple bullet max distance
        bulletLife = bulletLife * bulletLifeMultiplier;
    }
    shootingDirection = shootingDirectionInput;
    if (shootingDirection.y == 1)
        this->rectShape.rotate(spriteDirectionDown); // Based on the direction the shape is rotated
    if (shootingDirection.y == -1) this->rectShape.rotate(spriteDirectionUp);
    if (shootingDirection.x == -1) this->rectShape.rotate(spriteDirectionLeft);

}

void Bullet::fire() {
    this->rectShape.move(shootingDirection.x * bulletSpeed, shootingDirection.y * bulletSpeed);
    x = this->rectShape.getPosition().x;
    y = this->rectShape.getPosition().y;
}
