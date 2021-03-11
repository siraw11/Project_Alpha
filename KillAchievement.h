//
// Created by matteo on 10/03/21.
//

#ifndef PROJECT_ALPHA_KILLACHIEVEMENT_H
#define PROJECT_ALPHA_KILLACHIEVEMENT_H


#include "Observer.h"
#include "Hero.h"
#include "Badge.h"

class KillAchievement : public Observer{
    public:
    explicit KillAchievement(Hero* hero, Badge* badge);

    ~KillAchievement() override;
    void attach() override;
    void detach() override;
    void update() override;

private :
    Hero* subject;
    Badge* badge;


};


#endif //PROJECT_ALPHA_KILLACHIEVEMENT_H
