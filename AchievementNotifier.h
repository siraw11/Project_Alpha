//
// Created by davide on 26/10/19.
//

#ifndef GAME_ACHIVEMENTNOTIFIER_H
#define GAME_ACHIVEMENTNOTIFIER_H

#include "Achievements/FirstBlood.h"
#include "Achievements/FirstDeath.h"
#include "Achievements/PotionAchievement.h"

class AchievementNotifier {
public:
    AchievementNotifier();

    void update(sf::Clock *clock, sf::RenderWindow *window, int enemyKilled, int potionCounter, int deathCounter,sf::View* camera);

public:
    FirstBlood firstBlood;
    FirstDeath firstDeath;
    PotionAchievement potionUsed;
    sf::Clock *clock;
};


#endif //GAME_ACHIVEMENTNOTIFIER_H
