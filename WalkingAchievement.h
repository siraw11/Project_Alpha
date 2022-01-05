

#ifndef PROJECT_ALPHA_WALKINGACHIEVEMENT_H
#define PROJECT_ALPHA_WALKINGACHIEVEMENT_H

#include "Observer.h"
#include "Hero.h"
#include "Badge.h"

class WalkingAchievement : public Observer {
public:
    explicit WalkingAchievement(Hero* hero, Badge* badge);

    ~WalkingAchievement() override;
    void attach() override;
    void detach() override;
    void update() override;

private :
    Hero* subject;
    Badge* badge;


};



#endif //PROJECT_ALPHA_WALKINGACHIEVEMENT_H
