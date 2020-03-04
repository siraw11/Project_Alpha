//
// Created by davide on 20/10/19.
//

#include "DeathScreen.h"
#include "../StateMachine/State_Level.h"
#include "../StateMachine/State_Main.h"
#include "iostream"

DeathScreen::DeathScreen() {
    text1Pos.x = 100;
    text1Pos.y = 100;
    text2Pos.x = 100;
    text2Pos.y = 130;
    text3Pos.x = 100;
    text3Pos.y = 160;
    titlePos.x = 150;
    titlePos.y = 50;
    this->Font.loadFromFile("textures/arial_narrow_7.ttf");

    death[0].setFont(this->Font);
    death[0].setCharacterSize(textSize);
    death[0].setFillColor(sf::Color::Red);
    death[0].setPosition(text1Pos.x, text1Pos.y);
    death[0].setString("RESTART");

    death[1].setFont(this->Font);
    death[1].setCharacterSize(textSize);
    death[1].setFillColor(sf::Color::White);
    death[1].setPosition(text2Pos.x, text2Pos.y);
    death[1].setString("MAIN MENU");

    death[2].setFont(this->Font);
    death[2].setCharacterSize(textSize);
    death[2].setFillColor(sf::Color::White);
    death[2].setPosition(text3Pos.x, text3Pos.y);
    death[2].setString("EXIT");

    title.setFont(this->Font);
    title.setCharacterSize(textSize);
    title.setFillColor(sf::Color::Black);
    title.setPosition(titlePos.x, titlePos.y);
    title.setString("GAME OVER");
}

void DeathScreen::update(Input input, StateManager *state, sf::RenderWindow *window) {
    if (input == Input::Down) {
        selected++;
        if (selected < SIZE) {
            death[selected - 1].setFillColor(sf::Color::White);
        } else {
            selected--;
        }
        death[selected].setFillColor(sf::Color::Red);
    }
    if (input == Input::Up) {
        selected--;
        if (selected >= 0) {
            death[selected + 1].setFillColor(sf::Color::White);
        } else {
            selected++;
        }
        death[selected].setFillColor(sf::Color::Red);
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

void DeathScreen::drawMenu(sf::RenderWindow *window) {

    for (int i = 0; i < SIZE; i++) {
        window->draw(this->death[i]);
    }
    window->draw(title);
}
