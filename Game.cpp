//
// Created by Luca Graziotti on 04/11/2019.
//

#include <iostream>
#include "Game.h"
#include "GameStates/MenuHomeState.h"

GameDataRef Game::gameData = std::make_shared<GameData>();

Game::Game() {
    gameData->window.create(sf::VideoMode(sf::VideoMode::getDesktopMode()), "Motocross 2D",
                            sf::Style::Close | sf::Style::Titlebar);
    gameData->window.setVerticalSyncEnabled(true);
    gameData->machine.push_state(StateRef(new MenuHomeState()));

    Game::Run();
}

void Game::Run() {
    while (Game::gameData->window.isOpen()) {
        sf::Event event{};
        while (Game::gameData->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::gameData->window.close();
            } else {
                Game::gameData->machine.get_current_state()->handleInput(event);
            }
        }
        //this->gameData->machine.get_current_state()->HandleInput();
        Game::gameData->machine.get_current_state()->update();
        Game::gameData->machine.get_current_state()->draw();
        Game::gameData->window.display();
    }
}