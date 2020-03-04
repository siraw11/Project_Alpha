//
// Created by davide on 29/10/19.
//

#include "NextLevelScreen.h"
#include "iostream"
#include "../StateMachine/State_Main.h"
#include "../StateMachine/State_Level.h"

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

    nextLevel[0].setFont(this->Font);
    nextLevel[0].setCharacterSize(textSize);
    nextLevel[0].setFillColor(sf::Color::Red);
    nextLevel[0].setPosition(text1Pos.x, text1Pos.y);
    nextLevel[0].setString("NEXT LEVEL");

    nextLevel[2].setFont(this->Font);
    nextLevel[2].setCharacterSize(textSize);
    nextLevel[2].setFillColor(sf::Color::White);
    nextLevel[2].setPosition(text3Pos.x, text3Pos.y);
    nextLevel[2].setString("EXIT");

    nextLevel[1].setFont(this->Font);
    nextLevel[1].setCharacterSize(textSize);
    nextLevel[1].setFillColor(sf::Color::White);
    nextLevel[1].setPosition(text2Pos.x, text2Pos.y);
    nextLevel[1].setString("MAIN MENU");

    title.setFont(this->Font);
    title.setCharacterSize(textSize);
    title.setFillColor(sf::Color::Black);
    title.setPosition(titlePos.x, titlePos.y);
    title.setString("LEVEL COMPLETED");
}

void NextLevelScreen::update(Input input, StateManager *state, sf::RenderWindow *window) {
    if (input == Input::Down) {
        selected++;
        if (selected < SIZE) {
            nextLevel[selected - 1].setFillColor(sf::Color::White);
        } else {
            selected--;
        }
        nextLevel[selected].setFillColor(sf::Color::Red);
    }
    if (input == Input::Up) {
        selected--;
        if (selected >= 0) {
            nextLevel[selected + 1].setFillColor(sf::Color::White);
        } else {
            selected++;
        }
        nextLevel[selected].setFillColor(sf::Color::Red);
    }
    if (input == Input::Enter) {
        if (selected == 0) {
            state->setState(new State_Level(state));
        }
        if (selected == 1) {
            delete state;
            state->setState(new State_Main(state));
        }
        if (selected == 2) {
            window->close();
        }
    }
}

void NextLevelScreen::drawMenu(sf::RenderWindow *window) {
    for (int i = 0; i < SIZE; i++) {
        window->draw(this->nextLevel[i]);
    }
    window->draw(title);
}