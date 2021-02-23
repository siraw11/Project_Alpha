//
// Created by matteo on 22/02/21.
//

#include <iostream>
#include "Camera.h"

Camera::Camera() {
    reset(sf::FloatRect(position.x, position.y, 1920, 1080));
    setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

}

void Camera::update(const Hero& hero, const Alpha::GameDataRef& _data) {
    position.x = hero.getPosition().x + 20 - (_data->window.getSize().x / 2.0);
    position.y = hero.getPosition().y + 20 - (_data->window.getSize().y / 2.0);

    if (position.x < 0)
        position.x = 0;
    if (position.y < 0)
        position.y = 0;

    reset(sf::FloatRect(position.x, position.y, 3840, 2160));
    _data->window.setView(*this);
}

void Camera::resetCamera(const Alpha::GameDataRef& _data) {
    position.x = 0;
    position.y = 0;

    reset(sf::FloatRect(position.x, position.y, 3840, 2160));
    _data->window.setView(*this);

}


Camera::~Camera() = default;
