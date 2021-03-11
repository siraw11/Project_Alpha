//
// Created by matteo on 09/03/21.
//

#include <iostream>
#include "Badge.h"
#include "Camera.h"


Badge::Badge() {

    setSize(sf::Vector2f(120,60));
    setFillColor(sf::Color::Blue);
    setScale(BADGE_SCALE, BADGE_SCALE);
}

void Badge::init(const Alpha::GameDataRef& _data) {
    position.x = _data->window.getSize().x - BADGE_WIDTH*BADGE_SCALE;
    position.y = 0;
    setPosition(position);
    text.setFont(_data->assets.GetFont("font"));
    text.setScale(TEXT_SCALE,TEXT_SCALE);

}

void Badge::update(const Alpha::GameDataRef& _data, Camera& camera) {
   setPosition(camera.getPosition().x + _data->window.getSize().x - BADGE_WIDTH*BADGE_SCALE, camera.getPosition().y);
   text.setPosition(camera.getPosition().x +_data->window.getSize().x - TEXT_BADGE_WIDTH*TEXT_SCALE, camera.getPosition().y + TEXT_BADGE_HEIGHT*BADGE_SCALE);
   if(start)
        setText();
}

void Badge::drawBadge(const Alpha::GameDataRef& _data) {
    if(start){
         clock.restart();
         start = false;
    }
    if(clock.getElapsedTime() < duration){
        _data->window.draw(*this);
        _data->window.draw(text);
    }

}

void Badge::setText() {
    switch(type){
        case BadgeType::walker:{
            text.setString("first 10 steps");
            break;
        }
        case BadgeType::killer:{
            text.setString("10 kills");
            break;
        }
    }
}
