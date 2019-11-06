//
// Created by davide on 26/10/19.
//

#include "AchievementScreen.h"
#include "iostream"

AchievementScreen::AchievementScreen() {
    text1Pos.x = 100;
    text1Pos.y = 100;
    firstBloodPos.x = 100;
    firstBloodPos.y = 150;
    firstDeathPos.x = 100;
    firstDeathPos.y = 180;
    potionAchivPos.x = 100;
    potionAchivPos.y = 210;
    titlePos.x = 150;
    titlePos.y = 50;

    this->Font.loadFromFile("textures/arial_narrow_7.ttf");

    back[0].setFont(this->Font);
    back[0].setCharacterSize(textSize);
    back[0].setFillColor(sf::Color::Red);
    back[0].setPosition(text1Pos.x, text1Pos.y);
    back[0].setString("GO BACK");

    title.setFont(this->Font);
    title.setCharacterSize(textSize);
    title.setFillColor(sf::Color::Black);
    title.setPosition(titlePos.x, titlePos.y);
    title.setString("ACHIEVEMENT LIST");
}

void AchievementScreen::update(Input *input, GameStates *state) {

    if (*input == Input::Enter) {
        if (selected == 0) {
            (*state) = GameStates::Main_menu;
        }
    }
    *input = Input::Null;
}

void AchievementScreen::drawAchievements(AchievementNotifier *achievementNotifier, sf::RenderWindow *window) {
    achievementNotifier->firstBlood.description.setPosition(firstBloodPos.x, firstBloodPos.y);
    achievementNotifier->firstBlood.unlocked.setPosition(firstBloodPos.x + 500, firstBloodPos.y);
    achievementNotifier->firstDeath.description.setPosition(firstDeathPos.x, firstDeathPos.y);
    achievementNotifier->firstDeath.unlocked.setPosition(firstDeathPos.x + 500, firstDeathPos.y);
    achievementNotifier->potionUsed.description.setPosition(potionAchivPos.x, potionAchivPos.y);
    achievementNotifier->potionUsed.unlocked.setPosition(potionAchivPos.x + 500, potionAchivPos.y);
    for (int i = 0; i < SIZE; i++) {
        window->draw(this->back[i]);
    }
    window->draw(title);
    window->draw(achievementNotifier->firstBlood.description);
    window->draw(achievementNotifier->firstBlood.unlocked);
    window->draw(achievementNotifier->firstDeath.description);
    window->draw(achievementNotifier->firstDeath.unlocked);
    window->draw(achievementNotifier->potionUsed.description);
    window->draw(achievementNotifier->potionUsed.unlocked);
}
