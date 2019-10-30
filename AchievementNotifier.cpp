//
// Created by davide on 26/10/19.
//

#include "AchievementNotifier.h"
#include "Achievements/FirstBlood.h"
#include "Achievements/PotionAchievement.h"
#include "iostream"

AchievementNotifier::AchievementNotifier() = default;

void AchievementNotifier::update(sf::Clock *clock, sf::RenderWindow *window, int enemyKilled, int potionCounter,
                                 int deathCounter,sf::View* camera) {

    if (enemyKilled == 1 && !firstBlood.achieved) {
        firstBlood.clock = clock;
        firstBlood.update();
    }

    if (deathCounter == 1 && !firstDeath.achieved) {
        firstDeath.clock = clock;
        firstDeath.update();
    }
    if (potionCounter == 2 && !potionUsed.achieved){
        potionUsed.clock=clock;
        potionUsed.update();
    }
    firstBlood.drawPopUp(window,camera);
    firstDeath.drawPopUp(window,camera);
    potionUsed.drawPopUp(window,camera);
}