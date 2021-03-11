//
// Created by matteo on 09/03/21.
//

#include "WalkingAchievement.h"
#include <iostream>
#include "WalkingAchievement.h"

WalkingAchievement::WalkingAchievement(Hero *hero, Badge* badge) : subject(hero), badge(badge) {

    this->attach();

}

void WalkingAchievement::attach() {
    subject->subscribe(this);

}

void WalkingAchievement::detach() {

    subject->unsubscribe(this);
}

void WalkingAchievement::update() {

    if(subject->counterStep == 10){
        badge->start = true;
        badge->type = BadgeType::walker;
        this->done = true;
    }

}

WalkingAchievement::~WalkingAchievement()= default;