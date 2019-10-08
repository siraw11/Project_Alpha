//
// Created by andreatadde on 29/09/19.
//

#include "Animation.h"

void Animation::setAnimation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;

    totalTime = 0.0f;
    currentImage.x = 0;
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation() {

}

void Animation::Update(int row, float deltaTime, bool facingRight) {
    currentImage.y = row; // Row identifies the type of animation
    totalTime += deltaTime;
    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= imageCount.x) currentImage.x = 0;
    }

    uvRect.top = currentImage.y * uvRect.height;

    if (facingRight) {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    } else {
        // If i'm not facing right i just flip the image
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}