//
// Created by matteo on 09/03/21.
//

#include <iostream>
#include "Badge.h"
#include "Camera.h"


Badge::Badge() {

}

void Badge::init(const Alpha::GameDataRef& data) {

    trophy.setTexture(data->assets.GetTexture("Trophy"));
    trophy.setPosition(3800,20);
    trophy.setScale(TROPHY_TEXTURE_SCALEX,TROPHY_TEXTURE_SCALEY);
    position.x = TEXT_POSX - BADGE_WIDTH*BADGE_SCALE;
    position.y = 0;
    text.setPosition(position);
    text.setFont(data->assets.GetFont("font"));
    text.setFillColor(sf::Color::Cyan);
    text.setScale(TEXT_SCALE,TEXT_SCALE);

}

void Badge::update(const Alpha::GameDataRef& data, Camera& camera) {

   text.setPosition(camera.getPosition().x +TEXT_POSX - TEXT_BADGE_WIDTH*TEXT_SCALE, camera.getPosition().y + TEXT_BADGE_HEIGHT*BADGE_SCALE);
   if(start)
        setText();
   trophy.setPosition(camera.getPosition().x +TROPHY_POSX - TEXT_BADGE_WIDTH*TEXT_SCALE, camera.getPosition().y + TROPHY_POSY*TROPHY_SCALE);
}

void Badge::drawBadge(const Alpha::GameDataRef& data) {
    if(start){
         clock.restart();
         start = false;
    }
    if(clock.getElapsedTime() < duration){

        data->window.draw(text);
        data->window.draw(trophy);

    }

}

void Badge::setText() {
    switch(type){
        case BadgeType::walker:{
            text.setString(" Adventurer : \nfirst 10 steps");
            break;
        }
        case BadgeType::killer:{
            text.setString("Killer : \n5 kills");
            break;
        }
    }
}
