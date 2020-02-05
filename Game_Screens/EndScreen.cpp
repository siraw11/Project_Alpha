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

    endVector[0].setFont(this->Font);
    endVector[0].setCharacterSize(textSize);
    endVector[0].setFillColor(sf::Color::Red);
    endVector[0].setPosition(text1Pos.x, text1Pos.y);
    endVector[0].setString("MAIN MENU");

    endVector[1].setFont(this->Font);
    endVector[1].setCharacterSize(textSize);
    endVector[1].setFillColor(sf::Color::White);
    endVector[1].setPosition(text2Pos.x, text2Pos.y);
    endVector[1].setString("EXIT");

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
            endVector[selected - 1].setFillColor(sf::Color::White);
        } else {
            selected--;
        }
        endVector[selected].setFillColor(sf::Color::Red);
    }
    if (input == Input::Up) {
        selected--;
        if (selected >= 0) {
            endVector[selected + 1].setFillColor(sf::Color::White);
        } else {
            selected++;
        }
        endVector[selected].setFillColor(sf::Color::Red);
    }
    if (input == Input::Enter) {
        if (selected == 0) {
            delete state;
            state->setState(new State_Main(state));
        }
        if (selected == 1) {
            window->close();
        }
    }
}

void EndScreen::drawMenu(sf::RenderWindow *window) {
    for (int i = 0; i < SIZE_END; i++) {
        window->draw(this->endVector[i]);
    }
    window->draw(title);
}

EndScreen::~EndScreen() {

}
