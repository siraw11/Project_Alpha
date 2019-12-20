//
// Created by andreatadde on 12/12/19.
//

#include "EndScreen.h"
#include "../StateMachine/State_Level.h"
#include "../StateMachine/State_Achievement.h"

EndScreen::EndScreen() {
    text1Pos.x = 100;
    text1Pos.y = 100;
    text2Pos.x = 100;
    text2Pos.y = 130;
    titlePos.x = 150;
    titlePos.y = 50;

    this->Font.loadFromFile("textures/arial_narrow_7.ttf");

    endVect[0].setFont(this->Font);
    endVect[0].setCharacterSize(textSize);
    endVect[0].setFillColor(sf::Color::Red);
    endVect[0].setPosition(text1Pos.x, text1Pos.y);
    endVect[0].setString("ACHIEVEMENT SCREEN");

    endVect[1].setFont(this->Font);
    endVect[1].setCharacterSize(textSize);
    endVect[1].setFillColor(sf::Color::White);
    endVect[1].setPosition(text2Pos.x, text2Pos.y);
    endVect[1].setString("EXIT");

    title.setFont(this->Font);
    title.setCharacterSize(textSize);
    title.setFillColor(sf::Color::Black);
    title.setPosition(titlePos.x, titlePos.y);
    title.setString("GRAZIE PER AVER GIOCATO");
}

void EndScreen::update(Input input, StateManager *state, sf::RenderWindow *window) {
    if (input == Input::Down) {
        selected++;
        if (selected < SIZE_END) {
            endVect[selected - 1].setFillColor(sf::Color::White);
        } else {
            selected--;
        }
        endVect[selected].setFillColor(sf::Color::Red);
    }
    if (input == Input::Up) {
        selected--;
        if (selected >= 0) {
            endVect[selected + 1].setFillColor(sf::Color::White);
        } else {
            selected++;
        }
        endVect[selected].setFillColor(sf::Color::Red);
    }
    if (input == Input::Enter) {
        if (selected == 0) {
            delete state;
            state->setState(new State_Achievement(state));
        }
        if (selected == 1) {
            delete state;
            window->close();
        }
    }
}

void EndScreen::drawMenu(sf::RenderWindow *window) {
    for (int i = 0; i < SIZE_END; i++) {
        window->draw(this->endVect[i]);
    }
    window->draw(title);
}

EndScreen::~EndScreen() {

}
