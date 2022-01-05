


#include "KillAchievement.h"
KillAchievement::KillAchievement(Hero *hero, Badge* badge) : subject(hero), badge(badge) {

    this->attach();

}

void KillAchievement::attach() {
    subject->subscribe(this);

}

void KillAchievement::detach() {

    subject->unsubscribe(this);
}

void KillAchievement::update() {

    if(subject->counterKill == 5){
        badge->start = true;
        badge->type = BadgeType::killer;
        this->done = true;
    }

}

KillAchievement::~KillAchievement()= default;