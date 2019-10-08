//
// Created by andreatadde on 17/09/19.
//

#include "Bullet.h"

Bullet::Bullet(bool isPoweredUp, sf::Vector2f shootingDirectionInput) {
    bulletSpeed = 2.f;

    if (isPoweredUp) { // if isPoweredUp true => Triple bullet max distance
        bulletLife = 100.f * 3.f;
    } else bulletLife = 100.f;

    shootingDirection = shootingDirectionInput;
    if (shootingDirection.y == 1) this->rectShape.rotate(90); // Based on the direction the shape is rotated
    if (shootingDirection.y == -1) this->rectShape.rotate(-90);
    if (shootingDirection.x == -1) this->rectShape.rotate(180);

}

void Bullet::fire() {
    this->rectShape.move(shootingDirection.x * bulletSpeed, shootingDirection.y * bulletSpeed);
    x = this->rectShape.getPosition().x;
    y = this->rectShape.getPosition().y;
}
