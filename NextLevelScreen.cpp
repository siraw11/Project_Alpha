//
// Created by davide on 29/10/19.
//

#include "NextLevelScreen.h"
#include "iostream"

NextLevelScreen::NextLevelScreen() {
    text1Pos.x = 100;
    text1Pos.y = 100;
    text2Pos.x = 100;
    text2Pos.y = 130;
    text3Pos.x = 100;
    text3Pos.y = 160;
    titlePos.x = 150;
    titlePos.y = 50;

    this->Font.loadFromFile("textures/arial_narrow_7.ttf");

    menu[0].setFont(this->Font);
    menu[0].setCharacterSize(textSize);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setPosition(text1Pos.x, text1Pos.y);
    menu[0].setString("NEXT LEVEL");

    menu[2].setFont(this->Font);
    menu[2].setCharacterSize(textSize);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setPosition(text3Pos.x, text3Pos.y);
    menu[2].setString("EXIT");

    menu[1].setFont(this->Font);
    menu[1].setCharacterSize(textSize);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setPosition(text2Pos.x, text2Pos.y);
    menu[1].setString("MAIN MENU");

    title.setFont(this->Font);
    title.setCharacterSize(textSize);
    title.setFillColor(sf::Color::Black);
    title.setPosition(titlePos.x, titlePos.y);
    title.setString("LEVEL COMPLETED");
}

void NextLevelScreen::update(Input *input, GameStates *state, sf::RenderWindow *window) {
    if (*input == Input::Down) {
        selected++;
        if (selected < SIZE) {
            menu[selected - 1].setFillColor(sf::Color::White);
        } else {
            selected--;
        }
        menu[selected].setFillColor(sf::Color::Red);
    }
    if (*input == Input::Up) {
        selected--;
        if (selected >= 0) {
            menu[selected + 1].setFillColor(sf::Color::White);
        } else {
            selected++;
        }
        menu[selected].setFillColor(sf::Color::Red);
    }
    if (*input == Input::Enter) {
        if (selected == 0) {
            (*state) = GameStates::Level;
        }
        if (selected == 1) {
            (*state) = GameStates::Main_menu;
        }
        if (selected == 2) {
            window->close();
        }
    }
}

void NextLevelScreen::drawMenu(sf::RenderWindow *window) {
    for (int i = 0; i < SIZE; i++) {
        window->draw(this->menu[i]);
    }
    window->draw(title);
}