//
// Created by davide on 26/10/19.
//

#include "AchievementNotifier.h"
#include "Achievements/FirstBlood.h"
#include "Achievements/PotionAchievement.h"
#include "iostream"

AchievementNotifier::AchievementNotifier() = default;

void AchievementNotifier::update(sf::Clock *clock, sf::RenderWindow *window, int enemyKilled, int potionCounter,
                                 int deathCounter) {
    if (enemyKilled == 1 && !firstBlood.achieved) {
        firstBlood.clock = clock;
        firstBlood.update();
    }
    if (potionCounter == 2) {
        firstDeath.clock = clock;
        potionAchievement.update();
    }
    if (deathCounter == 1 && !firstDeath.achieved) {
        firstDeath.clock = clock;
        firstDeath.update();
    }
    firstBlood.drawPopUp(window);
    firstDeath.drawPopUp(window);
    potionAchievement.drawPopUp(window);
}