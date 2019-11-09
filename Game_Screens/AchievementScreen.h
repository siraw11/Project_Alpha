//
// Created by davide on 26/10/19.
//

#ifndef GAME_ACHIEVEMENTSCREEN_H
#define GAME_ACHIEVEMENTSCREEN_H
#define SIZEACHIVE 1

#include "../Input.h"
#include "SFML/Graphics.hpp"
#include "../Achievements/FirstBlood.h"
#include "../AchievementNotifier.h"
#include "../StateMachine/State_Main.h"
#include "../StateMachine/StateManager.h"
class AchievementScreen {

public:
    AchievementScreen();

    void update(Input input, StateManager *state);

    void drawAchievements(AchievementNotifier *achievementNotifier, sf::RenderWindow *window);

private:
    sf::Text title;
    sf::Text back[SIZEACHIVE];
    sf::Font Font;
    int selected = 0;
    sf::Vector2i text1Pos;
    sf::Vector2i firstBloodPos;
    sf::Vector2i firstDeathPos;
    sf::Vector2i potionAchivPos;
    sf::Vector2i titlePos;
    unsigned int textSize = 30;

};


#endif //GAME_ACHIEVEMENTSCREEN_H
